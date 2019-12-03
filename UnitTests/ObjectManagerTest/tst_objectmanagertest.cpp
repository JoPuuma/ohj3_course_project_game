#include <QString>
#include <QtTest>
#include "core/basicresources.h"
#include "Core/gameeventhandler.hh"
#include "interfaces/igameeventhandler.h"
#include "Core/player.hh"
#include "Workers/basicworker.hh"
#include "Tiles/rock.hh"
#include "Tiles/water.hh"
#include "core/coordinate.h"
#include "objecttypes.hh"
#include "Core/resourcemaps.hh"



Q_DECLARE_METATYPE(std::shared_ptr<Course::PlayerBase>)
Q_DECLARE_METATYPE(std::shared_ptr<Game::GameEventHandler>)
Q_DECLARE_METATYPE(std::shared_ptr<Game::ObjectManager>)
Q_DECLARE_METATYPE(std::shared_ptr<Course::TileBase>)



class ObjectManagerTest : public QObject
{
    Q_OBJECT

public:
    const Course::ResourceMap resource = {
        {Course::BasicResource::NONE, 0},
        {Course::BasicResource::MONEY, -50},
        {Course::BasicResource::FOOD, -570},
        {Course::BasicResource::WOOD, 97},
        {Course::BasicResource::STONE, 50},
        {Course::BasicResource::ORE, 0}
    };
    ObjectManagerTest();
    std::shared_ptr<Game::GameEventHandler> handler =
            std::make_shared<Game::GameEventHandler>();
    std::shared_ptr<Game::ObjectManager> manager =
            std::make_shared<Game::ObjectManager>(nullptr);

private Q_SLOTS:
    void testCanBuild();
    void testCanBuild_data();
    void testTrainWorker();
};

ObjectManagerTest::ObjectManagerTest()
{
}

void ObjectManagerTest::testCanBuild()
{
    QFETCH(int,x);
    QFETCH(int,y);
    Course::Coordinate c = Course::Coordinate(x,y);
//    std::shared_ptr<Game::Rock> tile =
//           std::make_shared<Game::Rock>(c,handler,manager);
    // ei saatu toimimaan jostain syystä
}

void ObjectManagerTest::testCanBuild_data()
{
    QTest::addColumn<int>("x");
    QTest::addColumn<int>("y");

    QTest::newRow("first")<<1<<2;

}

void ObjectManagerTest::testTrainWorker()
{
    std::shared_ptr<Game::Player> p = std::make_shared<Game::Player>("pate", 0xffffff);
    std::string str = "Miner";
    std::shared_ptr<Game::Miner> miner =
            std::make_shared<Game::Miner>(handler,manager,p);
    p->workers[1] = miner;
    manager->trainWorker(p,manager,handler,WorkerType::FISHER,1); // miner to fisher
    QCOMPARE(p->workers[1]->getType(),str); // nothing should happen

    handler->modifyResources(p,resource);
    str = "basicWorker";
    std::shared_ptr<Game::basicWorker> worker =
            std::make_shared<Game::basicWorker>(handler,manager,p);
    p->workers[2] = worker;
    manager->trainWorker(p,manager,handler,WorkerType::MINER,2); // basic worker to miner
    QCOMPARE(p->workers[2]->getType(),str); // not enough resources

}



QTEST_APPLESS_MAIN(ObjectManagerTest)

#include "tst_objectmanagertest.moc"
