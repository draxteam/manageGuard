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
    w_pbOk = new QPushButton("Créer");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_createCaserne()));
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));
    w_hlCaserneWindow = new QHBoxLayout;
        w_hlCaserneWindow->addWidget(w_pbOk);
        w_hlCaserneWindow->addWidget(w_pbCancel);

    w_lIdentityImg = new QLabel;
    QImage w_imgIdentity("Saves/Casernes/Pictures/defaut.jpg");
    QImage w_imgIdentity2 = w_imgIdentity.scaled(QSize(150,150),Qt::IgnoreAspectRatio);
    w_pmIdentity = new QPixmap(QPixmap::fromImage(w_imgIdentity2));
        w_lIdentityImg->setPixmap(*w_pmIdentity);
    w_pbLoadImg = new QPushButton("...", w_lIdentityImg);
        w_pbLoadImg->move(0, 0);
        w_pbLoadImg->setStyleSheet("QPushButton {width:50px;}");
        connect(w_pbLoadImg, SIGNAL(clicked()), this, SLOT(sl_openImg()));

    w_leCaserneName = new QLineEdit;
        connect(w_leCaserneName, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupName(const QString &)));
    w_leCaserneChief = new QLineEdit;
        connect(w_leCaserneChief, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupChef(const QString &)));
    w_leAddress = new QLineEdit;
        connect(w_leAddress, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupAdress(const QString &)));
    w_leZipCode = new QLineEdit;
        connect(w_leZipCode, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupZipCode(const QString &)));
    w_leCity = new QLineEdit;
        connect(w_leCity, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupCity(const QString &)));

    w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow("Nom de la caserne", w_leCaserneName);
        w_flMainCaserneWindow->addRow("Nom du chef de centre", w_leCaserneChief);
        w_flMainCaserneWindow->addRow("Adresse", w_leAddress);
        w_flMainCaserneWindow->addRow("Code Postal", w_leZipCode);
        w_flMainCaserneWindow->addRow("Ville", w_leCity);
        w_flMainCaserneWindow->addRow(w_hlCaserneWindow);
    w_hlIdentity = new QHBoxLayout();
        w_hlIdentity->addWidget(w_lIdentityImg);
        w_hlIdentity->addLayout(w_flMainCaserneWindow);

    setLayout(w_hlIdentity);
    this->exec();

    delete w_flMainCaserneWindow->labelForField(w_leCaserneName);
    delete w_flMainCaserneWindow->labelForField(w_leCaserneChief);
    delete w_flMainCaserneWindow->labelForField(w_leAddress);
    delete w_flMainCaserneWindow->labelForField(w_leZipCode);
    delete w_flMainCaserneWindow->labelForField(w_leCity);
    delete w_pbLoadImg;
    delete w_lIdentityImg;
    delete w_pmIdentity;
    delete w_leCaserneName;
    delete w_leCaserneChief;
    delete w_leAddress;
    delete w_leZipCode;
    delete w_leCity;
    delete w_pbOk;
    delete w_pbCancel;
    delete w_hlCaserneWindow;
    delete w_flMainCaserneWindow;
    delete w_hlIdentity;
}

