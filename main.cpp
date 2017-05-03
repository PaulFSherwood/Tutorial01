#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "MyRect.h"
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

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    MyRect * player = new MyRect();
    player->setRect(10, 10, 100, 100);

    // add the item to the scene
    scene->addItem(player);

    // make the item focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();  // hey rect you are the focused item
                       // and can get keyboard events

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);
    //    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800, 600);
    scene->setSceneRect(0,0, 800, 600);

    player->setPos(view->width()/2, view->height()-player->rect().height());

    // Spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    return a.exec();
}
