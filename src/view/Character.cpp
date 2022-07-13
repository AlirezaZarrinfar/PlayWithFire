#include "Character.h"
#include <QGraphicsItem>
#include "../view/Wall.h"
#include "../view/Bomb.h"
#include "../view/Box.h"

Character::Character(QString icon , int width , int height) : heigth(height), width(width) {
    QPixmap pixmap (":/images/" + icon);
    pixmap = pixmap.scaled(width/15,height/15);
        setPixmap(pixmap);
    }

    bool Character::checkWallOrBox() {
        for(QGraphicsItem *item : collidingItems())
        {
            Wall *wall = dynamic_cast<Wall *>(item);
            Box *box = dynamic_cast<Box *>(item);
            if(wall != nullptr || box != nullptr)
            {
                return true;
            }
            return false;
        }
    }

    bool Character::chechCharacter() {
        for(QGraphicsItem *item : collidingItems())
        {
            Character *character = dynamic_cast<Character *>(item);
            if(character != nullptr)
            {
                return true;
            }
            return false;
        }
    }

    void Character::moveChar(int x, int y) {
        int tempX = this->x();
        int tempY = this->y();
        setPos(x,y);
        if(checkWallOrBox() || chechCharacter()) {
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