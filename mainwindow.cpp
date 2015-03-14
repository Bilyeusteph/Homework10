/** @file mainwindow.cpp
    @brief This file contains the declarations to the mainwindow class. It is the opening window that
           contains pushbuttons for the instructions and to start the game.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "instructions.h"
#include "board.h"
#include <QString>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    // displays title and description of the game
    title=new QLabel("Bubble Boy");
    title->setStyleSheet("color: firebrick; font : 34pt; qproperty-alignment: AlignCenter");
    description=new QLabel("Too much water and he drowns.\nToo much soap and he's poisoned.\nCollect"
                          " 8 soap bars & 8 water drops\nto pop the bubble before time's up."
                           "\nCareful, you only get ONE chance!");
    description->setStyleSheet("qproperty-alignment: AlignCenter; font: 14pt\"Comic Sans\"; color: crimson");

    // push button to begin the game
    start=new QPushButton("Click Here To\nSave Him!");
    start->setStyleSheet("background-color: palevioletred; font: bold;");
    start->setMaximumSize(150,50);
    start->setMinimumSize(150,50);

    // push button for instructions
    QPushButton* instructB = new QPushButton("Instructions");
    instructB->setStyleSheet("background-color: palevioletred");
    instructB->setMaximumSize(150,50);
    instructB->setMinimumSize(150,50);
    Instructions* instructWindow = new Instructions;
    // connect instructions window with clicking the instructions button
    QObject::connect(instructB, SIGNAL(clicked()), instructWindow, SLOT(show()));

    QHBoxLayout* buttonlay = new QHBoxLayout;
    buttonlay->addWidget(instructB);
    buttonlay->addWidget(start);

    QString boystring = QString(":/Images/bigbubble.png");
    boy=new QPixmap(boystring);
    QLabel* boyLabel = new QLabel;
    boyLabel->setPixmap(*boy);
    boyLabel->setAlignment(Qt::AlignCenter);

    // add objects to the layout
    final_lay = new QVBoxLayout;
    final_lay->addWidget(title);
    final_lay->addWidget(boyLabel);
    final_lay->addWidget(description);
    final_lay->addLayout(buttonlay);

    // pass the layout to the widget
    openingw = new QWidget;
    openingw->setLayout(final_lay);
    this->setCentralWidget(openingw);
    this->setFixedSize(340, 350);
    this->setStyleSheet("background-color: azure");
}

/** @brief Connects start push button with the gameboard object board to be displayed
    @param game_board is the gameboard object to be displayed
 */
void MainWindow::setGameBoard(Board* game_board){
    board=game_board;
    QObject::connect(start, SIGNAL(clicked()), board, SLOT(show()));
    QObject::connect(start, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(start, SIGNAL(clicked()), board, SLOT(startGame()));
}
