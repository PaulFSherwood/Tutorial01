#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>

class MyRect: public QGraphicsRectItem {
public:
    void keyPressEvent(QKeyEvent * event);
private:
    bool LEFT = false;
    bool RIGHT = false;
};

#endif // MYRECT_H
