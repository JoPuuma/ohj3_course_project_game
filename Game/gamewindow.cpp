#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"
#include "Core/player.hh"

#include "core/playerbase.h"

#include "Core/worldgenerator.hh"
#include"core/worldgenerator.h"
#include "Tiles/rock.hh"
#include "Tiles/sand.hh"
#include "Tiles/water.hh"
#include "tiles/forest.h"

#include <QDebug>



GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler),
    scene_(new Game::GameScene(this)),
    maxRounds_(-1)
{
    Omanager_ = std::make_shared<Game::ObjectManager>();
    handler_ = std::make_shared<Game::GameEventHandler>();


    ui->setupUi(this);

    //start dialog
    Dialog d;

    connect(&d, &Dialog::sendData,this, &GameWindow::receiveData);
    connect(ui->buttonEndTurn, &QPushButton::clicked,
            this, &GameWindow::endTurn);
//    connect(ui->buttonCottage, &QPushButton::clicked,
//            this, &GameWindow::BuildCottage);

    d.exec();


   Game::GameScene* sgs_rawptr = scene_.get();

   ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));





   Game::WorldGenerator& worldgen = Game::WorldGenerator::getInstance();
//   worldgen.addConstructor<Game::Rock>('r');
//   worldgen.addConstructor<Game::Sand>('s');
//   worldgen.addConstructor<Game::Water>('w');
//   worldgen.addConstructor<Course::Forest>('f');

   worldgen.GenerateMap(7,7,Omanager_,handler_);




    startGame();

}

GameWindow::~GameWindow(){
    delete ui;
}

void GameWindow::setSize(int width, int height)
{
    scene_->setSize(width, height);
}

void GameWindow::setScale(int scale)
{
    scene_->setScale(scale);
}

void GameWindow::drawItem(std::shared_ptr<Course::GameObject> obj)
{
    scene_->DrawItem(obj);
}

void GameWindow::removeItem(std::shared_ptr<Course::GameObject> obj)
{
    scene_->RemoveItem(obj);
}

void GameWindow::updateItem(std::shared_ptr<Course::GameObject> obj)
{
    scene_->UpdateItem(obj);
}

void GameWindow::adjustResources()
{
    ui->lcdMoney->display(inTurn->resources_[Course::MONEY]);
    ui->lcdFood->display(inTurn->resources_[Course::FOOD]);
    ui->lcdWood->display(inTurn->resources_[Course::WOOD]);
    ui->lcdStone->display(inTurn->resources_[Course::STONE]);
    ui->lcdOre->display(inTurn->resources_[Course::ORE]);
}

void GameWindow::startGame()
{
    inTurn = playerObjs[0];
    adjustResources();
}

void GameWindow::receiveData(std::vector<std::string> players,
                             bool roundLimit,
                             int rounds){
    // create players
    for(std::string &player : players){
        std::shared_ptr<Game::Player> ptr(new Game::Player(player));
        handler_->addPlayer(player,ptr); // to gameEventHandler
        playerObjs.push_back(ptr); // to gamewindow
    }
    if(roundLimit) maxRounds_ = rounds;


}


void GameWindow::endTurn()
{
    qDebug() << "endTurn";
}
