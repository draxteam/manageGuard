#ifndef EstablishmentsEditWindow_H
#define EstablishmentsEditWindow_H

#include "Caserne.h"
#include "TCaserne.h"

#include <QtGui>
#include <QObject>
#include <QList>
#include <QDirIterator>

class EstablishmentsEditWindow : public QDialog
{
    Q_OBJECT

    public:
        EstablishmentsEditWindow();        //Constructeur

        void openCreate();      //Fenetre de création
        void openLoad();        //Fenetre de chargement
        void openEdit();        //Fenetre d'edition
        void openDelete();      //Fenetre de suppression

    public slots:
        void sl_createCaserne();
        void sl_loadCaserne();
        void sl_editCaserne();
        void sl_deleteCaserne();
        void sl_openImg();
        void sl_addMember();
        void sl_deleteMember();
        //Slot backup
        void sl_backupName(QString name);
        void sl_backupChef(QString chef);
        void sl_backupAdress(QString adresse);
        void sl_backupZipCode(QString zipcode);
        void sl_backupCity(QString city);

    private:
        void m_applyStyle();        //Applique la feuille de style .css
        void m_listerCasernes();        //Liste les casernes dans le dossier
        void m_freeWidgets(QString realiseWindow);        //Libère la mémoire allouée aux widgets

        //Attributs widgets
        QFormLayout *w_flMainCaserneWindow;
        QHBoxLayout *w_hlCaserneWindow;
        QLineEdit *w_leCaserneName;
        QLineEdit *w_leCaserneChief;
        QLineEdit *w_leAddress;
        QLineEdit *w_leZipCode;
        QLineEdit *w_leCity;
        QComboBox *w_cbCaserneName;
        QLabel *w_lDelete;
        QPushButton *w_pbOk;
        QPushButton *w_pbCancel;
        QLabel *w_lIdentityImg;
        QPixmap *w_pixIdentity;
        QPushButton *w_pbLoadImg;
        QHBoxLayout *w_hlIdentity;

        QString a_nameTemp;
        QString a_chefTemp;
        QString a_adressTemp;
        int a_zipCodeTemp;
        QString a_cityTemp;
        bool a_picturesTemp;
        QString a_cheminPictureTemp;
        QString a_nameMemberTemp;
        QString a_firstNameMemberTemp;
        QList <QString> a_listCaserne;
        QDirIterator *a_compteur;
        TCaserne *a_caserneTemp;
        Caserne *a_caserne;
        bool a_existCaserne;
        bool a_editMode;
};

#endif // CREATECASERNEWINDOW_H
