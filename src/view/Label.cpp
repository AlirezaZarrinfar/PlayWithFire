#include "Label.h"
#include <QFont>
#include <QTextDocument>
Label::Label() {
    setDefaultTextColor(QColor("black"));

    QFont font;
    font.setPixelSize(23);
    font.setBold(true);
    setFont(font);

    document()->setDocumentMargin(10);

}