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

    void resize();

    void drawItem( std::shared_ptr<Course::GameObject> obj);
    void adjustResources();
    void adjustGameWiew();
    void startGame();
    void adjustBuildingCosts();
    void adjustRightWorkers();
    void setHeadQuarter();
    void changeEnablers(bool b);
    void setImages();
    void maxMovesReached();


public slots: 
    /**
     * @brief Receive data from start dialog
     * @param p: vector, player names
     * @param roundLimit: bool, true if user uses roundlimit
     * @param rounds: int, if roundLimit is true rounds contains the round number
     */
    void receiveData(const std::vector<std::string>& p,
                     const bool& roundLimit,const int& rounds);
    /**
     * @brief build building when build button pressed
     */
    void build();
    void addWorker();
    void endTurn();
    /**
     * @brief display train dialog when train button pressed
     */
    void trainDialog();
    /**
     * @brief receive data from train dialog
     * @param type: WorkerType, new worker type
     */
    void getTrainigData(WorkerType& type);

private:
    Ui::GameWindow *ui;
    std::shared_ptr<Game::GameEventHandler> handler_ = nullptr;
    std::shared_ptr<Game::ObjectManager> oManager_ = nullptr;
    std::shared_ptr<Game::GameScene> scene_ = nullptr;
    std::shared_ptr<Game::Player> wInTurn = nullptr; // current player
    int currentWorkerIndex; // from 1 to 5
};

Q_DECLARE_METATYPE(BuildingType)
#endif // GAMEWINDOW_HH


