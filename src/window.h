#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>

class QPushButton;
class Window : public QWidget {
 public:
  explicit Window(QWidget* parent = 0);

 private:
  // QLineEdit* m_search_bar;
  std::vector<QPushButton*> m_emoji_list;
  QGridLayout* m_layout;
};