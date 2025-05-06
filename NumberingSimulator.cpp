#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

// Protótipos das funções
string DecimalToBinary(double numero);
double BinaryToDecimal(string binario);
double OctalToDecimal(double octal);
double DecimalToOctal(double decimal);
int HexadecimalToDecimal(string hexa);
string DecimalToHexadecimal(int decimal);
bool BinaryGreaterOrEqual(string a, string b);
string Add(string num1, string num2);
string Subtract(string num1, string num2);
string Multiply(string num1, string num2);
string Divide(string num1, string num2);
bool isValidBinary(string bin);

int main() {
    int opcao = 0;
    // Menu principal
    while (true) { 
        cout << "=== MENU PRINCIPAL ===" << endl;
        cout << "1. Conversao de numeros" << endl;
        cout << "2. Operacoes com numeros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int OpcaoConversao = 0; 
            // Submenu de Conversões
            cout << "\n=== MENU DE CONVERSAO ===" << endl;
            cout << "1. Decimal para Binario" << endl;
            cout << "2. Binario para Decimal" << endl;
            cout << "3. Decimal para Octal" << endl;
            cout << "4. Octal para Decimal" << endl;
            cout << "5. Decimal para Hexadecimal" << endl;
            cout << "6. Hexadecimal para Decimal" << endl;
            cout << "Escolha uma opcao: ";
            cin >> OpcaoConversao;

            if (OpcaoConversao == 1) {
                cout << "Digite um numero decimal: ";
                double decimal;
                cin >> decimal;
                cout << "Binario: " << DecimalToBinary(decimal) << endl;
            }
            else if (OpcaoConversao == 2) {
                cout << "Digite um numero binario: ";
                string binario;
                cin >> binario;
                if (!isValidBinary(binario)) {
                    cout << "Numero binario invalido!" << endl;
                    continue;
                }
                cout << "Decimal: " << BinaryToDecimal(binario) << endl;
            }
            else if (OpcaoConversao == 3) {
                cout << "Digite um numero decimal: ";
                double decimal;
                cin >> decimal;
                cout << "Octal: " << DecimalToOctal(decimal) << endl;
            }
            else if (OpcaoConversao == 4) {
                cout << "Digite um numero octal: ";
                double octal;
                cin >> octal;
                cout << "Decimal: " << OctalToDecimal(octal) << endl;
            }
            else if (OpcaoConversao == 5) {
                cout << "Digite um numero decimal: ";
                int decimal;
                cin >> decimal;
                cout << "Hexadecimal: " << DecimalToHexadecimal(decimal) << endl;
            }
            else if (OpcaoConversao == 6) {
                cout << "Digite um numero hexadecimal: ";
                string hexa;
                cin >> hexa;
                cout << "Decimal: " << HexadecimalToDecimal(hexa) << endl;
            }
            else {
                cout << "Opcao invalida!" << endl;
            }
        }
        else if (opcao == 2) {
            int OpcaoOperacao = 0;
            cout << "\n=== MENU DE OPERACOES ===" << endl;
            cout << "1. Somar dois numeros" << endl;
            cout << "2. Subtrair dois numeros" << endl;
            cout << "3. Multiplicar dois numeros" << endl;
            cout << "4. Dividir dois numeros" << endl;
            cout << "Escolha uma opcao: ";
            cin >> OpcaoOperacao;

            int base1, base2, base3;
            string num1_str, num2_str;
            double num1_dbl, num2_dbl;

            cout << "Escolha a base do primeiro numero (1-binario, 2-octal, 3-decimal, 4-hexadecimal): ";
            cin >> base1;
            
            if (base1 == 1) {
                cout << "Digite o numero binario: ";
                cin >> num1_str;
                if (!isValidBinary(num1_str)) {
                    cout << "Numero binario invalido!" << endl;
                    continue;
                }
            } else {
                cout << "Digite o numero: ";
                if (base1 == 3) cin >> num1_dbl;
                else cin >> num1_str;
            }

            cout << "Escolha a base do segundo numero (1-binario, 2-octal, 3-decimal, 4-hexadecimal): ";
            cin >> base2;
            
            if (base2 == 1) {
                cout << "Digite o numero binario: ";
                cin >> num2_str;
                if (!isValidBinary(num2_str)) {
                    cout << "Numero binario invalido!" << endl;
                    continue;
                }
            } else {
                cout << "Digite o numero: ";
                if (base2 == 3) cin >> num2_dbl;
                else cin >> num2_str;
            }

            cout << "Escolha a base para o resultado (1-binario, 2-octal, 3-decimal, 4-hexadecimal): ";
            cin >> base3;

            // Conversão para binário
            string binario1, binario2;
            
            if (base1 == 1) binario1 = num1_str;
            else if (base1 == 2) binario1 = DecimalToBinary(OctalToDecimal(stod(num1_str)));
            else if (base1 == 3) binario1 = DecimalToBinary(num1_dbl);
            else if (base1 == 4) binario1 = DecimalToBinary(HexadecimalToDecimal(num1_str));
            
            if (base2 == 1) binario2 = num2_str;
            else if (base2 == 2) binario2 = DecimalToBinary(OctalToDecimal(stod(num2_str)));
            else if (base2 == 3) binario2 = DecimalToBinary(num2_dbl);
            else if (base2 == 4) binario2 = DecimalToBinary(HexadecimalToDecimal(num2_str));

            string resultado;
            if (OpcaoOperacao == 1) {
                resultado = Add(binario1, binario2);
            } 
            else if (OpcaoOperacao == 2) {
                resultado = Subtract(binario1, binario2);
            } 
            else if (OpcaoOperacao == 3) {
                resultado = Multiply(binario1, binario2);
            } 
            else if (OpcaoOperacao == 4) {
                resultado = Divide(binario1, binario2);
            } 
            else {
                cout << "Opcao invalida!" << endl;
                continue;
            }

            // Exibição do resultado na base escolhida
            if (resultado.find("ERRO") != string::npos) {
                cout << resultado << endl;
                continue;
            }

            if (base3 == 1) {
                cout << "Resultado: " << resultado << endl;
            }
            else if (base3 == 2) {
                cout << "Resultado: " << DecimalToOctal(BinaryToDecimal(resultado)) << endl;
            }
            else if (base3 == 3) {
                cout << "Resultado: " << BinaryToDecimal(resultado) << endl;
            }
            else if (base3 == 4) {
                cout << "Resultado: " << DecimalToHexadecimal(static_cast<int>(BinaryToDecimal(resultado))) << endl;
            }
        }
        else if (opcao == 0) {
            cout << "Saindo do programa..." << endl;
            break; 
        }
        else {
            cout << "Opcao invalida! Tente novamente." << endl;
        }
    }
    return 0;
}

