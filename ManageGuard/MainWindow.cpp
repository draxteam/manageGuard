#include "MainWindow.h"

MainWindow::MainWindow()
{
    //===ZONE PRINCIPALE===//
    m_displayCentralWidget();

    //===ACTIONS===//
    m_createActions();

    //===DOCK MENU===//
    m_displayDock();

    //===BARRE D'OUTILS===//
    m_displayToolBar();

    //===MENUS===//
    m_displayMenu();

    // Menu ===
    m_applyStyle();

    // Fenêtres complémentaires ===
    caserneWindow = new EstablishmentsEditWindow();
    staffWindow = new StaffEditWindow();
}



// Méthodes
void MainWindow::m_displayCentralWidget()
{
    w_wPrincipal = new QWidget;
    setCentralWidget(w_wPrincipal);
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
    w_aLastCaserneT[0] = new QAction("Caserne 1", this);
    w_aLastCaserneT[1] = new QAction("Caserne 2", this);
    w_aLastCaserneT[2] = new QAction("Caserne 3", this);
    w_aLastCaserneT[3] = new QAction("Caserne 4", this);
    w_aLastCaserneT[4] = new QAction("Caserne 5", this);
    w_aPrint = new QAction(QIcon("icons/print.jpg"), "Imprimer", this);
        w_aPrint->setShortcut(QKeySequence("Ctrl+P"));
    w_aSetting = new QAction(QIcon("icons/settings.jpg"), "Préférences", this);
        w_aSetting->setShortcut(QKeySequence("Ctrl+S"));
        connect(w_aSetting, SIGNAL(triggered()), this, SLOT(sl_settings()));
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
    w_aAddStaff = new QAction("Ajouter du personnel", this);
        w_aAddStaff->setShortcut(QKeySequence("F3"));
        connect(w_aAddStaff, SIGNAL(triggered()), this, SLOT(sl_createStaff()));
    w_aEditStaff = new QAction("Modifier le personnel", this);
        w_aEditStaff->setShortcut(QKeySequence("F4"));
    w_aDelStaff = new QAction("Supprimer du personnel", this);
        w_aDelStaff->setShortcut(QKeySequence("F5"));

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
    w_mLastCaserne = w_mFile->addMenu("Casernes récemment gérées");
        w_mLastCaserne->addAction(w_aLastCaserneT[0]);
        w_mLastCaserne->addAction(w_aLastCaserneT[1]);
        w_mLastCaserne->addAction(w_aLastCaserneT[2]);
        w_mLastCaserne->addAction(w_aLastCaserneT[3]);
        w_mLastCaserne->addAction(w_aLastCaserneT[4]);
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
        w_wContCaserneTree->setContentsMargins(0,0,0,0);
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
        w_vlMainCaserneTree->setContentsMargins(0,0,0,0);
        w_vlMainCaserneTree->addWidget(w_tvCaserneTree);
    w_wContCaserneTree->setLayout(w_vlMainCaserneTree);
}

void MainWindow::m_applyStyle()
{
    if (QFile::exists("styles/style.css"))
    {
        QFile styleSheet("styles/style.css");
        if (styleSheet.open(QIODevice::ReadOnly))
        {
            QTextStream in(&styleSheet);
            QString style = in.readAll();
            qApp->setStyleSheet(style);
        }
    }
    else
    {
        QMessageBox::critical(this, "Erreur", "La feuille de style est introuvable <i>('styles/style.css')</i>,<br />Le style de base sera appliqué.");
    }
}




// Slots ===
 // Gestion du MenuBar et de la ToolBar
void MainWindow::sl_settings()
{
    settingsWindow = new MGSettings();
}

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
    staffWindow = new StaffEditWindow();
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
