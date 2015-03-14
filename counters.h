/** @file counters.h
    @brief This file contains the declarations to the counters class. It contains the count for how
           many raindrops and soap bars are collected by the player. The functions perform the increment.
 */

#ifndef COUNTERS_H
#define COUNTERS_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>

/**
 * @class Counters
 * @brief The Counters class keeps count of how many rain and soap objects are collected from the player.
 */
class Counters: public QGraphicsTextItem{

public:
    Counters(QGraphicsItem* parent=0);
    void incrementDrops();
    void incrementSoap();
    void resetScore();

    // keep track of the collected objects
    int rainTally;
    int soapTally;
};

#endif // COUNTERS_H
