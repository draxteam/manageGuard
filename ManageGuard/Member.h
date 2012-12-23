#ifndef MEMBER_H
#define MEMBER_H

#include "QObject"
#include "QCoreApplication"
#include "TMember.h"
#include <QFile>
#include <QDebug>

class Member
{
    public:
       Member(QString name, QString firstName, int date, int grade, bool pictures);       //Constructeur
       Member(QString name, QString firstName);
       ~Member();
       void m_create();
       void m_getBack();
       void m_set(int date, int grade, bool pictures);

    private:
       TMember *a_member;
       QString a_file;
       QString a_filePictures;
};

#endif // MEMBER_H
