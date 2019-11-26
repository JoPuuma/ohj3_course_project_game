#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"
#include "Core/player.hh"

#include "core/playerbase.h"

#include "Core/worldgenerator.hh"
#include "Tiles/rock.hh"
#include "Tiles/sand.hh"
#include "Tiles/water.hh"
#include "tiles/forest.h"
#include "Buildings/cottage.hh"
#include "Buildings/fishinghut.hh"
#include "Buildings/mine.hh"
#include "tiles/tilebase.h"

#include <QDebug>
#include <QString>

//const using MAX_ROUNDS_NOT_USED = -1;

GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler),
    scene_(new Game::GameScene(this))
{
    Omanager_ = std::make_shared<Game::ObjectManager>(scene_);
    handler_ = std::make_shared<Game::GameEventHandler>();


    ui->setupUi(this);

    //start dialog
    Dialog d;
    connect(&d, &Dialog::rejected, this, &GameWindow::close);
    connect(&d, &Dialog::sendData,this, &GameWindow::receiveData);
    connect(ui->buttonEndTurn, &QPushButton::clicked,
            this, &GameWindow::endTurn);
    connect(ui->buttonBuild, &QPushButton::clicked,
            this, &GameWindow::build);
    connect(ui->buttonWorker1, &QPushButton::clicked,
            this, &GameWindow::currentWorkerTo1);

    d.exec();

    ui->lcdMoney->setPalette(Qt::black);
    ui->lcdFood->setPalette(Qt::black);
    ui->lcdWood->setPalette(Qt::black);
    ui->lcdStone->setPalette(Qt::black);
    ui->lcdOre->setPalette(Qt::black);

    ui->comboBox->setItemData(0,"Cottage");
    ui->comboBox->setItemData(1,"FishingHut");
    ui->comboBox->setItemData(2,"Mine");


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
    ui->lcdMoney->display(wInTurn->resources_[Course::MONEY]);
    ui->lcdFood->display(wInTurn->resources_[Course::FOOD]);
    ui->lcdWood->display(wInTurn->resources_[Course::WOOD]);
    ui->lcdStone->display(wInTurn->resources_[Course::STONE]);
    ui->lcdOre->display(wInTurn->resources_[Course::ORE]);
}

void GameWindow::adjustGameWiew()
{
    adjustResources();
    ui->labelPlayerName->setText( QString::fromStdString(wInTurn->getName()) );
    ui->roundLabel->setText( QString::number(handler_->getRound()) );
}

void GameWindow::startGame()
{

    wInTurn = handler_->currentPlayer();
    adjustGameWiew();
}

void GameWindow::receiveData(const std::vector<std::string>& players,
                             const bool& roundLimit,
                             const int& rounds)
{
    if(roundLimit) handler_->initializeGame(players, handler_, Omanager_, rounds);
    else handler_->initializeGame(players, handler_, Omanager_);
}

void GameWindow::currentWorkerTo1()
{
    currentWorker = wInTurn->workers[1];
}

void GameWindow::currentWorkerTo2()
{
    currentWorker = wInTurn->workers[2];
}

void GameWindow::currentWorkerTo3()
{
    currentWorker = wInTurn->workers[3];
}

void GameWindow::currentWorkerTo4()
{
    currentWorker = wInTurn->workers[4];
}

void GameWindow::currentWorkerTo5()
{
    currentWorker = wInTurn->workers[5];
}

void GameWindow::build()
{
    Omanager_->createBuilding(scene_->getCurrentObject(),
                                                 wInTurn,
                                               Omanager_,
                                                handler_,
    ui->comboBox->currentData().toString().toStdString());
    adjustResources();
}

void GameWindow::addWorker(int& n)
{
    qDebug()<<n;
    Omanager_->addWorker(scene_->getCurrentObject(),
                         wInTurn,
                         Omanager_,
                         handler_,
                         "???");
}


void GameWindow::endTurn()
{
    handler_->endTurn();
    wInTurn = handler_->currentPlayer();
    adjustGameWiew();
}

