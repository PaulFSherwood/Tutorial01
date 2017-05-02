#include "MyRect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"

#include "QDebug"

void MyRect::keyPressEvent(QKeyEvent *event)
{
    // qDebug() << "MyRect knows you pressed a gkey" << endl;
    if(event->key() == Qt::Key_Left)
    {
        // set LEFT movement to true
        LEFT = true;
    } else {
        LEFT = false;
    }
    if(event->key() == Qt::Key_Right)
    {
        // set Right movement to true
        RIGHT = true;
    } else {
        RIGHT = false;
    }
    if(event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }


    if (LEFT) {
        setPos(x()-10, y());
    }
    if (RIGHT) {
        setPos(x()+10, y());
    }
}
