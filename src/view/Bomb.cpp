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
    changePicTimer();
    setPos(x,y);
    Timer();
}

void Bomb::changePicTimer() {
    picTimer = new QTimer();
    picTimer->setInterval(200);
    picTimer->start();
    connect(picTimer,&QTimer::timeout, this,&Bomb::changeBombPic);
}
void Bomb::Timer() {
    bombTimer = new QTimer();
    bombTimer->setInterval(bombTime * 1000);
    bombTimer->start();
    isActived = true;
    connect(bombTimer, &QTimer::timeout, this, &Bomb::explosion);
}
void Bomb::explosion() {
    isActived = false;
    emit destroyed(x,y,bombSender);
    delete icons;
    delete bombTimer;
    delete picTimer;
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