#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class MyRect : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    bool LEFT = false;
    bool RIGHT = false;
};

#endif // MYRECT_H
