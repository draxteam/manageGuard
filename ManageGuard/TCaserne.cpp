#include "TCaserne.h"

TCaserne::TCaserne ()
{
}

TCaserne::TCaserne (QString name, QString chef)
{
    a_name = name;
    a_chef = chef;
}

QString TCaserne::m_getName()
{
    return a_name;
}

void TCaserne::m_initClasseSystem()
{
    qRegisterMetaTypeStreamOperators<TCaserne>("TCaserne");
    qMetaTypeId<TCaserne>();
}

QDataStream & operator << (QDataStream & out, const TCaserne & Valeur)
{
    out << Valeur.a_name
        << Valeur.a_chef;

    return out;
}
QDataStream & operator >> (QDataStream & in, TCaserne &Valeur)
{
    in >> Valeur.a_name;
    in >> Valeur.a_chef;

    return in;
}

void TCaserne::m_set(QString chef)
{
    a_chef = chef;
}
