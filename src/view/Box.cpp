#include "Box.h"
Box::Box(int width,int height) : Block() {
    this->width = width;
    this->height = height;
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

Box::~Box(){
    if(!temp && hasItem) {
        Item *item = new Item(width, height, typeOfItem);
        item->setPos(x(), y());
        item->type = typeOfItem;
        scene()->addItem(item);
    }
}
