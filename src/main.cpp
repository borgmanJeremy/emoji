
#include <QApplication>
#include <QScrollArea>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QObject>
#include "emojiwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    auto* main_window = new QWidget;

    auto* scrollArea = new QScrollArea;
    EmojiWindow window;

    auto* v_layout = new QVBoxLayout(main_window);
    auto *line = new QLineEdit("fla", main_window);

    scrollArea->setWidget(&window);

    v_layout->addWidget(line);
    v_layout->addWidget(scrollArea);

    main_window->setFixedWidth(460);
    main_window->setFixedHeight(400);

    main_window->connect(line, &QLineEdit::textEdited,[&window, &line](){window.filter(line->text());});
    main_window->show();

    return app.exec();

}
