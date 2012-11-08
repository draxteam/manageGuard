#include "MainWindow.h"

MainWindow::MainWindow()
{
    // Coeur ===
    m_displayCentralWidget();

    // Actions ===
    m_createActions();

    // Dock Menu ===
    m_displayDock();

    // ToolBar ===
    m_displayToolBar();

    // Menu ===
    m_displayMenu();

    // Fenêtres complémentaires ===
    caserneWindow = new CaserneEditWindow();
    staffWindow = new StaffEditWindow();
}



// Méthodes
void MainWindow::m_displayCentralWidget()
{
    w_tbMainTab = new QTabWidget(this);
    int height(this->height());
    int width(this->width());
        w_tbMainTab->setGeometry(width, height, width, height);
    w_tbo1MainTab = new QWidget;
    w_tbo2MainTab = new QWidget;

        w_pbTest1 = new QPushButton("Just a test");
        w_vlOng1MainTab = new QVBoxLayout;
        w_vlOng1MainTab->addWidget(w_pbTest1);
        w_tbo1MainTab->setLayout(w_vlOng1MainTab);

        w_pbTest2 = new QPushButton("Just a test");
        w_vlOng2MainTab = new QVBoxLayout;
        w_vlOng2MainTab->addWidget(w_pbTest2);
        w_tbo2MainTab->setLayout(w_vlOng2MainTab);

    w_tbMainTab->addTab(w_tbo1MainTab, "Gardes");
    w_tbMainTab->addTab(w_tbo2MainTab, "Management");

    setCentralWidget(w_tbMainTab);
}

void MainWindow::m_createActions()
{
    // MenuBar ===
     // Fichier
    w_aCreateCaserne = new QAction(QIcon("icons/new.jpg"), "Nouvelle caserne", this);
        w_aCreateCaserne->setShortcut(QKeySequence("Ctrl+N"));
        connect(w_aCreateCaserne, SIGNAL(triggered()), this, SLOT(sl_createCaserne()));
    w_aOpenCaserne = new QAction(QIcon("icons/open.jpg"), "Charger une caserne", this);
        w_aOpenCaserne->setShortcut(QKeySequence("Ctrl+O"));
        connect(w_aOpenCaserne, SIGNAL(triggered()), this, SLOT(sl_loadCaserne()));
    m_lastCaserneCreateMenu();
    w_aPrint = new QAction(QIcon("icons/print.jpg"), "Imprimer", this);
        w_aPrint->setShortcut(QKeySequence("Ctrl+P"));
    w_aSetting = new QAction(QIcon("icons/settings.jpg"), "Préférences", this);
        w_aSetting->setShortcut(QKeySequence("Ctrl+S"));
    w_aExit = new QAction(QIcon("icons/exit.jpg"), "Quitter", this);
        w_aExit->setShortcut(QKeySequence("Esc"));
        connect(w_aExit, SIGNAL(triggered()), qApp, SLOT(quit()));

     // Gestion
    w_aEditCaserne = new QAction("Modifier la caserne", this);
        w_aEditCaserne->setShortcut(QKeySequence("F1"));
        connect(w_aEditCaserne, SIGNAL(triggered()), this, SLOT(sl_editCaserne()));
    w_aDelCaserne = new QAction("Supprimer la caserne", this);
        w_aDelCaserne->setShortcut(QKeySequence("F2"));
        connect(w_aDelCaserne, SIGNAL(triggered()), this, SLOT(sl_deleteCaserne()));
    w_aAddStaff = new QAction(QIcon("icons/staff_add.jpg"), "Ajouter du personnel", this);
        w_aAddStaff->setShortcut(QKeySequence("F3"));
        connect(w_aAddStaff, SIGNAL(triggered()), this, SLOT(sl_createStaff()));
    w_aEditStaff = new QAction(QIcon("icons/staff_edit.jpg"), "Modifier le personnel", this);
        w_aEditStaff->setShortcut(QKeySequence("F4"));
        connect(w_aEditStaff, SIGNAL(triggered()), this, SLOT(sl_editStaff()));
    w_aDelStaff = new QAction(QIcon("icons/staff_remove.jpg"), "Supprimer du personnel", this);
        w_aDelStaff->setShortcut(QKeySequence("F5"));
        connect(w_aDelStaff, SIGNAL(triggered()), this, SLOT(sl_deleteStaff()));

     // Affichage
    w_aFullScreen = new QAction(QIcon("icons/fullscreen.jpg"), "Plein écran", this);
        w_aFullScreen->setShortcut(QKeySequence("F11"));
        w_aFullScreen->setCheckable(true);
        connect(w_aFullScreen, SIGNAL(triggered()), this, SLOT(sl_showFullScreen()));

     // Aide
    w_aHelp = new QAction(QIcon("icons/help.jpg"), "Aide", this);
        w_aHelp->setShortcut(QKeySequence("F10"));
    w_aAbout = new QAction(QIcon("icons/about.jpg"), "A propos", this);
        connect(w_aAbout, SIGNAL(triggered()), this, SLOT(sl_about()));
    w_aVersion = new QAction("Version en cours", this);
    w_aSite = new QAction(QIcon("icons/site.jpg"), "Se rendre à draxteam.tk", this);
        w_aSite->setShortcut(QKeySequence("F9"));
}

