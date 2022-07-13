#include "Box.h"
Box::Box(int width,int height) : QGraphicsPixmapItem(){

    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
}

bool Box::checkBox() {
    for(QGraphicsItem *item : collidingItems())
    {
        Box *box = dynamic_cast<Box *>(item);
        if(box != nullptr)
        {
            return true;
        }
        return false;
    }
}