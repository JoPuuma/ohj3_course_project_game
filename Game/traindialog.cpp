#include "traindialog.hh"
#include "ui_traindialog.h"

TrainDialog::TrainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainDialog),
    worker(WorkerType::NONE)
{
    ui->setupUi(this);

    connect(ui->buttonOk, &QPushButton::clicked,
            this, &TrainDialog::OkPressed);
    connect(ui->buttonCancel, &QPushButton::clicked,
            this, &TrainDialog::reject);

    connect(ui->buttonMiner, &QPushButton::clicked,
            this, &TrainDialog::setMiner);
    connect(ui->buttonTimberJack, &QPushButton::clicked,
            this, &TrainDialog::setTimberJack);
    connect(ui->buttonFisher, &QPushButton::clicked,
            this, &TrainDialog::setFisher);

    ui->buttonCancel->setStyleSheet("background-color: red");
    ui->buttonOk->setStyleSheet("background-color: green");
}

TrainDialog::~TrainDialog()
{
    delete ui;
}

void TrainDialog::setMiner()
{
    ui->buttonMiner->setFlat(false);
    ui->buttonTimberJack->setFlat(true);
    ui->buttonFisher->setFlat(true);
    worker = WorkerType::MINER;
}

void TrainDialog::setTimberJack()
{
    ui->buttonMiner->setFlat(true);
    ui->buttonTimberJack->setFlat(false);
    ui->buttonFisher->setFlat(true);
    worker = WorkerType::TIMBERJACK;
}

void TrainDialog::setFisher()
{
    ui->buttonMiner->setFlat(true);
    ui->buttonTimberJack->setFlat(true);
    ui->buttonFisher->setFlat(false);
    worker = WorkerType::FISHER;
}

void TrainDialog::OkPressed()
{
    if(worker != WorkerType::NONE){
        emit sendData(worker);
        TrainDialog::done(true);
    }

}
