#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QtGui>

// Classe AssignItem
class AssignItem : public QWidget
{
    Q_OBJECT

public:
    AssignItem();
    virtual ~AssignItem();
    void createRow(int rowNb);

signals:
    void si_removeAssignRow(int itemNb);

private slots:
    void sl_removeAssignRow();

private:
    QLabel *w_lAssign;
    QPushButton *w_pbDelAssign;
    QHBoxLayout *w_hlAssignBox;
    int a_Nb;

};

#endif // ASSIGNITEM_H
