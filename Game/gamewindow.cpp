#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "Core/player.hh"
#include "traindialog.hh"

#include "Core/objectmanager.hh"
#include "Core/gameeventhandler.hh"
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
#include <QPixmap>
#include <QIcon>
#include <QMessageBox>

const int NONVALUE = -1;

GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler),
    scene_(new Game::GameScene(this)),
    currentWorkerIndex(NONVALUE)

{
    oManager_ = std::make_shared<Game::ObjectManager>(scene_);
    handler_ = std::make_shared<Game::GameEventHandler>();


    ui->setupUi(this);

    Dialog sd;      //start dialog

    connect(&sd, &Dialog::rejected, this, &GameWindow::close);
    connect(&sd, &Dialog::sendData,this, &GameWindow::receiveData);

    connect(ui->comboBox, QOverload<const QString &>::of(&QComboBox::currentIndexChanged),
            [=](const QString &text){Q_UNUSED(text);  adjustBuildingCosts(); });
    connect(ui->buttonEndTurn, &QPushButton::clicked,
            this, &GameWindow::endTurn);
    connect(ui->buttonBuild, &QPushButton::clicked,
            this, &GameWindow::build);
    connect(ui->buttonAssign, &QPushButton::clicked,
            this, &GameWindow::addWorker);
    connect(ui->buttonTrain, &QPushButton::clicked,
            this,&GameWindow::trainDialog);

    connect(ui->buttonWorker1, &QPushButton::clicked,
            this,[=](){currentWorkerIndex = 1;});
    connect(ui->buttonWorker2, &QPushButton::clicked,
            this,[=](){currentWorkerIndex = 2;});
    connect(ui->buttonWorker3, &QPushButton::clicked,
            this,[=](){currentWorkerIndex = 3;});
    connect(ui->buttonWorker4, &QPushButton::clicked,
            this,[=](){currentWorkerIndex = 4;});
    connect(ui->buttonWorker5, &QPushButton::clicked,
            this,[=](){currentWorkerIndex = 5;});


    sd.exec();

    ui->lcdMoney->setPalette(Qt::black);
    ui->lcdFood->setPalette(Qt::black);
    ui->lcdWood->setPalette(Qt::black);
    ui->lcdStone->setPalette(Qt::black);
    ui->lcdOre->setPalette(Qt::black);

    ui->comboBox->addItem("Cottage");
    ui->comboBox->addItem("FishingHut");
    ui->comboBox->addItem("Mine");

    ui->comboBox->setItemData(0, BuildingType::COTTAGE);
    ui->comboBox->setItemData(1, BuildingType::FISHINGHUT);
    ui->comboBox->setItemData(2, BuildingType::MINE);


   Game::GameScene* sgs_rawptr = scene_.get();
   ui->graphicsView->setScene(dynamic_cast<QGraphicsScene*>(sgs_rawptr));


   Game::WorldGenerator& worldgen = Game::WorldGenerator::getInstance();
   worldgen.addConstructor<Game::Rock>('r');
   worldgen.addConstructor<Game::Sand>('s');
   worldgen.addConstructor<Game::Water>('w');
   worldgen.addConstructor<Course::Forest>('f');
   worldgen.generateMap(7,7,oManager_,handler_);

    setImages();
    startGame();
}

GameWindow::~GameWindow(){
    delete ui;
}

void GameWindow::resize()
{
    scene_->resize();
}

void GameWindow::drawItem(std::shared_ptr<Course::GameObject> obj)
{
    scene_->DrawItem(obj);
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
    adjustRightWorkers();
    ui->labelPlayerName->setText( QString::fromStdString(wInTurn->getName()) );
    ui->roundLabel->setText( QString::number(handler_->getRound()) );
}

void GameWindow::startGame()
{

    wInTurn = handler_->currentPlayer();
    adjustGameWiew();
    setHeadQuarter();
}

void GameWindow::receiveData(const std::vector<std::string>& players,
                             const bool& roundLimit,
                             const int& rounds)
{
    if(roundLimit) handler_->initializeGame(players, handler_, oManager_, rounds);
    else handler_->initializeGame(players, handler_, oManager_);
}

void GameWindow::build()
{
    if(handler_->getRound() == 0 && wInTurn->getBuildingCount() == 0) setHeadQuarter();

    else{
        oManager_->createBuilding(scene_->getCurrentObject(),
                                                     wInTurn,
                                                   oManager_,
                                                    handler_,
       static_cast<BuildingType>(ui->comboBox->currentData().toInt()));
      adjustResources();
      maxMovesReached();
    }
}

void GameWindow::addWorker()
{
    if (currentWorkerIndex != NONVALUE) {
    oManager_->addWorker(scene_->getCurrentObject(),
                         wInTurn,
                         currentWorkerIndex);
    }
}


void GameWindow::endTurn()
{
    handler_->endTurn();
    wInTurn = handler_->currentPlayer();
    handler_->maxMoves = 0;
    ui->buttonBuild->setEnabled(true);
    ui->buttonTrain->setEnabled(true);
    adjustGameWiew();

    if (handler_->gameEnd(oManager_)) {
       std::string winner = handler_->determineWinner();
       QMessageBox::information(this, tr("Game over !"),tr("The winner is : ")+
                                tr(winner.c_str()));
       close();
    }

}

void GameWindow::trainDialog()
{
    TrainDialog td;
    connect(&td, &TrainDialog::sendData,this,&GameWindow::getTrainingData);
    td.exec();
}

void GameWindow::getTrainingData(WorkerType& type)
{
    if( currentWorkerIndex != NONVALUE) {
    oManager_->trainWorker(wInTurn,oManager_,handler_,type,currentWorkerIndex);
    adjustResources();
    adjustRightWorkers();
    maxMovesReached();
    }
}


