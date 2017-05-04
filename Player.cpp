#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsRectItem(parent){
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/Explode.wav"));
    m_bFirstRelease = false;
    keysPressed = 0;
}

void Player::keyPressEvent(QKeyEvent *event){
    m_bFirstRelease = true;
    keysPressed += event->key();
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
void Player::keyReleaseEvent(QKeyEvent *event){
    if(m_bFirstRelease) {
        processMultiKeys(keysPressed);
    }
    m_bFirstRelease = false;
    keysPressed -= event->key();
}
void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

QMediaPlayer *Player::getBulletSound() const
{
    return bulletSound;
}

void Player::setBulletSound(QMediaPlayer *value)
{
    bulletSound = value;
}
