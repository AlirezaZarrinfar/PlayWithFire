#ifndef PLAYWITHFIRE_SCOREBOARD_H
#define PLAYWITHFIRE_SCOREBOARD_H


#include <QGraphicsView>

class Scoreboard : public QGraphicsView{
public:
    Scoreboard(int redScore , int blueScore , QString name1 , QString name2);
};


#endif //PLAYWITHFIRE_SCOREBOARD_H
