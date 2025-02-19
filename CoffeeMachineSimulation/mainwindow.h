#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CoffeeRecipes.h" // For CoffeeType
#include <QPropertyAnimation>
#include <QTimer>

#include "mainwindow.h"
#include "ui_mainwindow.h"

// ADD these lines to fix 'invalid use of incomplete type'
#include "MaintenanceModel.h"
#include "LoggerModel.h"
#include "CoffeeRecipes.h"

// Possibly also include the others if you use them
#include "PaymentModel.h"
#include "InventoryModel.h"
#include "BrewingModel.h"
#include "BrewingEngine.h"
#include "Config.h"

#include <QMessageBox>
#include <QInputDialog>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void orderEspresso();
    void orderCappuccino();
    void orderLatte();
    void addFunds();
    void refillInventory();
    void checkMaintenance();
    void performMaintenance();
    void showLogs();
    void updateUI();
    void appendLog(const QString &entry);
    void appendBrewingStep(const QString &step);
    void updateMenuResources();
    void updateCoffeeCup(int level);

    void toggleLogs();
  //  void on_btnShowLogs_clicked();

private:
    // -------------- Add the missing function --------------
    void orderCoffee(CoffeeType type, double price);

    Ui::MainWindow *ui;

    // Your models
    PaymentModel    *payment;
    InventoryModel *inventory;
    BrewingModel   *brewing;
    MaintenanceModel *maintenance;
    LoggerModel    *logger;

    QPropertyAnimation *coffeeAnimation;
    void animateCoffeeFill();
    QTimer *coffeeFillTimer;
    int coffeeFillLevel;
    void startCoffeeFill();
    void updateCoffeeFill();
    int orderCount = 0;
};

#endif // MAINWINDOW_H
