#include "emojiwindow.h"


void EmojiWindow::prevent_row_stretch(int last_row) {
    for (int i = 0; i < last_row + 1; ++i) {
        m_layout->setRowStretch(i, 0);
    }
    // Add a blank widget to fill rest of area
    m_layout->setRowStretch(last_row + 1, 1);
    m_layout->addWidget(new QWidget(this), last_row + 1, 0);
}


QSvgWidget *create_svg(std::string emoji, QWidget *parent) {
    auto emoji_symbol = new QSvgWidget(QString::fromStdString(emoji), parent);
    auto height = emoji_symbol->height();
    auto width = emoji_symbol->width();
    return emoji_symbol;
}

void EmojiWindow::filter(QString text) {
    create_layout(m_layout, text);
    m_layout->invalidate();
}

void EmojiWindow::create_layout(QGridLayout *layout, QString const &search_term) {
    // First clear layout
    if (search_term.size() > 2) {

        if (this->layout() != nullptr) {
            QLayoutItem *child;
            while ((child = layout->takeAt(0)) != nullptr) {
                child->widget()->deleteLater();
                delete child;
            }
        }

        emoji.find_matches(search_term.toStdString());
        unsigned int row_count = 0;
        unsigned int col_count = 0;

        for (auto const match: emoji.filter_results) {
            layout->addWidget(create_svg(emoji.path_prefix + "/" + emoji.emoji_list[match].hexcode + ".svg",this ), row_count, col_count);
            col_count += 1;
            if (col_count >= number_of_cols) {
                row_count++;
                col_count = 0;
            }
        }
        prevent_row_stretch(row_count);
    }
}

EmojiWindow::EmojiWindow(QWidget *parent) : QWidget(parent) {
    m_layout = new QGridLayout;
    emoji = Emoji::EmojiList();
    create_layout(m_layout, "flag");

    this->setLayout(m_layout);
}

