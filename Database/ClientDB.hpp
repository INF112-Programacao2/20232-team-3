#ifndef CLIENTDB_HPP
#define CLIENTDB_HPP

#include "../Client/Developer.hpp"
#include <string>

class Developer;

class ClientDB
{
private:
    std::string _path;
public:
    ClientDB(std::string path);
    void edit_info(Developer* dev);
    bool exist_userName(std::string &username);
};

#endif // CLIENTDB_HPP
