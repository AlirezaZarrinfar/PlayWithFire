#include "Item.h"

Item::Item(int width , int height,QString typeOfItem){
    QPixmap pixmap(":/images/" + typeOfItem);
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);

}