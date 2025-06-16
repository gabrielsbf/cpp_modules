#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <map>
#include <iostream>

class Harl
{
private:
    std::map<std::string, void (Harl::*)()> map_fun;
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

public:
    Harl()
    {
        map_fun["debug"] = &Harl::debug;
        map_fun["info"] = &Harl::info;
        map_fun["warning"] = &Harl::warning;
        map_fun["error"] = &Harl::error;
    };
    ~Harl() {};
    void complain(std::string level);
};

#endif