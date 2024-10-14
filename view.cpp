#include <QDebug>
#include <QKeyEvent>
#include <QScrollBar>
#include "view.h"

viewExample::viewExample()
{
  setRenderHint(QPainter::Antialiasing);

  setCacheMode(QGraphicsView::CacheNone);

  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setWindowTitle("scene");
  setFrameStyle(0);
  setSceneRect(0, 0, 800, 600);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(800, 600);

  QPixmap bgPixmap(":/pics/mario.png");
  QPixmap scaledPixmap = bgPixmap.scaled(800, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

  QGraphicsPixmapItem* backgroundItem = new QGraphicsPixmapItem(scaledPixmap);
  backgroundItem->setZValue(-1);  // Фон находится позади всех элементов
  mScene.addItem(backgroundItem);

  mScene.setItemIndexMethod(QGraphicsScene::NoIndex);


  setScene(&mScene);
  _init_view_elements();
}
//------------------------------------------------------------------------------
void viewExample::_init_view_elements()
{

  mZombieAttack.setPos(100,  100);
  mZombieMoving.setPos(150,  100);
  mZombieNothing.setPos(200, 100);
  mZombie.setPos(300,425);

  mScene.addItem(&mZombieAttack);
  mScene.addItem(&mZombieMoving);
  mScene.addItem(&mZombieNothing);
  mScene.addItem(&mZombie);
}

//------------------------------------------------------------------------------
void viewExample::keyReleaseEvent(QKeyEvent *apEvent)
{
  switch(apEvent->key())
  {
    case Qt::Key_A:
    {
      mZombie.set_left_direction();
      mZombie.move();
      break;
    }
    case Qt::Key_D:
    {
      mZombie.set_right_direction();
      mZombie.move();
      break;
    }
    case Qt::Key_Enter:
    case Qt::Key_Return:
    {
      mZombie.attack();
      break;
    }
    case Qt::Key_Space:
    {
      mZombie.stop();
      break;
    }
  }
}
