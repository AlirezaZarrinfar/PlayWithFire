#ifndef PLAYWITHFIRE_CHARACTER_H
#define PLAYWITHFIRE_CHARACTER_H
#include <QGraphicsPixmapItem>

class Character : public QGraphicsPixmapItem{
private:
    int width{};
    int heigth{};
public:
    Character(QString icon, int width , int height);
    bool CheckWall();
    void moveChar(int x , int y);
};


#endif //PLAYWITHFIRE_CHARACTER_H
