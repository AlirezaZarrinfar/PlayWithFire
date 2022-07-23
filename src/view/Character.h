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
    QPixmap pixmap;
    QList<QString> list;
    int i{0};
public:
    int life{3};
    QString type {};
    int score{0};
    int bombRadius{2};
    Character( int width , int height , QString type);
    bool checkWallOrBox();
    bool checkItem();
    bool chechCharacter();
    void moveChar(int x , int y);
    Bomb * createBomb();
};


#endif //PLAYWITHFIRE_CHARACTER_H
