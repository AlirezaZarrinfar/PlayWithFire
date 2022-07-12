#include "Character.h"
#include <QGraphicsItem>
#include "../view/Wall.h"
#include "../view/Bomb.h"

Character::Character(QString icon , int width , int height) : heigth(height), width(width) {
    QPixmap pixmap (":/images/" + icon);
    pixmap = pixmap.scaled(width/16,height/16);
    setPixmap(pixmap);
}

bool Character::CheckWall() {
    for(QGraphicsItem *item : collidingItems())
    {
        Wall *wall = dynamic_cast<Wall *>(item);
        if(wall != nullptr)
        {
            return true;
        }
    }
}

void Character::moveChar(int x, int y) {
    int tempX = this->x();
    int tempY = this->y();
    setPos(x,y);
    if(CheckWall()) {
        setPos(tempX, tempY);
    }
}

Bomb * Character::createBomb() {
    if(bombCreated == 0)
    {
        bomb = new Bomb(x(), y(), heigth, width);
        bombCreated++;
        return bomb;
    }
    else if(!bomb->isActived) {
        bomb = new Bomb(x(), y(), heigth, width);
        bombCreated++;
        return bomb;
    }
    else
    {
        return nullptr;
    }
}