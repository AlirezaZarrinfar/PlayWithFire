#include "Bomb.h"
#include <QTimer>
Bomb::Bomb(int x,int y,int height , int width) : x(x) , height(height) , width(width) , y(y) {

    icons = new QList<QString>();
    icons->append(":/images/bomb");
    icons->append(":/images/bomb2");
    icons->append(":/images/bomb3");
    QPixmap pixmap (icons->at(i%2));
    pixmap = pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
    i++;
    timer = new QTimer();
    timer->setInterval(200);
    timer->start();
    isActived = true;
    connect(timer,&QTimer::timeout, this,&Bomb::changeBombPic);
    setPos(x,y);
    Timer();
}

void Bomb::Timer() {
    timer = new QTimer();
    timer->setInterval(bombTime*1000);
    timer->start();
    isActived = true;
    connect(timer,&QTimer::timeout, this,&Bomb::explosion);
}
void Bomb::explosion() {
    isActived = false;
    emit destroyed(x,y,bombSender);
    delete timer;
    delete this;
}

void Bomb::changeBombPic() {
    if(i>17)
    {
        QPixmap pixmap (icons->at(2));
        pixmap = pixmap.scaled(width/15,height/15);
        setPixmap(pixmap);
    }
    else {
        QPixmap pixmap(icons->at(i % 2));
        pixmap = pixmap.scaled(width / 15, height / 15);
        setPixmap(pixmap);
    }
    i++;
}