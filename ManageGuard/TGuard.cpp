#include "TGuard.h"

TGuard::TGuard (int date[4])
{
    a_date[0] = date[0];
    a_date[1] = date[1];
    a_date[2] = date[2];
    a_date[3] = date[3];
}

int* TGuard::m_getDate()
{
    return a_date;
}

