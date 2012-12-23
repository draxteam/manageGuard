#include "CaserneEditWindow.h"

CaserneEditWindow::CaserneEditWindow()
{
    m_applyStyle();
    a_caserneTemp = new TCaserne();
    a_existCaserne = false;
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

    w_leCaserneName->~QLineEdit();
    w_leCaserneChief->~QLineEdit();
    w_pbOk->~QPushButton();
    w_pbCancel->~QPushButton();
    w_hlCaserneWindow->~QHBoxLayout();
    w_flMainCaserneWindow->~QFormLayout();

}

void CaserneEditWindow::openLoad()
{
    m_listerCasernes();
    int nombre = a_listCaserne.count();

    w_cbCaserneName = new QComboBox;
        for(int i(0);i<nombre;i++)
        {
            w_cbCaserneName->addItem(a_listCaserne[i]);
        }
        connect(w_cbCaserneName, SIGNAL(currentIndexChanged(QString)), this, SLOT(sl_backupName(const QString)));
    w_pbOk = new QPushButton("Ouvrir");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_loadCaserne()));
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

    w_cbCaserneName->~QComboBox();
    w_pbOk->~QPushButton();
    w_pbCancel->~QPushButton();
    w_hlCaserneWindow->~QHBoxLayout();
    w_flMainCaserneWindow->~QFormLayout();
}

void CaserneEditWindow::openEdit()
{
    if(a_existCaserne == true)
    {
        w_leCaserneChief = new QLineEdit;
            connect(w_leCaserneChief, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupChef(const QString &)));
        w_pbOk = new QPushButton("Editer");
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_editCaserne()));
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
        w_pbCancel = new QPushButton("Annuler");
            connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

        w_hlCaserneWindow = new QHBoxLayout;
        w_hlCaserneWindow->addWidget(w_pbOk);
        w_hlCaserneWindow->addWidget(w_pbCancel);

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow("Nom du chef", w_leCaserneChief);
        w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

        setLayout(w_flMainCaserneWindow);
        this->exec();

        w_leCaserneChief->~QLineEdit();
        w_pbOk->~QPushButton();
        w_pbCancel->~QPushButton();
        w_hlCaserneWindow->~QHBoxLayout();
        w_flMainCaserneWindow->~QFormLayout();
    }

    else
    {
        w_lDelete = new QLabel("Vous devez d'abord ouvrir une caserne.");
        w_pbOk = new QPushButton("Ok");
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow(w_lDelete);
        w_flMainCaserneWindow->addRow(w_pbOk);

        setLayout(w_flMainCaserneWindow);
        this->exec();

        w_lDelete->~QLabel();
        w_pbOk->~QPushButton();
        w_flMainCaserneWindow->~QFormLayout();
    }
}

void CaserneEditWindow::openDelete()
{
    if(a_existCaserne == true)
    {
        w_lDelete = new QLabel("Attention vous êtes sur le point de supprimer la caserne!");
        w_pbOk = new QPushButton("Supprimer");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_deleteCaserne()));
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
        w_pbCancel = new QPushButton("Annuler");
            connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

        w_hlCaserneWindow = new QHBoxLayout;
        w_hlCaserneWindow->addWidget(w_pbOk);
        w_hlCaserneWindow->addWidget(w_pbCancel);

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow(w_lDelete);
        w_flMainCaserneWindow->addRow(w_hlCaserneWindow);

        setLayout(w_flMainCaserneWindow);
        this->exec();

        w_lDelete->~QLabel();
        w_pbOk->~QPushButton();
        w_pbCancel->~QPushButton();
        w_hlCaserneWindow->~QHBoxLayout();
        w_flMainCaserneWindow->~QFormLayout();
    }

    else
    {
        w_lDelete = new QLabel("Vous devez d'abord ouvrir une caserne.");
        w_pbOk = new QPushButton("Ok");
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow(w_lDelete);
        w_flMainCaserneWindow->addRow(w_pbOk);

        setLayout(w_flMainCaserneWindow);
        this->exec();

        w_lDelete->~QLabel();
        w_pbOk->~QPushButton();
        w_flMainCaserneWindow->~QFormLayout();
    }
}


// Méthode Graphique
void CaserneEditWindow::m_applyStyle()
{
    QFile styleSheet("styles/style.css");
    if (styleSheet.open(QIODevice::ReadOnly))
    {
        QTextStream in(&styleSheet);
        QString style = in.readAll();
        qApp->setStyleSheet(style);
    }
}

void CaserneEditWindow::sl_createCaserne()
{
    a_caserne = new Caserne(a_nameTemp, a_chefTemp);
    a_caserne->m_create();

    a_existCaserne = true;
}

void CaserneEditWindow::sl_loadCaserne()
{
    a_caserne = new Caserne(a_nameTemp);
    a_caserne->m_getBack();

    a_existCaserne = true;
}

void CaserneEditWindow::sl_editCaserne()
{
    a_caserne->m_set(a_chefTemp);
}

void CaserneEditWindow::sl_deleteCaserne()
{
    a_caserne->~Caserne();

    a_existCaserne = false;
}

void CaserneEditWindow::sl_backupName(QString name)
{
    a_nameTemp = name;
}

void CaserneEditWindow::sl_backupChef(QString chef)
{
    a_chefTemp = chef;
}

void CaserneEditWindow::m_listerCasernes()
{
    QStringList listFilter;
    listFilter << "*.cas";

    a_compteur = new QDirIterator(QDir::currentPath() + "/Saves/Casernes/", listFilter, QDir::Files | QDir::NoSymLinks);

    while(a_compteur->hasNext())
     {
        a_compteur->next();
        QString chemin = "Saves/Casernes/" + a_compteur->fileName();
        QFile file(chemin);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        in >> *a_caserneTemp;
        a_nameTemp = a_caserneTemp->m_getName();
        a_listCaserne.push_back(a_nameTemp);
     }
}
