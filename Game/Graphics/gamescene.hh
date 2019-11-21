#ifndef GAMESCENE_HH
#define GAMESCENE_HH

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include <map>
#include <memory>

#include "core/gameobject.h"

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

    void RemoveItem( std::shared_ptr<Course::GameObject> obj);

    void UpdateItem( std::shared_ptr<Course::GameObject> obj);

    virtual bool event(QEvent* event) override;

private:
    QGraphicsItem* m_mapBoundRect;
    int  m_width;
    int m_height;
    int m_scale;
};

} // namespace Game

#endif // GAMESCENE_HH
