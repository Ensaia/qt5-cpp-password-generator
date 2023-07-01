#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->passwordLengthSpinBox->setValue(8);
    ui->passwordLengthSpinBox->setMinimum(6);
    ui->passwordLengthSpinBox->setMaximum(20);

    ui->upperCapitalsCheckBox->setChecked(true);
    ui->lowerCapitalscheckBox->setChecked(true);
    ui->numbersCheckBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_passwordGeneratorPushButton_clicked()
{
    PasswdGenerator passwordGenerator;
    PasswdGenerator::SymbolTypes types;

    if(ui->upperCapitalsCheckBox->isChecked()){
        types.setFlag(PasswdGenerator::Uppercase);
    }
    if(ui->lowerCapitalscheckBox->isChecked()){
        types.setFlag(PasswdGenerator::Lowercase);
    }
    if(ui->numbersCheckBox->isChecked()){
        types.setFlag(PasswdGenerator::Digits);
    }
    if(ui->symbolsCheckBox->isChecked()){
        types.setFlag(PasswdGenerator::Symbols);
    }

    passwordGenerator.setTypes(types);
    QString password = passwordGenerator.generate(ui->passwordLengthSpinBox->value());
    ui->passwordLineEdit->setText(password);
}


void MainWindow::on_copyPasswordPushButton_clicked()
{
    auto clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->passwordLineEdit->text());
}

