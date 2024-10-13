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

  setWindowTitle("view");

  setFrameStyle(0);
  setSceneRect(0, 0, 800, 800);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(800, 800);

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
  mZombie.setPos(300,300);

  mScene.addItem(&mZombieAttack);
  mScene.addItem(&mZombieMoving);
  mScene.addItem(&mZombieNothing);
  mScene.addItem(&mZombie);
}
//------------------------------------------------------------------------------
void viewExample::btn_B_clicked(Qt::MouseButton aBtn)
{
  qWarning() << "B clicked " << aBtn;
}
//------------------------------------------------------------------------------
void viewExample::btn_C_clicked(Qt::MouseButton aBtn)
{
  qWarning() << "C clicked " << aBtn;
}
//------------------------------------------------------------------------------
void viewExample::btn_Bomb_clicked(Qt::MouseButton aBtn)
{
  qWarning() << "Bomb clicked " << aBtn;
}
//------------------------------------------------------------------------------
void viewExample::keyReleaseEvent(QKeyEvent *apEvent)
{
  switch(apEvent->key())
  {
    case Qt::Key_Left:
    {
      mZombie.set_left_direction();
      mZombie.move();
      break;
    }
    case Qt::Key_Right:
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
