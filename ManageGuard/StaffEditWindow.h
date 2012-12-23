#ifndef STAFFEDITWINDOW_H
#define STAFFEDITWINDOW_H

#include <QtGui>
#include "includes/SubWidget.h"
#include "TMember.h"
#include "Member.h"

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
    void sl_createMember();
    void sl_loadMember();
    void sl_editMember();
    void sl_deleteMember();
    void sl_backupName(QString name);
    void sl_backupFirstName(QString firstName);
    void sl_backupDate(int date);
    void sl_backupGrade(int grade);
    void sl_backupPictures(QString file);

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

    QString a_nameTemp;
    QString a_firstNameTemp;
    int a_dateTemp;
    int a_gradeTemp;
    bool a_picturesTemp;
    QString a_cheminPictureTemp;
    QList <QString> a_listMember;
    QDirIterator *a_compteur;
    TMember *a_memberTemp;
    Member *a_member;
    bool a_existMember;
};

#endif // CREATECASERNEWINDOW_H
