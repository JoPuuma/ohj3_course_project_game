#include "gamescene.hh"
#include "mapitem.hh"

#include "QEvent"
#include "QGraphicsSceneMouseEvent"

#include "math.h"

namespace Game {


GameScene::GameScene(QWidget* parent,
                     int width,
                     int height,
                     int scale):
    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(7),
    m_height(7),
    m_scale(78)
{



}

void GameScene::DrawItem(std::shared_ptr<Course::GameObject> obj)
{
    //SimpleMapItem* nItem = new SimpleMapItem(obj, m_scale);
    //addItem(nItem);
}




} // namespace Game
