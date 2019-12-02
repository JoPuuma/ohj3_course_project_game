#include <QString>
#include <QtTest>
#include "core/basicresources.h"
#include "Core/gameeventhandler.hh"



class GameeventhandlerTest : public QObject
{
    Q_OBJECT

public:
    GameeventhandlerTest();

private Q_SLOTS:
    void testCase1();
    void testModifyResources();
};

GameeventhandlerTest::GameeventhandlerTest()
{
}

void GameeventhandlerTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void GameeventhandlerTest::testModifyResources()
{

}

QTEST_APPLESS_MAIN(GameeventhandlerTest)

#include "tst_gameeventhandlertest.moc"
