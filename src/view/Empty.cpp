#include "Empty.h"
#include "Box.h"
#include "Character.h"
#include "Wall.h"
#include "Block.h"
Empty::Empty(int x , int y ,int width,int height,Character * bombsender) : QGraphicsPixmapItem(){
    bombSender = bombsender;
    QPixmap pixmap(":/images/empty");
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
}

bool Empty::checkBoxOrChar() {
    for(QGraphicsItem *item : collidingItems())
    {
        Block *box = dynamic_cast<Box *>(item);
        if(box != nullptr && box->type=="Box")
        {
            delete box;
            bombSender->score += 5;
            return true;
        }
        Character *character = dynamic_cast<Character *>(item);
        if(character != nullptr)
        {
            character->life -- ;
            if (character != bombSender && character->life == 0)
            {
                bombSender->score += 50;
            }
            return true;
        }
        return false;
    }
}


bool Empty::checkWall() {
    for(QGraphicsItem *item : collidingItems())
    {
        Block *wall = dynamic_cast<Wall *>(item);
        if(wall != nullptr && wall->type=="Wall")
        {
            return true;
        }
        return false;
    }
}