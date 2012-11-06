#include "Member.h"

Member::Member(std::string nom, std::string prenom, int grade)
{
    a_nom = nom;
    a_prenom = prenom;
    a_grade = grade;

    std::string extension = ".per";
    a_nameFile = a_nom + extension;

    a_create = false;
}

Member::Member(std::string nom)
{
    a_nom = nom;
    std::string extension = ".per";
    a_nameFile = a_nom + extension;

    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.read((char *)&a_prenom, sizeof(std::string));
    a_fileI.read((char *)&a_grade, sizeof(int));
    a_fileI.close();

    a_create = true;
}

void Member::m_create()
{
    if(a_create == false)
    {
        a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
        a_fileO.write ((char *)&a_nom, sizeof(std::string));
        a_fileO.write ((char *)&a_prenom, sizeof(std::string));
        a_fileO.write ((char *)&a_grade, sizeof(int));
        a_fileO.close();

        a_create = true;
    }
}

void Member::m_setting(int grade)
{
    if(a_create == true)
    {
        a_grade = grade;

        a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
        a_fileO.write ((char *)&a_grade, sizeof(std::string));
        a_fileO.close();

        a_create = true;
    }
}
