//#include "mapwindow.hh"
#include "gamewindow.hh"

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);



    //MapWindow mapWindow;
    //mapWindow.show();
    GameWindow gameWindow;
    gameWindow.show();

    return app.exec();

}
