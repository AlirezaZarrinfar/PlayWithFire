#include "Character.h"
#include <QGraphicsItem>
#include "../view/Wall.h"
#include "../view/Bomb.h"
#include "../view/Box.h"
#include "../view/Block.h"
#include "Label.h"

Character::Character(QString icon , int width , int height) : heigth(height), width(width) {
    QPixmap pixmap (":/images/" + icon);
    pixmap = pixmap.scaled(width/15,height/15);
        setPixmap(pixmap);
    }

    bool Character::checkWallOrBox() {
        for(QGraphicsItem *item : collidingItems())
        {
            Label *label = dynamic_cast<Label *>(item);
            Block *block = dynamic_cast<Block *>(item);
            if(block != nullptr || label != nullptr)
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
            bomb->bombSender = type;
            bombCreated++;
            return bomb;
        }
        else if(!bomb->isActived) {
            bomb = new Bomb(x(), y(), heigth, width);
            bomb->bombSender = type;
            bombCreated++;
        return bomb;
    }
    else
    {
        return nullptr;
    }
}