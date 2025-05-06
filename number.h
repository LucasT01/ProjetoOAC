#pragma once

#include <string>

class Number
{
private:
    std::string m_value;
public:
    Number(const std::string& valor, int base);
    std::string ValueToBase(int base, int precisaoFracao = 4);
};
