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
    m_scale(77)
{
    resize();

}

void GameScene::setSize(int width, int height)
{
    m_width = width;

    m_height = height;


}

void GameScene::setScale(int scale)
{
    m_scale = scale;
}

void GameScene::resize()
{
    QRect rect = QRect( 0, 0, m_width * m_scale, m_height * m_scale);

    addRect(rect, QPen(Qt::black));
    setSceneRect(rect);

    m_mapBoundRect = itemAt(rect.topLeft(), QTransform());
    m_mapBoundRect->setZValue(-1);

}



void GameScene::DrawItem(std::shared_ptr<Course::GameObject> obj)
{

    MapItem* nItem = new MapItem(obj, m_scale);
    addItem(nItem);
}


void GameScene::RemoveItem(std::shared_ptr<Course::GameObject> obj)
{

}

void GameScene::UpdateItem(std::shared_ptr<Course::GameObject> obj)
{

}

std::shared_ptr<Course::GameObject> GameScene::getCurrentObject()
{
    return currentObject;
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        QGraphicsSceneMouseEvent* mouse_event =
                dynamic_cast<QGraphicsSceneMouseEvent*>(event);

        if ( sceneRect().contains(mouse_event->scenePos())){

            QPointF point = mouse_event->scenePos() / m_scale;

            point.rx() = floor(point.rx());
            point.ry() = floor(point.ry());

            QGraphicsItem* pressed = itemAt(point * m_scale, QTransform());

            if ( pressed == m_mapBoundRect ){
                qDebug() << "Click on map area.";
            }else{
                qDebug() << "ObjID: " <<
                            static_cast<Game::MapItem*>(pressed)
                            ->getBoundObject()->ID  << " pressed.";
                currentObject = static_cast<Game::MapItem*>(pressed)->getBoundObject();
                return true;
            }

        }
    }

//    return QGraphicsScene::event(event);
    return false;
}

} // namespace Game
