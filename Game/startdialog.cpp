#include "startdialog.hh"
#include "ui_startdialog.h"
#include "mapwindow.hh"
#include <algorithm>
#include <cctype>
// poista
#include <iostream>
// tämä

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog){

    ui->setupUi(this);
    ui->spinBoxRounds->hide(); // spinbox is not displayed by default

    connect(ui->pushButtonCancel, &QPushButton::clicked,
            this, &Dialog::reject);
    connect(ui->checkBoxUsesMax, &QCheckBox::clicked,
            this, &Dialog::checkBoxValueChanged);
    connect(ui->pushButtonOK, &QPushButton::clicked,
            this, &Dialog::checkValues);
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::checkValues(){
    // add names from ui to vector
    players.push_back(ui->player1Name->text().toStdString());
    players.push_back(ui->player2Name->text().toStdString());
    players.push_back(ui->player3Name->text().toStdString());
    players.push_back(ui->player4Name->text().toStdString());

    for(int i = 0; i <= 4; i++){
   //     std::string s = players.at(i);
  //      s.erase(std::remove_if(s.begin(), s.end(), ::isspace),s.end());
        if(players[i] == ""){
            players.erase(players.begin() + i);
        }
    }

    //std::vector<std::string>::size_type two = 2;
    if(players.size() >= 2){
     //   emit Dialog::sendData(players,ui->spinBoxRounds->value());

    }
    else{
        players.clear();
        std::cout<<"ali"<<std::endl;
    }

}

void Dialog::checkBoxValueChanged(){
    if(ui->checkBoxUsesMax->isChecked()){
        ui->spinBoxRounds->show();
    }
    else{
        ui->spinBoxRounds->hide();
    }
}
