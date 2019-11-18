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
    // add names from ui to the vector
    players.push_back(ui->player1Name->text().toStdString());
    players.push_back(ui->player2Name->text().toStdString());
    players.push_back(ui->player3Name->text().toStdString());
    players.push_back(ui->player4Name->text().toStdString());

    int index = 0;
    for(std::string& player:players){
        player.erase(       // remove whitespace
          std::remove_if(player.begin(), player.end(), ::isspace),player.end());

        if(player == ""){   // remove empty names
            players.erase(players.begin() + index);
        }
        index += 1;
    }

    if(players.size() >= 2){
        emit Dialog::sendData(players,
                              ui->checkBoxUsesMax->isChecked(),
                              ui->spinBoxRounds->value());
        Dialog::done(1);
    }
    else{
        players.clear();
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
