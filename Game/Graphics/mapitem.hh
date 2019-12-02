#ifndef MAPITEM_HH
#define MAPITEM_HH

#include <QGraphicsItem>
#include <QPainter>

#include <memory>
#include <map>

#include "Core/objectmanager.hh"
#include "core/gameobject.h"
namespace Game{

/**
 * @brief The MapItem class is a custom QGraphicsItem that
 * acts as a single GameObject's graphical element.
 */
class MapItem: public QGraphicsItem
{
public:
    /**
     * @brief Constructor
     * @param obj shared_ptr to the obj.
     * @param size of the created item in pixels.
     * @pre obj must have a valid Coordinate.
     */
    MapItem(const std::shared_ptr<Course::GameObject> &obj, int size);

    /**
     * @brief boundingRect
     * @return the bounding rectangle of this item.
     */
    QRectF boundingRect() const override;

    /**
     * @brief paints the item
     * @param painter
     * @param option
     * @param widget
     * @note The GraphicsView containing the scene this belongs to
     * usually calls this function.
     */
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
    /**
     * @brief getPoint
     * @return objects QpointF location on gamescene.
     */
    QPointF getPoint() ;

     /**
      * @brief getBoundObject
      * @return the object this item is bound to.
      */
     const std::shared_ptr<Course::GameObject> &getBoundObject();

private:
    const std::shared_ptr<Course::GameObject> m_gameobject;
    QPoint m_scenelocation;
    int m_size;

    static std::map<std::string, QColor> c_mapcolors;
    /**
     * @brief addNewColor , each tile type has different color.
     * @param type objects type.
     */
    static void addNewColor(std::string type);

};

}
#endif // MAPITEM_HH
