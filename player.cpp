/** @file player.cpp
 *  @brief contains definitions to player class constructor and functions. Creates a picture of a
 *         bubble that flies left and right collecting objects
 */

#include "Player.h"
#include "raindrops.h"
#include "soapbars.h"
#include <QGraphicsScene>
#include <QLabel>
#include <cmath>

/** Constructor, creates the bubble boy picture
 *      @param parent is to ensure the window takes control of this will deallocate it properly.
 */
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent), Rbutton_value(0), Lbutton_value(0){
    Ltimer = new QTimer(this);
    // connect moveright with the timer
    connect(Ltimer,SIGNAL(timeout()),this,SLOT(moveright()));

    Rtimer = new QTimer(this);
    // connect moveleft with a timer
    connect(Rtimer,SIGNAL(timeout()),this,SLOT(moveleft()));

    // small bubble boys' picture
    setPixmap(QPixmap(":/Images/player.png"));

    // displays when a fan is on and off
    textOnL = new QGraphicsTextItem("ON");
    textOnL->setPos(60,180);
    textOnL->setFont((QFont("times",18)));
    textOnL->setDefaultTextColor(Qt::blue);
    textOffL = new QGraphicsTextItem("OFF");
    textOffL->setPos(60, 180);
    textOffL->setFont((QFont("times",18)));
    textOffL->setDefaultTextColor(Qt::red);

    textOnR = new QGraphicsTextItem("ON");
    textOnR->setPos(700,180);
    textOnR->setFont((QFont("times",18)));
    textOnR->setDefaultTextColor(Qt::blue);
    textOffR = new QGraphicsTextItem("OFF");
    textOffR->setPos(700, 180);
    textOffR->setFont((QFont("times",18)));
    textOffR->setDefaultTextColor(Qt::red);
}

/**
 * @brief Player::Player creates a picture for when the player wins
 * @param unused to differentiate between constructors
 */
Player::Player (int unused){
    setPixmap(QPixmap(":/Images/FreeBoy.png"));
}

/**
 * @brief Player::Player creates a picture for when the player dies
 * @param unused1 to differentiate between constructors
 * @param unused2 to differentiate between constructors
 */
Player::Player (int unused1, int unused2){
    setPixmap(QPixmap(":/Images/DeadBoy.png"));
}

/**
 * @brief Player::startraining SLOT creates raindrop objects (the pixmap picture)
 *        and adds them to the scene.
 */
void Player::startraining(){
    RainDrops* raindrop = new RainDrops();
    scene()->addItem(raindrop);
}

/**
 * @brief Player::soapflying SLOT creates soap bar objects (the pixmap picture)
 *        and adds them to the scene.
 */
void Player::soapflying(){
    SoapBars* soapbar = new SoapBars;
    scene()->addItem(soapbar);
}

/**
 * @brief Player::bonusdrop SLOT creates a special bonus rain drop object
 */
void Player::bonusdrop(){
    int x =0;
    RainDrops* bonusdrop = new RainDrops(x);
    scene()->addItem(bonusdrop);
}

/**
 * @brief Player::evildrop SLOT creates an evil soap bar object
 */
void Player::evilsoap(){
    int x =0;
    SoapBars* evilSoap = new SoapBars(x);
    scene()->addItem(evilSoap);
}

/**
 * @brief Player::changeLeft SLOT moves the players position based on which fan is turned on.
 *                If both are turned on, is acts as if both fans are off.
 */
void Player::changeLeft(){
    // change the bool value to opposite of what it is
    Lbutton_value = !Lbutton_value;

    // adds the ON or OFF flag according to is the left fan is on or off
    if (Lbutton_value ==1){
        scene()->removeItem(textOffL);
        scene()->addItem(textOnL);
    }
    else{
        scene()->removeItem(textOnL);
        scene()->addItem(textOffL);
    }

    // only changes position if the left button is "on" and right button is "off"
    if ((Lbutton_value ==1)&&(Rbutton_value==0)){
        // how fast the player object moves
        Ltimer->start(32);
    }

    // stops the timer if both values are one (both fans on)
    else if ((Lbutton_value ==1)&&(Rbutton_value==1)){
        Rtimer->stop();
    }

    // stars the right fan if it is the only fan on
    else if ((Lbutton_value ==0)&&(Rbutton_value==1)){
        Rtimer->start(32);
    }

    // stops the timer when the left fan is off, i.e. when Lbutton_value=0
    else
        Ltimer->stop();
}

/**
 * @brief Player::changeRight SLOT moves the players posiiton based on which fan is turned on.
 *                            If both are turned on, it acts if both fans are off.
 */
void Player::changeRight(){
    // change the bool value to opposite of what it is
    Rbutton_value = !Rbutton_value;

    // adds the ON and OFF flag according to if the right fan is on or off
    if (Rbutton_value ==1){
        scene()->removeItem(textOffR);
        scene()->addItem(textOnR);
    }
    else{
        scene()->removeItem(textOnR);
        scene()->addItem(textOffR);
    }

    // only changes position if the left button is "off" and right button is "on"
    if ((Lbutton_value ==0)&&(Rbutton_value==1)){
        // how fast the player object moves
        Rtimer->start(32);
    }

    // stops the timer if both values are one (both fans on)
    else if ((Lbutton_value ==1)&&(Rbutton_value==1)){
        Ltimer->stop();
    }

    // starts the left fan if it is the only one on
    else if ((Lbutton_value ==1)&&(Rbutton_value==0)){
        Ltimer->start(32);
    }

    // stops the timer when the right fan is off, i.e. when Rbutton_value=0
    else
        Rtimer->stop();
}

/**
 * @brief Player::moveright SLOT changes the x coordinate of the player, moving
 *        it to the right
 */
void Player::moveright(){
        if (pos().x() < 610){
            if (pos().y() > 200){
                int positionX = pos().x();
                double pos = sin(positionX);
                if (positionX%2 == 0)
                    setPos(x()+3, y()+pos);
                else
                    setPos(x()+3, y()-pos);
            }
            else
                setPos(x()+3, y()+4);
         }
}

/**
 * @brief Player::moveleft SLOT changes the x coordinate of the player, moving
 *        it to the left
 */
void Player::moveleft(){
        if (pos().x() > 160){
            if (pos().y()<400){
                int positionX = pos().x();
                double pos = sin(positionX);

                if (positionX%2 == 0)
                    setPos(x()-3, y()+pos);
                else
                    setPos(x()-3, y()-pos);
            }
            else
                setPos(x()-3, y()-4);
         }
}