void CaserneEditWindow::openEdit()
{
    if(a_existCaserne == true)
    {
        w_pbOk = new QPushButton("Modifier");
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(sl_editCaserne()));
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
        w_pbCancel = new QPushButton("Annuler");
            connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));
        w_hlCaserneWindow = new QHBoxLayout;
            w_hlCaserneWindow->addWidget(w_pbOk);
            w_hlCaserneWindow->addWidget(w_pbCancel);

        w_lIdentityImg = new QLabel;
        QImage *w_imgIdentity;
        if(a_picturesTemp == true)
        {
            w_imgIdentity = new QImage("Saves/Casernes/Pictures/" + a_nameTemp + ".jpg");
        }
        else
        {
            w_imgIdentity = new QImage("Saves/Casernes/Pictures/defaut.jpg");
        }
        QImage w_imgIdentity2 = w_imgIdentity->scaled(QSize(150,150),Qt::IgnoreAspectRatio);
        w_pmIdentity = new QPixmap(QPixmap::fromImage(w_imgIdentity2));
            w_lIdentityImg->setPixmap(*w_pmIdentity);
        w_pbLoadImg = new QPushButton("...", w_lIdentityImg);
            w_pbLoadImg->move(0, 0);
            w_pbLoadImg->setStyleSheet("QPushButton {width:50px;}");
            connect(w_pbLoadImg, SIGNAL(clicked()), this, SLOT(sl_openImg()));

        w_leCaserneName = new QLineEdit(a_nameTemp);
            w_leCaserneName->setReadOnly(true);
            connect(w_leCaserneName, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupName(const QString &)));
        w_leCaserneChief = new QLineEdit(a_chefTemp);
            connect(w_leCaserneChief, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupChef(const QString &)));
        w_leAddress = new QLineEdit(a_adressTemp);
            connect(w_leAddress, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupAdress(const QString &)));
        w_leZipCode = new QLineEdit(QString::number(a_zipCodeTemp));
            connect(w_leZipCode, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupZipCode(const QString &)));
        w_leCity = new QLineEdit(a_cityTemp);
            connect(w_leCity, SIGNAL(textChanged(const QString &)), this, SLOT(sl_backupCity(const QString &)));
        w_flMainCaserneWindow = new QFormLayout;
            w_flMainCaserneWindow->addRow("Nom de la caserne", w_leCaserneName);
            w_flMainCaserneWindow->addRow("Nom du chef de centre", w_leCaserneChief);
            w_flMainCaserneWindow->addRow("Adresse", w_leAddress);
            w_flMainCaserneWindow->addRow("Code Postal", w_leZipCode);
            w_flMainCaserneWindow->addRow("Ville", w_leCity);
            w_flMainCaserneWindow->addRow(w_hlCaserneWindow);
        w_hlIdentity = new QHBoxLayout();
            w_hlIdentity->addWidget(w_lIdentityImg);
            w_hlIdentity->addLayout(w_flMainCaserneWindow);

        setLayout(w_hlIdentity);
        this->exec();

        delete w_flMainCaserneWindow->labelForField(w_leCaserneName);
        delete w_flMainCaserneWindow->labelForField(w_leCaserneChief);
        delete w_flMainCaserneWindow->labelForField(w_leAddress);
        delete w_flMainCaserneWindow->labelForField(w_leZipCode);
        delete w_flMainCaserneWindow->labelForField(w_leCity);
        delete w_pbLoadImg;
        delete w_lIdentityImg;
        delete w_pmIdentity;
        delete w_leCaserneName;
        delete w_leCaserneChief;
        delete w_leAddress;
        delete w_leZipCode;
        delete w_leCity;
        delete w_pbOk;
        delete w_pbCancel;
        delete w_hlCaserneWindow;
        delete w_flMainCaserneWindow;
        delete w_hlIdentity;
    }
    else
    {
        w_lDelete = new QLabel("Il faut d'abord ouvrir une caserne.");
        w_pbOk = new QPushButton("Ok");

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow(w_lDelete);
        w_flMainCaserneWindow->addRow(w_pbOk);
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));

        setLayout(w_flMainCaserneWindow);
        this->exec();

        delete w_flMainCaserneWindow->labelForField(w_lDelete);
        delete w_flMainCaserneWindow->labelForField(w_pbOk);
        delete w_lDelete;
        delete w_pbOk;
        delete w_flMainCaserneWindow;
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

        delete w_flMainCaserneWindow->labelForField(w_lDelete);
        delete w_flMainCaserneWindow->labelForField(w_hlCaserneWindow);
        delete w_lDelete;
        delete w_pbOk;
        delete w_pbCancel;
        delete w_hlCaserneWindow;
        delete w_flMainCaserneWindow;
    }
    else
    {
        w_lDelete = new QLabel("Il faut d'abord ouvrir une caserne.");
        w_pbOk = new QPushButton("Ok");

        w_flMainCaserneWindow = new QFormLayout;
        w_flMainCaserneWindow->addRow(w_lDelete);
        w_flMainCaserneWindow->addRow(w_pbOk);
            connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));

        setLayout(w_flMainCaserneWindow);
        this->exec();

        delete w_flMainCaserneWindow->labelForField(w_lDelete);
        delete w_flMainCaserneWindow->labelForField(w_pbOk);
        delete w_lDelete;
        delete w_pbOk;
        delete w_flMainCaserneWindow;
    }
}

