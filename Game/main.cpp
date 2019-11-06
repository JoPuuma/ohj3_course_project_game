#include "mapwindow.hh"
#include "startdialog.hh"

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    MapWindow mapWindow;
    Dialog startdialog;
    startdialog.show();
    mapWindow.show();
    return app.exec();


}
