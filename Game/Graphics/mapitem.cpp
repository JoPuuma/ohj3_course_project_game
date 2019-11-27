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
    Q_UNUSED( option ); Q_UNUSED( widget );
    painter->setBrush(QBrush(c_mapcolors.at(m_gameobject->getType())));
    if ( m_gameobject->getType() == "" ){
        // Draw different types in different shapes
    }
    painter->drawRect(boundingRect());
}

const std::shared_ptr<Course::GameObject> &MapItem::getBoundObject()
{
    return m_gameobject;
}

void MapItem::updateLoc()
{
    if ( !m_gameobject ){
        delete this;
    } else {
        update(boundingRect()); // Test if necessary
        m_scenelocation = m_gameobject->getCoordinate().asQpoint();
    }
}

bool MapItem::isSameObj(std::shared_ptr<Course::GameObject> obj)
{
    return obj == m_gameobject;
}

int MapItem::getSize() const
{
    return m_size;
}

void MapItem::setSize(int size)
{
    if ( size > 0 && size <= 500 ){
        m_size = size;
    }
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
