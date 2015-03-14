/** @file instructions.h
    @brief This file contains the declarations to the instructions class. It is a window that opens when
           an instructions push button is clicked on the main window.
 */

#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QWidget>

namespace Ui {
class Instructions;
}

/**
 * @class Instructions
 * @brief The Instructions class contains only a constructor, which is a window that contains the instructions
 *        of the game.
 */
class Instructions : public QWidget
{
    Q_OBJECT

public:
    // Constructor
    explicit Instructions(QWidget *parent = 0);
    ~Instructions();

private:
    Ui::Instructions *ui;
};

#endif // INSTRUCTIONS_H
