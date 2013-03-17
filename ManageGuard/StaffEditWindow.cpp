#include "StaffEditWindow.h"

#define NB_MAX_ASSIGN 5

StaffEditWindow::StaffEditWindow()
{
    m_applyStyle();
}

// Création des fenêtres
void StaffEditWindow::openCreate()
{
    w_leStaffName = new QLineEdit;
    w_leStaffSecName = new QLineEdit;
    w_cbStaffGrade = new QComboBox;
        w_cbStaffGrade->addItem("Sapeur 2è classe");
        w_cbStaffGrade->addItem("Sapeur 1è classe");
        w_cbStaffGrade->addItem("Caporal");
        w_cbStaffGrade->addItem("Caporal-Chef");
        w_cbStaffGrade->addItem("Sergent");
        w_cbStaffGrade->addItem("Sergent-Chef");
        w_cbStaffGrade->addItem("Adjudant");
        w_cbStaffGrade->addItem("Adjudant-Chef");
        w_cbStaffGrade->addItem("Major");
        w_cbStaffGrade->addItem("Lieutenant");
        w_cbStaffGrade->addItem("Capitaine");
        w_cbStaffGrade->addItem("Commandant");
        w_cbStaffGrade->addItem("Lieutenant-Colonel");
        w_cbStaffGrade->addItem("Colonel");
    w_pbAddAssign = new QPushButton(QIcon("icons/add.png"), "");
        w_pbAddAssign->setStyleSheet("QPushButton {background:0; border:0; height:20px; max-width:20px;}");
        w_pbAddAssign->setIconSize(QSize(10, 10));
        connect(w_pbAddAssign, SIGNAL(clicked()), this, SLOT(sl_addRowAssign()));
    w_cbStaffAssign= new QComboBox;
        w_cbStaffAssign->addItem("Sapeur 2è classe");
        w_cbStaffAssign->addItem("Sapeur 1è classe");
        w_cbStaffAssign->addItem("Caporal");
        w_cbStaffAssign->addItem("Caporal-Chef");
        w_cbStaffAssign->addItem("Sergent");
    w_pbOk = new QPushButton("Créer");
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlAssignStaffWindow = new QHBoxLayout;
    w_hlAssignStaffWindow->addWidget(w_cbStaffAssign);
    w_hlAssignStaffWindow->addWidget(w_pbAddAssign);

    w_vlAssignRow = new QVBoxLayout;
    a_nbItem = 0;
    a_nbItemStart = 0;

    w_hlButtonStaffWindow = new QHBoxLayout;
    w_hlButtonStaffWindow->addWidget(w_pbOk);
    w_hlButtonStaffWindow->addWidget(w_pbCancel);

    w_flMainStaffWindow = new QFormLayout;
    w_flMainStaffWindow->addRow("Nom du personnel", w_leStaffName);
    w_flMainStaffWindow->addRow("Prénom du personnel", w_leStaffSecName);
    w_flMainStaffWindow->addRow("Grade du personnel", w_cbStaffGrade);
    w_flMainStaffWindow->addRow("Assignation du personnel", w_hlAssignStaffWindow);
    w_flMainStaffWindow->addRow(w_vlAssignRow);
    w_flMainStaffWindow->addRow(w_hlButtonStaffWindow);

    setLayout(w_flMainStaffWindow);
    this->exec();
}

void StaffEditWindow::openEdit()
{
    w_leStaffName = new QLineEdit;
    w_leStaffSecName = new QLineEdit;
    w_cbStaffGrade = new QComboBox;
        w_cbStaffGrade->addItem("Sapeur 2è classe");
        w_cbStaffGrade->addItem("Sapeur 1è classe");
        w_cbStaffGrade->addItem("Caporal");
        w_cbStaffGrade->addItem("Caporal-Chef");
        w_cbStaffGrade->addItem("Sergent");
        w_cbStaffGrade->addItem("Sergent-Chef");
        w_cbStaffGrade->addItem("Adjudant");
        w_cbStaffGrade->addItem("Adjudant-Chef");
        w_cbStaffGrade->addItem("Major");
        w_cbStaffGrade->addItem("Lieutenant");
        w_cbStaffGrade->addItem("Capitaine");
        w_cbStaffGrade->addItem("Commandant");
        w_cbStaffGrade->addItem("Lieutenant-Colonel");
        w_cbStaffGrade->addItem("Colonel");
    w_pbAddAssign = new QPushButton(QIcon("icons/add.png"), "");
        w_pbAddAssign->setStyleSheet("QPushButton {background:0; border:0; height:20px; max-width:20px;}");
        w_pbAddAssign->setIconSize(QSize(10, 10));
        connect(w_pbAddAssign, SIGNAL(clicked()), this, SLOT(sl_addRowAssign()));
    w_cbStaffAssign= new QComboBox;
        w_cbStaffAssign->addItem("Même système que pour le create");
    w_pbOk = new QPushButton("Editer");
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlAssignStaffWindow = new QHBoxLayout;
    w_hlAssignStaffWindow->addWidget(w_cbStaffAssign);
    w_hlAssignStaffWindow->addWidget(w_pbAddAssign);

    w_vlAssignRow = new QVBoxLayout;
    a_nbItem = 0; // Compter les assignations déja présentes
    a_nbItemStart = 0;

    w_hlButtonStaffWindow = new QHBoxLayout;
    w_hlButtonStaffWindow->addWidget(w_pbOk);
    w_hlButtonStaffWindow->addWidget(w_pbCancel);

    w_flMainStaffWindow = new QFormLayout;
    w_flMainStaffWindow->addRow("Nom du personnel", w_leStaffName);
    w_flMainStaffWindow->addRow("Prénom du personnel", w_leStaffSecName);
    w_flMainStaffWindow->addRow("Grade du personnel", w_cbStaffGrade);
    w_flMainStaffWindow->addRow("Assignation du personnel", w_hlAssignStaffWindow);
    w_flMainStaffWindow->addRow(w_vlAssignRow);
    w_flMainStaffWindow->addRow(w_hlButtonStaffWindow);

    setLayout(w_flMainStaffWindow);
    this->exec();
}

