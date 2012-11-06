#include "Guard.h"
Guard::Guard(int date[4], std::string name[6])
{
    a_date[0] = date[0];
    a_date[1] = date[1];
    a_date[2] = date[2];
    a_date[3] = date[3];
    a_name[0] = name[0];
    a_name[1] = name[1];
    a_name[2] = name[2];
    a_name[3] = name[3];
    a_name[4] = name[4];
    a_name[5] = name[5];

    std::ostringstream oss1;
    oss1 << a_date[0];
    std::ostringstream oss2;
    oss2 << a_date[1];
    std::ostringstream oss3;
    oss3 << a_date[2];
    std::ostringstream oss4;
    oss4 << a_date[3];

    std::string nom = oss1.str() + "_" + oss2.str() + "_" + oss3.str() + "_" + oss4.str();
    std::string extension = ".guard";
    a_nameFile = nom + extension;

    a_create = false;
}

Guard::Guard(int date[4])
{
    a_date[0] = date[0];
    a_date[1] = date[1];
    a_date[2] = date[2];
    a_date[3] = date[3];

    std::ostringstream oss1;
    oss1 << a_date[0];
    std::ostringstream oss2;
    oss2 << a_date[1];
    std::ostringstream oss3;
    oss3 << a_date[2];
    std::ostringstream oss4;
    oss4 << a_date[3];

    std::string nom = oss1.str() + "_" + oss2.str() + "_" + oss3.str() + "_" + oss4.str();
    std::string extension = ".guard";
    a_nameFile = nom + extension;

    a_fileI.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
    a_fileI.read((char *)&a_name, sizeof(std::string));
    a_fileI.close();

    a_create = true;
}

void Guard::m_create()
{
    if(a_create == false)
    {
        a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
        a_fileO.write ((char *)&a_date, sizeof(std::string));
        a_fileO.write ((char *)&a_name, sizeof(std::string));
        a_fileO.close();

        a_create = true;
    }
}

void Guard::m_setting(int name[6])
{
    if(a_create == true)
    {
        a_name[0] = name[0];
        a_name[1] = name[1];
        a_name[2] = name[2];
        a_name[3] = name[3];
        a_name[4] = name[4];
        a_name[5] = name[5];

        a_fileO.open(a_nameFile.c_str(), std::ios::out | std::ios::binary);
        a_fileO.write ((char *)&a_name, sizeof(std::string));
        a_fileO.close();

        a_create = true;
    }
}
