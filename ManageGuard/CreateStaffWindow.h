#ifndef CREATESTAFFWINDOW_H
#define CREATESTAFFWINDOW_H

#include <QtGui>

class CreateStaffWindow : public QDialog
{

public:
    CreateStaffWindow();

private:
    void m_addStyleSheets();

    QFormLayout *w_flMainStaffWindow;
    QHBoxLayout *w_hlStaffWindow;
    QLineEdit *w_leStaffName;
    QLineEdit *w_leStaffSecName;
    QComboBox *w_cbStaffGrade;
    QPushButton *w_pbCreate;
    QPushButton *w_pbCancel;

};

#endif // CREATECASERNEWINDOW_H
