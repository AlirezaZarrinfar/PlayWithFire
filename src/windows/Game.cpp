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
#include <QDebug>
#include "../view/Label.h"
#include "time.h"
#include "Scoreboard.h"

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

    for (int z = 0;z<80;z++) {
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
    redChar->type = "Red";
    scene->addItem(redChar);

    blueChar = new Character("charBlue", width(), height());
    blueChar->setPos(scene->width()*13/15 ,scene->height()*13/15);
    blueChar->type = "Blue";
    scene->addItem(blueChar);



    scene->addRect(QRect(scene->width()/23 , 0,2.3*(scene->width()/15),scene->height()/22),QPen(QColor("black"),1),QBrush(QColor("Orange")));
    scene->addRect(QRect(scene->width()/2 - scene->width()/13 , 0,3.5*(scene->width()/15),scene->height()/22),QPen(QColor("Black"),1),QBrush(QColor("Orange")));

    label1 = new Label(scene->width(),scene->height());
    label1->setPos(scene->width()/20,0);
    scene->addItem(label1);
    QString string = QString::number(redChar->life);
    label1->setDefaultTextColor(QColor("Red"));
    label1->setPlainText("Red life: " + string);

    label2 = new Label(scene->width(),scene->height());
    label2->setPos(2*(scene->width()/15),0);
    scene->addItem(label2);
    QString string2 = QString::number(blueChar->life);
    label2->setDefaultTextColor(QColor("Blue"));
    label2->setPlainText("Blue life: " + string2);


    label3 = new Label(scene->width(),scene->height());
    label3->setPos((scene->width()/2)-(scene->width()/15),0);
    scene->addItem(label3);
    QString string3 = QString::number(redChar->score);
    label3->setDefaultTextColor(QColor("Red"));
    label3->setPlainText("Player Red : " + string3);

    label4 = new Label(scene->width(),scene->height());
    label4->setPos((scene->width()/2)+(scene->width()/15),0);
    scene->addItem(label4);
    QString string4 = QString::number(blueChar->score);
    label4->setDefaultTextColor(QColor("Blue"));
    label4->setPlainText("Player Blue : " + string4);

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

void Game::bombDestroyed(int x , int y , QString bombSender) {
    Character * temp ;
    if (bombSender == "Red")
    {
        temp = redChar;
    }
    else
    {
        temp = blueChar;
    }
    auto Empty = new class Empty(x,y,width(),height(),temp);
    scene()->addItem(Empty);
    scene()->removeItem(redChar);
    scene()->addItem(redChar);
    scene()->removeItem(blueChar);
    scene()->addItem(blueChar);
    Empty->setPos(x ,y);
    Empty->checkBoxOrChar();
    for (int i = 1; i <= temp->bombRadius; i++)
    {
        Empty->setPos(x + i * (scene()->width() / 15), y);
        if (Empty->checkWall())
        {
            break;
        }
        else {
            Empty->checkBoxOrChar();
        }
    }
//
    for (int i = 1; i <= temp->bombRadius; i++)
    {
        Empty->setPos(x - i * (scene()->width() / 15), y);
        if (Empty->checkWall())
        {
            break;
        }
        else {
            Empty->checkBoxOrChar();
        }
    }
    //

    for (int i = 1; i <= temp->bombRadius; i++)
    {
        Empty->setPos(x, y + i * (scene()->height() / 15));
        if (Empty->checkWall())
        {
            break;
        }
        else {
            Empty->checkBoxOrChar();
        }
    }
//
    for (int i = 1; i <= temp->bombRadius; i++)
    {
        Empty->setPos(x, y - i * (scene()->height() / 15));
        if (Empty->checkWall())
        {
            break;
        }
        else {
            Empty->checkBoxOrChar();
        }
    }

    /*
      Empty->setPos(x + (scene()->width()/15),y+ (scene()->height()/15));
      Empty->checkBoxOrChar();
      Empty->setPos(x - (scene()->width()/15),y- (scene()->height()/15));
      Empty->checkBoxOrChar();
      Empty->setPos(x + (scene()->width()/15) ,y - (scene()->height()/15));
      Empty->checkBoxOrChar();
      Empty->setPos(x - (scene()->width()/15) ,y + (scene()->height()/15));
      Empty->checkBoxOrChar();
      */
    delete Empty;
    if (blueChar->life == 0 || redChar->life==0)
    {
        close();
        (new Scoreboard(redChar->score,blueChar->score))->show();
    }
    QString string = QString::number(redChar->life);
    label1->setPlainText("Red life: " + string);

    QString string2 = QString::number(blueChar->life);
    label2->setPlainText("Blue life: " + string2);

    QString string3 = QString::number(redChar->score);
    label3->setPlainText("Player Red : " + string3);

    QString string4 = QString::number(blueChar->score);
    label4->setPlainText("Player Blue : " + string4);

}

