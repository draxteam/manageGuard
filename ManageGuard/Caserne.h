#ifndef CASERNE_H
#define CASERNE_H

#include "QObject"
#include "QCoreApplication"
#include "TCaserne.h"
#include <QFile>
#include <QDebug>

class Caserne
{
    public:
        Caserne(QString name, QString chef);        //Constructeur
        Caserne(QString name);      //Constructeur
        ~Caserne();     //Destructeur
        void m_create();        //Creation de la caserne
        void m_getBack();       //R�cup�ration de la caserne
        void m_set(QString name, QString chef);     //Edite les param�tres
  //      void m_addMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4); //Ajoute un membre au personnel
 //       void m_deleteMember(std::string name);   //Suprime un membre du personnel
 //       void m_settingMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4);
  //      void m_addGuard(int date[4]);
   //     void m_deleteGuard(int date[4]);

    private:
        TCaserne *a_caserne;        //Contient la caserne
        QString a_file;     //Contient le fichier de destination
};

#endif // CASERNE_H
