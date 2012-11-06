#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>
#include <QMenuBar>
#include <QDockWidget>
#include <QAction>

#include "CaserneEditWindow.h"
#include "StaffEditWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructeur ===
    MainWindow();

public slots:
    void sl_showFullScreen();

private slots:
    void sl_createCaserne();
    void sl_loadCaserne();
    void sl_editCaserne();
    void sl_deleteCaserne();
    void sl_createStaff();
    void sl_about();


private:
    // Méthodes ===
    void m_displayCentralWidget();
    void m_createActions();
    void m_displayMenu();
    void m_displayToolBar();
    void m_displayDock();
    void m_addStyleSheets();


    // Attributs ===
     //Fenetre
    QWidget *w_wPrincipal;
    QGridLayout *w_lPrincipal;


     //Menus
    QMenuBar *w_mbMenuBar;
    QMenu *w_mFile;
    QAction *w_aCreateCaserne;
    QAction *w_aOpenCaserne;
    QMenu *w_mLastCaserne;
    QAction *w_aLastCaserneT[5];
    QAction *w_aPrint;
    QAction *w_aSetting;
    QAction *w_aExit;

    QMenu *w_mManag;
    QAction *w_aEditCaserne;
    QAction *w_aDelCaserne;
    QAction *w_aAddStaff;
    QAction *w_aEditStaff;
    QAction *w_aDelStaff;

    QMenu *w_mDisplay;
    QAction *w_aDisplayToolBar;
    QAction *w_aDisplayCaserneTree;
    QAction *w_aFullScreen;

    QMenu *w_mHelp;
    QAction *w_aHelp;
    QAction *w_aVersion;
    QAction *w_aAbout;
        QDialog *w_dwAboutWindow;
        QVBoxLayout *w_vlMainAbout;
        QHBoxLayout *w_hlMainAbout;
        QString w_strVersion;
        QString w_strSite;
        QLabel *w_lAbout;
        QPushButton *w_pbSite;
        QPushButton *w_pbCloseAbout;
        QHBoxLayout *w_hlBtnAbout;
    QAction *w_aSite;


     //Barre d'outils
    QToolBar *w_tbTool;
    QWidget *w_tbsSpacer;
    QAction *w_aViewContextToolMenu;


     //DockMenu Objets
    QDockWidget *w_dCaserneTree;
    QWidget *w_wContCaserneTree;
    QVBoxLayout *w_vlMainCaserneTree;
    QAction *w_aViewContextDockMenu;
    QTreeView *w_tvCaserneTree;
    QStandardItemModel *w_modCaserneTree;
        QStandardItem *w_itemCaserne;

     //Slots
    CaserneEditWindow *caserneWindow;
    StaffEditWindow *staffWindow;
};

#endif // MAINWINDOW_H
