#include "CaserneEditWindow.h"

CaserneEditWindow::CaserneEditWindow()
{
    m_addStyleSheets();

<<<<<<< HEAD
<<<<<<< Updated upstream
    m_compterFicher();
=======
    m_chargementCasernes();
>>>>>>> Stashed changes
=======
   // m_compterFicher();
>>>>>>> chargement_casernes
}

// Création des fenêtres
void CaserneEditWindow::openCreate()
{
    w_leCaserneName = new QLineEdit;
        connect(w_leCaserneName, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupName(const QString &)));
    w_leCaserneChief = new QLineEdit;
        connect(w_leCaserneChief, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupChef(const QString &)));
    w_pbOk = new QPushButton("Créer");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_createCaserne()));
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlCaserneWindow = new QHBoxLayout;
    w_hlCaserneWindow->addWidget(w_pbOk);
    w_hlCaserneWindow->addWidget(w_pbCancel);

    w_flMainCaserneWindow = new QFormLayout;
    w_flMainCaserneWindow->addRow("Nom de la caserne", w_leCaserneName);
    w_flMainCaserneWindow->addRow("Nom du chef", w_leCaserneChief);
    w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

    setLayout(w_flMainCaserneWindow);
    this->exec();
}

void CaserneEditWindow::openLoad()
{
    w_cbCaserneName = new QComboBox;
    w_pbOk = new QPushButton("Ouvrir");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlCaserneWindow = new QHBoxLayout;
    w_hlCaserneWindow->addWidget(w_pbOk);
    w_hlCaserneWindow->addWidget(w_pbCancel);

    w_flMainCaserneWindow = new QFormLayout;
    w_flMainCaserneWindow->addRow("Caserne à ouvrir", w_cbCaserneName);
    w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

    setLayout(w_flMainCaserneWindow);
    this->exec();
}

void CaserneEditWindow::openEdit()
{
    w_cbCaserneName = new QComboBox;
    w_leCaserneName = new QLineEdit;
        connect(w_leCaserneName, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupName(const QString &)));
    w_leCaserneChief = new QLineEdit;
        connect(w_leCaserneChief, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupChef(const QString &)));
    w_pbOk = new QPushButton("Editer");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_createCaserne()));
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlCaserneWindow = new QHBoxLayout;
    w_hlCaserneWindow->addWidget(w_pbOk);
    w_hlCaserneWindow->addWidget(w_pbCancel);

    w_flMainCaserneWindow = new QFormLayout;
    w_flMainCaserneWindow->addRow("Caserne à éditer", w_cbCaserneName);
    w_flMainCaserneWindow->addRow("Nom de la caserne", w_leCaserneName);
    w_flMainCaserneWindow->addRow("Nom du chef", w_leCaserneChief);
    w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

    setLayout(w_flMainCaserneWindow);
    this->exec();
}

void CaserneEditWindow::openDelete()
{
    w_cbCaserneName = new QComboBox;
    w_pbOk = new QPushButton("Supprimer");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlCaserneWindow = new QHBoxLayout;
    w_hlCaserneWindow->addWidget(w_pbOk);
    w_hlCaserneWindow->addWidget(w_pbCancel);

    w_flMainCaserneWindow = new QFormLayout;
    w_flMainCaserneWindow->addRow("Caserne à supprimer", w_cbCaserneName);
    w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

    setLayout(w_flMainCaserneWindow);
    this->exec();
}


// Méthode Graphique
void CaserneEditWindow::m_addStyleSheets()
{
    setStyleSheet("QDialog {background-color:#6B6B6B; background-image:url(icons/background.jpg)}\
                   QLineEdit {background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6B6B6B, stop:1 #5E5E5E); border:1px solid #404040;}\
                   QWidget {color:#B8B8B8;}\
                   QPushButton {background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6B6B6B, stop:1 #5E5E5E); border:1px solid #404040;\
                                height:20px;}\
                   QPushButton:hover {background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #5E5E5E, stop:1 #424242);\
                                 border:1px solid #404040; height:20px;}\
                   QPushButton:pressed {background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #424242, stop:1 #6B6B6B);\
                                 border:1px solid #404040; height:20px;}\
                   QComboBox {background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #6B6B6B, stop:1 #5E5E5E); border:1px solid #404040;}\
                   QComboBox QAbstractItemView {border:1px solid #404040;\
                                                background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #5E5E5E, stop:1 #424242);\
                                                selection-background-color:qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #424242, stop:1 #6B6B6B);}\
                   QString {background-color:#B8B8B8; border:1px solid #404040;}");
}

void CaserneEditWindow::sl_createCaserne()
{
    Caserne *caserne1 = new Caserne(a_name, a_chef);
    caserne1->m_create();
}

void CaserneEditWindow::sl_backupName(QString name)
{
    a_name = name.toStdString();
}

void CaserneEditWindow::sl_backupChef(QString chef)
{
    a_chef = chef.toStdString();
}

void CaserneEditWindow::m_chargementCasernes()
{
    QStringList listFilter;
    listFilter << "*.cas";
    a_nbrCaserne = 0;

    a_compteur = new QDirIterator(QDir::currentPath() + "/Saves/Casernes/", listFilter, QDir::Files);

    while(a_compteur->hasNext())
     {
         a_nbrCaserne++;
         std::ifstream file;
         file.open(a_compteur->fileName().toStdString().c_str(), std::ios::out | std::ios::binary);
         file.read ((char *)&a_caserne, sizeof(TCaserne));
         a_listCaserne.push_back(a_caserne);
         a_compteur->next();
     }
}
