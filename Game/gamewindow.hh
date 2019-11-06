#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QDialog>

namespace Ui {
class GameWindow;
}

class GameWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
};

#endif // GAMEWINDOW_HH
