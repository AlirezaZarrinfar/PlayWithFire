#include <QFont>
#include "TextField.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QTextDocument>
TextField::TextField(int width,int height) : QGraphicsTextItem()
                    ,width(width),height(height)
{

    setDefaultTextColor(QColor("black"));
    QFont font;
    font.setPixelSize(width/30*height/30);
    font.setBold(true);
    setFont(font);
//Text in Editor Mode
    setTextInteractionFlags(Qt::TextEditorInteraction);

    setTextWidth(width);
    document()->setDocumentMargin(10);

}

void TextField::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPixmap pixmap (":/images/input");
    pixmap=pixmap.scaled(width,height);
    painter->setBrush(pixmap);
    painter->drawRect(QGraphicsTextItem::boundingRect());

    //Boarder
    QStyleOptionGraphicsItem newOption(*option);
    newOption.state=QStyle::State_None;
    QGraphicsTextItem::paint(painter, &newOption, widget);
}

QRectF TextField::boundingRect() const {
    auto rect=QGraphicsTextItem::boundingRect();
    rect.setWidth(width);
    rect.setHeight(height);
    return QGraphicsTextItem::boundingRect();
}