void MainWindow::m_displayMenu()
{
    w_mbMenuBar = new QMenuBar;
    setMenuBar(w_mbMenuBar);

    // Fichier
    w_mFile = w_mbMenuBar->addMenu("Fichier");
    w_mFile->addAction(w_aCreateCaserne);
    w_mFile->addAction(w_aOpenCaserne);
    w_mLastCaserne = w_mFile->addMenu("Casernes récentes");
    for (int i = 0; i < 5; ++i)
        //w_mLastCaserne->addAction(&w_aLastCaserneT[i]);
    w_mFile->addSeparator();
    w_mFile->addAction(w_aPrint);
    w_mFile->addAction(w_aSetting);
    w_mFile->addAction(w_aExit);

    // Gestion
    w_mManag = w_mbMenuBar->addMenu("Action");
    w_mManag->addAction(w_aEditCaserne);
    w_mManag->addAction(w_aDelCaserne);
    w_mManag->addSeparator();
    w_mManag->addAction(w_aAddStaff);
    w_mManag->addAction(w_aEditStaff);
    w_mManag->addAction(w_aDelStaff);

    // Affichage
    w_mDisplay = w_mbMenuBar->addMenu("Affichage");
    w_mDisplay->addAction(w_tbTool->toggleViewAction());
    w_mDisplay->addAction(w_dCaserneTree->toggleViewAction());
    w_mDisplay->addSeparator();
    w_mDisplay->addAction(w_aFullScreen);

    // Aide
    w_mHelp = w_mbMenuBar->addMenu("?");
    w_mHelp->addAction(w_aHelp);
    w_mHelp->addAction(w_aAbout);
    w_mHelp->addAction(w_aVersion);
    w_mHelp->addAction(w_aSite);

    m_addStyleSheets();
}

void MainWindow::m_lastCaserneCreateMenu()
{
}

void MainWindow::m_displayToolBar()
{
    w_tbTool = addToolBar("Barre d'outils");
    w_tbTool->setMovable(false);
    w_tbTool->setIconSize(QSize(17, 17));

    w_tbTool->addAction(w_aCreateCaserne);
    w_tbTool->addAction(w_aOpenCaserne);
    w_tbTool->addAction(w_aPrint);
    w_tbTool->addAction(w_aSetting);
    w_tbTool->addSeparator();
    w_tbTool->addAction(w_aAddStaff);
    w_tbTool->addAction(w_aEditStaff);
    w_tbTool->addAction(w_aDelStaff);
    w_tbTool->addSeparator();
    w_tbTool->addAction(w_aFullScreen);
    w_tbTool->addSeparator();
    w_tbTool->addAction(w_aHelp);
    w_tbTool->addAction(w_aAbout);
    w_tbTool->addAction(w_aSite);
    w_tbsSpacer = new QWidget();
    w_tbsSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    w_tbTool->addWidget(w_tbsSpacer);
    w_tbTool->addAction(w_aExit);
}

void MainWindow::m_displayDock()
{
    w_dCaserneTree = new QDockWidget("Arbre des casernes", this);
        w_dCaserneTree->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable);
        w_dCaserneTree->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
        w_dCaserneTree->setMinimumSize(150, w_dCaserneTree->height());
    addDockWidget(Qt::LeftDockWidgetArea, w_dCaserneTree);

    w_wContCaserneTree = new QWidget;
    w_dCaserneTree->setWidget(w_wContCaserneTree);

    w_modCaserneTree = new QStandardItemModel;

    w_itemCaserne = new QStandardItem("Caserne 1");
    w_modCaserneTree->appendRow(w_itemCaserne);
    w_itemCaserne->appendRow(new QStandardItem("Staff 1"));
    w_itemCaserne->appendRow(new QStandardItem("Staff 2"));
    w_itemCaserne->appendRow(new QStandardItem("Staff 3"));

    w_tvCaserneTree = new QTreeView;
        w_tvCaserneTree->header()->hide();
        w_tvCaserneTree->setModel(w_modCaserneTree);

    w_vlMainCaserneTree = new QVBoxLayout;
    w_vlMainCaserneTree->addWidget(w_tvCaserneTree);
    w_wContCaserneTree->setLayout(w_vlMainCaserneTree);
}




// Slots ===
 // Gestion du MenuBar et de la ToolBar
void MainWindow::sl_showFullScreen()
{
    if (w_aFullScreen->isChecked())
        showFullScreen();
    else
        showNormal();
}

