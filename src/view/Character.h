#ifndef PLAYWITHFIRE_CHARACTER_H
#define PLAYWITHFIRE_CHARACTER_H
#include <QGraphicsPixmapItem>
#include "../view/Bomb.h"


class Character : public QGraphicsPixmapItem{
private:
    int width{};
    int heigth{};
    int bombCreated{0};
    Bomb * bomb{nullptr};
public:
    int life{5};
    Character(QString icon, int width , int height);
    bool checkWallOrBox();
    bool chechCharacter();
    void moveChar(int x , int y);
    Bomb * createBomb();
};


#endif //PLAYWITHFIRE_CHARACTER_H
