#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Enemy: public QObject, public QGraphicsPixmapItem  {
    Q_OBJECT;
private:
    int row;
    int column;
    int last;
    int data[20][35];
    QString e;
public:

    Enemy(int [20][35],QString, QGraphicsItem * parent=0);

public slots:
    void move();
    void shoot();
};

#endif // ENEMY_H
