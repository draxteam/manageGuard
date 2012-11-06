#ifndef STAFFEDITWINDOW_H
#define STAFFEDITWINDOW_H

#include <QtGui>

class StaffEditWindow : public QDialog
{
    Q_OBJECT

public:
    StaffEditWindow();
    void openCreate();

public slots:
    void sl_addRowAssign();
    void sl_delRowAssign();

private:
    void m_addStyleSheets();

    // Fenêtre base
    QFormLayout *w_flMainStaffWindow;
    QHBoxLayout *w_hlButtonStaffWindow;
    QHBoxLayout *w_hlAssignStaffWindow;
    QLineEdit *w_leStaffName;
    QLineEdit *w_leStaffSecName;
    QComboBox *w_cbStaffGrade;
    QComboBox *w_cbStaffAssign;
    QPushButton *w_pbAddAssign;
    QPushButton *w_pbCreate;
    QPushButton *w_pbCancel;

    QVBoxLayout *w_vlAssignRow;
    int a_nbItem;
};

#endif // CREATECASERNEWINDOW_H
