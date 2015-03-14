/** @file youlose.cpp
    @brief This file contains the declarations to the youlose class, which is a window to tell the player they lost.
 */

#include "youlose.h"
#include "ui_youlose.h"
#include <QLabel>
#include <QVBoxLayout>

/**
 * @brief YouLose::YouLose is a window that tells the player they lost.
 * @param parent so the widget owner will deallocate this constructor properly.
 */
YouLose::YouLose(QWidget *parent) : QWidget(parent), ui(new Ui::YouLose){
        // displays title and description of the game
        QLabel* words=new QLabel("YOU LOSE");
        words->setStyleSheet("qproperty-alignment: AlignCenter; font: 20pt\"Comic Sans\"; color: azure");

        QLabel* words2=new QLabel("He's dead!");
        words2->setStyleSheet("qproperty-alignment: AlignCenter; font: 16pt\"Comic Sans\"; color: black");

        QString boystring = QString(":/Images/DeadBoy.png");
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
        this->setStyleSheet("background-color: crimson");

        ui->setupUi(this);
}

// destructor
YouLose::~YouLose(){
    delete ui;
}
