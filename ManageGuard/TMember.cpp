#include "TMember.h"

TMember::TMember ()
{

}

TMember::TMember (QString name, QString firstName, int date, int grade, bool pictures)
{
    a_name = name;
    a_firstName = firstName;
    a_date = date;
    a_grade = grade;
    a_pictures = pictures;
}

QString TMember::m_getName()
{
    return a_name;
}

QString TMember::m_getFirstName()
{
    return a_firstName;
}

void TMember::m_initClasseSystem()
{
    qRegisterMetaTypeStreamOperators<TMember>("TMember");
    qMetaTypeId<TMember>();
}

QDataStream & operator << (QDataStream & out, const TMember & Valeur)
{
    out << Valeur.a_name
        << Valeur.a_firstName
        << Valeur.a_date
        << Valeur.a_grade
        << Valeur.a_pictures;

    return out;
}
QDataStream & operator >> (QDataStream & in, TMember &Valeur)
{
    in >> Valeur.a_name;
    in >> Valeur.a_firstName;
    in >> Valeur.a_date;
    in >> Valeur.a_grade;
    in >> Valeur.a_pictures;

    return in;
}

void TMember::m_set(int date, int grade, bool pictures)
{
    a_date = date;
    a_grade = grade;
    a_pictures = pictures;
}

