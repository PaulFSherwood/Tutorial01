#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set bullet sound
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/Explode.wav"));

    // set player graphic
    setPixmap(QPixmap(":/images/ship01.png"));

    keyLeft = keyRight = keySpace = false;
}

void Player::keyPressEvent(QKeyEvent *event){
    // TRYING DIFFERNT KEY PRESS EVENTS
//    // move the player left and right
//    if (event->key() == Qt::Key_Left){
//        if (pos().x() > 0)
//        setPos(x()-10,y());
//    }
//    if (event->key() == Qt::Key_Right){
//        if (pos().x() + 100 < 800)
//        setPos(x()+10,y());
//    }


    // find the right key that is pressed
    switch(event->key()) {
        case Qt::Key_Left:
            if (pos().x() > 0) {
                qDebug() << "keyLeft = true";
                keyLeft = true;
                break;
            }
        case Qt::Key_Right:
            if (pos().x() + 100 < 800) {
                keyRight = true;
                break;
            }

        case Qt::Key_Space:
            keySpace = true;
            break;

    }







    // shoot with the spacebar
    if (event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
        // play bulletsound
        if (bulletSound->state() == QMediaPlayer::PlayingState) {
            bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState) {
            bulletSound->play();
        }

    }
    //Player::keyPressEvent(event);
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Left:
            keyLeft = false;
            break;
        case Qt::Key_Right:
            keyRight = false;
            break;
        case Qt::Key_Space:
            keySpace = false;
            break;
    }

    // Player::keyReleaseEvent(event);
}



void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::movePlayer() {
    qDebug() << "in movePlayer";
    if (keyLeft){
        setPos(x()-10,y());
    }
    if (keyRight) {
        setPos(x()+10,y());
    }
    if (keySpace) {
        qDebug() << "space hit";
    }
}

class MyWidget : public QWidget
{
    Q_OBJECT
    public:
    MyWidget() {
        setFocusPolicy(Qt::StrongFocus); startTimer(1000/60);
    }
    void keyPressEvent(QKeyEvent *e) {
        keys[e->key()] = true; QWidget::keyPressEvent(e);
    }
    void keyReleaseEvent(QKeyEvent *e)
    {
        keys[e->key()] = false; QWidget::keyReleaseEvent(e);
    }
    void timerEvent(QTimerEvent *)
    {
        if(keys[Qt::Key_Up]) /* some game logic */;
    }
    private:
    QMap<int, bool> keys;
};
