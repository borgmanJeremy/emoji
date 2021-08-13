#include "emojiwindow.h"

QPushButton *create_button(QString emoji, QWidget *parent) {
    auto emoji_symbol = new QPushButton(emoji, parent);
    emoji_symbol->setFont(QFont("Noto Color Emoji", 14));
    emoji_symbol->setFlat(true);

    return emoji_symbol;
}


QSvgWidget *create_svg(std::string emoji, QWidget *parent) {
    auto emoji_symbol = new QSvgWidget(QString::fromStdString(emoji), parent);

    return emoji_symbol;
}
void EmojiWindow::filter(QString text) {
    create_layout(m_layout, text);
    this->setLayout(m_layout);
}

void EmojiWindow::create_layout(QGridLayout *layout, QString const &search_term) {
    // First clear layout
    if (search_term.size() >2){
        QLayoutItem *child;
        while ((child = layout->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }


        emoji.find_matches(search_term.toStdString());
        unsigned int row_count = 0;
        unsigned int col_count = 0;

        for (auto const match : emoji.filter_results) {
            layout->addWidget(create_svg(emoji.path_prefix + "/" + emoji.emoji_list[match].hexcode + ".svg",this), row_count,
                              col_count, 1, 1);
            col_count += 1;
            if (col_count >= number_of_cols) {
                row_count++;
                col_count = 0;
            }
        }
    }
}

EmojiWindow::EmojiWindow(QWidget *parent) : QWidget(parent){
    m_layout = new QGridLayout;
    emoji = Emoji::EmojiList();
    m_layout->setHorizontalSpacing(0);
    m_layout->setVerticalSpacing(0);
    create_layout(m_layout, "eye");

    this->setLayout(m_layout);
}

