//#include "mapwindow.hh"
#include "gamewindow.hh"
#include "Core/gameeventhandler.hh"

#include<memory>

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);


    GameWindow gameWindow;
    gameWindow.show();

    return app.exec();

}
