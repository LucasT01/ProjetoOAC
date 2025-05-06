#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void calculateAndDisplay(std::function<std::string(const std::string&, const std::string&)> operation);

private slots:
    void on_bttnConvert_clicked();

    void on_bttnAdd_clicked();

    void on_bttnSubtract_clicked();

    void on_bttnDivide_clicked();

    void on_bttnMultiply_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
