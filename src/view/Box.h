#ifndef PLAYWITHFIRE_BOX_H
#define PLAYWITHFIRE_BOX_H
#include <QGraphicsPixmapItem>


class Box : public QGraphicsPixmapItem{

public:
    Box(int width,int height);
    bool checkBox();
};


#endif //PLAYWITHFIRE_BOX_H
