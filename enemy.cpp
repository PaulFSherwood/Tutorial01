#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <QObject>
#include <stdlib.h>

Enemy::Enemy() : QObject(), QGraphicsRectItem()
{
    // Set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);
    // draw the rect
    setRect(0, 0, 100, 100);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move()
{
    // move Enemy down
    setPos(x() , y()+5);

    if (y() > 600) {
        scene()->removeItem(this);
        delete this;
        return;
    }
    if (pos().y()+rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
