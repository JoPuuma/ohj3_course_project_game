#ifndef GAMESCENE_HH
#define GAMESCENE_HH

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QPainter>

#include <map>
#include <memory>
#include <vector>

#include "core/gameobject.h"
#include "tiles/tilebase.h"

namespace Game {

class MapItem;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QWidget* qt_parent = nullptr);


    ~GameScene() = default;


    void resize();   

    void DrawItem( std::shared_ptr<Course::GameObject> obj);
    void UpdateItem( std::shared_ptr<Course::GameObject> obj, unsigned int oldID);
    void drawBuilding(std::shared_ptr<Course::GameObject> obj);
    void drawWorker(std::shared_ptr<Course::GameObject> obj, unsigned int workerNumber);
    void addPen(std::shared_ptr<Course::GameObject> obj, int color);

    std::shared_ptr<Course::TileBase>  getCurrentObject();

    virtual bool event(QEvent* event) override;

    std::shared_ptr<Course::GameObject> currentObject = nullptr;

private:
    QGraphicsItem* m_mapBoundRect;
    int  m_width;
    int m_height;
    int m_scale;
    std::map<unsigned int, MapItem*> mapItems;
    std::map<unsigned int, QGraphicsPixmapItem*> workers;
    QGraphicsItem* rectPtr;

};

} // namespace Game

#endif // GAMESCENE_HH
