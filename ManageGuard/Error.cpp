#include "Error.h"

Error::Error()
{
}

QString Error::m_readError(int errorNbr)
{
    if (errorNbr == 1 )
        m_displayDialError("Erreur d'affichage");
    return 0;
}

void Error::m_displayDialError(QString returnError)
{
    w_pbOk = new QPushButton("Ok");
        connect(w_pbOk, SIGNAL(clicked()), this, SLOT(accept()));
    w_hlButtonOk = new QHBoxLayout;
        w_hlButtonOk->addWidget(w_pbOk);

    w_lError = new QLabel(returnError);

    w_vlError = new QVBoxLayout();
        w_vlError->addWidget(w_lError);
        w_vlError->addLayout(w_hlButtonOk);

    setLayout(w_vlError);
    this->exec();
}
