#ifndef STAFFEDITWINDOW_H
#define STAFFEDITWINDOW_H

#include <QtGui>
#include "includes/SubWidget.h"

class StaffEditWindow : public QDialog
{
    Q_OBJECT

public:
    StaffEditWindow();
    void openCreate();
    void openEdit();
    void openDelete();

public slots:
    void sl_addRowAssign();

private slots:
    void sl_delRowAssign(int itemNb);

private:
    void m_applyStyle();

    // Fenêtre base
    QFormLayout *w_flMainStaffWindow;
    QHBoxLayout *w_hlButtonStaffWindow;
    QHBoxLayout *w_hlAssignStaffWindow;
    QLineEdit *w_leStaffName;
    QLineEdit *w_leStaffSecName;
    QComboBox *w_cbStaffGrade;
    QComboBox *w_cbStaffAssign;
    QComboBox *w_cbRemoveStaff;
    QPushButton *w_pbAddAssign;
    QPushButton *w_pbOk;
    QPushButton *w_pbCancel;
    QVBoxLayout *w_vlAssignRow;
    AssignItem *w_assignItem;
    int a_nbItem;
    int a_nbItemStart;
};

#endif // CREATECASERNEWINDOW_H
