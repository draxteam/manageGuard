#include "StaffEditWindow.h"

#define NB_MAX_ASSIGN 5

StaffEditWindow::StaffEditWindow()
{
    m_addStyleSheets();
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
    w_pbCreate = new QPushButton("Créer");
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlAssignStaffWindow = new QHBoxLayout;
    w_hlAssignStaffWindow->addWidget(w_cbStaffAssign);
    w_hlAssignStaffWindow->addWidget(w_pbAddAssign);

    w_vlAssignRow = new QVBoxLayout;
    a_nbItem = 0;

    w_hlButtonStaffWindow = new QHBoxLayout;
    w_hlButtonStaffWindow->addWidget(w_pbCreate);
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

// Slots
void StaffEditWindow::sl_addRowAssign()
{
    ++a_nbItem;
    if (a_nbItem <= NB_MAX_ASSIGN)
    {
        w_assignItem = new AssignItem[a_nbItem];
        for (int i = 0; i < a_nbItem ; i++) // Supprime les assignations
        {
            w_vlAssignRow->removeWidget(&w_assignItem[i]);
        }

        for (int j = 0; j < a_nbItem ; j++) // Ajoute les assignations
        {
            w_vlAssignRow->addWidget(&w_assignItem[j]);
        }
    }
}

void StaffEditWindow::sl_delRowAssign()
{
}



// Méthode Graphique
void StaffEditWindow::m_addStyleSheets()
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
                   QString {background-color:#B8B8B8; border:1px solid #404040;}\
                   QScrollBar:vertical {border:1px solid #404040; background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #5E5E5E, stop:1 #6B6B6B);\
                                        width: 15px; margin: 12px 0 12px 0;}\
                   QScrollBar::handle:vertical {background-color:qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #DBDBDB, stop:1 #B8B8B8);min-height: 10px;}\
                   QScrollBar::add-line:vertical {border:1px solid #404040; background: #6B6B6B; height: 10px; subcontrol-position: bottom;\
                                                  subcontrol-origin: margin;}\
                   QScrollBar::sub-line:vertical {border:1px solid #404040; background: #6B6B6B; height: 10px; subcontrol-position: top;\
                                                  subcontrol-origin: margin;}\
                   QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {border: 0; width: 3px; height: 3px; background: #DBDBDB;}\
                   QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {background: none;}");
}
