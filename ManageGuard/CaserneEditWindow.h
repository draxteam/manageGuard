#ifndef CASERNEEDITWINDOW_H
#define CASERNEEDITWINDOW_H

#include <QtGui>
#include "Caserne.h"
#include "TCaserne.h"
#include <vector>
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
    void m_addStyleSheets();
    void m_chargementCasernes();

    QFormLayout *w_flMainCaserneWindow;
    QHBoxLayout *w_hlCaserneWindow;
    QLineEdit *w_leCaserneName;
    QLineEdit *w_leCaserneChief;
    QComboBox *w_cbCaserneName;
    QPushButton *w_pbOk;
    QPushButton *w_pbCancel;

    std::string a_name;
    std::string a_chef;
    int a_nbrCaserne;
    std::vector <TCaserne> a_listCaserne;
    QDirIterator *a_compteur;
    TCaserne a_caserne;


public slots:
    void sl_createCaserne();
    void sl_backupName(QString name);
    void sl_backupChef(QString chef);

};

#endif // CREATECASERNEWINDOW_H
