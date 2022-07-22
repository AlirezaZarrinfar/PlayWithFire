#ifndef PLAYWITHFIRE_ITEM_H
#define PLAYWITHFIRE_ITEM_H
#include <QGraphicsPixmapItem>


class Item : public QGraphicsPixmapItem {
public:
    Item(int width , int height,QString typeOfItem);
    QString type{};
};


#endif //PLAYWITHFIRE_ITEM_H
