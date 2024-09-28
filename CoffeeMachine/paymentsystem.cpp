#include "paymentsystem.h"
#include "ui_paymentsystem.h"
#include <QPixmap>
#include <QDebug>
#include <QPushButton>
#include "Globals.h"

double balance = 0.0;


PaymentSystem::PaymentSystem(QWidget *parent, double initialBalance) :
    QWidget(parent),
    ui(new Ui::paymentSystem),
    backgroundLabel(new QLabel(this)),
    initialBalance(initialBalance),
    currentBalance(initialBalance)
{
    ui->setupUi(this);
    QPixmap backgroundPixmap(":/new/prefix1/PaymentSystem.jpg");
    if (backgroundPixmap.isNull()) {
        qDebug() << "Failed to load background image";
    } else {
        // Set the pixmap to the label
        backgroundLabel->setPixmap(backgroundPixmap);
        // Set the label to fill the widget
        backgroundLabel->setGeometry(this->rect());
        backgroundLabel->setScaledContents(true);
        // Ensure the background label is behind other widgets
        backgroundLabel->lower();
    }
    // Background image setup (omitted for brevity)

    // Connect coin buttons
    connect(ui->tenCent, &QPushButton::clicked, this, &PaymentSystem::onCoinButtonClicked);
    connect(ui->twentyCent, &QPushButton::clicked, this, &PaymentSystem::onCoinButtonClicked);
    connect(ui->thirtyCent, &QPushButton::clicked, this, &PaymentSystem::onCoinButtonClicked);
    connect(ui->coinOneEuro, &QPushButton::clicked, this, &PaymentSystem::onCoinButtonClicked);
    connect(ui->coinTwoEuro, &QPushButton::clicked, this, &PaymentSystem::onCoinButtonClicked);

    // Connect Confirm and Cancel buttons
    connect(ui->Confirm, &QPushButton::clicked, this, &PaymentSystem::onConfirmClicked);
    connect(ui->Cancel, &QPushButton::clicked, this, &PaymentSystem::onCancelClicked);

    // Display the initial balance
    ui->label->setText(QString("New Balance: %1€").arg(currentBalance, 0, 'f', 2));
}

PaymentSystem::~PaymentSystem()
{
    delete ui;
}

void PaymentSystem::resizeEvent(QResizeEvent *event)
{
    if (backgroundLabel) {
        backgroundLabel->setGeometry(this->rect());
    }
    QWidget::resizeEvent(event);
}

void PaymentSystem::onCoinButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button)
        return;

    double amount = 0.0;

    if (button == ui->tenCent)
        amount = 0.10;
    else if (button == ui->twentyCent)
        amount = 0.20;
    else if (button == ui->thirtyCent)
        amount = 0.50;
    else if (button == ui->coinOneEuro)
        amount = 1.00;
    else if (button == ui->coinTwoEuro)
        amount = 2.00;

    currentBalance += amount;

    // Update the balance label
    ui->label->setText(QString("New Balance: %1€").arg(currentBalance, 0, 'f', 2));
}

void PaymentSystem::onConfirmClicked()
{
    emit balanceUpdated(currentBalance);
    this->close();
}

void PaymentSystem::onCancelClicked()
{
    currentBalance = initialBalance;
    this->close();
}
