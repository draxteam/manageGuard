#include "CreateStaffWindow.h"

CreateStaffWindow::CreateStaffWindow()
{
    w_leStaffName = new QLineEdit;
    w_leStaffSecName = new QLineEdit;
    w_cbStaffGrade = new QComboBox;
    w_cbStaffGrade->addItem("Test");
    w_cbStaffGrade->addItem("Test2");
    w_cbStaffGrade->addItem("Test3");
    w_pbCreate = new QPushButton("Créer");
    w_pbCancel = new QPushButton("Annuler");
        connect(w_pbCancel, SIGNAL(clicked()), this, SLOT(accept()));

    w_hlStaffWindow = new QHBoxLayout;
    w_hlStaffWindow->addWidget(w_pbCreate);
    w_hlStaffWindow->addWidget(w_pbCancel);

    w_flMainStaffWindow = new QFormLayout;
    w_flMainStaffWindow->addRow("Nom du personnel", w_leStaffName);
    w_flMainStaffWindow->addRow("Prénom du personnel", w_leStaffSecName);
    w_flMainStaffWindow->addRow("Grade du personnel", w_cbStaffGrade);
    w_flMainStaffWindow->addRow(w_hlStaffWindow);

    setLayout(w_flMainStaffWindow);

    m_addStyleSheets();
}



// Méthode Graphique
void CreateStaffWindow::m_addStyleSheets()
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
