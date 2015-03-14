/** @file soapbars.h
    @brief This file contains the definitions to the soapbar class, a flying object for the player to collect.
           Contains public slots to move at different speeds and two soapbar objects, which have different pictures
*/

#ifndef SOAPBARS_H
#define SOAPBARS_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

/**
 * @class SoapBars
 * @brief The SoapBars class has soap bar pictures that move up the screen
 */
class SoapBars : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public slots:
    void moveup();
    void moveupFast();

public:
    SoapBars(QGraphicsItem * parent=0);
    SoapBars(int unused);
    ~SoapBars();
};

#endif // SOAPBARS_H
