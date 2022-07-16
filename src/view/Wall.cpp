#include "Wall.h"

Wall::Wall(int width,int height) : Block(){
    Block::type = "Wall";
    QPixmap pixmap(":/images/wall");
    pixmap=pixmap.scaled(width/15,height/15);
    setPixmap(pixmap);
}
