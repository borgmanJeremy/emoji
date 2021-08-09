#include "window.h"

QPushButton* create_button(QString emoji, QWidget* parent){

    auto emoji_symbol = new QPushButton(emoji, parent);
    emoji_symbol->setFont(QFont("Noto Color Emoji",21));
    emoji_symbol->setFlat(true);
    return emoji_symbol;

}

Window::Window(QWidget* parent) : QWidget(parent) {
  m_layout = new QGridLayout;
  const auto num_cols = 5;

  m_emoji_list.push_back(create_button("\U0001F600", this));
  m_emoji_list.push_back(create_button("\U0001F4A9", this));

  for (unsigned int i=0; i<m_emoji_list.size(); i++){

        m_layout->addWidget(m_emoji_list[i], 0, i, 1, 1);
  }

  this->setLayout(m_layout);
}

