#include "gamescene.hh"
#include "mapitem.hh"

#include "QEvent"
#include "QGraphicsSceneMouseEvent"

#include "math.h"
#include "map"

namespace Game {


GameScene::GameScene(QWidget* parent):
    QGraphicsScene(parent),
    m_mapBoundRect(nullptr),
    m_width(7),
    m_height(7),
    m_scale(77)
{
    resize();
    QRect rect = QRect( 0, 0, m_scale, m_scale);
    rectPtr = addRect(rect, QPen(Qt::red,2));
    rectPtr->setZValue(10);

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
    nItem->setZValue(-1);
    addItem(nItem);
    mapItems[obj->ID] = nItem;
}


void GameScene::UpdateItem(std::shared_ptr<Course::GameObject> obj, unsigned int oldID)
{
    std::map<unsigned int, QGraphicsPixmapItem*>::iterator ID = workers.find(oldID);

    // update image to worker if it is already putted to the gamescene.
    if (ID != workers.end()) {

      QGraphicsPixmapItem* value = ID->second;
      workers.erase(ID);
      workers[obj->ID] = value;

      if (obj->getType() == "Miner") {

          workers[obj->ID]->setPixmap( QPixmap(":/images/miner.jpg") );
          workers[obj->ID]->setScale(0.01);
          workers[obj->ID]->setZValue(10);

     }

      else  if (obj->getType() == "Fisher") {
          workers[obj->ID]->setPixmap( QPixmap(":/images/fisher.jpg") );
          workers[obj->ID]->setScale(0.07);
          workers[obj->ID]->setZValue(10);

      }

      else  if (obj->getType() == "Timberjack") {
          workers[obj->ID]->setPixmap( QPixmap(":/images/timberJack.jpg") );
          workers[obj->ID]->setScale(0.07);
          workers[obj->ID]->setZValue(10);

      }

    }

}

void GameScene::drawBuilding(std::shared_ptr<Course::GameObject> obj)
{
    if (obj->getType() == "Cottage") {
        QGraphicsPixmapItem *pm = addPixmap( QPixmap(":/images/cottage.jpg") );
        pm->setPos(rectPtr->pos());
        pm->setScale(0.05);
        pm->setZValue(1);
    }

    else if (obj->getType() == "Fishinghut") {
        QGraphicsPixmapItem *pm = addPixmap( QPixmap(":/images/fishingHut.jpg") );
        pm->setPos(rectPtr->pos());
        pm->setScale(0.08);
        pm->setZValue(1);
    }

    else if (obj->getType() == "Mine") {
        QGraphicsPixmapItem *pm = addPixmap( QPixmap(":/images/mine.jpg") );
        pm->setPos(rectPtr->pos());
        pm->setScale(0.08);
        pm->setZValue(1);
    }
    else if(obj->getType() == "HeadQuarters"){
        QGraphicsPixmapItem *pm = addPixmap( QPixmap(":/images/HQ.jpg") );
        pm->setPos(rectPtr->pos());
        pm->setScale(0.35);
        pm->setZValue(1);
    }

}

void GameScene::drawWorker(std::shared_ptr<Course::GameObject> obj, unsigned int workerNumber)
{
    std::map<unsigned int, QGraphicsPixmapItem*>::iterator id;
    id = workers.find(obj->ID);

    // if the workers is added first time to the gamescene.
    if (id == workers.end()) {

        if (obj->getType() == "basicWorker") {
            workers[obj->ID] = addPixmap( QPixmap(":/images/basicWorker.jpg") );
            workers[obj->ID]->setScale(0.05);

        }

        else  if (obj->getType() == "Miner") {
            workers[obj->ID] = addPixmap( QPixmap(":/images/miner.jpg") );
            workers[obj->ID]->setScale(0.01);

        }

        else  if (obj->getType() == "Fisher") {
            workers[obj->ID] = addPixmap( QPixmap(":/images/fisher.jpg") );
            workers[obj->ID]->setScale(0.07);

        }

        else  if (obj->getType() == "Timberjack") {
            workers[obj->ID] = addPixmap( QPixmap(":/images/timberJack.jpg") );
            workers[obj->ID]->setScale(0.07);

        }

        workers[obj->ID]->setZValue(10);
    }
    // set worker to new position.
    workers[obj->ID]->setPos(rectPtr->pos().rx() + 50 ,
                             rectPtr->pos().y() + ((workerNumber -1) * 12));

}

void GameScene::addPen(std::shared_ptr<Course::GameObject> obj, int color)
{
    QPoint point = QPoint(obj->getCoordinate().x()*m_scale,obj->getCoordinate().y()*m_scale);
    QRect rect = QRect(point, QSize(m_scale, m_scale));
    addRect(rect, QPen(QColor(color),4));
}

std::shared_ptr<Course::TileBase> GameScene::getCurrentObject()
{
    return std::dynamic_pointer_cast<Course::TileBase>(currentObject);
}

bool GameScene::event(QEvent *event)
{
    if(event->type() == QEvent::GraphicsSceneMousePress)
    {
        rectPtr->setPos(QPoint(25*m_scale,25*m_scale));

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

                rectPtr->setPos(QPoint(point.rx()*m_scale,point.ry()*m_scale));

                for (const auto &item : mapItems) {

                    // find tile object from the point which is clicked.
                    if (item.second->getPoint() == rectPtr->pos()){
                        currentObject = static_cast<Game::MapItem*>(item.second)->getBoundObject();
                    }
                }

                return true;
            }

        }
    }

    return QGraphicsScene::event(event);

}



} // namespace Game
