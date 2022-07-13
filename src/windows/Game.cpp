#include "Game.h"
#include "../view/Wall.h"
#include "../view/Character.h"
#include "../view/Bomb.h"
#include "../view/Box.h"
#include <QKeyEvent>
#include <QTimer>
#include <iostream>
#include "../view/Empty.h"
#include <QRandomGenerator>
#include "../view/Label.h"
#include "time.h"

Game::Game(QString name1,QString name2) : QGraphicsView(){
    setFocus();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();



    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);


    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
          //
            if(i !=0&&i !=14 && j !=0 && j !=14 &&
                    (j%2 !=0 || i%2 !=0))
                continue;
            auto wall =new Wall(width(),height());
            scene->addItem(wall);
            wall->setPos(width()/15* i,height()/15* j);
        }

    srand(time(0));

    for (int z = 0;z<70;z++) {
      int i = rand()%15;
      int j = rand()%15;
      if (i != 0 && i != 14 && j != 0 && j != 14 &&
          (j % 2 != 0 || i % 2 != 0) && !(i == 1 && j==1) && !(i == 1 && j==2) && !(i == 2 && j==1)
          && !(i == 12 && j==13) && !(i == 13 && j==13) && !(i == 13 && j==12)
          && !(i == 1 && j==3) && !(i == 3 && j==1) && !(i == 11 && j==13) && !(i == 13 && j==11)
          ) {

          auto box = new class Box(width(), height());
          box->setPos(i * (width() / 15), j * (height() / 15));
          scene->addItem(box);
          if(box->checkBox())
          {
              delete box;
              z--;
          }
      }
      else
      {
          z--;
      }
  }


    redChar = new Character("charRed", width(), height());
    redChar->setPos(scene->width()/15,scene->height()/15);
    scene->addItem(redChar);

    blueChar = new Character("charBlue", width(), height());
    blueChar->setPos(scene->width()*13/15 ,scene->height()*13/15);
    scene->addItem(blueChar);



    scene->addRect(QRect(scene->width()/20 , 0,2.65*(scene->width()/15),scene->height()/18),QPen(QColor("black"),3),QBrush(QColor("Black")));

    label1 = new Label();
    label1->setPos(scene->width()/20,0);
    scene->addItem(label1);
    QString string = QString::number(redChar->life);
    label1->setDefaultTextColor(QColor("Red"));
    label1->setPlainText("Player Red : " + string);

    label2 = new Label();
    label2->setPos(2*(scene->width()/15),0);
    scene->addItem(label2);
    QString string2 = QString::number(blueChar->life);
    label2->setDefaultTextColor(QColor("Blue"));
    label2->setPlainText("Player Blue : " + string);

}
void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //Red Char
    if(event->key() == Qt::Key::Key_Right)
    {
        redChar->moveChar(redChar->x() + scene()->width()/15,redChar->y());
    }
    else if(event->key() == Qt::Key::Key_Left)
    {
        redChar->moveChar(redChar->x() - scene()->width()/15,redChar->y());

    }
    else if(event->key() == Qt::Key::Key_Down)
    {
        redChar->moveChar(redChar->x() ,redChar->y()+ scene()->height()/15);
    }
    else if(event->key() == Qt::Key::Key_Up)
    {
        redChar->moveChar(redChar->x() ,redChar->y()- scene()->height()/15);
    }
    else if(event->key() == Qt::Key::Key_Space)
    {
        auto bomb = redChar->createBomb();
        if(bomb != nullptr){
            connect(bomb,&Bomb::destroyed, this, &Game::bombDestroyed);
            scene()->addItem(bomb);
        }
    }
    //Blue Char
    if(event->key() == Qt::Key::Key_D)
    {
        blueChar->moveChar(blueChar->x() + scene()->width()/15,blueChar->y());
    }
    else if(event->key() == Qt::Key::Key_A)
    {
        blueChar->moveChar(blueChar->x() - scene()->width()/15,blueChar->y());

    }
    else if(event->key() == Qt::Key::Key_S)
    {
        blueChar->moveChar(blueChar->x() ,blueChar->y()+ scene()->height()/15);
    }
    else if(event->key() == Qt::Key::Key_W)
    {
        blueChar->moveChar(blueChar->x() ,blueChar->y()- scene()->height()/15);
    }
    else if(event->key() == Qt::Key::Key_X)
    {
        auto bomb = blueChar->createBomb();
        if(bomb != nullptr) {
            connect(bomb, &Bomb::destroyed, this, &Game::bombDestroyed);
            scene()->addItem(bomb);
        }
    }
}

void Game::bombDestroyed(int x , int y) {
    auto Empty = new class Empty(x,y,width(),height());
    scene()->addItem(Empty);
    Empty->setPos(x + (scene()->width()/15),y);
    Empty->checkBox();
    Empty->setPos(x - (scene()->width()/15),y);
    Empty->checkBox();
    Empty->setPos(x ,y - (scene()->height()/15));
    Empty->checkBox();
    Empty->setPos(x ,y + (scene()->height()/15));
    Empty->checkBox();
    Empty->setPos(x + (scene()->width()/15),y+ (scene()->height()/15));
    Empty->checkBox();
    Empty->setPos(x - (scene()->width()/15),y- (scene()->height()/15));
    Empty->checkBox();
    Empty->setPos(x + (scene()->width()/15) ,y - (scene()->height()/15));
    Empty->checkBox();
    Empty->setPos(x - (scene()->width()/15) ,y + (scene()->height()/15));
    Empty->checkBox();

    if(redChar->x() == x && redChar->y() == y)
        redChar->life--;

    if (blueChar->x() == x && blueChar->y() == y)
        blueChar->life--;

    delete Empty;
    if (blueChar->life == 0 || redChar->life==0)
    {
        close();
    }
    QString string = QString::number(redChar->life);
    label1->setPlainText("Player Red : " + string);

    QString string2 = QString::number(blueChar->life);
    label2->setPlainText("Player Blue : " + string2);

}

