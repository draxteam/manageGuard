#ifndef TGUARD_H
#define TGUARD_H

#include "QObject"

class TGuard
{
    public:
    TGuard(int date[4]);
        int* m_getDate();

    private:
        int a_date[4];
};

#endif // TGUARD_H