// Função para validar números binários
bool isValidBinary(string bin) {
    size_t dot_pos = bin.find('.');
    if (dot_pos != string::npos) {
        bin.erase(dot_pos, 1);
    }
    for (char c : bin) {
        if (c != '0' && c != '1') {
            return false;
        }
    }
    return true;
}

// Função para comparar números binários
bool BinaryGreaterOrEqual(string a, string b) {
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

//------------------------------------------------------------------------------------------------

//Função para converter um numero decimal em binario.
string DecimalToBinary(double numero)
{
    if (numero == 0) return "0";
    string binario;
     int precisao = 6; //precisão de 6 casas após a vírgula.

    // Separando a parte inteira da fracionária
    int ParteInt = static_cast<int>(numero); //Pega apenas a parte do número antes da vírgula.
    double ParteFracionaria = numero - ParteInt;

    while (ParteInt > 0) {
	//Divisão do número por 2, e o resto da divisão é armazenado em uma variável char, através do auxílio da soma com o char de zero.
        char bit = (ParteInt % 2) + '0';
        binario = bit + binario; // Coloca o bit encontrado à esquerda no numero binario que estamos encontrando, para a correta ordem do numero binario.
        ParteInt /= 2; // Divide o número por 2 e armazena nele mesmo.
    }

    // Se não houver parte fracionária, retorna aqui.
    if (ParteFracionaria == 0) {
        return binario;
    }
     binario += '.'; // adiciona um ponto para separar as duas partes.

    while (precisao-- && ParteFracionaria > 0) { // enquanto precisão é maior que 0 e enquanto a parte fracionária ainda não virou 0.
        ParteFracionaria *= 2;  // Multiplica a parte fracionária por 2. O número inteiro dessa multiplicação será o próximo dígito binário.
        if (ParteFracionaria >= 1) {
            binario += '1';  // Se a parte fracionária multiplicada for maior ou igual a 1, adiciona 1 ao binário, pois "passou do inteiro".
            ParteFracionaria -= 1; //subtrai 1 para continuar trabalhando só com a nova parte fracionária.
        } else {
            binario += '0'; //Se a parte fracionária multiplicada for menor que 1, adiciona 0.
        }
    }
	
    return binario; 
}

//Função para converter um numero binario em decimal.
double BinaryToDecimal(string binario) {
   double decimal = 0.0;
    int pontoPos = binario.find('.'); 
    // Procura a posição do ponto decimal ('.').
    // Se não encontrar, retorna string::npos.

    if (pontoPos == string::npos) {
        // Se não encontrou ponto, é só parte inteira
        pontoPos = binario.size(); 
    }

    // Parte inteira (antes do ponto)
    for (int i = 0; i < pontoPos; i++) {
        if (binario[i] == '1') {
            decimal += pow(2, pontoPos - 1 - i);
            // Cada '1' vale 2 elevado à posição (contando de trás pra frente).
        }
    }

    // Parte fracionária (depois do ponto).
    for (int i = pontoPos + 1; i < binario.size(); i++) {
        if (binario[i] == '1') {
            decimal += pow(2, -(i - pontoPos));
            // Cada '1' vale 2 elevado ao negativo da posição após o ponto.
        }
    }

    return decimal;
}
	
double OctalToDecimal(double octal) {
    int i = 0, resto;
    double decimal = 0.0;
    int inteiro = (int)octal;
    double fracao = octal - inteiro;

    // Conversão da parte inteira
    while (inteiro != 0)
    {
        resto = inteiro%10;
        inteiro/=10;
        decimal += resto*pow(8,i++);
    }
    i = 1;

    // Conversão da parte fracionária
    while(fracao != 0 && i <= 6){ // Limite de precisão: 6 dígitos
        fracao *= 10;
        resto = round(fracao);
        decimal += resto*pow(8,-i++);
        fracao -= resto;
    }
    return decimal;
}

double DecimalToOctal(double decimal) {
    int i = 0, resto;
    double octal = 0.0;
    int inteiro = (int)decimal;
    double fracao = decimal - inteiro;

    // Conversão da parte inteira
    while (inteiro != 0) {
        resto = inteiro%8;
        inteiro /= 8;
        octal += resto * pow(10, i++);
    }

    // Conversão da parte fracionária
    i = 1;
    while (fracao != 0.0 && i <= 6) { // Limite de precisão: 6 dígitos
        fracao *= 8;
        resto = round(fracao);
        octal += resto*pow(10, -i++);
        fracao -= resto;
    }

    return octal;
}


int HexadecimalToDecimal(string hexa){

 int decimal = 0;
    int tamanho = hexa.size();
    
    for (int i = 0; i < tamanho; i++) {
        char c = toupper(hexa[i]);
        int valor;
        
        if (c >= '0' && c <= '9') {
            valor = c - '0';
        } else if (c >= 'A' && c <= 'F') {
            valor = 10 + (c - 'A');
        } else {
            // Caractere inválido
            return -1;
        }
        
        decimal = decimal * 16 + valor;
    }
    
    return decimal;
}

string DecimalToHexadecimal(int decimal) {
    if (decimal == 0) return "0";
    
    string hexa;
    while (decimal > 0) {
        int resto = decimal % 16;
        char digito;
        
        if (resto < 10) {
            digito = '0' + resto;
        } else {
            digito = 'A' + (resto - 10);
        }
        
        hexa = digito + hexa;
        decimal /= 16;
    }
    
    return hexa;
}

//Função que adiciona dois números binários:
string Add(string numA, string numB){
	
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

string Subtract(string num1, string num2) {
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

string Multiply(string num1, string num2) {
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


string Divide(string num1, string num2) {
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
        remainder = Multiply(remainder, "10");
        remainder = Add(remainder, string(1, dividend[i]));
        
        // Verifica se podemos subtrair o divisor
        string product = Multiply(divisor, quotient + "1");
        if (BinaryGreaterOrEqual(remainder, divisor)) {
            remainder = Subtract(remainder, divisor);
            quotient = Add(quotient, "1");
        } else {
            quotient = Multiply(quotient, "10"); // Shift left
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


























