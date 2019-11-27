#ifndef GAMESCENE_HH
#define GAMESCENE_HH

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <map>
#include <memory>
#include <vector>

#include "core/gameobject.h"
#include "tiles/tilebase.h"

namespace Game {


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

    void DrawItem( std::shared_ptr<Course::GameObject> obj);
    void drawRect(QRect rect);
    void RemoveItem( std::shared_ptr<Course::GameObject> obj);
    void UpdateItem( std::shared_ptr<Course::GameObject> obj);

    std::shared_ptr<Course::TileBase>  getCurrentObject();

    virtual bool event(QEvent* event) override;
    std::shared_ptr<Course::GameObject> currentObject = nullptr;

private:
    QGraphicsItem* m_mapBoundRect;
    int  m_width;
    int m_height;
    int m_scale;

};

} // namespace Game

#endif // GAMESCENE_HH
