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

    textField1= new TextField(200,55);
    textField1->setPlainText("");
    scene->addItem(textField1);
    textField1->setPos(width()/2,height()/2);

    textField2 = new TextField(200,55);
    textField2->setPlainText("");
    scene->addItem(textField2);
    textField2->setPos(width()/2,height()/2-100);


    auto textField3 = new TextField(200,500);
    textField3->setPlainText("");
    scene->addItem(textField3);
    textField3->setPos(width()/2,height()/2-200);

    auto label1= new Label(scene->width(),scene->height());
    label1->setPlainText("Player 1 Name :");
    scene->addItem(label1);
    label1->setPos(width()/2,height()/2-label1->boundingRect().height()-100);

    auto label2= new Label(scene->width(),scene->height());
    label2->setPlainText("Player 2 Name :");
    scene->addItem(label2);
    label2->setPos(width()/2,height()/2-label2->boundingRect().height());

    auto label3= new Label(scene->width(),scene->height());
    label2->setPlainText("Players life :");
    scene->addItem(label3);
    label2->setPos(width()/2,height()/2-label3->boundingRect().height()-200);

    auto button= new Button(200,55);
    button->setPlainText("    Start Game:");
    scene->addItem(button);
    button->setPos(width()/2,height()/2+button->boundingRect().height()+30);

    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    auto name1=textField1->toPlainText();
    auto name2 = textField2->toPlainText();
    close();
    (new Game(name1,name2))->show();
}




