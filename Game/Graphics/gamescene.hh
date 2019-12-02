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

/**
 * @brief The GameScene is a custom QGraphicsScene that shows
 * a rendering of the game map.
 */
class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:

    /**
     * @brief Constructor for the class.
     * @param qt_parent points to the parent object per Qt's parent-child-system.
     */
    GameScene(QWidget* qt_parent = nullptr);

    /**
     * @brief Default destructor.
     */
    ~GameScene() = default;

    /**
     * @brief resize recalculates the bounding rectangle
     */
    void resize();

    /**
     * @brief Draws the tiles to the map.
     * @param obj shared ptr to the object.
     */
    void DrawItem( std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief Updates worker's image on map.
     * @param obj shared ptr to the object.
     * @param oldID worker's old ID before training.
     */
    void UpdateItem( std::shared_ptr<Course::GameObject> obj, unsigned int oldID);

    /**
     * @brief draw a building to the map.
     * @param obj shared ptr to the object.
     */
    void drawBuilding(std::shared_ptr<Course::GameObject> obj);

    /**
     * @brief draw a worker to the map.
     * @param obj shared ptr to the object.
     * @param workerNumber specifies the location on map.
     */
    void drawWorker(std::shared_ptr<Course::GameObject> obj, unsigned int workerNumber);

    /**
     * @brief marks the tile to player.
     * @param obj shared ptr to the object.
     * @param color (each player has different color).
     */
    void addPen(std::shared_ptr<Course::GameObject> obj, int color);

    /**
     * @brief getCurrentObject
     * @return selected tile.
     */
    std::shared_ptr<Course::TileBase>  getCurrentObject();

    /**
     * @brief event handler that notifies when objects or the play
     * area is clicked.
     * @param event that has happened.
     * @return True: if event was  handled in the handler.
     * False: if the event handling was passed over.
     */
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
