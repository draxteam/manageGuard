#ifndef CASERNEEDITWINDOW_H
#define CASERNEEDITWINDOW_H

#include <QtGui>
#include <QObject>
#include "Caserne.h"
#include "TCaserne.h"
#include <QList>
#include <QDirIterator>
#include <iostream>
#include <fstream>

class CaserneEditWindow : public QDialog
{
    Q_OBJECT

public:
    CaserneEditWindow();
    void openCreate();
    void openLoad();
    void openEdit();
    void openDelete();

private:
    void m_applyStyle();
    void m_listerCasernes();

    QFormLayout *w_flMainCaserneWindow;
    QHBoxLayout *w_hlCaserneWindow;
    QLineEdit *w_leCaserneName;
    QLineEdit *w_leCaserneChief;
    QLineEdit *w_leAddress;
    QLineEdit *w_leZipCode;
    QLineEdit *w_leCity;
    QComboBox *w_cbCaserneName;
    QLabel *w_lDelete;
    QPushButton *w_pbOk;
    QPushButton *w_pbCancel;
    QLabel *w_lIdentityImg;
    QPixmap *w_pmIdentity;
    QPushButton *w_pbLoadImg;
    QHBoxLayout *w_hlIdentity;

    QString a_nameTemp;
    QString a_chefTemp;
    QList <QString> a_listCaserne;
    QDirIterator *a_compteur;
    TCaserne *a_caserneTemp;
    Caserne *a_caserne;
    bool a_existCaserne;
    bool a_editMode;


public slots:
    void sl_createCaserne();
    void sl_loadCaserne();
    void sl_editCaserne();
    void sl_deleteCaserne();
    void sl_openImg();
    void sl_backupName(QString name);
    void sl_backupChef(QString chef);

};

#endif // CREATECASERNEWINDOW_H
