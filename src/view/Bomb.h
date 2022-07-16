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
    int bombTime{3};
    QString bombSender{};
    bool isActived{false};
    Bomb(int x,int y,int height , int width);
    void Timer();
public slots:
    void explosion();
signals:
    void destroyed(int x,int y , QString bombsender);
};


#endif //PLAYWITHFIRE_BOMB_H
