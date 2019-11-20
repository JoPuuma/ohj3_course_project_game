#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"

#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow){

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

}
