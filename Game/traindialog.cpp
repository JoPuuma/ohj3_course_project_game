#include "traindialog.hh"
#include "ui_traindialog.h"

TrainDialog::TrainDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainDialog)
{
    ui->setupUi(this);
}

TrainDialog::~TrainDialog()
{
    delete ui;
}
