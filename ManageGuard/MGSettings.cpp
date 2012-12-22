#include "MGSettings.h"

MGSettings::MGSettings()
{
    w_dSettingsWindow = new QDialog(this);
        w_dSettingsWindow->setWindowTitle(tr("Options"));

    w_tabSettings = new QTabWidget(w_dSettingsWindow);
    w_vlTabSettings = new QVBoxLayout;
        w_vlTabSettings->setObjectName("TabSettings");
        w_vlTabSettings->setContentsMargins(5,5,5,5);

    // Onglet Affichage ===
    w_tab1Display = new QWidget(w_tabSettings);
    w_vlTabDisplay = new QVBoxLayout;

    // Groupe Home
    w_gbDisplay = new QGroupBox(tr("Page d'accueil"));
    w_vlGroupDisplay = new QVBoxLayout;

    w_lDisplayPage = new QLabel(tr("Définir la page d'accueil :"));
    w_leDisplayPage = new QLineEdit;

    w_hlDisplayPage = new QHBoxLayout;
        w_hlDisplayPage->addWidget(w_lDisplayPage);
        w_hlDisplayPage->addWidget(w_leDisplayPage);

    w_pbDefineCurrentPage = new QPushButton(tr("Définir la page actuelle"), w_dSettingsWindow);

    w_vlGroupDisplay->addLayout(w_hlDisplayPage);
    w_vlGroupDisplay->addWidget(w_pbDefineCurrentPage);
    w_gbDisplay->setLayout(w_vlGroupDisplay);

    w_vlTabDisplay->addWidget(w_gbDisplay);


    // Ajout des onglets
    w_tabSettings->addTab(w_tab1Display, tr("Affichage"));
    w_vlTabSettings->addWidget(w_tabSettings);

    // boutons ok et annuler :
    QPushButton *boutonParametreDefaut = new QPushButton("Paramètres par défaut", w_dSettingsWindow);
    QPushButton *boutonOk6 = new QPushButton("Ok", w_dSettingsWindow);
    QPushButton *boutonAnnulerPreferences = new QPushButton("Annuler", w_dSettingsWindow);

    QHBoxLayout *layoutDroite = new QHBoxLayout;
    layoutDroite->setAlignment(Qt::AlignRight);
    layoutDroite->setSpacing(6);
    layoutDroite->addWidget(boutonOk6);
    layoutDroite->addWidget(boutonAnnulerPreferences);

    QHBoxLayout *layoutBoutons = new QHBoxLayout;
    layoutBoutons->addWidget(boutonParametreDefaut);
    layoutBoutons->addLayout(layoutDroite);
    layoutBoutons->setAlignment(boutonParametreDefaut, Qt::AlignLeft);

    w_vlTabSettings->addLayout(layoutBoutons);
    w_dSettingsWindow->setLayout(w_vlTabSettings);
    w_dSettingsWindow->show();
}
