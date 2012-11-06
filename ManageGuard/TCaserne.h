#ifndef TCASERNE_H
#define TCASERNE_H

#include "QObject"
#include <vector>

class TCaserne
{
    public:
        TCaserne();
        TCaserne(std::string name, std::string chef);       //Constructeur

    private:
        std::string a_name;
        std::string a_chef;
        std::vector<TCaserne> a_listMembers;
};

#endif // TCASERNE_H
