#ifndef TRAINDIALOG_HH
#define TRAINDIALOG_HH

#include <QDialog>

namespace Ui {
class TrainDialog;
}

class TrainDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrainDialog(QWidget *parent = 0);
    ~TrainDialog();

private slots:
    void setMiner();
    void setTimberJack();
    void setFisher();

private:
    Ui::TrainDialog *ui;

};

#endif // TRAINDIALOG_HH
