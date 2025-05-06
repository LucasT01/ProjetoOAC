# Projeto OAC

## Objetivo

O **Projeto OAC** é um software educacional desenvolvido para realizar:

* Conversão de números entre diferentes bases numéricas (2, 8, 10, 16).
* Operações aritméticas básicas (adição, subtração, multiplicação e divisão) entre números de bases variadas.

Seu objetivo é auxiliar no ensino de sistemas de numeração e operações entre diferentes bases, conceitos fundamentais na disciplina de Organização e Arquitetura de Computadores (OAC).

O projeto possui uma interface gráfica desenvolvida com **Qt Creator**, e toda a lógica de conversão e cálculo é implementada em **C++**.

---

## Estrutura do Projeto

O projeto é organizado da seguinte forma:

* **Build files**:

  * `CMakeLists.txt`

* **Formulário Qt**:

  * `mainwindow.ui` — Define a interface gráfica da aplicação.

* **Cabeçalhos (Headers)**:

  * `number.h` — Define a classe `Number`.
  * `calculator.h` — Define a classe `Calculator`.
  * `mainwindow.h` — Define a classe `MainWindow`.

* **Código-fonte**:

  * `number.cpp`
  * `calculator.cpp`
  * `mainwindow.cpp`
  * `main.cpp`

---

## Descrição das Classes

### `Number`

* Responsável pela conversão entre bases numéricas.
* **Atributo principal**:

  * `m_value`: número sempre armazenado internamente na **base decimal**.
* **Construtor**:

  * Recebe um valor (`std::string`) e a base original (`int`).
  * Converte o valor da base original para decimal e armazena em `m_value`.
* **Método**:

  * `std::string ValueToBase(int base, int precisaoFracao = 4)`: converte o valor decimal interno (`m_value`) para a base desejada, retornando o resultado como `std::string`.

---

### `Calculator`

* Realiza operações aritméticas sobre **números binários**.
* **Métodos**:

  * `static std::string add(const std::string bin1, const std::string bin2)`
  * `static std::string subtract(const std::string bin1, const std::string bin2)`
  * `static std::string multiply(const std::string bin1, const std::string bin2)`
  * `static std::string divide(const std::string bin1, const std::string bin2)`

Todos os métodos recebem **números binários** como `std::string` e retornam o **resultado também em binário**.

---

### `MainWindow`

* Gerencia a interface gráfica e a interação com o usuário.
* Possui duas seções principais:

  * **Conversão numérica**:

    * Campo para inserção do valor.
    * Combobox para seleção da base original.
    * Combobox para seleção da base de destino.
    * Exibição do resultado em campo somente leitura.

  * **Calculadora**:

    * Dois campos de entrada para números e suas respectivas bases.
    * Botões de operação (+, -, ×, ÷).
    * Combobox para selecionar a base do resultado.
    * Resultado exibido em campo somente leitura.

---

## Como Usar

### Compilação

1. Abra o projeto no **Qt Creator**.
2. Verifique se o **CMake** está configurado corretamente (o projeto já fornece um `CMakeLists.txt`).
3. Compile e execute diretamente pela IDE.

### Requisitos

* Qt Creator (versão 6 ou superior recomendada)
* Kit de desenvolvimento C++ configurado (GCC, MinGW ou MSVC)

---

## Considerações

* A conversão e as operações são limitadas as bases de 2, 8, 10 e 16 conforme especificado.
* As operações entre números são realizadas no sistema binário internamente.
* A precisão para operações com frações é limitada conforme o projeto define (tipicamente até 4 casas decimais).

---
