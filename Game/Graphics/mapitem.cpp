#include "mapitem.hh"


namespace Game {

std::map<std::string, QColor> MapItem::c_mapcolors = {};

MapItem::MapItem(const std::shared_ptr<Course::GameObject> &obj, int size):
    m_gameobject(obj), m_scenelocation(m_gameobject->getCoordinatePtr()->asQpoint()), m_size(size)
{

    addNewColor(m_gameobject->getType());
}

QRectF MapItem::boundingRect() const
{
     return QRectF(m_scenelocation * m_size, m_scenelocation * m_size + QPoint(m_size, m_size));
}

void MapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option); Q_UNUSED( widget );
    painter->setBrush(QBrush(c_mapcolors.at(m_gameobject->getType())));

    QPen whitePen(Qt::white,2);
    painter->setPen(whitePen);

    painter->drawRect(boundingRect());

}

QPointF MapItem::getPoint()
{
    return QPointF(m_gameobject->getCoordinatePtr()->x() * m_size, m_gameobject->getCoordinatePtr()->y() * m_size);
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}


void MapItem::addNewColor(std::string type)
{
    if ( c_mapcolors.find(type) == c_mapcolors.end() ){
        c_mapcolors["Forest"] = QColor(0x56cd4c);
        c_mapcolors["Sand"] = QColor(0xf3e33c);
        c_mapcolors["Rock"] = QColor(0x8d9092);
        c_mapcolors["Water"] = QColor(0x59b4f1);
    }
}

}
