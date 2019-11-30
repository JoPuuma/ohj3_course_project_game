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

class GameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GameScene(QWidget* qt_parent = nullptr,
              int width = 7,
              int height = 7,
              int scale = 78
            );


    ~GameScene() = default;

    void setSize(int width, int height);
    void setScale(int scale);
    void resize();   
    void drawRect(QRectF rect);


    void DrawItem( std::shared_ptr<Course::GameObject> obj);
    void RemoveItem( std::shared_ptr<Course::GameObject> obj);
    void UpdateItem( std::shared_ptr<Course::GameObject> obj);
    void drawBuilding(std::shared_ptr<Course::GameObject> obj);

    std::shared_ptr<Course::TileBase>  getCurrentObject();

    virtual bool event(QEvent* event) override;

    std::shared_ptr<Course::GameObject> currentObject = nullptr;

private:
    QPainter* painter_;
    QGraphicsItem* m_mapBoundRect;
    int  m_width;
    int m_height;
    int m_scale;
    std::map<unsigned int, MapItem*> mapItems;
    QGraphicsItem* rectPtr;

};

} // namespace Game

#endif // GAMESCENE_HH
