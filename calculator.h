// calculator.h
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>

class Calculator {
public:
    static std::string add(const std::string bin1, const std::string bin2);
    static std::string subtract(const std::string bin1, const std::string bin2);
    static std::string multiply(const std::string bin1, const std::string bin2);
    static std::string divide(const std::string bin1, const std::string bin2);
private:
    static bool BinaryGreaterOrEqual(std::string a, std::string b);
};

#endif // CALCULATOR_H
