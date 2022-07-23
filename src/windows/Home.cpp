#include <QFile>
#include <QCoreApplication>
#include "Home.h"
#include "../view/TextField.h"
#include "../view/Label.h"
#include "../view/Button.h"
#include "Game.h"
#include "Scoreboard.h"
#include <QMediaPlayer>
Home::Home() {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    showFullScreen();

    auto scene =new QGraphicsScene(this);
    scene->setSceneRect(0,0,width(),height());
    QPixmap pixmap(":/images/home") ;
    pixmap = pixmap.scaled(scene->width(),scene->height());
    setScene(scene);
    QGraphicsPixmapItem * item = new QGraphicsPixmapItem();
    item->setPixmap(pixmap);

    scene->addItem(item);
    textField1= new TextField(scene->width()/9,scene->height()/15);
    scene->addItem(textField1);
    textField1->setPos(width()/2 - scene->width()/9/2,height()/2);

    textField2 = new TextField(scene->width()/9,scene->height()/15);
    scene->addItem(textField2);
    textField2->setPos(width()/2 - scene->width()/9/2,height()/2-height()/10.5);


    textField3 = new TextField(scene->width()/9,scene->height()/15);
    scene->addItem(textField3);
    textField3->setPos(width()/2 - scene->width()/9/2,height()/2-(2*height()/10.5));

    auto label1= new Label(scene->width(),scene->height());
    label1->setPlainText("Player 1 Name :");
    scene->addItem(label1);
    label1->setPos(width()/2- scene->width()/9/2,height()/2-label1->boundingRect().height()-height()/10.5);
    label1->setDefaultTextColor(QColor("white"));

    auto label2= new Label(scene->width(),scene->height());
    label2->setPlainText("Player 2 Name :");
    scene->addItem(label2);
    label2->setPos(width()/2- scene->width()/9/2,height()/2-label2->boundingRect().height());
    label2->setDefaultTextColor(QColor("white"));

    auto label3= new Label(scene->width(),scene->height());
    label3->setPlainText("Players life :");
    scene->addItem(label3);
    label3->setPos(width()/2- scene->width()/9/2,height()/2-label3->boundingRect().height()-(2*height()/10.5));
    label3->setDefaultTextColor(QColor("white"));

    auto button= new Button(scene->width()/9,scene->height()/15);
    button->setPlainText("    Start Game:");
    scene->addItem(button);
    button->setPos(width()/2- scene->width()/9/2,height()/2+button->boundingRect().height()+height()/30);


    QFile file("../file.txt");
    file.open(QIODevice::ReadOnly);
    QString strFile = file.readAll();
    QStringList list = strFile.split(" ");
    textField1->setPlainText(list.at(0));
    textField2->setPlainText(list.at(1));
    textField3->setPlainText(list.at(2));
    file.close();


    connect(button,&Button::onPress,this,&Home::onGameStart);
}

void Home::onGameStart() {
    QString name1=textField1->toPlainText();
    QString name2 = textField2->toPlainText();
    auto lifes = textField3->toPlainText().toInt();

    if(lifes == 0)
    {
        textField3->setPlainText("please enter number");
    }
    else if (!(name2.isEmpty()) && !(name1.isEmpty()))
    {
        (new Game(name1,name2,lifes))->show();
        QFile file("../file.txt");
        file.open(QIODevice::WriteOnly);
        file.write(name1.toUtf8() + " " + name2.toUtf8() + " " + QString::number(lifes).toUtf8());
        file.flush();
        file.close();
        this->close();
       // (new Scoreboard(100,150,player1Name,player2Name))->show();
    }
}




