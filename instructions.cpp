/** @file instructions.cpp
    @brief This file contains the declarations to the instructions class. It is a window that opens
           when the player presses the instructions push button in the main window.
 */

#include "instructions.h"
#include "ui_instructions.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QPixmap>

/**
 * @brief Instructions::Instructions contains pictures of the falling objects of the game and briefly describes the game.
 * @param parent so the window that takes ownship of this will make sure it is deallocated properly.
 */
Instructions::Instructions(QWidget *parent) : QWidget(parent), ui(new Ui::Instructions){
    // displays text for the window
    QLabel* title=new QLabel("INSTRUCTIONS");
    title->setStyleSheet("qproperty-alignment: AlignCenter; font: 36pt\"Comic Sans\"; color: black");

    QLabel* instruct = new QLabel("Use the fans to blow him left and right by pressing the ON/OFF buttons\n"
                                 "If both fans are on, the bubble will be stagnant.\n");
    instruct->setAlignment(Qt::AlignCenter);
    instruct->setStyleSheet("font: 16pt\"Comic Sans\"; color: black");

    // add objects to the layout
    QVBoxLayout* text1 = new QVBoxLayout;
    text1->addWidget(title);
    text1->addWidget(instruct);

    // the following 5 blocks of code are to display pictures.
    QString regDrop = QString(":/Images/BigRegDrop.png");
    QString bonusDrop = QString(":/Images/BigBonusDrop.png");
    QString regSoap = QString(":/Images/BigRegSoap.png");
    QString evilSoap = QString(":/Images/BigEvilSoap.png");

    QPixmap* regD=new QPixmap(regDrop);
    QPixmap* bonusD=new QPixmap(bonusDrop);
    QPixmap* regS=new QPixmap(regSoap);
    QPixmap* evilS=new QPixmap(evilSoap);

    QLabel* rDrop = new QLabel;
    QLabel* bDrop = new QLabel;
    QLabel* rSoap = new QLabel;
    QLabel* eSoap = new QLabel;

    rDrop->setPixmap(*regD);
    bDrop->setPixmap(*bonusD);
    rSoap->setPixmap(*regS);
    eSoap->setPixmap(*evilS);

    rDrop->setAlignment(Qt::AlignCenter);
    bDrop->setAlignment(Qt::AlignCenter);
    rSoap->setAlignment(Qt::AlignCenter);
    eSoap->setAlignment(Qt::AlignCenter);

    QHBoxLayout* pictures = new QHBoxLayout;
    pictures->addWidget(rDrop);
    pictures->addWidget(rSoap);
    pictures->addWidget(bDrop);
    pictures->addWidget(eSoap);

    QLabel* text2 = new QLabel("  Regular Rain Drop        Regular Soap Bars       Bonus Rain Drop         Evil Soap Bars");
    text2->setStyleSheet("qproperty-alignment: AlignLeft; font: 18pt\"Comic Sans\"; color: black");

    QLabel* text3 = new QLabel("      +1 rain point                    +1 soap point              "
                               "+2 rain points &           Reset soap and rain\n            "
                               "                                                                     "
                               " + 2 soap points                  points to 0");
    text3->setStyleSheet("qproperty-alignment: AlignLeft; font: 16pt\"Comic Sans\"; color: black");

    QLabel* text4 = new QLabel("You have 70 seconds to save Bubble Boys life, HURRY!");
    text4->setStyleSheet("qproperty-alignment: AlignCenter; font: 18pt\"Comic Sans\"; color: red");

    QVBoxLayout* final_lay = new QVBoxLayout;
    final_lay->addLayout(text1);
    final_lay->addLayout(pictures);
    final_lay->addWidget(text2);
    final_lay->addWidget(text3);
    final_lay->addWidget(text4);

    // pass the layout to the widget
    setLayout(final_lay);
    setFixedSize(800, 400);
    setStyleSheet("background-color: white");
    setWindowTitle("Instructions");

    ui->setupUi(this);
}

// Destructor
Instructions::~Instructions(){
    delete ui;
}
