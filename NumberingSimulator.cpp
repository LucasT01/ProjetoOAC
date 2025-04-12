#include <iostream>
#include <string>

using namespace std;

//Cabeçalho das funções.
string DecimalToBinary(int numero);


int main (){

  //Recebe o número decimal para binário, converte e mostra na tela.
    cout << "Digite um número decimal: ";
    int decimal;
    cin >> decimal;

    string binario = DecimalToBinary(decimal);
    cout << "Binario: " << binario << endl;
  
    return 0;
}

//Função para converter um numero decimal em binario.
string DecimalToBinary(int numero)
{

string binario;

while (numero > 0)
{
  
if (numero == 0) return "0";

//Divisão do número por 2, e o resto da divisão é armazenado em uma variável char, através do auxílio da soma com o char de zero.
char bit = (numero % 2) + '0';  
binario = bit + binario; // Coloca o bit encontrado à esquerda no numero binario que estamos encontrando, para a correta ordem do numero binario.
numero /= 2; // Divide o número por 2 e armazena nele mesmo.
}
return binario; 
}
