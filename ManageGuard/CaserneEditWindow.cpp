#include "CaserneEditWindow.h"

CaserneEditWindow::CaserneEditWindow()
{
    m_addStyleSheets();

    m_chargementCasernes();
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
    setStyleSheet("QDialog {background-color:#28282b;}"
                 "QLineEdit {background-color:#1f1f22; border:0;}"
                 "QLineEdit:focus {background-color:#d47e18; border:0; color:#f0f0f0;}"
                 "QWidget {color:#B8B8B8;}"
                 "QPushButton {background-color:#1f1f22; border:0; height:20px; color:#c1c1c1;}"
                 "QPushButton:hover {background-color:#d47e18; border:0; color:#f0f0f0;}"
                 "QPushButton:pressed {background-color:#d47e18; border:0; color:#f0f0f0;}"
                 "QComboBox {background-color:#1f1f22; border:0;}"
                 "QComboBox QAbstractItemView {border:0; background-color:#28282b; selection-background-color:#d47e18; selection-color:#f0f0f0;}"
                 "QScrollBar:vertical {background-color:#1f1f22; width: 15px; margin: 10px 0 10px 0;}"
                 "QScrollBar::handle:vertical {background-color:#d47e18; margin: 3px;}"
                 "QScrollBar::add-line:vertical {border:0; background-color: #1f1f22; height: 10px; subcontrol-position: bottom;"
                                                "subcontrol-origin: margin;}"
                 "QScrollBar::sub-line:vertical {border:0; background-color: #1f1f22; height: 10px; subcontrol-position: top;"
                                                "subcontrol-origin: margin;}"
                 "QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border: 0; width: 4px; height: 2px; background: #d47e18;}"
                 "QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");
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
