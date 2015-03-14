/** @file quitwidget.h
    @brief THIS FILE IS UNUSED
 */

#ifndef QUITWIDGET_H
#define QUITWIDGET_H

#include <QWidget>

namespace Ui {
class QuitWidget;
}

/**
 * @class QuitWidget
 * @brief The QuitWidget class IS UNUSED IN THIS GAME
 */
class QuitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuitWidget(QWidget *parent = 0);
    ~QuitWidget();

private:
    Ui::QuitWidget *ui;
};

#endif // QUITWIDGET_H
