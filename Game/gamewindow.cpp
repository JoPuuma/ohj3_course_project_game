#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "Core/gameeventhandler.hh"
#include "Core/objectmanager.hh"
#include "Core/player.hh"

#include "core/playerbase.h"

#include <QDebug>



GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler),
    scene_(new Game::GameScene(this))
{

    auto uusi = std::make_shared<Course::PlayerBase>("uusi");
    Omanager_ = std::make_shared<Game::ObjectManager>() ;

    std::shared_ptr<Game::GameEventHandler> GEHandler;
    handler_ = std::make_shared<Game::GameEventHandler> ();

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

void GameWindow::receiveData(std::vector<std::string> players,
                             bool roundLimit,
                             int rounds){
    for(auto &player:players){
        std::shared_ptr<Game::Player> ptr(new Game::Player(player));
        playerObjs.push_back(ptr);
    }
}


void GameWindow::endTurn()
{

}
