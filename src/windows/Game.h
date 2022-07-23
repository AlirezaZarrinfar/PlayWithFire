#ifndef PLAYWITHFIRE_GAME_H
#define PLAYWITHFIRE_GAME_H
#include <QGraphicsView>
#include "../view/Character.h"
#include "../view/Label.h"

class Game : public QGraphicsView{
private:
    Character * redChar;
    Character * blueChar;
    Label * redLifeLabel ;
    Label * blueLifeLabel ;
    Label * redScoreLabel ;
    Label * blueScoreLabel ;
    Label * redBombsLabel ;
    Label * blueBombsLabel ;
    Label * bombRadiusLabel ;

    QString player1Name;
    QString player2Name;
public:
    Game(QString player1Name, QString player2Name, int lifes);
public slots:
    void bombDestroyed(int x , int y , QString bombSender);
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
};



#endif //PLAYWITHFIRE_GAME_H
