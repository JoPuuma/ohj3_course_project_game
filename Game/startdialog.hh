#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include <QGraphicsScene>
#include <QDebug>
#include "ui_mapwindow.h"

#include "interfaces/igameeventhandler.h"
#include "graphics/simplegamescene.h"



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:

    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:

    Ui::Dialog *ui;
};

#endif // STARTDIALOG_HH
