#ifndef CASERNE_H
#define CASERNE_H

#include "QObject"
#include "QCoreApplication"
#include "TMember.h"
#include "TGuard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "TCaserne.h"


class Caserne
{
    public:
        Caserne(std::string name, std::string chef);       //Constructeur
        void m_create();    //Créer la caserne
  //      void m_addMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4); //Ajoute un membre au personnel
 //       void m_deleteMember(std::string name);   //Suprime un membre du personnel
 //       void m_settingMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4);
  //      void m_addGuard(int date[4]);
   //     void m_deleteGuard(int date[4]);

    private:
        TCaserne *a_caserne;
        std::string a_nameFile;
        std::ofstream a_fileO;
        std::ifstream a_fileI;
};

#endif // CASERNE_H
