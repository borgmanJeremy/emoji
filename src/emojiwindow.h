#include <QGridLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QSvgWidget>
#include <vector>
#include "emoji/emoji.h"

class QPushButton;

class EmojiWindow : public QWidget {
public:
    explicit EmojiWindow(QWidget *parent = 0);

public slots:

    void filter(QString text);

private:
    QGridLayout *m_layout;
    int number_of_cols = 5;

    void create_layout(QGridLayout *layout, QString const &search_term);
};