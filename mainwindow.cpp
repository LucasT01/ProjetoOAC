#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "number.h"
#include "calculator.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

string str_value, str_result;

int original_base, converted_base;

void MainWindow::on_bttnConvert_clicked()
{
    try{
        str_value = ui->strValue->text().toStdString();
        original_base = ui->intBaseOriginal->currentText().toInt();
        converted_base = ui->intBaseConverted->currentText().toInt();
        Number number(str_value,original_base);
        str_result = number.ValueToBase(converted_base);
        ui->strResult->setText(QString::fromStdString(str_result));
    } catch (const std::invalid_argument& e) {
        // Captura o erro e exibe a mensagem de exceção na QLineEdit
        ui->strResult->setText(QString::fromStdString(e.what()));
    }
}

void MainWindow::calculateAndDisplay(std::function<std::string(const std::string&, const std::string&)> operation)
{
    try {
        // Pega os valores e bases
        std::string value1 = ui->strValueCalc1->text().toStdString();
        int base1 = ui->intBaseOriginalCalc1->currentText().toInt();
        Number num1(value1, base1);

        std::string value2 = ui->strValueCalc2->text().toStdString();
        int base2 = ui->intBaseOriginalCalc2->currentText().toInt();
        Number num2(value2, base2);

        int targetBase = ui->intBaseConvertedCalc->currentText().toInt();

        // Executa a operação recebida
        std::string binResult = operation(
            num1.ValueToBase(2),
            num2.ValueToBase(2)
            );

        // Converte o resultado para a base final
        Number result(binResult, 2);
        std::string finalResult = result.ValueToBase(targetBase);

        // Mostra no campo de resultado
        ui->strResultCalc->setText(QString::fromStdString(finalResult));

    } catch (const std::invalid_argument& e) {
        // Se der erro, mostra a mensagem
        ui->strResultCalc->setText(QString::fromStdString(e.what()));
    }
}

void MainWindow::on_bttnAdd_clicked()
{
    calculateAndDisplay(Calculator::add);
}

void MainWindow::on_bttnSubtract_clicked()
{
    calculateAndDisplay(Calculator::subtract);
}


void MainWindow::on_bttnDivide_clicked()
{
    calculateAndDisplay(Calculator::divide);
}


void MainWindow::on_bttnMultiply_clicked()
{
    calculateAndDisplay(Calculator::multiply);
}

