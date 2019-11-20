#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <map>

#include "Core/gameeventhandler.hh"


namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

public slots:
    void receiveData(std::vector<std::string> p, bool roundLimit, int rounds);
private:
    Ui::GameWindow *ui;

};

#endif // GAMEWINDOW_HH
