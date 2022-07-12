//
// Created by AIDA on 7/12/2022.
//

#include "Game.h"
#include "../view/Wall.h"

Game::Game(QString name) : QGraphicsView(){
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
}
