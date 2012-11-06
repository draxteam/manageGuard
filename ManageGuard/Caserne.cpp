#include "Caserne.h"

Caserne::Caserne (std::string name, std::string chef)
{    
    a_caserne = new TCaserne(name, chef);

    std::string extension = ".cas";
    a_nameFile = "Saves/Casernes/" + name + extension;
}

void Caserne::m_create()
{
        a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
        a_fileO.write ((char *)&a_caserne, sizeof(TCaserne));
        a_fileO.close();
}

/*
void Caserne::m_addMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4)
{
    std::vector<TMember> membersTemp;
    TMember addMember(name, statut1, statut2, statut3, statut4);

    a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);

    a_fileI.read((char *)&membersTemp, sizeof(TMember));
    membersTemp.push_back(addMember);
    a_fileO.write((char *)&membersTemp, sizeof(TMember));

    a_fileO.close();
    a_fileI.close();
}

void Caserne::m_deleteMember(std::string name)
{
    std::vector<TMember> membersTemp;
    std::vector<TMember>::iterator positionMember;

    a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);

    a_fileI.read((char *)&membersTemp, sizeof(TMember));

    for(positionMember = membersTemp.begin() ; positionMember != membersTemp.end() ; positionMember++)
    {
       if((*positionMember).m_getName() == name)
       {
           membersTemp.erase(positionMember);
       }

    }

    a_fileO.write((char *)&membersTemp, sizeof(TMember));

    a_fileO.close();
    a_fileI.close();
}

void Caserne::m_settingMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4)
{
    std::vector<TMember> membersTemp;
    TMember addMember(name, statut1, statut2, statut3, statut4);
    std::vector<TMember>::iterator positionMember;

    a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);

    a_fileI.read((char *)&membersTemp, sizeof(TMember));

    for(positionMember = membersTemp.begin() ; positionMember != membersTemp.end() ; positionMember++)
    {
       if((*positionMember).m_getName() == name)
       {
           membersTemp.erase(positionMember);
           membersTemp.push_back(addMember);
           a_fileO.write((char *)&membersTemp, sizeof(TMember));
       }

    }

    a_fileO.close();
    a_fileI.close();
}

void Caserne::m_addGuard(int date[4])
{
    std::vector<TGuard> guardsTemp;
    TGuard addGuard(date);

    a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);

    a_fileI.read((char *)&guardsTemp, sizeof(TGuard));
    guardsTemp.push_back(addGuard);
    a_fileO.write((char *)&guardsTemp, sizeof(TGuard));

    a_fileO.close();
    a_fileI.close();
}

void Caserne::m_deleteGuard(int date[4])
{
    std::vector<TGuard> guardsTemp;
    std::vector<TGuard>::iterator positionGuard;

    a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);

    a_fileI.read((char *)&guardsTemp, sizeof(TGuard));

    for(positionGuard = guardsTemp.begin() ; positionGuard != guardsTemp.end() ; positionGuard++)
    {
       if((*positionGuard).m_getDate() == date)
       {
           guardsTemp.erase(positionGuard);
       }

    }

    a_fileO.write((char *)&guardsTemp, sizeof(TGuard));

    a_fileO.close();
    a_fileI.close();
}

*/

