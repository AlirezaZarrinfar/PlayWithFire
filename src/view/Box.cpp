#include "Box.h"
Box::Box(int width,int height) : QGraphicsPixmapItem(){

    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(width,height);
    setPixmap(pixmap);
}