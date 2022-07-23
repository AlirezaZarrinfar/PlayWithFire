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
    QTimer *bombTimer;
    QTimer *picTimer;
    int i{0};
    QList<QString> * icons;
    void changePicTimer();
public:
    int bombTime{4};
    QString bombSender{};
    bool isActived{false};
    Bomb(int x,int y,int height , int width);
    void Timer();
public slots:
    void explosion();
    void changeBombPic();
signals:
    void destroyed(int x,int y , QString bombsender);
};


#endif //PLAYWITHFIRE_BOMB_H
