#ifndef ROOM3_H
#define ROOM3_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class room3: public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT;
private:
    int row;
    int column;
    int last;
    int data[20][35];
    QString e;
public:

    room3(int [20][35],QString,QGraphicsItem * parent=0);

public slots:
    void move();
    void shoot();
};

#endif // ROOM3_H
