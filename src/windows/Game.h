#ifndef PLAYWITHFIRE_GAME_H
#define PLAYWITHFIRE_GAME_H
#include <QGraphicsView>
#include "../view/Character.h"


class Game : public QGraphicsView{
private:
    Character * redChar;
    Character * blueChar;
public:
    Game(QString name1,QString name2);

protected:
    void keyPressEvent(QKeyEvent *event) override;
};



#endif //PLAYWITHFIRE_GAME_H
