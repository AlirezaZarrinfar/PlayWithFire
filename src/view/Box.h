#ifndef PLAYWITHFIRE_BOX_H
#define PLAYWITHFIRE_BOX_H
#include <QGraphicsPixmapItem>
#include "Block.h"


class Box : public Block{

public:
    Box(int width,int height);
    bool checkBox();
};


#endif //PLAYWITHFIRE_BOX_H
