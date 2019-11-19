#include "gamewindow.hh"
#include "ui_gamewindow.h"
#include "startdialog.hh"

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);

    //start dialog
    Dialog d;
    d.exec();

}

GameWindow::~GameWindow()
{
    delete ui;
}
