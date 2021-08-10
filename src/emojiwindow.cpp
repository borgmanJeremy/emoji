#include "emojiwindow.h"

QPushButton *create_button(QString emoji, QWidget *parent) {
    auto emoji_symbol = new QPushButton(emoji, parent);
    emoji_symbol->setFont(QFont("Noto Color Emoji", 14));
    emoji_symbol->setFlat(true);

    return emoji_symbol;
}


void EmojiWindow::filter(QString text){
    create_layout(m_layout, text);
    this->setLayout(m_layout);
}

void EmojiWindow::create_layout(QGridLayout* layout, QString const &search_term){
    // First clear layout
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr){
        delete child->widget();
        delete child;
    }

    auto matches = Emoji::search_keys(search_term.toStdString());
    unsigned int row_count = 0;
    unsigned int col_count = 0;
    QByteArray ar ("\U0001F3F3\ufe0f\u200d\U0001f308");
    layout->addWidget(create_button(ar, this), row_count,
                      col_count, 1, 1);

    // for (auto const match : matches) {
    //     layout->addWidget(create_button(QString::fromStdString(Emoji::emoji_list[match].code), this), row_count,
    //                         col_count, 1, 1);
    //     col_count += 1;
    //     if (col_count >= number_of_cols) {
    //         row_count++;
    //         col_count = 0;
    //     }
    // }
}

EmojiWindow::EmojiWindow(QWidget *parent) : QWidget(parent) {
    m_layout = new QGridLayout;

    m_layout->setHorizontalSpacing(0);
    m_layout->setVerticalSpacing(0);
    create_layout(m_layout, "Flag");

    this->setLayout(m_layout);
}

