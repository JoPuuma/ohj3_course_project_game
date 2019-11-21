#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <map>
#include<memory>

#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"
#include "Graphics/gamescene.hh"

namespace Ui {
class GameWindow;
}

//class ObjectManager;
//class GameEventHandler;
class Player;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0,
                        std::shared_ptr<Game::GameEventHandler> handler = {});
    ~GameWindow();

public slots:
    void receiveData(std::vector<std::string> p, bool roundLimit, int rounds);
    /*
    void BuildCottage();
    void BuildHQ();
    void BuildMine();
    void BuildFishingHut();
    */
    void endTurn();

private:
    Ui::GameWindow *ui;
    std::shared_ptr<Game::GameEventHandler> handler_ = nullptr;
    std::shared_ptr<Game::ObjectManager> Omanager_ = nullptr;
    std::shared_ptr<Game::GameScene> scene_ = nullptr;
    std::vector<std::shared_ptr<Game::Player>> playerObjs;
};

#endif // GAMEWINDOW_HH
