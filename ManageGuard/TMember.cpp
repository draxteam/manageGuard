#include "TMember.h"

TMember::TMember (std::string name, bool statut1, bool statut2, bool statut3, bool statut4)
{
    a_name = name;
    a_statut1 = statut1;
    a_statut2 = statut2;
    a_statut3 = statut3;
    a_statut4 = statut4;
}

std::string TMember::m_getName()
{
    return a_name;
}

bool TMember::m_getStatut1()
{
    return a_statut1;
}

bool TMember::m_getStatut2()
{
    return a_statut2;
}

bool TMember::m_getStatut3()
{
    return a_statut3;
}

bool TMember::m_getStatut4()
{
    return a_statut4;
}

