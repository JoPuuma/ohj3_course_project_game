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
    handler_(handler){

    auto uusi = std::make_shared<Course::PlayerBase>("uusi");
    Omanager_ = std::make_shared<Game::ObjectManager>();

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

}

GameWindow::~GameWindow(){
    delete ui;
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
