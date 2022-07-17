
#include "Scoreboard.h"
#include "../view/Label.h"

Scoreboard::Scoreboard(int redScore , int blueScore) {
    setFocus();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();



    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("white"));
    setScene(scene);


    QString red = QString::number(redScore);
    QString blue = QString::number(blueScore);
    auto winner = new Label(width()*2.2,height()*2.2);
    if(redScore > blueScore)
    {
        winner->setPlainText("Red is winner !");
        winner->setDefaultTextColor(QColor("Red"));
    }
    else if (redScore == blueScore)
    {
        winner->setPlainText("Red = Blue !");
    }
    else
    {
        winner->setPlainText("Blue is winner !");
        winner->setDefaultTextColor(QColor("Blue"));
    }
    scene->addItem(winner);
    winner->setPos((scene->width()/3),0);
    auto scores = new Label(width()*2,height()*2);
    scores->setPlainText("Red = " + red + "  " + "Blue = " + blue);
    scores->setPos((scene->width()/3),scene->height()/3);
    scene->addItem(scores);


}