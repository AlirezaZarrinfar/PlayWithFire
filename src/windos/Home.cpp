#include "Home.h"
#include "../view/TextField.h"
#include "../view/Label.h"
#include "../view/Button.h"
#include "Game.h"

Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    scene->setBackgroundBrush(QColor("#FFFFFF"));
    setScene(scene);

    textField= new TextField(200,55);
    textField->setPlainText("");
    scene->addItem(textField);
    textField->setPos(width()/2,height()/2);

    auto label= new Label();
    label->setPlainText("Username:");
    scene->addItem(label);
    label->setPos(width()/2,height()/2-label->boundingRect().height());

    auto button= new Button(200,55);
    button->setPlainText("    Start Game:");
    scene->addItem(button);
    button->setPos(width()/2,height()/2+button->boundingRect().height()+30);

    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    auto name=textField->toPlainText();
    close();
    (new Game(name))->show();
}




