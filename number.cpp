#include <string>
#include <stdexcept>
#include <cmath>
#include "Number.h"

Number::Number(const std::string& valor, int base) {
    if (base < 2 || base > 36)
        throw std::invalid_argument("Base inválida.");

    size_t dotPos = valor.find('.');
    std::string intPart = valor.substr(0, dotPos);
    std::string fracPart = (dotPos != std::string::npos) ? valor.substr(dotPos + 1) : "";

    // Verificar se o número é negativo
    bool isNegative = false;
    if (!intPart.empty() && intPart[0] == '-') {
        isNegative = true;
        intPart = intPart.substr(1);  // Remover o sinal negativo da parte inteira
    }

    // Parte inteira
    double decimal = 0.0;
    int exp = 0;
    for (int i = intPart.size() - 1; i >= 0; --i) {
        char c = intPart[i];
        int digit;
        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'A' && c <= 'Z') digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10;
        else throw std::invalid_argument("Caractere inválido.");

        if (digit >= base) throw std::invalid_argument("Dígito fora da base.");

        decimal += digit * std::pow(base, exp++);
    }

    // Parte fracionária
    double fracMultiplier = 1.0 / base;
    for (char c : fracPart) {
        int digit;
        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'A' && c <= 'Z') digit = c - 'A' + 10;
        else if (c >= 'a' && c <= 'z') digit = c - 'a' + 10;
        else throw std::invalid_argument("Caractere inválido.");

        if (digit >= base) throw std::invalid_argument("Dígito fora da base.");

        decimal += digit * fracMultiplier;
        fracMultiplier /= base;
    }

    // Se o número for negativo, inverter o sinal
    if (isNegative) decimal = -decimal;

    // Transformar o double resultante para string
    m_value = std::to_string(decimal);
};

std::string Number::ValueToBase(int base, int precisaoFracao) {
    if (base < 2 || base > 36)
        throw std::invalid_argument("Base inválida.");

    static const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    double decimal = std::stod(m_value); // converte string para double
    if (decimal == 0.0)
        return "0";

    // Verificar se o número é negativo
    bool isNegative = decimal < 0;
    if (isNegative) decimal = -decimal;

    // Parte inteira
    long long intPart = static_cast<long long>(decimal);
    double fracPart = decimal - intPart;

    std::string intResult;
    do {
        int digit = intPart % base;
        intResult = digits[digit] + intResult;
        intPart /= base;
    } while (intPart > 0);

    // Parte fracionária
    std::string fracResult;
    if (fracPart > 0.0) {
        fracResult += ".";
        for (int i = 0; i < precisaoFracao && fracPart > 0.0; ++i) {
            fracPart *= base;
            int digit = static_cast<int>(fracPart);
            fracResult += digits[digit];
            fracPart -= digit;
        }
    }

    if (isNegative) return "-" + intResult + fracResult;
    else return intResult + fracResult;
};
