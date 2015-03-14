/** @file soapbars.cpp
    @brief This file contains the declarations to the soapbar class, which is an object that
           flies up the screen for the player to collect.
 */

#include "soapbars.h"
#include "ui_soapbars.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "board.h"
#include "counters.h"

extern Board* board;

/** Regular soapbar constructor. Has a soa bar picture and connects it with moveup slot to move up the screen.
 *      @param parent is to ensure the window takes control of this will deallocate it properly.
 */
SoapBars::SoapBars(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    //set random x position, where soap factory is
    int random_number = rand()%700;
    if ((random_number < 610) && (random_number > 160))
        setPos(random_number,390);
    else
        return;

    // setting raindrop image
    setPixmap(QPixmap(":/Images/soapbar.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move the soap every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveup()));

    // start the timer; the number controls how fast the soap bars move
    timer->start(16);
}

/** Special soap bar constructor same as a regular soap constructor, but with a different picture and slot function properties.
 *      @param int is unused, mearly to distinguish between constructors with no necessary parameters.
 */
SoapBars::SoapBars(int unused){
    //set random x position, where soap factory is
    int random_number = rand()%700;
    if ((random_number < 610) && (random_number > 160))
        setPos(random_number,390);
    else
        return;

    // setting raindrop image
    setPixmap(QPixmap(":/Images/evilSoap.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move the soap every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(moveupFast()));

    // start the timer; the number controls how fast the soap bars move
    timer->start(20);
}

/** SLOT: moves item up, makes item dissapear when collide with player,
 *        and increments count. For regular soap bar objects.
 */
void SoapBars::moveup(){
    // gets a list of all items currently colliding with this raindrop
    QList<QGraphicsItem*> collision = collidingItems();

    // if raindrop touches the player, remove the drop and register to ratiobar
    for (size_t i=0, n=collision.size(); i<n; ++i){
        if (typeid(*(collision[i]))==typeid(Player)){
            // increment soap tally if game hasn't reached end conditions
            if ((board->numberCount->soapTally<=8) && (board->numberCount->rainTally<=8)){
                if ((board->numberCount->soapTally!=8) && (board->numberCount->rainTally!=8)){
                board->numberCount->incrementSoap();
                }
            }
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    // otherwise, move the soapbars up
    setPos(x(),y()-2);

    //when the soapbars go out of the screen, destroy it
    if (pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}

/** SLOT: moves item up, makes item dissapear when collide with player,
 *        and resets count to 0,0 if collide with player. For evil soap objects
 */
void SoapBars::moveupFast(){

    // gets a list of all items currently colliding with this raindrop
    QList<QGraphicsItem*> collision = collidingItems();

    // if raindrop touches the player, remove the drop and register to ratiobar
    for (size_t i=0, n=collision.size(); i<n; ++i){
        if (typeid(*(collision[i]))==typeid(Player)){
            // reset score if game hasn't ended
            if ((board->numberCount->soapTally<=8) && (board->numberCount->rainTally<=8)){
                if ((board->numberCount->soapTally!=8) && (board->numberCount->rainTally!=8)){
                board->numberCount->resetScore();
                }
            }
            scene()->removeItem(this);
            delete this;
            return;

        }
    }

    // otherwise, move the soapbar up faster
    setPos(x(),y()-3);

    //when the soapbars go out of the screen, destroy it
    if (pos().y()<0){
        scene()->removeItem(this);
        delete this;
    }
}

// destructor
SoapBars::~SoapBars() {}