void GameWindow::adjustBuildingCosts()
{
    Course::ResourceMap CurrentMap = {};
    BuildingType buildT = static_cast<BuildingType>(ui->comboBox->currentData().toInt());
    if(buildT == COTTAGE){
        CurrentMap = Game::ConstResourceMap::COTTAGE_BUILD_COST;
    }
    else if(buildT == FISHINGHUT){
        CurrentMap = Game::ConstResourceMap::FISHINGHUT_BUILD_COST;
    }
    else if(buildT == MINE){
        CurrentMap = Game::ConstResourceMap::MINE_BUILD_COST;
    }
    ui->labelMoneyCost->setText(QString::number(-1*CurrentMap[Course::MONEY]));
    ui->labelFoodCost->setText(QString::number(-1*CurrentMap[Course::FOOD]));
    ui->labelWoodCost->setText(QString::number(-1*CurrentMap[Course::WOOD]));
    ui->labelStoneCost->setText(QString::number(-1*CurrentMap[Course::STONE]));
    ui->labelOreCost->setText(QString::number(-1*CurrentMap[Course::ORE]));

}

void GameWindow::adjustRightWorkers()
{

    for (unsigned int i = 1; i < 6; ++i) {

        if (wInTurn->workers[i]->getType() == "Miner") {

            if (i == 1) ui->buttonWorker1->setIcon(QIcon(":/images/miner.jpg"));
            else if (i == 2) ui->buttonWorker2->setIcon(QIcon(":/images/miner.jpg"));
            else if (i == 3) ui->buttonWorker3->setIcon(QIcon(":/images/miner.jpg"));
            else if (i == 4) ui->buttonWorker4->setIcon(QIcon(":/images/miner.jpg"));
            else if (i == 5) ui->buttonWorker5->setIcon(QIcon(":/images/miner.jpg"));

        }
        else if (wInTurn->workers[i]->getType() == "Fisher") {
            if (i == 1) ui->buttonWorker1->setIcon(QIcon(":/images/fisher.jpg"));
            else if (i == 2) ui->buttonWorker2->setIcon(QIcon(":/images/fisher.jpg"));
            else if (i == 3) ui->buttonWorker3->setIcon(QIcon(":/images/fisher.jpg"));
            else if (i == 4) ui->buttonWorker4->setIcon(QIcon(":/images/fisher.jpg"));
            else if (i == 5) ui->buttonWorker5->setIcon(QIcon(":/images/fisher.jpg"));
        }
        else if (wInTurn->workers[i]->getType() == "Timberjack") {
            if (i == 1) ui->buttonWorker1->setIcon(QIcon(":/images/timberJack.jpg"));
            else if (i == 2) ui->buttonWorker2->setIcon(QIcon(":/images/timberJack.jpg"));
            else if (i == 3) ui->buttonWorker3->setIcon(QIcon(":/images/timberJack.jpg"));
            else if (i == 4) ui->buttonWorker4->setIcon(QIcon(":/images/timberJack.jpg"));
            else if (i == 5) ui->buttonWorker5->setIcon(QIcon(":/images/timberJack.jpg"));
        }
        else {

            if (i == 1) ui->buttonWorker1->setIcon(QIcon(":/images/basicWorker.jpg"));
            else if (i == 2) ui->buttonWorker2->setIcon(QIcon(":/images/basicWorker.jpg"));
            else if (i == 3) ui->buttonWorker3->setIcon(QIcon(":/images/basicWorker.jpg"));
            else if (i == 4) ui->buttonWorker4->setIcon(QIcon(":/images/basicWorker.jpg"));
            else if (i == 5) ui->buttonWorker5->setIcon(QIcon(":/images/basicWorker.jpg"));

        }
    }

}

void GameWindow::setHeadQuarter()
{

    changeEnablers(false);
    if(scene_->getCurrentObject() != nullptr){
        oManager_->createHQ(scene_->getCurrentObject(),
                                             wInTurn,
                                           oManager_,
                                            handler_);
       if (wInTurn->getBuildingCount() > 0) {

            if(wInTurn->next == nullptr){ // true if all players have HQ
                changeEnablers(true);
                adjustBuildingCosts();
            }
                handler_->endTurn();
                wInTurn = handler_->currentPlayer();
                adjustGameWiew();
         }
    }
}

void GameWindow::changeEnablers(bool b)
{
    ui->comboBox->setEnabled(b);
    ui->buttonEndTurn->setEnabled(b);
    ui->buttonTrain->setEnabled(b);
    ui->buttonAssign->setEnabled(b);
}

void GameWindow::setImages()
{

    ui->buttonWorker1->setIcon(QIcon(":/images/basicWorker.jpg"));
    ui->buttonWorker2->setIcon(QIcon(":/images/basicWorker.jpg"));
    ui->buttonWorker3->setIcon(QIcon(":/images/basicWorker.jpg"));
    ui->buttonWorker4->setIcon(QIcon(":/images/basicWorker.jpg"));
    ui->buttonWorker5->setIcon(QIcon(":/images/basicWorker.jpg"));
    ui->buttonWorker1->setFlat(true);
    ui->buttonWorker2->setFlat(true);
    ui->buttonWorker3->setFlat(true);
    ui->buttonWorker4->setFlat(true);
    ui->buttonWorker5->setFlat(true);

}

void GameWindow::maxMovesReached()
{
    if (handler_->maxMoves == 3) {
        ui->buttonBuild->setEnabled(false);
        ui->buttonTrain->setEnabled(false);
    }

}