void StaffEditWindow::openDelete()
{
    w_cbRemoveStaff = new QComboBox;
        w_cbRemoveStaff->addItem("Liste du personnel");
    w_pbOk = new QPushButton("Supprimer");
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlButtonStaffWindow = new QHBoxLayout;
    w_hlButtonStaffWindow->addWidget(w_pbOk);
    w_hlButtonStaffWindow->addWidget(w_pbCancel);

    w_flMainStaffWindow = new QFormLayout;
    w_flMainStaffWindow->addRow("Personnel à supprimer", w_cbRemoveStaff);
    w_flMainStaffWindow->addRow(w_hlButtonStaffWindow);

    setLayout(w_flMainStaffWindow);
    this->exec();
}

// Slots
void StaffEditWindow::sl_addRowAssign()
{
    ++a_nbItem;
    if (a_nbItem <= NB_MAX_ASSIGN)
    {
        w_assignItem = new AssignItem[a_nbItem];

        for (int j = a_nbItemStart; j < a_nbItem ; j++) // Ajoute les assignations
        {
            w_assignItem[j].createRow(j);
                connect(&w_assignItem[j], SIGNAL(si_removeAssignRow(int)), this, SLOT(sl_delRowAssign(int)));
            w_vlAssignRow->addWidget(&w_assignItem[j]);
        }

        ++a_nbItemStart;
    }
}

void StaffEditWindow::sl_delRowAssign(int itemNb)
{
    w_vlAssignRow->removeWidget(&w_assignItem[itemNb]);
    delete[] w_assignItem;
}



// Méthode Graphique
void StaffEditWindow::m_applyStyle()
{
    QFile styleSheet("styles/style.css");
    if (styleSheet.open(QIODevice::ReadOnly))
    {
        QTextStream in(&styleSheet);
        QString style = in.readAll();
        qApp->setStyleSheet(style);
    }
}

void StaffEditWindow::sl_createMember()
{
    a_member = new Member(a_nameTemp, a_firstNameTemp, a_dateTemp, a_gradeTemp, a_picturesTemp);
    a_member->m_create();

    if(a_picturesTemp == true)
    {
        QFile::copy (a_cheminPictureTemp, "Saves/Membres/Pictures/" + a_nameTemp + a_firstNameTemp[0] + ".jpg");
    }

    a_existMember = true;
}

void StaffEditWindow::sl_loadMember()
{
    a_member = new Member(a_nameTemp, a_firstNameTemp);
    a_member->m_getBack();

    a_existMember = true;
}

void StaffEditWindow::sl_editMember()
{
    a_member->m_set(a_dateTemp, a_gradeTemp, a_picturesTemp);

    if(a_picturesTemp == true)
    {
        QFile::copy (a_cheminPictureTemp, "Saves/Membres/Pictures/" + a_nameTemp + a_firstNameTemp[0] + ".jpg");
    }

    else
    {
        QFile filePictures ("Saves/Membres/Pictures/" + a_nameTemp + a_firstNameTemp[0] + ".jpg");
        filePictures.remove();
    }
}

void StaffEditWindow::sl_deleteMember()
{
    a_member->~Member();

    a_existMember = false;
}

void StaffEditWindow::sl_backupName(QString name)
{
    a_nameTemp = name;
}

void StaffEditWindow::sl_backupFirstName(QString firstName)
{
    a_firstNameTemp = firstName;
}

void StaffEditWindow::sl_backupDate(int date)
{
    a_dateTemp = date;
}

void StaffEditWindow::sl_backupGrade(int grade)
{
    a_gradeTemp = grade;
}

void StaffEditWindow::sl_backupPictures(QString file)
{
    if(file != "")
    {
        a_picturesTemp = true;
        a_cheminPictureTemp = file;
    }

    else
    {
        a_picturesTemp = false;
    }

}

void StaffEditWindow::m_listerMembers()
{
    QStringList listFilter;
    listFilter << "*.memb";

    a_compteur = new QDirIterator(QDir::currentPath() + "/Saves/Membres/", listFilter, QDir::Files | QDir::NoSymLinks);

    while(a_compteur->hasNext())
     {
        a_compteur->next();
        QString chemin = "Saves/Membres/" + a_compteur->fileName();
        QFile file(chemin);
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);
        in >> *a_memberTemp;
        a_nameTemp = a_memberTemp->m_getName();
        a_firstNameTemp = a_memberTemp->m_getFirstName();
        a_listMember.push_back(a_nameTemp + a_firstNameTemp[0]);
     }
}
