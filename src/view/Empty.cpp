#include "Empty.h"
#include "Box.h"
#include "Character.h"

Empty::Empty(int x , int y ,int width,int height) : QGraphicsPixmapItem(){

    QPixmap pixmap(":/images/empty");
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
}

bool Empty::checkBox() {
    for(QGraphicsItem *item : collidingItems())
    {
        Box *box = dynamic_cast<Box *>(item);
        if(box != nullptr)
        {
            delete box;
            return true;
        }
        Character *character = dynamic_cast<Character *>(item);
        if(character != nullptr)
        {
            character->life -- ;
            return true;
        }
        return false;
    }
}

