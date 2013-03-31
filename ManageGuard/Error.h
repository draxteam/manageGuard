#ifndef ERROR_H
#define ERROR_H

#include <QObject>

class Error
{
    public:
        Error();

    private:
        QString m_readError(int errorNbr);        //Lit les erreurs envoyés à la fonction
};

#endif // ERROR_H
