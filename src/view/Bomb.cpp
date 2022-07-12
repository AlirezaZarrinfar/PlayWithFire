#include "Bomb.h"
#include <QTimer>
Bomb::Bomb(int x,int y,int height , int width) : x(x) , height(height) , width(width) , y(y) {
    QPixmap pixmap (":/images/bomb");
    pixmap = pixmap.scaled(width/30,height/20+5);
    setPixmap(pixmap);
    setPos(x+30,y);
    Timer();
}

void Bomb::Timer() {
    timer = new QTimer();
    timer->setInterval(3000);
    timer->start();
    isActived = true;
    connect(timer,&QTimer::timeout, this,&Bomb::explosion);
}
void Bomb::explosion() {
    isActived = false;
    delete timer;
    delete this;
}
