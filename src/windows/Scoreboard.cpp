
#include "Scoreboard.h"
#include "../view/Label.h"

Scoreboard::Scoreboard(int redScore , int blueScore,QString name1 , QString name2) {
    setFocus();
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("white"));
    setScene(scene);

    QPixmap pixmap(":/images/end") ;
    pixmap = pixmap.scaled(scene->width(),scene->height());
    setScene(scene);
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(pixmap);
    scene->addItem(item);

    QString red = QString::number(redScore);
    QString blue = QString::number(blueScore);
    auto winner = new Label(width()*1.5,height()*1.5);
    if(redScore > blueScore)
    {
        winner->setPlainText(name1 + " is winner !");
        winner->setDefaultTextColor(QColor("Red"));
    }
    else if (redScore == blueScore)
    {
        winner->setPlainText(name1 + " = "+name2+" !");
    }
    else
    {
        winner->setPlainText(name2 + " is winner !");
        winner->setDefaultTextColor(QColor("Blue"));
    }
    scene->addItem(winner);
    winner->setPos((scene->width()/3+scene->width()/5),scene->height()/16);
    auto scores = new Label(width()*1.5,height()*1.5);
    scores->setPlainText(name1 + " = " + red + "  -  " + name2 + " = " + blue);
    scores->setPos((scene->width()/7),scene->height()-scene->height()/8);
    scores->setDefaultTextColor(QColor("#569556"));
    scene->addItem(scores);


}