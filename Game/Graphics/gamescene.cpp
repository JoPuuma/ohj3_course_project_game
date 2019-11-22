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
    QRect rect = QRect( m_width * m_scale / - 2, m_height * m_scale / -2,
                        m_width * m_scale - 1, m_height * m_scale - 1 );

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
                qDebug() << "Opressed.";
                return true;
            }

        }
    }

    return false;
}

} // namespace Game
