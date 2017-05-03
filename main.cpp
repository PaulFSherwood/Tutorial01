#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "Player.h"
#include "Game.h"

/*
 * Basic knowledge of c++ (pointer and memory management
 * Very basic knowledge of Qt (widget)
 * Tutorial Topics
 * -QGraphicsScene
 * -QGraphicsItem (QGraphcisRectItem)
 * -QGraphicsView
 * =====================================================
 * events (kePressEvent(0 and QKeyEvent)
 * event propogation system (the order that event is pass
 *                           ed around)
 * QDebug
 * =====================================================
 * QTimer
 * signals and slots (connect function)
 * QObject and Q_OBJECT macro
 */
/*
 * -parents
 * -QGraphicsTextItem, setPlainText(), setFont(), setDefaultTextColor()
 */
Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
