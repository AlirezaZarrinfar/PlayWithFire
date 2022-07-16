//
// Created by zarri on 7/16/2022.
//

#ifndef PLAYWITHFIRE_BLOCK_H
#define PLAYWITHFIRE_BLOCK_H


#include <QString>
#include <QGraphicsPixmapItem>

class Block : public QGraphicsPixmapItem{
public:
    Block();
    QString type;
};


#endif //PLAYWITHFIRE_BLOCK_H
