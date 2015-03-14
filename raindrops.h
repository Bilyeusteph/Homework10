/** @file raindrops.h
    @brief This file contains the definitions to the raindrops class, a flying object for the player to collect.
           Contains public slots to move at different speeds and two raindrop objects, which have different pictures.
 */

#ifndef RAINDROPS_H
#define RAINDROPS_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "board.h"

/**
 * @class RainDrops
 * @brief The RainDrops class has rain drop pictures that move down the screen.
 */
class RainDrops : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public slots:
    void movedown();
    void movedownFast();

public:
    RainDrops(QGraphicsItem * parent=0);
    RainDrops(int unused);
};

#endif // RAINDROPS_H
