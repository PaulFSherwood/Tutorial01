#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
    QMediaPlayer *getBulletSound() const;
    void setBulletSound(QMediaPlayer *value);

public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
    bool LEFT;
};

#endif // PLAYER_H
