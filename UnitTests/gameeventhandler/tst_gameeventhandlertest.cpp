#include <QString>
#include <QtTest>
#include "core/basicresources.h"
#include "Core/gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "Core/player.hh"
#include "Workers/basicworker.hh"
#include "gamewindow.hh"


Q_DECLARE_METATYPE(std::shared_ptr<Course::PlayerBase>)
Q_DECLARE_METATYPE(std::shared_ptr<Game::GameEventHandler>)
Q_DECLARE_METATYPE(std::shared_ptr<Game::ObjectManager>)
Q_DECLARE_METATYPE(std::shared_ptr<Game::GameScene>)
Q_DECLARE_METATYPE(std::vector<std::string>)


class GameeventhandlerTest : public QObject
{
    Q_OBJECT


public:

    GameeventhandlerTest();
    std::shared_ptr<Game::ObjectManager> createManager();

private Q_SLOTS:

    void testModifyResources();
    void testGameInitializing();
    void testGameInitializing_data();


};

GameeventhandlerTest::GameeventhandlerTest()
{
}

std::shared_ptr<Game::ObjectManager> GameeventhandlerTest::createManager()
{
    std::shared_ptr<Game::ObjectManager> manager =
            std::make_shared<Game::ObjectManager>(nullptr);
    return manager;
}

void GameeventhandlerTest::testModifyResources()
{
    const Course::ResourceMap resource1 = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, 10},
        {Course::BasicResource::FOOD, 60},
        {Course::BasicResource::WOOD, 97},
        {Course::BasicResource::STONE, 50},
        {Course::BasicResource::ORE, 10}
    };
    const Course::ResourceMap resource2 = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, 10},
        {Course::BasicResource::FOOD, -60},
        {Course::BasicResource::WOOD, 97},
        {Course::BasicResource::STONE, 50},
        {Course::BasicResource::ORE, -115}
    };
    Game::GameEventHandler handler;
    std::shared_ptr<Game::Player> p =
            std::make_shared<Game::Player>("Pate",0xffffff);

    QCOMPARE(handler.modifyResources(p,resource1),true);
    QCOMPARE(handler.modifyResources(p,resource2),false);

}

void GameeventhandlerTest::testGameInitializing()
{
    QFETCH(std::shared_ptr<Game::GameEventHandler>, handler);
    QFETCH(std::shared_ptr<Game::ObjectManager>, manager);
    QFETCH(std::vector<std::string>, names);

    const Course::ResourceMap resource1 = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, 10},
        {Course::BasicResource::FOOD, 60},
        {Course::BasicResource::WOOD, 97},
        {Course::BasicResource::STONE, 50},
        {Course::BasicResource::ORE, 10}
    };

    handler->initializeGame(names,handler,manager);
    QCOMPARE(handler->currentPlayer()->getName(),names[0]) ;
    handler->endTurn();
    QCOMPARE(handler->currentPlayer()->getName(),names[1]) ;

    handler->modifyResources(handler->currentPlayer(),resource1);
    QCOMPARE(handler->determineWinner(),names[1]);

    QCOMPARE(handler->gameEnd(manager),false);
    QCOMPARE(handler->currentPlayer()->workers.size(),std::size_t(5));
}

void GameeventhandlerTest::testGameInitializing_data()
{
    QTest::addColumn<std::shared_ptr<Game::GameEventHandler>>("handler");
    QTest::addColumn<std::shared_ptr<Game::ObjectManager>>("manager");
    QTest::addColumn<std::vector<std::string>>("names");
    //QTest::addColumn<int>("playerCount");


    std::shared_ptr<Game::GameEventHandler> handler1 =
            std::make_shared<Game::GameEventHandler>();
    std::shared_ptr<Game::GameEventHandler> handler2 =
            std::make_shared<Game::GameEventHandler>();
    std::vector<std::string> players1 = {"eka","toka","kolmas"};
    std::vector<std::string> players2 = {"eka","toka","kolmas","neljäs"};

    QTest::newRow("firstCase")<<handler1<<createManager()<<players1;
    QTest::newRow("secondCase")<<handler2<<createManager()<<players2;

}



QTEST_APPLESS_MAIN(GameeventhandlerTest)

#include "tst_gameeventhandlertest.moc"