void MainWindow::sl_about()
{
    w_dwAboutWindow = new QDialog(this);
    w_dwAboutWindow->setFixedSize(250, 150);
    w_dwAboutWindow->setWindowTitle("A propos");

    w_hlMainAbout = new QHBoxLayout(this);

    w_strVersion = ("v0.11021 alpha");
    w_strSite = ("<a href='http://draxteam.tk/'>draxteam.tk</a>");

    w_lAbout = new QLabel("<center><h2>Manage Guard</h2></center> <br />\
                               Développeurs : Guillaume Papin, Cyril Pou-vich<br />\
                               Version : " + w_strVersion + "<br />\
                               Site officiel : " + w_strSite + "<br />\
                               Licence : Licence libre GNU GPL V.3 ", w_dwAboutWindow);

    w_pbSite = new QPushButton("Site", w_dwAboutWindow);
        connect(w_pbSite, SIGNAL(clicked()), this, SLOT(close()));
    w_pbCloseAbout = new QPushButton("OK", w_dwAboutWindow);
        connect(w_pbCloseAbout, SIGNAL(clicked()), this, SLOT(close()));

    w_hlMainAbout->addWidget(w_lAbout);

    w_hlBtnAbout = new QHBoxLayout;
          w_hlBtnAbout->addWidget(w_pbSite);
          w_hlBtnAbout->addWidget(w_pbCloseAbout);

    w_vlMainAbout = new QVBoxLayout;
       w_vlMainAbout->addLayout(w_hlMainAbout);
       w_vlMainAbout->addLayout(w_hlBtnAbout);

    w_dwAboutWindow->setLayout(w_vlMainAbout);
    w_dwAboutWindow->show();
}

 // Gestion des fenêtres caserne
void MainWindow::sl_createCaserne()
{
    caserneWindow->openCreate();
}

void MainWindow::sl_loadCaserne()
{
    caserneWindow->openLoad();
}

void MainWindow::sl_editCaserne()
{
    caserneWindow->openEdit();
}

void MainWindow::sl_deleteCaserne()
{
    caserneWindow->openDelete();
}

 // Gestion des fenêtres staff
void MainWindow::sl_createStaff()
{
    staffWindow->openCreate();
}

void MainWindow::sl_editStaff()
{
    staffWindow->openEdit();
}

void MainWindow::sl_deleteStaff()
{
    staffWindow->openDelete();
}



// Méthode Graphique ===
void MainWindow::m_addStyleSheets()
{
    // MenuBar
    w_mbMenuBar->setStyleSheet("QMenuBar {background-color:#2d2d30;}"
                               "QMenuBar::item {background:transparent; color:#c1c1c1;}"
                               "QMenuBar::item:selected {background:#d47e18; color:#f0f0f0;}");

    // Menus, ToolBar
    setStyleSheet("QMenu {background-color:#2d2d30; border:1px solid #d47e18;}"
                  "QMenu::item {background:transparent; color:#c1c1c1;}"
                  "QMenu::item:selected {color:#d47e18;}"
                  "QMenu::separator {background:#d47e18; margin: 3px 5px 3px 5px; height:1px;}"
                   /* ToolBar */
                  "QToolBar {border:0; border-bottom:1px solid #d47e18; background-color:#2d2d30;}"
                  "QToolBar::separator {background:#B8B8B8; margin: 4px 7px 4px 7px; width:1px;}"
                  "QToolButton {border:0; margin-right:2px; margin-bottom:3px;}"
                  "QToolTip {color:#e7e7e7; border:1px solid #d47e18; background-color:#2d2d30;}"
                   /* Fenêtre */
                  "QMainWindow, QDialog {background-color:#28282b;}"
                  "QLabel {color:#c1c1c1;}"
                   /* Dock */
                  "QDockWidget {background-color:#1f1f22; color:#B8B8B8;}"
                  "QDockWidget::close-button:hover, QDockWidget::float-button:hover {border:0;}"
                   /* ListView */
                  "QTreeView {background-color:#252526; border:1px solid #404040; color:#DBDBDB;}"
                  "QTreeView::item:selected {background: #d47e18; border:0; color:#f0f0f0; padding:-1px;}"
                   /* LineEdit */
                  "QLineEdit {background-color:#1f1f22; border:0;}"
                  "QLineEdit:focus {background-color:#d47e18; border:0; color:#f0f0f0;}"
                   /* PushButton */
                  "QPushButton {background-color:#1f1f22; border:0; height:20px; color:#c1c1c1;}"
                  "QPushButton:hover {background-color:#d47e18; border:0; color:#f0f0f0;}"
                  "QPushButton:pressed {background-color:#d47e18; border:0; color:#f0f0f0;}"
                   /* TabWigdet */
                  "QTabWidget::pane {border-top: 2px solid #d47e18; background-color:#252526;}"
                  "QTabBar::tab {color:#c1c1c1; border:0; min-width: 150px; padding: 3px; margin-bottom:-1px;}"
                  "QTabBar::tab:selected, QTabBar::tab:hover {color:#f0f0f0; background-color: #d47e18;}"
                  "QTabBar::tab:!selected {background-color:#1f1f22;}");
}
