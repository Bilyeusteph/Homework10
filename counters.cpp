/** @file counters.cpp
    @brief This file contains the declarations to the counters class. It updates the display of the number
           of rain drops and soap bars.
 */

#include "counters.h"
#include "ui_counters.h"
#include <QFont>

/** Constructor, initializes variables soaptally and raintally to 0.
 */
Counters::Counters(QGraphicsItem *parent): QGraphicsTextItem(parent), rainTally(0), soapTally(0){
    // display the count of raindrops, which starts at 0
    setPlainText(QString("Rain Drops: ") + QString::number(rainTally) +
                 QString("\nSoap: ") + QString::number(soapTally));
    setDefaultTextColor(Qt::gray);
    setFont(QFont("times",26));
    setPos(8,12);
}

/**  Displays and increments rain drop count
 */
void Counters::incrementDrops(){
    // display text
    setPlainText(QString("Rain Drops: ") + QString::number(++rainTally) +
                 QString("\nSoap: ") + QString::number(soapTally));

    // if the soap and rain are both 5, make the text blue
    if ((soapTally==8) && (rainTally==8)){
        setDefaultTextColor(Qt::blue);
    }

    // if rain tally is above 5, make the text red
    if (rainTally>8){
        setDefaultTextColor(Qt::red);
    }
}

/** Displays and increments soap count
 */
void Counters::incrementSoap(){
    // display text
    setPlainText(QString("Rain Drops: ") + QString::number(rainTally) +
                 QString("\nSoap: ") + QString::number(++soapTally));

    // if the soap and rain are both 8, make the text blue
    if ((soapTally==8) && (rainTally==8)){
        setDefaultTextColor(Qt::blue);
    }

    // if soap tally is above 8, make the text red
    if (soapTally>8){
        setDefaultTextColor(Qt::red);
    }
}

/** Resets rain and soap number to 0 and 0. This is made for the bonus drop.
 */
void Counters::resetScore(){
    rainTally =0;
    soapTally =0;
    setPlainText(QString("Rain Drops: ") + QString::number(rainTally) +
                 QString("\nSoap: ") + QString::number(soapTally));
    setDefaultTextColor(Qt::gray);
}
