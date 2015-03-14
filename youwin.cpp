/** @file youwin.cpp
    @brief This file contains the declarations to the youwin class, which is a window to tell the player they won.
 */

#include "youwin.h"
#include "ui_youwin.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QString>
#include <QPixmap>

/**
 * @brief YouWin::YouWin is a window that tells the player they won.
 * @param parent so the widget owner will deallocate this constructor properly.
 */
YouWin::YouWin(QWidget *parent) : QWidget(parent), ui(new Ui::YouWin){
    // displays title and description of the game
    QLabel* words=new QLabel("YOU WIN");
    words->setStyleSheet("qproperty-alignment: AlignCenter; font: 22pt\"Comic Sans\"; color: crimson");

    QLabel* words2=new QLabel("He's free!");
    words2->setStyleSheet("qproperty-alignment: AlignCenter; font: 16pt\"Comic Sans\"; color: black");

    QString boystring = QString(":/Images/FreeBoy.png");
    QPixmap* boy=new QPixmap(boystring);
    QLabel* boyLabel = new QLabel;
    boyLabel->setPixmap(*boy);
    boyLabel->setAlignment(Qt::AlignCenter);

    // add objects to the layout
    QVBoxLayout* final_lay = new QVBoxLayout;
    final_lay->addWidget(words);
    final_lay->addWidget(words2);
    final_lay->addWidget(boyLabel);

    // pass the layout to the widget
    this->setLayout(final_lay);
    this->setFixedSize(280, 320);
    this->setStyleSheet("background-color: azure");

    ui->setupUi(this);
}

YouWin::~YouWin(){
    delete ui;
}
