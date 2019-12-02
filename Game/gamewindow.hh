#ifndef GAMEWINDOW_HH
#define GAMEWINDOW_HH

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <map>
#include <memory>
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

    /**
     * @brief adjust updated resources to GameView
     */
    void adjustResources();

    /**
     * @brief adjust GameWiew:
     *  resources
     * workers
     * player
     * turn
     */
    void adjustGameWiew();

    /**
     * @brief starts the Game
     */
    void startGame();

    /**
     * @brief adjust BuildingCosts when player chooses building
     */
    void adjustBuildingCosts();

    /**
     * @brief adjust RightWorkers when player train workers
     * or it's another player's turn
     */
    void adjustRightWorkers();

    /**
     * @brief set HeadQuarter when player chooses tile
     */
    void setHeadQuarter();

    /**
     * @brief change buttons to disabled when it is round 0
     * @param b
     */
    void changeEnablers(bool b);

    /**
     * @brief set worker buttons Image to basicWorker
     */
    void setImages();

    /**
     * @brief  if player reaches maxMoves disable 'build' and 'train' buttons
     */
    void maxMovesReached();
    std::shared_ptr<Game::GameScene> scene_ = nullptr;


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
     * @brief build building when 'build' button is pressed
     */
    void build();

    /**
     * @brief add worker to the tile when 'assign'  button is pressed
     */
    void addWorker();

    /**
     * @brief ends Turn when 'end turn' button is pressed
     */
    void endTurn();
    /**
     * @brief display train dialog when 'train' button is pressed
     */
    void trainDialog();
    /**
     * @brief receive data from train dialog
     * @param type: WorkerType, new worker type
     */
    void getTrainingData(WorkerType& type);

private:
    Ui::GameWindow *ui;
    std::shared_ptr<Game::GameEventHandler> handler_ = nullptr;
    std::shared_ptr<Game::ObjectManager> oManager_ = nullptr;
    std::shared_ptr<Game::Player> wInTurn = nullptr; // current player
    int currentWorkerIndex; // from 1 to 5
};

Q_DECLARE_METATYPE(BuildingType)
#endif // GAMEWINDOW_HH


