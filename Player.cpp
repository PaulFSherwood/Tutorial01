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
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    if (event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+10,y());
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space){
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

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
