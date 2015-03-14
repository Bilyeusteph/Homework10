/** @author Stephanie Bilyeu
 *  @date March 13, 2015
 *  @file main.cpp
 *  @brief This file creates a board and opens the mainwindow to the game.
 */

#include "mainwindow.h"
#include <QApplication>
#include "board.h"

Board* board;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a window
    MainWindow* window = new MainWindow;

    // create a board
    board=new Board;

    // connect the board and window and vice versa
    board->setMainWindow(window);
    window->setGameBoard(board);

    // show the window
    window->show();

    return a.exec();
}
