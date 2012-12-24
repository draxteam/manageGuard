#include "Caserne.h"

Caserne::Caserne (QString name, QString chef, QString adress, int zipCode, QString city, bool pictures)
{    
    a_caserne = new TCaserne(name, chef, adress, zipCode, city, pictures);
    a_caserne->m_initClasseSystem();

    QString extension = ".cas";
    a_file = "Saves/Casernes/" + name + extension;
    a_filePictures = "Saves/Casernes/Pictures/" + name + ".jpg";
}

Caserne::Caserne (QString name)
{
    QString extension = ".cas";
    a_file = "Saves/Casernes/" + name + extension;
    a_filePictures = "Saves/Casernes/Pictures/" + name + ".jpg";
}

Caserne::~Caserne()
{
    QFile file(a_file);
    file.remove();

    QString cheminPictures(a_filePictures);
    QFile filePictures (cheminPictures);
    filePictures.remove();
}

void Caserne::m_create()
{
    QFile file(a_file);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << *a_caserne;
    file.close();
}

void Caserne::m_getBack()
{
    a_caserne = new TCaserne();
    QFile file(a_file);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> *a_caserne;
    file.close();
}

void Caserne::m_set(QString chef, QString adress, int zipCode, QString city, bool pictures)
{
    a_caserne->m_set(chef, adress, zipCode, city, pictures);
}

QString Caserne::m_getChef()
{
    QString chef;
    chef = a_caserne->m_getChef();

    return chef;
}

QString Caserne::m_getAdress()
{
    QString adress;
    adress = a_caserne->m_getAdress();

    return adress;
}

int Caserne::m_getZipCode()
{
    int zipCode;
    zipCode = a_caserne->m_getZipCode();

    return zipCode;
}

QString Caserne::m_getCity()
{
    QString city;
    city = a_caserne->m_getCity();

    return city;
}

bool Caserne::m_getPictures()
{
    bool pictures;
    pictures = a_caserne->m_getPictures();

    return pictures;
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

