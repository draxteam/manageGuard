#ifndef ERROR_H
#define ERROR_H

#include <QObject>
#include <QtGui>

class Error : public QDialog
{
    public:
        Error();

    private:
        QString m_readError(int errorNbr);        //Lit les erreurs envoyés à la fonction
        void m_displayDialError(QString returnError); //Affiche l'erreur à l'écran

        QPushButton *w_pbOk;
        QHBoxLayout *w_hlButtonOk;
        QLabel *w_lError;
        QVBoxLayout *w_vlError;
};

#endif // ERROR_H
