/** @file board.cpp
    @brief This file contains the definitions to the board class. It creates a player and sets up
           the game by adding the display and the flying soap and rain peices around.
 */

#include "board.h"
#include "ui_board.h"
#include "player.h"
#include "raindrops.h"
#include "counters.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QImage>
#include <QString>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>

/** Board constructor. Sets up game play.
 *      @param parent to control ownership to deallocate properly.
 */
Board::Board(QWidget *parent){
    //background
    playScreen = new QGraphicsScene(this);
    playScreen->setSceneRect(0,0,800,500);
    setBackgroundBrush(QBrush(QImage(":/Images/background.png")));

    // set properties of the window
    setScene(playScreen);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,500);

    // create bubble boy and add him to the playScreen
    smallplayer = new Player();
    smallplayer->setPos(300, 270);
    smallplayer->setFlag(QGraphicsItem::ItemIsFocusable);
    smallplayer->setFocus();
    playScreen->addItem(smallplayer);

    // create left button
    leftbutton = new QPushButton("ON / OFF");
    leftbutton->setFixedSize(100,26);
    leftbutton->setStyleSheet("background-color: black; color: bisque");

    // create right button
    rightbutton = new QPushButton("ON / OFF");
    rightbutton->setFixedSize(100,26);
    rightbutton->setStyleSheet("background-color: black; color: bisque");

    // create clock
    clock = new Clock(this, 1, 10);
    clock->setFixedSize(130,50);
    QVBoxLayout* clocklay=new QVBoxLayout;
    clocklay->addWidget(clock,0,Qt::AlignRight);

    // put buttons on the window in appropriate place
    QGridLayout* buttonLayout = new QGridLayout;
    buttonLayout->addWidget(leftbutton, 1,0,Qt::AlignLeft);
    buttonLayout->addWidget(rightbutton, 1, 20,Qt::AlignRight);
    buttonLayout->setContentsMargins(5, 640, 5, 750);

    // add clock and button layout to screen
    clocklay->addLayout(buttonLayout);
    setLayout(clocklay);

    // create/display/update rain and soap numbers
    numberCount = new Counters();
    playScreen->addItem(numberCount);

    // start raining
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), smallplayer, SLOT(startraining()));

    // start soap flying
    timer2 = new QTimer(this);
    QObject::connect(timer2, SIGNAL(timeout()), smallplayer, SLOT(soapflying()));

    // start bonus drops
    timer3 = new QTimer(this);
    QObject::connect(timer3, SIGNAL(timeout()), smallplayer, SLOT(bonusdrop()));

    // start evil soap
    timer4 = new QTimer(this);
    QObject::connect(timer4, SIGNAL(timeout()), smallplayer, SLOT(evilsoap()));

    // connect push buttons with bubble boy linear movement
    QObject::connect(leftbutton, SIGNAL(clicked()), smallplayer, SLOT(changeLeft()));
    QObject::connect(rightbutton,SIGNAL(clicked()), smallplayer, SLOT(changeRight()));

    // connects a timer to timerSlot, which checks if ending or winning conditions have been met
    controlTimers = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(timerSlot()));
}

/**
 * @brief Board::startGame starts all the timers of the flying objects and the clock countdown
 */
void Board::startGame(){
    timer->start(1491);
    timer2->start(1576);
    timer3->start(4539);
    timer4->start(4305);
    clock->timer->start(1000);
}

/**
 * @brief Board::timerSlot stops all timers of flying objects and the clock when end game conditions
 *               are satisfied. Also removes the player object from the screen and displays a free or dead figure.
 */
void Board::timerSlot(){
    // if soap or rain goes over 8 or time runs out, player loses.
    if (((numberCount->soapTally > 8) || (numberCount->rainTally > 8)) ||
            (((clock->timeValue->second()==0) && clock->timeValue->minute()==0))){
         playScreen->removeItem(smallplayer);
         timer->stop();
         timer2->stop();
         timer3->stop();
         timer4->stop();
         clock->timer->stop();
         deadPlayer = new Player(0, 0);
         deadPlayer->setPos(320, 220);
         playScreen->addItem(deadPlayer);
    }

    // if soap and rain drops are each 8, player wins
    if ((numberCount->soapTally == 8) && (numberCount->rainTally == 8)){
         playScreen->removeItem(smallplayer);
         timer->stop();
         timer2->stop();
         timer3->stop();
         timer4->stop();
         clock->timer->stop();
         freePlayer = new Player (0);
         freePlayer->setPos(320,220);
         playScreen->addItem(freePlayer);
    }
}

/**
 * @brief GameBoard::setMainWindow opens the main window and sets up a Board object
 * @param main_window is the main window object
 */
void Board::setMainWindow(MainWindow *main_window){
    mw=main_window;
}
