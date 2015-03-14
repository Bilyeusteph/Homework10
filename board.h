/** @file board.h
    @brief This file contains the declarations to the board class. It contains the images
           for game play and the timers to start the moving peices.
 */

#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QPushButton>
#include "player.h"
#include "mainwindow.h"
#include "counters.h"
#include "clock.h"
#include <QTimer>

// forward declaration
class MainWindow;

/**
 * @class Board
 * @brief The Board class contains the set up of the board game, sets up the images and the timers that
 *        control the flying objects.
 */
class Board : public QGraphicsView{
    Q_OBJECT
    // make raindrops a class to access clock values
    friend class RainDrops;

public slots:
    void timerSlot();
    void startGame();

public:
    // Constructor
    Board(QWidget* parent=0);

    // the graphics scene
    QGraphicsScene* playScreen;

    // player
    Player* smallplayer;

    // fan push buttons
    QPushButton* leftbutton;
    QPushButton* rightbutton;

    // tally the objects collected
    Counters* numberCount;

    // count down clock
    Clock* clock;

    // Pictures when the player wins or loses.
    Player* deadPlayer;
    Player* freePlayer;

    // sets mainwindow
    void setMainWindow(MainWindow* main_window);

private:
    MainWindow* mw;
    // timers for the soap and rain drops
    QTimer* timer;
    QTimer* timer2;
    QTimer* timer3;
    QTimer* timer4;
    QTimer* controlTimers;
};

#endif // BOARD_H
