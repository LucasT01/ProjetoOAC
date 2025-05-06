#include "calculator.h"
#include<string>
#include <algorithm>

using namespace std;

bool Calculator::BinaryGreaterOrEqual(string a, string b) {
    // Remove zeros à esquerda e pontos
    auto removeLeadingZeros = [](string &s) {
        size_t dot_pos = s.find('.');
        string int_part = (dot_pos != string::npos) ? s.substr(0, dot_pos) : s;
        int_part.erase(0, int_part.find_first_not_of('0'));
        if (int_part.empty()) int_part = "0";
        if (dot_pos != string::npos) {
            return int_part + s.substr(dot_pos);
        }
        return int_part;
    };

    a = removeLeadingZeros(a);
    b = removeLeadingZeros(b);

    // Compara comprimentos das partes inteiras
    size_t a_dot = a.find('.');
    size_t b_dot = b.find('.');

    string a_int = (a_dot != string::npos) ? a.substr(0, a_dot) : a;
    string b_int = (b_dot != string::npos) ? b.substr(0, b_dot) : b;

    if (a_int.length() > b_int.length()) return true;
    if (a_int.length() < b_int.length()) return false;

    // Compara bit a bit
    return a >= b;
}

//Função que adiciona dois números binários:
string Calculator::add(string numA, string numB){
    // Encontra o ponto nas duas strings.
    size_t pontoA = numA.find('.');
    size_t pontoB = numB.find('.');

    // Separa a parte inteira da parte fracionária.
    string inteiraA, fracA;
    if (pontoA != string::npos) {
        inteiraA = numA.substr(0, pontoA);
        fracA = numA.substr(pontoA + 1);
    } else {
        inteiraA = numA;
        fracA = "";
    }

    string inteiraB, fracB;
    if (pontoB != string::npos) {
        inteiraB = numB.substr(0, pontoB);
        fracB = numB.substr(pontoB + 1);
    } else {
        inteiraB = numB;
        fracB = "";
    }

    // Iguala o tamanho das partes fracionárias
    while (fracA.size() < fracB.size()) fracA += '0';
    while (fracB.size() < fracA.size()) fracB += '0';

    // Iguala o tamanho das partes inteiras
    while (inteiraA.size() < inteiraB.size()) inteiraA = '0' + inteiraA;
    while (inteiraB.size() < inteiraA.size()) inteiraB = '0' + inteiraB;

    string ResultadoFrac = "";
    int carry = 0;

    // Soma parte fracionária da direita para a esquerda.
    for (int i = fracA.size() - 1; i >= 0; i--) {
        int bitA = fracA[i] - '0';
        int bitB = fracB[i] - '0';
        int soma = bitA + bitB + carry;
        ResultadoFrac += (soma % 2) + '0';
        carry = soma / 2;
    }
    reverse(ResultadoFrac.begin(), ResultadoFrac.end()); //Inverte a ordem.

    string  ResultadoInt = "";

    // Soma parte inteira da direita para a esquerda.
    for (int i = inteiraA.size() - 1; i >= 0; i--) {
        int bitA = inteiraA[i] - '0';
        int bitB = inteiraB[i] - '0';
        int soma = bitA + bitB + carry;
        ResultadoInt += (soma % 2) + '0';
        carry = soma / 2;
    }

    if (carry != 0) {
        ResultadoInt += '1'; // Se sobrou carry, acrescenta no final
    }

    reverse(ResultadoInt.begin(), ResultadoInt.end());

    // Monta o resultado final.
    if (ResultadoFrac.empty()) {
        return ResultadoInt;
    } else {
        return ResultadoInt + "." + ResultadoFrac;
    }
}

string Calculator::subtract(string num1, string num2) {
    // Encontra os pontos decimais
    size_t ponto1 = num1.find('.');
    size_t ponto2 = num2.find('.');

    // Separa partes inteiras e fracionárias
    string int1 = (ponto1 != string::npos) ? num1.substr(0, ponto1) : num1;
    string frac1 = (ponto1 != string::npos) ? num1.substr(ponto1 + 1) : "";

    string int2 = (ponto2 != string::npos) ? num2.substr(0, ponto2) : num2;
    string frac2 = (ponto2 != string::npos) ? num2.substr(ponto2 + 1) : "";

    // Iguala os tamanhos
    while (int1.size() < int2.size()) int1 = '0' + int1;
    while (int2.size() < int1.size()) int2 = '0' + int2;

    while (frac1.size() < frac2.size()) frac1 += '0';
    while (frac2.size() < frac1.size()) frac2 += '0';

    string resultadoInt, resultadoFrac;
    int borrow = 0;

    // Subtrai parte fracionária (direita para esquerda)
    for (int i = frac1.size() - 1; i >= 0; i--) {
        int bit1 = frac1[i] - '0';
        int bit2 = frac2[i] - '0';

        bit1 -= borrow;
        borrow = 0;

        if (bit1 < bit2) {
            bit1 += 2;
            borrow = 1;
        }

        resultadoFrac = to_string(bit1 - bit2) + resultadoFrac;
    }

    // Subtrai parte inteira (direita para esquerda)
    for (int i = int1.size() - 1; i >= 0; i--) {
        int bit1 = int1[i] - '0';
        int bit2 = int2[i] - '0';

        bit1 -= borrow;
        borrow = 0;

        if (bit1 < bit2) {
            bit1 += 2;
            borrow = 1;
        }

        resultadoInt = to_string(bit1 - bit2) + resultadoInt;
    }

    // Remove zeros à esquerda
    while (resultadoInt.size() > 1 && resultadoInt[0] == '0') {
        resultadoInt.erase(0, 1);
    }

    // Remove zeros à direita na parte fracionária
    while (!resultadoFrac.empty() && resultadoFrac.back() == '0') {
        resultadoFrac.pop_back();
    }

    if (resultadoFrac.empty()) {
        return resultadoInt;
    } else {
        return resultadoInt + "." + resultadoFrac;
    }
}

