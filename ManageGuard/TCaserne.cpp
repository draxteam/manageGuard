#include "TCaserne.h"

TCaserne::TCaserne ()
{
}

TCaserne::TCaserne (QString name, QString chef, QString adress, int zipCode, QString city, bool pictures)
{
    a_name = name;
    a_chef = chef;
    a_adress = adress;
    a_zipCode = zipCode;
    a_city = city;
    a_pictures = pictures;
}

void TCaserne::m_set(QString chef, QString adress, int zipCode, QString city, bool pictures)
{
    a_chef = chef;
    a_adress = adress;
    a_zipCode = zipCode;
    a_city = city;
    a_pictures = pictures;
}

void TCaserne::m_addMember(QString name)
{
    a_listMembers.push_back(name);
}

void TCaserne::m_deleteMember(QString name)
{
    int position = a_listMembers.indexOf(name);
    a_listMembers[position].clear();
}

QString TCaserne::m_getName()
{
    return a_name;
}

QString TCaserne::m_getChef()
{
    return a_chef;
}

QString TCaserne::m_getAdress()
{
    return a_adress;
}

int TCaserne::m_getZipCode()
{
    return a_zipCode;
}

QString TCaserne::m_getCity()
{
    return a_city;
}

bool TCaserne::m_getPictures()
{
    return a_pictures;
}

QList<QString> TCaserne::m_getListMembers()
{
    return a_listMembers;
}

void TCaserne::m_initClasseSystem()
{
    qRegisterMetaTypeStreamOperators<TCaserne>("TCaserne");
    qMetaTypeId<TCaserne>();
}

QDataStream & operator << (QDataStream & out, const TCaserne & Valeur)
{
    out << Valeur.a_name
        << Valeur.a_chef
        << Valeur.a_adress
        << Valeur.a_zipCode
        << Valeur.a_city
        << Valeur.a_pictures
        << Valeur.a_listMembers;

    return out;
}
QDataStream & operator >> (QDataStream & in, TCaserne &Valeur)
{
    in >> Valeur.a_name;
    in >> Valeur.a_chef;
    in >> Valeur.a_adress;
    in >> Valeur.a_zipCode;
    in >> Valeur.a_city;
    in >> Valeur.a_pictures;
    in >> Valeur.a_listMembers;

    return in;
}
