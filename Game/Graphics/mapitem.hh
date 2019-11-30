#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "Core/objectmanager.hh"
#include "core/gameobject.h"
namespace Game{


class MapItem: public QGraphicsItem
{
public:
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    QRectF boundingRect() const override;

    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

     QPointF getPoint() ;
     const std::shared_ptr<Course::GameObject> &getBoundObject();

      void updateLoc();

      bool isSameObj(std::shared_ptr<Course::GameObject> obj);

      int getSize() const;

      void setSize(int size);

      void setPen(QColor color);

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    static void addNewColor(std::string type);
    bool currentActivated = false;
    QPainter* painter_;
};

}
#endif // MAPITEM_HH
