#ifndef GUARD_H
#define GUARD_H

#include "QObject"
#include <iostream>
#include <fstream>
#include <sstream>

class Guard
{
    public:
    Guard(int date[4], std::string name[6]);       //Constructeur
    Guard(int date[4]);
    void m_create();
    void m_setting(int name[6]);

    private:
        int a_date[4];
        std::string a_name[6];
        bool a_create;
        std::ofstream a_fileO;
        std::ifstream a_fileI;
        std::string a_nameFile;
};

#endif // GUARD_H
