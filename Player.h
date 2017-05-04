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
    void keyReleaseEvent(QKeyEvent * event);
    QMediaPlayer *getBulletSound() const;
    void setBulletSound(QMediaPlayer *value);

public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
    QSet<Qt::Key> keysPressed;
    bool m_bFirstRelease;
    int keysPressed;
};

#endif // PLAYER_H