void CaserneEditWindow::openLoad()
{
    m_listerCasernes();
    int nombre = a_listCaserne.count();

    w_cbCaserneName = new QComboBox;
        for(int i(0);i<nombre;i++)
            w_cbCaserneName->addItem(a_listCaserne[i]);
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

    delete w_flMainCaserneWindow->labelForField(w_cbCaserneName);
    delete w_cbCaserneName;
    delete w_pbOk;
    delete w_pbCancel;
    delete w_hlCaserneWindow;
    delete w_flMainCaserneWindow;
}

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
    a_caserne = new Caserne(a_nameTemp, a_chefTemp, a_adressTemp, a_zipCodeTemp, a_cityTemp, a_picturesTemp);
    a_caserne->m_create();

    if(a_picturesTemp == true)
    {
        QFile::copy (a_cheminPictureTemp, "Saves/Casernes/Pictures/" + a_nameTemp + ".jpg");
    }

    a_existCaserne = true;
}

void CaserneEditWindow::sl_loadCaserne()
{
    a_caserne = new Caserne(a_nameTemp);
    a_caserne->m_getBack();

    a_chefTemp = a_caserne->m_getChef();
    a_adressTemp = a_caserne->m_getAdress();
    a_zipCodeTemp = a_caserne->m_getZipCode();
    a_cityTemp = a_caserne->m_getCity();
    a_picturesTemp = a_caserne->m_getPictures();

    a_existCaserne = true;
}

void CaserneEditWindow::sl_editCaserne()
{
    a_caserne->m_set(a_chefTemp, a_adressTemp, a_zipCodeTemp, a_cityTemp, a_picturesTemp);

    if(a_picturesTemp == true)
    {
        QFile::copy (a_cheminPictureTemp, "Saves/Casernes/Pictures/" + a_nameTemp + ".jpg");
    }

    else
    {
        QFile filePictures ("Saves/Casernes/Pictures/" + a_nameTemp + ".jpg");
        filePictures.remove();
    }
}

void CaserneEditWindow::sl_deleteCaserne()
{
    a_caserne->~Caserne();

    a_existCaserne = false;
}

void CaserneEditWindow::sl_addMember()
{
    QString name = a_nameMemberTemp + a_firstNameMemberTemp[0];
    a_caserne->m_addMember(name);
}


void CaserneEditWindow::sl_deleteMember()
{
    QString name = a_nameMemberTemp + a_firstNameMemberTemp[0];
    a_caserne->m_deleteMember(name);
}

void CaserneEditWindow::sl_backupName(QString name)
{
    a_nameTemp = name;
}

void CaserneEditWindow::sl_backupChef(QString chef)
{
    a_chefTemp = chef;
}

void CaserneEditWindow::sl_backupAdress(QString adress)
{
    a_adressTemp = adress;
}

void CaserneEditWindow::sl_backupZipCode(QString zipCode)
{
    a_zipCodeTemp = zipCode.toInt();
}

void CaserneEditWindow::sl_backupCity(QString city)
{
    a_cityTemp = city;
}

void CaserneEditWindow::m_listerCasernes()
{
    QStringList listFilter;
    listFilter << "*.cas";

    a_listCaserne.clear();

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

void CaserneEditWindow::sl_openImg()
{
    QString a_img = QFileDialog::getOpenFileName(this, "Ouvrir une image", QString(), "Images (*.jpg *.jpeg)");
    if (a_img != "")
    {
        QImage w_img(a_img);
        QImage w_img2 = w_img.scaled(QSize(150,150),Qt::IgnoreAspectRatio);
        w_lIdentityImg->setPixmap(QPixmap::fromImage(w_img2));

        a_picturesTemp = true;
        a_cheminPictureTemp = a_img;
    }

    else
    {
        a_picturesTemp = false;
    }
}
