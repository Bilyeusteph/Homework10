/** @file raindrops.cpp
    @brief This file contains the declarations to the raindrop class, which is an object that
           flies down the screen for the player to collect.
 */

#include "raindrops.h"
#include "ui_raindrops.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include <stdlib.h>
#include "board.h"
#include "counters.h"

extern Board* board;

/** Regular drop constructor. Has a rain drop picture and connects it with movedown slot to move down the screen.
 *      @param parent is to ensure the window takes control of this will deallocate it properly.
 */
RainDrops::RainDrops(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent){
    //set random x position, and where clouds are
    int random_number = rand()%700;
    // only drops raindrops if within the x coordinates of the clouds
    if ((random_number < 610) && (random_number > 160))
            setPos(random_number,85);
    else
        return;

    // setting raindrop image
    setPixmap(QPixmap(":/Images/regulardrop.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the soap every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movedown()));

    // start the timer, the number controls the speed of the drops
    timer->start(16);
}

/** Bonus drop constructor, same as a regular drop constructor, but with a different picture and moves faster.
 *      @param int is unused, mearly to distinguish between constructors with no necessary parameters.
 */
RainDrops::RainDrops(int unused){
    //set random x position, and where clouds are
    int random_number = rand()%700;
    // only drops raindrops if within the x coordinates of the clouds
    if ((random_number < 610) && (random_number > 160))
            setPos(random_number,85);
    else
        return;

    // setting raindrop image
    setPixmap(QPixmap(":/Images/bonusDrop.png"));
    setTransformOriginPoint(50,50);

    // make/connect a timer to move() the soap every so often
    QTimer* timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(movedownFast()));

    // start the timer, the number controls the speed of the drops
    timer->start(20);
}

/** SLOT: Moves regular drops down and increaments one point
 */
void RainDrops::movedown(){
    // gets a list of all items currently colliding with this raindrop
    QList<QGraphicsItem*> collision = collidingItems();

    // if raindrop touches the player, remove the drop and register to ratiobar
    for (size_t i=0, n=collision.size(); i<n; ++i){
        if (typeid(*(collision[i]))==typeid(Player)){
           // increment Rain Drop tally if player is not over drop count
           if ((board->numberCount->soapTally<=8) && (board->numberCount->rainTally<=8)){
               if ((board->numberCount->soapTally!=8) && (board->numberCount->rainTally!=8)){
                board->numberCount->incrementDrops();
               }
           }
           scene()->removeItem(this);
           delete this;
           return;
        }
    }

    // otherwise, move the raindrop down
    setPos(x(),(y()+2));

    //when the raindrop goes out of the screen, destroy it
    if (pos().y()>500){
        scene()->removeItem(this);
        delete this;
        return;
    }
}

/** SLOT: For the bonus drop. Moves fast and increments each set of points 2 times.
 */
void RainDrops::movedownFast(){
    // gets a list of all items currently colliding with this raindrop
    QList<QGraphicsItem*> collision = collidingItems();

    // if raindrop touches the player, remove the drop and register to ratiobar
    for (size_t i=0, n=collision.size(); i<n; ++i){
        if (typeid(*(collision[i]))==typeid(Player)){
           // increment Rain Drop and Soap Bar tally 2 times if the tally's are below 8
           if ((board->numberCount->soapTally<=8) && (board->numberCount->rainTally<=8)){
               if ((board->numberCount->soapTally!=8) && (board->numberCount->rainTally!=8)){
                 board->numberCount->incrementDrops();
                 board->numberCount->incrementSoap();
                 board->numberCount->incrementDrops();
                 board->numberCount->incrementSoap();
               }
           }
           scene()->removeItem(this);
           delete this;
           return;
        }
    }

    // otherwise, move the raindrop down quickly
    setPos(x(),(y()+4));

    //when the raindrop goes out of the screen, destroy it
    if (pos().y()>500){
        scene()->removeItem(this);
        delete this;
    }
}
