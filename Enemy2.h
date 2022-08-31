#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy2: public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT;
private:
    int row;
    int column;
    int last;
    int data[20][35];
    QString e;
public:

    Enemy2(int [20][35],QString,QGraphicsItem * parent=0);

public slots:
    void move();
    void shoot();
};

#endif // ENEMY2_H

