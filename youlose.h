/** @file youlose.h
    @brief This file contains the definitions to the youlose class, which is a window to tell the player they lost.
 */

#ifndef YOULOSE_H
#define YOULOSE_H

#include <QWidget>

namespace Ui {
class YouLose;
}

/** @class YouLose
    @brief Opens a you lose window. THIS IS UNUSED IN THIS GAME
 */
class YouLose : public QWidget
{
    Q_OBJECT

public:
    explicit YouLose(QWidget *parent = 0);
    ~YouLose();

private:
    Ui::YouLose *ui;
};

#endif // YOULOSE_H
