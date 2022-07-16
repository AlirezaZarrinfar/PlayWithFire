#include "Box.h"
Box::Box(int width,int height) : Block() {
    Block::type = "Box";
    QPixmap pixmap(":/images/box");
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
}

bool Box::checkBox() {
    for(QGraphicsItem *item : collidingItems())
    {
        Block *box = dynamic_cast<Box *>(item);
        if(box != nullptr && box->type=="Box")
        {
            return true;
        }
        return false;
    }
}