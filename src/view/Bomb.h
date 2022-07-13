#include <QGraphicsPixmapItem>
#ifndef PLAYWITHFIRE_BOMB_H
#define PLAYWITHFIRE_BOMB_H
#include <QTimer>


class Bomb : public QObject, public QGraphicsPixmapItem{
Q_OBJECT
private:
    int x{};
    int y{};
    int width{};
    int height{};
    QTimer *timer;
public:
    bool isActived{false};
    Bomb(int x,int y,int height , int width);
    void Timer();
public slots:
    void explosion();
signals:
    void destroyed(int x,int y);
};


#endif //PLAYWITHFIRE_BOMB_H
