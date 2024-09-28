#ifndef PAYMENTSYSTEM_H
#define PAYMENTSYSTEM_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class paymentSystem;
}

class PaymentSystem : public QWidget
{
    Q_OBJECT

public:
    explicit PaymentSystem(QWidget *parent = nullptr, double initialBalance = 0.0);
    ~PaymentSystem();

signals:
    void balanceUpdated(double newBalance);

protected:
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onCoinButtonClicked();
    void onConfirmClicked();
    void onCancelClicked();

private:
    Ui::paymentSystem *ui;
    QLabel *backgroundLabel;

    double initialBalance;
    double currentBalance;
};

#endif // PAYMENTSYSTEM_H
