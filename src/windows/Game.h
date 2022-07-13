#ifndef PLAYWITHFIRE_GAME_H
#define PLAYWITHFIRE_GAME_H
#include <QGraphicsView>
#include "../view/Character.h"
#include "../view/Label.h"

class Game : public QGraphicsView{
private:
    Character * redChar;
    Character * blueChar;
    Label * label1 ;
    Label * label2 ;

public:
    Game(QString name1,QString name2);
public slots:
    void bombDestroyed(int x , int y);
protected:
    void keyPressEvent(QKeyEvent *event) override;
};



#endif //PLAYWITHFIRE_GAME_H
