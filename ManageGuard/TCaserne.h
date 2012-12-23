#ifndef TCASERNE_H
#define TCASERNE_H

#include "QObject"
#include <Qvector>
#include <QVariant>
#include <QDebug>

class TCaserne
{
    public:
        TCaserne();     //Constructeur
        TCaserne(QString name, QString chef);       //Constructeur
        QString m_getName();        //Renvoit le nom
        static void m_initClasseSystem ();      //Pr�pare la classe � �tre s�rialiser
        void m_set(QString name, QString chef);     //Edite les param�tres

    private:
        QString a_name;     //Contient le nom de la caserne
        QString a_chef;     //Contient le nom du chef de la caserne
        QVector<QString> a_listMembers;     //Contient la liste des membres de la caserne

        friend QDataStream & operator << (QDataStream &, const TCaserne &);     //Definit l'op�rateur << comme ami
        friend QDataStream & operator >> (QDataStream &, TCaserne &);     //Definit l'op�rateur >> comme ami
};

Q_DECLARE_METATYPE(TCaserne)
    QDataStream & operator << (QDataStream & out, const TCaserne & Valeur);
    QDataStream & operator >> (QDataStream & in, TCaserne & Valeur);

#endif // TCASERNE_H
