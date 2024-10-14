#ifndef VIEW_HPP
#define VIEW_HPP

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QLabel>

#include "zombieattack.h"
#include "zombiemoving.h"
#include "zombiestanding.h"

#include "zombie.h"

class viewExample : public QGraphicsView
{
public:
  viewExample();

private:
  void _init_view_elements();

private slots:
  void keyReleaseEvent(QKeyEvent*)override;

private:
  zombieAttack   mZombieAttack;
  zombieMoving   mZombieMoving;
  zombieStanding mZombieNothing;
  zombie         mZombie;

  QGraphicsScene mScene;
};

#endif // VIEWEXAMPLE_HPP
