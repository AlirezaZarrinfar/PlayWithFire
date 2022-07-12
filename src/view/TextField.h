#ifndef PLAYWITHFIRE_TEXTFIELD_H
#define PLAYWITHFIRE_TEXTFIELD_H
#include <QGraphicsTextItem>

class TextField :public QGraphicsTextItem{
private:
    int width{};
    int height{};
public:
    TextField(int width,int height);

    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};


#endif //PLAYWITHFIRE_TEXTFIELD_H
