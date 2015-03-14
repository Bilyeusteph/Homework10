#include "quitwidget.h"
#include "ui_quitwidget.h"

/** @class QuitWidget
    @brief asks to quit the widget. THIS CLASS IS UNUSED IN THE GAME
 */
QuitWidget::QuitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuitWidget)
{
    ui->setupUi(this);
}

QuitWidget::~QuitWidget()
{
    delete ui;
}
