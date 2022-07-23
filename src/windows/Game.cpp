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
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include <QMovie>
#include <QGraphicsProxyWidget>


Game::Game(QString player1Name, QString player2Name, int lifes) : QGraphicsView(){
    setFocus();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();
    //resize(1920/2*1.5,1080/2*1.5);

    this->player1Name = player1Name;
    this->player2Name = player2Name;

    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("black"));
    setScene(scene);


    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++){

            if(i !=0&&i !=14 && j !=0 && j !=14 &&
                    (j%2 !=0 || i%2 !=0))
                continue;
            auto wall =new Wall(width(),height());
            scene->addItem(wall);
            wall->setPos(width()/15* i,height()/15* j);
        }

    srand(time(0));
    for (int z = 1;z<=87;z++) {
        int i = rand() % 15;
        int j = rand() % 15;
        if (i != 0 && i != 14 && j != 0 && j != 14 &&
            (j % 2 != 0 || i % 2 != 0) && !(i == 1 && j == 1) && !(i == 1 && j == 2) && !(i == 2 && j == 1)
            && !(i == 12 && j == 13) && !(i == 13 && j == 13) && !(i == 13 && j == 12)
            && !(i == 1 && j == 3) && !(i == 3 && j == 1) && !(i == 11 && j == 13) && !(i == 13 && j == 11)
                ) {

            auto box = new class Box(width(), height());
            box->setPos(i * (width() / 15), j * (height() / 15));

            if (z % 7 == 0) {
                QPixmap pixmap(":/images/boxitem");
                pixmap = pixmap.scaled(width() / 15, height() / 15);
                box->setPixmap(pixmap);
                box->hasItem = true;
                if (z < 43) {
                    box->typeOfItem = "heart";
                } else {
                    box->typeOfItem = "radius";
                }
            }

            scene->addItem(box);

            if (box->checkBox()) {
                box->temp = true;
                delete box;
                z--;
            }
        } else {
            z--;
        }
    }


    redChar = new Character( width(), height() , "Red");
    redChar->setPos(scene->width()/15,scene->height()/15);
    redChar->life = lifes;
    scene->addItem(redChar);



    blueChar = new Character( width(), height(),"Blue");
    blueChar->setPos(scene->width()*13/15 ,scene->height()*13/15);
    blueChar->life = lifes;
    scene->addItem(blueChar);




    redLifeLabel = new Label(scene->width(), scene->height());
    redLifeLabel->setPos(scene->width() / 18, 0);
    QString redLifeString = QString::number(redChar->life);
    redLifeLabel->setDefaultTextColor(QColor("Red"));
    redLifeLabel->setPlainText(player1Name + " life: " + redLifeString);

    blueLifeLabel = new Label(scene->width(), scene->height());
    blueLifeLabel->setPos(redLifeLabel->x() + redLifeLabel->boundingRect().width() + scene->width() / 25, 0);
    QString blueLifeString = QString::number(blueChar->life);
    blueLifeLabel->setDefaultTextColor(QColor("Blue"));
    blueLifeLabel->setPlainText(player2Name + " life: " + blueLifeString);



    redScoreLabel = new Label(scene->width(), scene->height());
    redScoreLabel->setPos((scene->width() / 2) - (scene->width() / 15), 0);
    QString redScoreString = QString::number(redChar->score);
    redScoreLabel->setDefaultTextColor(QColor("Red"));
    redScoreLabel->setPlainText(player1Name + " : " + redScoreString);

    blueScoreLabel = new Label(scene->width(), scene->height());
    blueScoreLabel->setPos(redScoreLabel->x() + redScoreLabel->boundingRect().width() + scene->width() / 25, 0);
    QString blueScoreString = QString::number(blueChar->score);
    blueScoreLabel->setDefaultTextColor(QColor("Blue"));
    blueScoreLabel->setPlainText(player2Name + " : " + blueScoreString);


    scene->addRect(QRect(scene->width()/23 , 0,width()-scene->width()/11,scene->height()/22),QPen(QColor("black"),1),QBrush(QColor("Orange")));


    scene->addItem(blueLifeLabel);
    scene->addItem(redLifeLabel);
    scene->addItem(redScoreLabel);
    scene->addItem(blueScoreLabel);

    bombRadiusLabel = new Label(scene->width(), scene->height());
    bombRadiusLabel->setPos(scene->width() - (scene->width() / 5), 0);
    bombRadiusLabel->setDefaultTextColor(QColor("black"));
    bombRadiusLabel->setPlainText("Bomb Radius : ");

    redBombsLabel = new Label(scene->width(), scene->height());
    redBombsLabel->setPos(bombRadiusLabel->x() + bombRadiusLabel->boundingRect().width() + scene->width() / 200, 0);
    QString redBombsString = QString::number(redChar->bombRadius);
    redBombsLabel->setDefaultTextColor(QColor("Red "));
    redBombsLabel->setPlainText(redBombsString);

    blueBombsLabel = new Label(scene->width(), scene->height());
    blueBombsLabel->setPos(redBombsLabel->x() + redBombsLabel->boundingRect().width() + scene->width() / 200, 0);
    QString blueBombsString = QString::number(blueChar->bombRadius);
    blueBombsLabel->setDefaultTextColor(QColor("Blue"));
    blueBombsLabel->setPlainText(blueBombsString);

    scene->addItem(bombRadiusLabel);
    scene->addItem(redBombsLabel);
    scene->addItem(blueBombsLabel);
}

