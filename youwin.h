/** @file youwin.h
    @brief This file contains the definitions to the youwin class, which is a window to tell the player they won.
 */

#ifndef YOUWIN_H
#define YOUWIN_H

#include <QWidget>

namespace Ui {
class YouWin;
}

/** @class YouWin
    @brief Is an independent you win window. UNUSED IN THIS GAME
 */
class YouWin : public QWidget
{
    Q_OBJECT

public:
    explicit YouWin(QWidget *parent = 0);
    ~YouWin();

private:
    Ui::YouWin *ui;
};

#endif // YOUWIN_H
