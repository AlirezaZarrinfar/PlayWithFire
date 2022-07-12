#ifndef PLAYWITHFIRE_BUTTON_H
#define PLAYWITHFIRE_BUTTON_H
#include <QGraphicsTextItem>

class Button : public QGraphicsTextItem{
    Q_OBJECT
private:
    int width{};
    int height{};
public:
    Button(int width,int height);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void onPress();
};


#endif //PLAYWITHFIRE_BUTTON_H
