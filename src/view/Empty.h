#ifndef PLAYWITHFIRE_EMPTY_H
#define PLAYWITHFIRE_EMPTY_H
#include <QGraphicsPixmapItem>
#include "Character.h"


class Empty : public QGraphicsPixmapItem{
private:
    Character * bombSender{};
public:
    Empty(int x , int y ,int width,int height,Character * bombsender);
    bool checkBoxOrChar();
    bool checkWall();
};


#endif //PLAYWITHFIRE_EMPTY_H
