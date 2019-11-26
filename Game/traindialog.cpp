#include "traindialog.hh"
#include "ui_traindialog.h"

TrainDialog::TrainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainDialog)
{
    ui->setupUi(this);

//    connect(ui->buttonBox->Ok, &QDialogButtonBox::clicked,
//            this, &TrainDialog::sendData);
//    connect(ui->buttonBox->Cancel, &QDialogButtonBox::clicked,
//            this, &TrainDialog::reject);
//    connect(ui->buttonMiner, &QPushButton::clicked,
//            this, &TrainDialog::setMiner);
//    connect(ui->buttonTimberJack, &QPushButton::clicked,
//            this, &TrainDialog::setTimberJack);
//    connect(ui->buttonMiner, &QPushButton::clicked,
//            this, &TrainDialog::setMiner);
}

TrainDialog::~TrainDialog()
{
    delete ui;
}

void TrainDialog::setMiner()
{

}

void TrainDialog::setTimberJack()
{

}

void TrainDialog::setFisher()
{

}
