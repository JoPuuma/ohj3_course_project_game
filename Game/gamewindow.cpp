#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"
#include "Core/gameeventhandler.hh"


#include <QDebug>

GameWindow::GameWindow(QWidget *parent,
                       std::shared_ptr<Game::GameEventHandler> handler) :
    QMainWindow(parent),
    ui(new Ui::GameWindow),
    handler_(handler){

//    if(handler_ == nullptr){
//        std::shared_ptr<Game::GameEventHandler> GEHandler(new Game::GameEventHandler());
//        handler_ = GEHandler;
//    }
    ui->setupUi(this);

    //start dialog
    Dialog d;

    connect(&d, &Dialog::sendData,this, &GameWindow::receiveData);

    d.exec();

}

GameWindow::~GameWindow(){
    delete ui;
}

void GameWindow::receiveData(std::vector<std::string> players,
                             bool roundLimit,
                             int rounds){
    for(auto &player:players){
        //handler_->addPlayer(player);
    }
}
