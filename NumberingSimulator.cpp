#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

//Cabeçalho das funções.
string DecimalToBinary(double numero); 
double BinaryToDecimal(string binario);

double OctalToDecimal(double octal); // Petronilo Bion
double DecimalToOctal(double decimal); // Petronilo Bion

// int HexadecimalToDecimal(string hexa);
// string DecimalToHexadecimal(int decimal);

string Add(string num1, string num2);
//string Subtract(string num1, string num2);
//string Multiply(string num1, string num2);
//string Divide(string num1, string num2);

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
        else if (opcao == 2) 
	{
            int OpcaoOperacao = 0;
		//Submenu de Operações.
            cout << "\n=== MENU DE OPERACOES ===" << endl;
            cout << "1. Somar dois numeros" << endl;
            cout << "2. Subtrair dois numeros" << endl;
            cout << "3. Multiplicar dois numeros" << endl;
            cout << "4. Dividir dois numeros" << endl;
            cout << "Escolha uma opcao: ";
            cin >> OpcaoOperacao;

            cout << "Escolha a base do primeiro numero (digite um numero do 1 ao 4): " << endl;
	    cout << "1 - binario, 2 - octal, 3 - decimal, 4 - hexadecimal " << endl;  
             int base1;
             cin >> base1;
            cout << "Digite o primeiro numero: ";
	    int numero1;
            cin >> numero1;

            cout << "Escolha a base do segundo numero (digite um numero do 1 ao 4): ";
            cout << "1 - binario, 2 - octal, 3 - decimal, 4 - hexadecimal " << endl;
	     int base2;
             cin >> base2;
             cout << "Digite o segundo numero: ";
	     int numero2;
             cin >> numero2;

	     cout << "Escolha a base que voce quer para o resultado (digite um numero do 1 ao 4): " << endl;
	    cout << "1 - binario, 2 - octal, 3 - decimal, 4 - hexadecimal " << endl;  
             int base3;
             cin >> base3;

	    //Abaixo a conversão dos números para binário antes daa operações:

	    string binario1, binario2;

            if (base1 == 1) binario1 = to_string((int)numero1); // Se já é binário, converte pra string.
            else if (base1 == 2) binario1 = DecimalToBinary(OctalToDecimal(numero1)); // Octal -> Decimal -> Binário
            else if (base1 == 3) binario1 = DecimalToBinary(numero1); // Decimal -> Binário
            // else if (base1 == 4) binario1 = DecimalToBinary(HexadecimalToDecimal(numero1)); // Hexadecimal -> Decimal -> Binário.
            // (Essa função ainda não foi implementada)


            if (base2 == 1) binario2 = to_string((int)numero2);
            else if (base2 == 2) binario2 = DecimalToBinary(OctalToDecimal(numero2));
            else if (base2 == 3) binario2 = DecimalToBinary(numero2);
            // else if (base2 == 4) binario2 = DecimalToBinary(HexadecimalToDecimal(numero2));

	    //(EM CADA UMA DAS OPERAÇÕES ABAIXO, REALIZAR A CONVERSÃO DE VOLTA À BASE ORIGINAL (base3) FORNECIDA PELO USUÁRIO)
		
             if (OpcaoOperacao == 1){
		     
		    string soma = Add(binario1, binario2);
		     
		      if (base3 == 1)
		      {
		      cout << "Soma: " << soma << endl;
		      }
                      else if (base3 == 2)
		      {

			       cout << "Soma: " << DecimalToOctal(BinaryToDecimal(soma)) << endl;
		      }
                      else if (base3 == 3)
		      {
                               cout << "Soma: " << BinaryToDecimal(soma) << endl;
			      
		      }
		     
                      // else if (base3 == 4){
		     //cout << "A soma é: " <<  DecimalToHexadecimal(BinaryToDecimal(soma)) << endl; // Hexadecimal <- Decimal <- Binário.}
                      // (Essa função ainda não foi implementada)
		     
	     }

            // if (OpcaoOperacao == 2) Subtract(binario1, binario2);

	    // if (OpcaoOperacao == 3) Multiply(binario1, binario2);

	    // if (OpcaoOperacao == 4) Divide(binario1, binario2);


            cout << "Demais operacoes ainda serao implementadas" << endl;
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


// int HexadecimalToDecimal(string hexa){







// string DecimalToHexadecimal(int decimal){








//Função que adiciona dois núemros binários:
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







	
//string Subtract(string num1, string num2){










//string Multiply(string num1, string num2){









//string Divide(string num1, string num2){




























