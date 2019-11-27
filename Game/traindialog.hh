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

signals:
    void sendData(const std::string& workerType);

private slots:
    void setMiner();
    void setTimberJack();
    void setFisher();
    void OkPressed();

private:
    Ui::TrainDialog *ui;
    std::string worker;

};

#endif // TRAINDIALOG_HH
