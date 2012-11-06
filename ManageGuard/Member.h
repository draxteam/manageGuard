#ifndef MEMBER_H
#define MEMBER_H

#include "QObject"
#include <iostream>
#include <fstream>

class Member
{
    public:
       Member(std::string nom, std::string prenom, int grade);       //Constructeur
       Member(std::string nom);
       void m_create();
       void m_setting(int grade);

    private:
       std::string a_nom;
       std::string a_prenom;
       int a_grade;
       std::string a_nameFile;
       bool a_create;
       std::ofstream a_fileO;
       std::ifstream a_fileI;
};

#endif // MEMBER_H
