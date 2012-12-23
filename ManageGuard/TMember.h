#ifndef TMEMBER_H
#define TMEMBER_H

#include "QObject"
#include <QVariant>

class TMember
{
    public:
        TMember();
        TMember(QString name, QString firstName, int date, int grade, bool pictures);
        QString m_getName();
        QString m_getFirstName();
        static void m_initClasseSystem ();      //Prépare la classe à être sérialiser
        void m_set(int date, int grade, bool pictures);

    private:
        QString a_name;
        QString a_firstName;
        int a_date;
        int a_grade;
        bool a_pictures;

        friend QDataStream & operator << (QDataStream &, const TMember &);     //Definit l'opérateur << comme ami
        friend QDataStream & operator >> (QDataStream &, TMember &);     //Definit l'opérateur >> comme ami
};

Q_DECLARE_METATYPE(TMember)
    QDataStream & operator << (QDataStream & out, const TMember & Valeur);
    QDataStream & operator >> (QDataStream & in, TMember & Valeur);

#endif // TMEMBER_H
