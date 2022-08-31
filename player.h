#ifndef PLAYER_H
#define PLAYER_H


#include <QGraphicsPixmapItem>
#include <QKeyEvent>
class player :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int row;
    int column;
    int last;
    int data[20][35];
public:

    player(int [20][35]);
public slots:
    void keyPressEvent(QKeyEvent* event);
};
#endif // PLAYER_H

