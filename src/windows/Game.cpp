//
// Created by AIDA on 7/12/2022.
//

#include "Game.h"
#include "../view/Wall.h"
#include "../view/Character.h"
#include <QKeyEvent>

Game::Game(QString name1,QString name2) : QGraphicsView(){
    setFocus();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor(":/image/bg1"));
    setScene(scene);

    auto blockWidth=width()/15;
    auto blockHeight=height()/15;

    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){
          //
            if(i !=0&&i !=14 && j !=0 && j !=14 &&
                    (j%2 !=0 || i%2 !=0))
                continue;
            auto wall =new Wall(blockWidth,blockHeight);
            scene->addItem(wall);
            wall->setPos(blockWidth* i,blockHeight* j);

        }
    redChar = new Character("charRed", width(), height());
    redChar->setPos(135,75);
    scene->addItem(redChar);

    blueChar = new Character("charBlue", width(), height());
    blueChar->setPos(1671,939);
    scene->addItem(blueChar);

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

}


