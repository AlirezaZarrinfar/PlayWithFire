#ifndef PLAYWITHFIRE_HOME_H
#define PLAYWITHFIRE_HOME_H
#include <QGraphicsView>
#include "../view/TextField.h"

class Home :public QGraphicsView{
Q_OBJECT
private:
    TextField *textField;
public:
  Home();

public slots:
    void onGameStart();


};


#endif //PLAYWITHFIRE_HOME_H
