#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"
#include "paymentsystem.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString existingText = ui->Balance->text();

    QString updatedText = existingText + " " + QString::number(balance, 'f', 2);

    ui->Balance->setText(updatedText);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ChargeBalance_clicked()
{
    PaymentSystem *paymentSystem = new PaymentSystem(this,balance);
    connect(paymentSystem, &PaymentSystem::balanceUpdated, this, &MainWindow::updateBalance);

    paymentSystem->show();
}

void MainWindow::updateBalance(double newBalance)
{
    balance = newBalance;

    // Update the balance label
    ui->Balance->setText(QString("Balance: %1€").arg(balance, 0, 'f', 2));
}
