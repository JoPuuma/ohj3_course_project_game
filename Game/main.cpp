//#include "mapwindow.hh"
#include "gamewindow.hh"
#include "Core/gameeventhandler.hh"

#include<memory>

#include <QApplication>


int main(int argc, char* argv[])
{

    QApplication app(argc, argv);

    //std::shared_ptr<Game::GameEventHandler> GEHandler(new Game::GameEventHandler());
    //GameWindow gameWindow(0, GEHandler);
    GameWindow gameWindow;
    gameWindow.show();

    return app.exec();

}
