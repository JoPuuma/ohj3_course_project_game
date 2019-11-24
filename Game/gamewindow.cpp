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
#include <QString>

//const using MAX_ROUNDS_NOT_USED = -1;

GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler),
    scene_(new Game::GameScene(this)),
    round_(1),
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

    ui->lcdMoney->setPalette(Qt::black);
    ui->lcdFood->setPalette(Qt::black);
    ui->lcdWood->setPalette(Qt::black);
    ui->lcdStone->setPalette(Qt::black);
    ui->lcdOre->setPalette(Qt::black);



   Game::GameScene* sgs_rawptr = scene_.get();

   ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));

   Game::WorldGenerator& worldgen = Game::WorldGenerator::getInstance();
   worldgen.addConstructor<Game::Rock>('r');
   worldgen.addConstructor<Game::Sand>('s');
   worldgen.addConstructor<Game::Water>('w');
   worldgen.addConstructor<Course::Forest>('f');
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

void GameWindow::resize()
{
    scene_->resize();
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

void GameWindow::adjustGameWiew()
{
    adjustResources();
    ui->labelPlayerName->setText( QString::fromStdString(inTurn->getName()) );
    ui->roundLabel->setText( QString::number(round_) );
}

void GameWindow::startGame()
{
    inTurn = playerPtrs[0];
    adjustGameWiew();
}

void GameWindow::receiveData(const std::vector<std::string>& players,
                             const bool& roundLimit,
                             const int& rounds){
    // create players
    std::shared_ptr<Game::Player> previousPlayerPtr = nullptr;
    for(const std::string &player : players){
        // new player
        std::shared_ptr<Game::Player> ptr =
                    std::make_shared<Game::Player>(Game::Player(player));

        handler_->addPlayer(player,ptr); // to gameEventHandler        
        playerPtrs.push_back(ptr); // to gameWindow

        if(previousPlayerPtr != nullptr){
            previousPlayerPtr->addNextPlayer(ptr);
        }
        previousPlayerPtr = ptr;
    }
    if(roundLimit) maxRounds_ = rounds;
}


void GameWindow::endTurn()
{
    if(inTurn->next == nullptr){
        inTurn = playerPtrs[0];
        round_++;
    }else{
        inTurn = inTurn->next;
    }

    adjustGameWiew();
}

bool GameWindow::gameEnd()
{
    return round_ == maxRounds_;  // || all tiles in use
}
