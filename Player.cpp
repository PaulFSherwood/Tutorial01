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
            // if (pos().x() > 0) {
            keyLeft = true;
            break;
            // }
        case Qt::Key_Right:
            // if (pos().x() + 100 < 800) {
            keyRight = true;
            break;
            // }
        case Qt::Key_Space:
            keySpace = true;
            break;
    }


//    // shoot with the spacebar
//    if (event->key() == Qt::Key_Space){
//        // create a bullet
//        Bullet * bullet = new Bullet();
//        bullet->setPos(x(),y());
//        scene()->addItem(bullet);
//        // play bulletsound
//        if (bulletSound->state() == QMediaPlayer::PlayingState) {
//            bulletSound->setPosition(0);
//        }
//        else if (bulletSound->state() == QMediaPlayer::StoppedState) {
//            bulletSound->play();
//        }

//    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if (!event->isAutoRepeat()) {
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
    }

}



void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

void Player::movePlayer() {
    if (keyLeft && keySpace) {
        if (pos().x() > 0) {
            setPos(x()-10,y());
        }
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
    else if (keyRight && keySpace) {
        if (pos().x() + 100 < 800) {
            setPos(x()+10,y());
        }
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
    else if (keyLeft) {
        if (pos().x() > 0) {
            setPos(x()-10,y());
        }
    }
    else if (keyRight) {
        if (pos().x() + 100 < 800) {
            setPos(x()+10,y());
        }
    }
    else if (keySpace) {
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
}