string Calculator::multiply(string num1, string num2) {
    // Remove pontos decimais e calcula posição do ponto no resultado
    size_t ponto1 = num1.find('.');
    size_t ponto2 = num2.find('.');

    int casasDecimais = 0;
    if (ponto1 != string::npos) {
        casasDecimais += num1.size() - ponto1 - 1;
        num1.erase(ponto1, 1);
    }
    if (ponto2 != string::npos) {
        casasDecimais += num2.size() - ponto2 - 1;
        num2.erase(ponto2, 1);
    }

    // Multiplica os números como inteiros
    string resultado(num1.size() + num2.size(), '0');

    for (int i = num1.size() - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = num2.size() - 1; j >= 0; j--) {
            int produto = (num1[i] - '0') * (num2[j] - '0') +
                          (resultado[i + j + 1] - '0') + carry;
            carry = produto / 2;
            resultado[i + j + 1] = (produto % 2) + '0';
        }
        resultado[i] += carry;
    }

    // Remove zeros à esquerda
    size_t start_pos = resultado.find_first_not_of('0');
    if (start_pos != string::npos) {
        resultado = resultado.substr(start_pos);
    } else {
        resultado = "0";
    }

    // Insere o ponto decimal
    if (casasDecimais > 0) {
        if (casasDecimais >= resultado.size()) {
            resultado = string(casasDecimais - resultado.size() + 1, '0') + resultado;
        }
        resultado.insert(resultado.size() - casasDecimais, ".");

        // Remove zeros desnecessários após o ponto
        size_t ponto_pos = resultado.find('.');
        if (ponto_pos != string::npos) {
            size_t last_non_zero = resultado.find_last_not_of('0');
            if (last_non_zero == ponto_pos) {
                resultado.erase(ponto_pos);
            } else if (last_non_zero > ponto_pos) {
                resultado.erase(last_non_zero + 1);
            }
        }
    }

    return resultado.empty() ? "0" : resultado;
}


string Calculator::divide(string num1, string num2) {
    // Verifica divisão por zero
    bool isZero = true;
    for (char c : num2) {
        if (c != '0' && c != '.') {
            isZero = false;
            break;
        }
    }
    if (isZero) return "ERRO: Divisao por zero";

    // Encontra posições dos pontos decimais
    size_t dot1 = num1.find('.');
    size_t dot2 = num2.find('.');

    // Remove pontos decimais e calcula o deslocamento
    string int1 = (dot1 != string::npos) ? num1.substr(0, dot1) : num1;
    string frac1 = (dot1 != string::npos) ? num1.substr(dot1 + 1) : "";

    string int2 = (dot2 != string::npos) ? num2.substr(0, dot2) : num2;
    string frac2 = (dot2 != string::npos) ? num2.substr(dot2 + 1) : "";

    // Calcula o número de casas decimais no resultado
    int decimalPlaces = frac1.length() - frac2.length();

    // Cria números inteiros para divisão
    string dividend = int1 + frac1;
    string divisor = int2 + frac2;

    // Adiciona zeros para precisão (8 casas decimais)
    dividend += "00000000";
    decimalPlaces += 8;

    // Inicializa quociente e resto
    string quotient = "0";
    string remainder = "0";

    // Algoritmo de divisão binária
    for (size_t i = 0; i < dividend.length(); i++) {
        // Desloca o resto e adiciona o próximo dígito
        remainder = multiply(remainder, "10");
        remainder = add(remainder, string(1, dividend[i]));

        // Verifica se podemos subtrair o divisor
        string product = multiply(divisor, quotient + "1");
        if (BinaryGreaterOrEqual(remainder, divisor)) {
            remainder = subtract(remainder, divisor);
            quotient = add(quotient, "1");
        } else {
            quotient = multiply(quotient, "10"); // Shift left
        }
    }

    // Insere o ponto decimal
    if (decimalPlaces > 0) {
        while (quotient.length() <= decimalPlaces) {
            quotient = "0" + quotient;
        }
        quotient.insert(quotient.length() - decimalPlaces, ".");

        // Remove zeros desnecessários
        size_t dotPos = quotient.find('.');
        if (dotPos != string::npos) {
            size_t lastNonZero = quotient.find_last_not_of('0');
            if (lastNonZero == dotPos) {
                quotient.erase(dotPos);
            } else if (lastNonZero > dotPos) {
                quotient.erase(lastNonZero + 1);
            }
        }
    }

    // Remove zeros à esquerda
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty()) quotient = "0";
    if (quotient[0] == '.') quotient = "0" + quotient;

    return quotient;
}
