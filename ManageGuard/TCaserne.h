#ifndef TCASERNE_H
#define TCASERNE_H

#include <QObject>
#include <Qvector>
#include <QVariant>

class TCaserne
{
    public:
        TCaserne();     //Constructeur
        TCaserne(QString name, QString chef, QString adress, int zipCode, QString city, bool pictures);       //Constructeur

        static void m_initClasseSystem ();      //Prépare la classe à être sérialiser
        void m_set(QString chef, QString adress, int zipCode, QString city, bool pictures);     //Edite les paramètres

        //Methodes get
        QString m_getName();
        QString m_getChef();
        QString m_getAdress();
        int m_getZipCode();
        QString m_getCity();
        bool m_getPictures();

    private:
        QString a_name;     //Contient le nom de la caserne
        QString a_chef;     //Contient le nom du chef de la caserne
        QString a_adress;
        int a_zipCode;
        QString a_city;
        bool a_pictures;

        friend QDataStream & operator << (QDataStream &, const TCaserne &);     //Definit l'opérateur << comme ami
        friend QDataStream & operator >> (QDataStream &, TCaserne &);     //Definit l'opérateur >> comme ami
};

Q_DECLARE_METATYPE(TCaserne)
    QDataStream & operator << (QDataStream & out, const TCaserne & Valeur);
    QDataStream & operator >> (QDataStream & in, TCaserne & Valeur);

#endif // TCASERNE_H
