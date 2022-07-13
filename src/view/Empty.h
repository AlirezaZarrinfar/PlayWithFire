#ifndef PLAYWITHFIRE_EMPTY_H
#define PLAYWITHFIRE_EMPTY_H
#include <QGraphicsPixmapItem>


class Empty : public QGraphicsPixmapItem{
public:
    Empty(int x , int y ,int width,int height);
    bool checkBox();


};


#endif //PLAYWITHFIRE_EMPTY_H
