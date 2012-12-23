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
<<<<<<< HEAD
        void m_set(QString chef);     //Edite les param�tres
=======
        void m_set(QString name, QString chef);     //Edite les param�tres
>>>>>>> 6a5791becc042be516474f4a00e26ff93dacf771

    private:
        QString a_name;     //Contient le nom de la caserne
        QString a_chef;     //Contient le nom du chef de la caserne

        friend QDataStream & operator << (QDataStream &, const TCaserne &);     //Definit l'op�rateur << comme ami
        friend QDataStream & operator >> (QDataStream &, TCaserne &);     //Definit l'op�rateur >> comme ami
};

Q_DECLARE_METATYPE(TCaserne)
    QDataStream & operator << (QDataStream & out, const TCaserne & Valeur);
    QDataStream & operator >> (QDataStream & in, TCaserne & Valeur);

#endif // TCASERNE_H
