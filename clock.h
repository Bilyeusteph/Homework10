/** @file clock.h
    @brief This file contains the declarations and definitions, defined inline to the Clock class.
           Contains a countdown that looks like a digital clock.
 */

#ifndef CLOCK_H
#define CLOCK_H

#include <QLCDNumber>
#include <QTimer>
#include <QTime>

/**
 * @class Clock
 * @brief The Clock class is defined inline. Makes board a friend to access the minutes and seconds left on the clock.
 *        The constructor allows you to create a clock with the minutes and seconds as the parameters passed in.
 */
class Clock: public QLCDNumber{
  Q_OBJECT

// declare Board as a friend to access private variables
friend class Board;

public slots:

/**
 * @brief setDisplay SLOT: If time is up, clock stops.
 */
void setDisplay(){
    this->timeValue->setHMS(0,this->timeValue->addSecs(-1).minute(),this->timeValue->addSecs(-1).second());
    this->display(this->timeValue->toString());
    if ((timeValue->second())==0 && (timeValue->minute())==0){
             timer->stop();
    }
}

public:

/**
 * @brief Clock displays a digital looking count down timer
 * @param minutes how many minutes the clock should start counting down from
 * @param seconds how many seconds the clock should start counting down from
 */
Clock(QWidget * parentWidget,int minutes,int seconds){
    timer = new QTimer(this);
    timeValue = new QTime(0,minutes,seconds);
    this->setParent(parentWidget);
    this->display(timeValue->toString());
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(setDisplay()));
}


    QTimer* timer;
    QTime*  timeValue;
};

#endif // CLOCK_H
