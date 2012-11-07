#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QtGui>

// Classe AssignItem
class AssignItem : public QWidget
{
    Q_OBJECT

public:
    AssignItem();

private:
    QLabel *w_lAssign;
    QPushButton *w_pbDelAssign;
    QHBoxLayout *w_hlAssignBox;

};

#endif // ASSIGNITEM_H
