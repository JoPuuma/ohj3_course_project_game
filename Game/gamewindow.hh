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

    void adjustResources();
    void adjustGameWiew();
    void startGame();
    void buildChanged();
    void setHeadQuarter();



public slots: 
    void receiveData(const std::vector<std::string>& p,
                     const bool& roundLimit,const int& rounds);
    void currentWorkerTo1();
    void currentWorkerTo2();
    void currentWorkerTo3();
    void currentWorkerTo4();
    void currentWorkerTo5();

    void build();
    void addWorker();
    void endTurn();
    void trainDialog();
    void getTrainigData(const std::string& workerType);


private:
    Ui::GameWindow *ui;
    std::shared_ptr<Game::GameEventHandler> handler_ = nullptr;
    std::shared_ptr<Game::ObjectManager> Omanager_ = nullptr;
    std::shared_ptr<Game::GameScene> scene_ = nullptr;
    std::shared_ptr<Game::Player> wInTurn = nullptr;
    std::shared_ptr<Course::WorkerBase> currentWorker= nullptr;
    std::shared_ptr<TrainDialog> traindialog = nullptr;
    //std::shared_ptr<Course::TileBase> currentTile = nullptr;
};


#endif // GAMEWINDOW_HH


