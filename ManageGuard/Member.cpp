#include "Member.h"

Member::Member(QString name, QString firstName, int date, int grade, bool pictures)
{
    a_member = new TMember(name, firstName, date, grade, pictures);
    a_member->m_initClasseSystem();

    QString extension = ".memb";
    a_file = "Saves/Membres/" + name + firstName[0] + extension;
    a_filePictures = "Saves/Membres/Pictures/" + name + firstName[0] + ".png";
}

Member::Member(QString name, QString firstName)
{
    QString extension = ".memb";
    a_file = "Saves/Membres/" + name + firstName[0] + extension;
    a_filePictures = "Saves/Membres/Pictures/" + name + firstName[0] + ".png";
}

Member::~Member()
{
    QFile file(a_file);
    file.remove();
    QString cheminPictures(a_filePictures);
    QFile filePictures (cheminPictures);
    filePictures.remove();
}

void Member::m_create()
{
    QFile file(a_file);
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << *a_member;
    file.close();
}

void Member::m_getBack()
{
    a_member = new TMember();
    QFile file(a_file);
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    in >> *a_member;
    file.close();
}

void Member::m_set(int date, int grade, bool pictures)
{
    a_member->m_set(date, grade, pictures);
}