QSet<int> pressedKeys;
void Game::keyPressEvent(QKeyEvent *event) {
    QGraphicsView::keyPressEvent(event);
    //Red Char
    if (event->type() == QEvent::KeyPress) {
        pressedKeys += ((QKeyEvent *) event)->key();
        if (pressedKeys.contains(Qt::Key_Right)) {
            redChar->moveChar(redChar->x() + scene()->width() / 15, redChar->y());
        }
        if (pressedKeys.contains(Qt::Key_Left)) {
            redChar->moveChar(redChar->x() - scene()->width() / 15, redChar->y());
        }
        if (pressedKeys.contains(Qt::Key_Down)) {
            redChar->moveChar(redChar->x(), redChar->y() + scene()->height() / 15);
        }
        if (pressedKeys.contains(Qt::Key_Up)) {
            redChar->moveChar(redChar->x(), redChar->y() - scene()->height() / 15);
        }
        if (pressedKeys.contains(Qt::Key_Space)) {
            auto bomb = redChar->createBomb();
            if (bomb != nullptr) {
                connect(bomb, &Bomb::destroyed, this, &Game::bombDestroyed);
                scene()->addItem(bomb);
            }
        }

        //Blue Char
        if (pressedKeys.contains(Qt::Key_D)) {
            blueChar->moveChar(blueChar->x() + scene()->width() / 15, blueChar->y());
        }
        if (pressedKeys.contains(Qt::Key_A)) {
            blueChar->moveChar(blueChar->x() - scene()->width() / 15, blueChar->y());

        }
        if (pressedKeys.contains(Qt::Key_S)) {
            blueChar->moveChar(blueChar->x(), blueChar->y() + scene()->height() / 15);
        }
        if (pressedKeys.contains(Qt::Key_W)) {
            blueChar->moveChar(blueChar->x(), blueChar->y() - scene()->height() / 15);
        }
        if (pressedKeys.contains(Qt::Key_X)) {
            auto bomb = blueChar->createBomb();
            if (bomb != nullptr) {
                connect(bomb, &Bomb::destroyed, this, &Game::bombDestroyed);
                scene()->addItem(bomb);
            }
        }
    }
    else if(event->type()==QEvent::KeyRelease)
    {
        pressedKeys -= ((QKeyEvent*)event)->key();
    }

    QString redLifeString = QString::number(redChar->life);
    redLifeLabel->setPlainText(player1Name + " life: " + redLifeString);

    QString blueLifeString = QString::number(blueChar->life);
    blueLifeLabel->setPlainText(player2Name + " life: " + blueLifeString);

    QString redRadiusString = QString::number(redChar->bombRadius);
    redBombsLabel->setPlainText(redRadiusString);

    QString blueRadiusString = QString::number(blueChar->bombRadius);
    blueBombsLabel->setPlainText(blueRadiusString);
}


void Game::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsView::keyReleaseEvent(event);

    if(event->type()==QEvent::KeyRelease)
    {
        pressedKeys -= ((QKeyEvent*)event)->key();
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
        (new Scoreboard(redChar->score, blueChar->score, player1Name, player2Name))->show();
        close();
    }
    QString string = QString::number(redChar->life);
    redLifeLabel->setPlainText(player1Name + " life: " + string);

    QString string2 = QString::number(blueChar->life);
    blueLifeLabel->setPlainText(player2Name + " life: " + string2);

    QString string3 = QString::number(redChar->score);
    redScoreLabel->setPlainText(player1Name + " : " + string3);

    QString string4 = QString::number(blueChar->score);
    blueScoreLabel->setPlainText(player2Name + " : " + string4);

}

