#include "Bomb.h"
#include <QTimer>
Bomb::Bomb(int x,int y,int height , int width) : x(x) , height(height) , width(width) , y(y) {
    QPixmap pixmap (":/images/bomb");
    pixmap = pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
    setPos(x,y);
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
    emit destroyed(x,y);
    delete timer;
    delete this;
}
