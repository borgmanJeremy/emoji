
#include <QApplication>
#include <QScrollArea>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QObject>
#include <QPixmap>
#include "emojiwindow.h"

struct CategoryButton {
    std::string description;
    std::string emoji_code;

};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto *main_window = new QWidget;

    auto *scrollArea = new QScrollArea;
    EmojiWindow window;

    auto *v_layout = new QVBoxLayout(main_window);
    auto *line = new QLineEdit("flag", main_window);

    std::vector<CategoryButton> const category_list  { {"activities", "26BD"},
                                                 {"animals-nature", "1F63A"}};

    QString icon_path = "/home/jeremy/github/emoji/assets/buttons/";

    QPixmap pixmap(icon_path + "26BD.png");
    QIcon ButtonIcon(pixmap);

    std::vector <QPushButton*> button_list;

    auto *buttonBox = new QWidget;

    auto *button_layout = new QHBoxLayout(buttonBox);
    for (auto const &button: category_list){
        button_list.emplace_back(new QPushButton(QString::fromStdString(button.description)));
    }

    for (auto &button : button_list){
        button->setIcon(pixmap);
        button_layout->addWidget(button);
    }


    scrollArea->setWidget(&window);

    v_layout->addWidget(line);
    v_layout->addWidget(scrollArea);
    v_layout->addWidget(buttonBox);

    main_window->setFixedWidth(460);
    main_window->setFixedHeight(400);

    main_window->connect(line, &QLineEdit::textEdited,[&window, &line](){window.filter(line->text());});



    main_window->show();

    return app.exec();

}
