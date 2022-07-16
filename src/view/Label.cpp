#include "Label.h"
#include <QFont>
#include <QTextDocument>
Label::Label(int width , int height) {
    setDefaultTextColor(QColor("black"));

    QFont font;
    font.setPixelSize(width*height/100000);
    font.setBold(true);
    setFont(font);

    //document()->setDocumentMargin(10);

}