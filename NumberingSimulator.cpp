#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//Cabeçalho das funções.
string DecimalToBinary(double numero); 
double BinaryToDecimal(string binario);

double OctalToDecimal(double octal); // Petronilo Bion
double DecimalToOctal(double decimal); // Petronilo Bion

// int HexadecimalToDecimal(string hexa);
// string DecimalToHexadecimal(int decimal);
// string BinaryToOctal(string binary);
// string BinaryToHexadecimal(string binary);

//double Add(double numero1, double numero2, int base1, int base2);
//double Subtract(double numero1, double numero2, int base1, int base2);
//double Multiply(double numero1, double numero2, int base1, int base2);
//double Divide(double numero1, double numero2, int base1, int base2);

int main (){
 int opcao = 0;
	//Menu principal.
    while (true) { 
        cout << "=== MENU PRINCIPAL ===" << endl;
        cout << "1. Conversao de numeros" << endl;
        cout << "2. Operacoes com numeros" << endl;
        cout << "0. Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int OpcaoConversao = 0; 
		//Submenu de Conversões.
            cout << "\n=== MENU DE CONVERSAO ===" << endl;
            cout << "1. Decimal para Binario" << endl;
            cout << "2. Binario para Decimal" << endl;
            cout << "3. Decimal para Octal" << endl;
            cout << "4. Octal para Decimal" << endl;
            // A ser adicionado mais funções.
            cout << "Escolha uma opcao: ";
            cin >> OpcaoConversao;

            if (OpcaoConversao == 1) {
                // Decimal para Binário
                cout << "Digite um numero decimal: ";
                double decimal;
                cin >> decimal;

                string binario = DecimalToBinary(decimal);
                cout << "Binario: " << binario << endl;
            }
            else if (OpcaoConversao == 2) {
                // Binário para Decimal
                cout << "Digite um numero binario: ";
                string binario;
                cin >> binario;

                double decimal = BinaryToDecimal(binario);
                cout << "Decimal de " << binario << ": " << decimal << endl;
            }
            else if (OpcaoConversao == 3) {
                // Decimal para Octal
                cout << "Digite um numero decimal: ";
                double decimal;
                cin >> decimal;

                double octal = DecimalToOctal(decimal);
                cout << "Octal: " << octal << endl;
            }
            else if (OpcaoConversao == 4) {
                // Octal para Decimal
                cout << "Digite um numero octal: ";
                double octal;
                cin >> octal;

                double decimal = OctalToDecimal(octal);
                cout << "Decimal: " << decimal << endl;
            }
            else {
                cout << "Opcao invalida!" << endl;
            }
        }
        else if (opcao == 2) {
            int OpcaoOperacao = 0;
		//Submenu de Operações.
            cout << "\n=== MENU DE OPERACOES ===" << endl;
            cout << "1. Somar dois numeros" << endl;
            cout << "2. Subtrair dois numeros" << endl;
            cout << "3. Multiplicar dois numeros" << endl;
            cout << "4. Dividir dois numeros" << endl;
            cout << "Escolha uma opcao: ";
            cin >> OpcaoOperacao;

            //cout << "Digite o primeiro numero: ";
            // cout << "Escolha a base do primeiro numero: "; << endl;
	    //cout << 1 - binario, 2 - octal, 3 - decimal, 4 - hexadecimal " << endl;
            // cin >> base1;
            // cout << "Digite o primeiro numero: ";
            // cin >> numero1;

            // cout << "Escolha a base do segundo numero: ";
            //cout << 1 - binario, 2 - octal, 3 - decimal, 4 - hexadecimal " << endl;
            // cin >> base2;
            // cout << "Digite o segundo numero: ";
            // cin >> numero2;

	    //AQUI IMPLEMENTAR A CONVERSÃO DE NUMERO1 E NUMERO2 ANTES DAS OPERAÇÕES.

            // if (OpcaoOperacao == 1) Add(numero1, numero2, base1, base2);
		
            // if (OpcaoOperacao == 2) Subtract(numero1, numero2, base1, base2);

	    // if (OpcaoOperacao == 3) Multiply(numero1, numero2, base1, base2);

	    // if (OpcaoOperacao == 4) Divide(numero1, numero2, base1, base2);

            cout << "Operacoes ainda serao implementadas" << endl;
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
