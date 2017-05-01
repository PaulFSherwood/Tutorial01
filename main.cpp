#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
 * Basic knowledge of c++ (pointer and memory management
 * Very basic knowledge of Qt (widget)
 * Tutorial Topics
 * -QGraphicsScene
 * -QGraphicsItem (QGraphcisRectItem)
 * -QGraphicsView
 * =====================================================
 * events (kePressEvent(0 and QKeyEvent)
 * event propogation system
 * QDebug
 * =====================================================
 * QTimer
 * signals and slots (connect function)
 * QObject and Q_OBJECT macro
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // Create an item to put into the scene
    MyRect * rect = new MyRect();
    rect->setRect(10, 10, 100, 100);

    // add the item to the scene
    scene->addItem(rect);

    // make the item focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);
    //    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    return a.exec();
}
