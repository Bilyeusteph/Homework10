/** @file player.h
    @brief This file contains the declarations to the player class. It has public slots that allow him
           to move and collect the flying soap and rain drops.
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <Qtimer>
#include <QWidget>
#include <QLabel>
#include <QGraphicsTextItem>

/**
 * @class Player
 * @brief The Player class contains declarations public slots that allow him to move left and right and collect the
 *        soap and rain objects.
 */
class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public slots:
    void startraining();
    void soapflying();
    void bonusdrop();
    void evilsoap();
    void changeLeft();
    void changeRight();
    void moveleft();
    void moveright();

public:
    Player (QGraphicsItem * parent=0);

    // these constructors contain pictures when the player wins or loses
    Player (int unused);
    Player (int unused1, int unused2);

private:
    // if these = 0, then left button is OFF
    // if these =1, then left button is ON
    bool Rbutton_value;
    bool Lbutton_value;
    QTimer* Ltimer;
    QTimer* Rtimer;
    // displays when fan is ON or OFF
    QGraphicsTextItem* textOnL;
    QGraphicsTextItem* textOffL;
    QGraphicsTextItem* textOnR;
    QGraphicsTextItem* textOffR;
};

#endif // PLAYER_H
