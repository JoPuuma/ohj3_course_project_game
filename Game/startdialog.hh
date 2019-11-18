#ifndef STARTDIALOG_HH
#define STARTDIALOG_HH

#include <QDialog>
#include <QGraphicsScene>
#include <QDebug>
//#include <vector>
//#include <string>
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


public slots:
    void checkValues();
    void checkBoxValueChanged();

signals:
    void sendData(std::vector<std::string> p, bool roundLimit, int rounds);

private:

    Ui::Dialog *ui;
    std::vector<std::string> players;
};

#endif // STARTDIALOG_HH
