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
    MapItem(const std::shared_ptr<Course::GameObject> &obj);
};

}
#endif // MAPITEM_HH
