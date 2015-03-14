/** @file mainwindow.h
    @brief This file contains the declarations to the opening window.
           It has the title and description of the game as well as
           a push button to start the game, opening up the boardgame window.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "board.h"
#include <QKeyEvent>
#include <QPixmap>

//forward declaration to use gameboard object to open when push button is clicked
class Board;

/**
 * @class MainWindow
 * @brief The MainWindow class is a window with text and buttons for the instructions and game.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setGameBoard(Board* game_board);
    QPushButton* start;

private:
    // board game
    Board* board;

    // objects to be placed onto the opening window
    QLabel* title;
    QLabel* description;
    QPixmap* boy;

    // final layout where all objects will be arranged
    QVBoxLayout* final_lay;

    // the object that the final layout will be passed to to be shown
    QWidget* openingw;
};

#endif // MAINWINDOW_H
