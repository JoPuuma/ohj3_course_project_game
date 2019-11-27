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
#include "objecttypes.hh"


namespace Ui {
class GameWindow;
}

class Player;
class TrainDialog;

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = 0,
                        std::shared_ptr<Game::GameEventHandler> handler = {});
    ~GameWindow();

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void removeItem( std::shared_ptr<Course::GameObject> obj);
    void updateItem( std::shared_ptr<Course::GameObject> obj);
    void drawrect(QRect rect);
    void adjustResources();
    void adjustGameWiew();
    void startGame();
    void adjustBuildingCosts();
    void setHeadQuarter();
    void changeEnablers(bool b);


public slots: 
    void receiveData(const std::vector<std::string>& p,
                     const bool& roundLimit,const int& rounds);

    void build();
    void addWorker();
    void endTurn();
    void trainDialog();
    void getTrainigData(WorkerType& type);


private:
    Ui::GameWindow *ui;
    std::shared_ptr<Game::GameEventHandler> handler_ = nullptr;
    std::shared_ptr<Game::ObjectManager> oManager_ = nullptr;
    std::shared_ptr<Game::GameScene> scene_ = nullptr;
    std::shared_ptr<Game::Player> wInTurn = nullptr;
    int currentWorkerIndex;
};

Q_DECLARE_METATYPE(BuildingType)
#endif // GAMEWINDOW_HH


