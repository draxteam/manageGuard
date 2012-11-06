#ifndef TMEMBER_H
#define TMEMBER_H

#include "QObject"

class TMember
{
    public:
        TMember(std::string name, bool statut1, bool statut2, bool statut3, bool statut4);
        std::string m_getName();
        bool m_getStatut1();
        bool m_getStatut2();
        bool m_getStatut3();
        bool m_getStatut4();



    private:
        std::string a_name;
        bool a_statut1;
        bool a_statut2;
        bool a_statut3;
        bool a_statut4;

};

#endif // TMEMBER_H
