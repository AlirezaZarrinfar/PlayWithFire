#ifndef PLAYWITHFIRE_BOX_H
#define PLAYWITHFIRE_BOX_H
#include <QGraphicsPixmapItem>
#include "Block.h"
#include "Item.h"
#include <QGraphicsScene>


class Box : public Block{
private:
    int width;
    int height;
public:
    QString typeOfItem{};
    Box(int width,int height);
    bool checkBox();
    bool hasItem{false};
    bool temp{false};
    ~Box();
};


#endif //PLAYWITHFIRE_BOX_H
