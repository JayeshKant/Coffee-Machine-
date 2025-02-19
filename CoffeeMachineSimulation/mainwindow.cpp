#include "mainwindow.h"
#include "ui_mainwindow.h"

// Must include the actual model headers for full definitions
#include "PaymentModel.h"
#include "InventoryModel.h"
#include "BrewingModel.h"
#include "BrewingEngine.h"
#include "MaintenanceModel.h"
#include "LoggerModel.h"
#include "CoffeeRecipes.h"
#include "Config.h"
#include <QTimer>

#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , payment(new PaymentModel())
    , inventory(new InventoryModel())
    , brewing(new BrewingModel()) // <-- pointer name "brewing"
    , maintenance(new MaintenanceModel())
    , logger(new LoggerModel())
{
    ui->setupUi(this);
    coffeeFillTimer = new QTimer(this);
    connect(coffeeFillTimer, &QTimer::timeout, this, &MainWindow::updateCoffeeFill);

    payment->addBalance(0.0);
    logger->logEvent("Initial funds added: $50.0");
    updateUI();
    // Connect signals from your UI buttons to slots
    connect(ui->btnEspresso, &QPushButton::clicked,
            this, &MainWindow::orderEspresso);
    connect(ui->btnCappuccino, &QPushButton::clicked,
            this, &MainWindow::orderCappuccino);
    connect(ui->btnLatte, &QPushButton::clicked,
            this, &MainWindow::orderLatte);

    // Connect logger to append general logs
    connect(logger, &LoggerModel::newLogEntry,
            this, &MainWindow::appendLog);

    connect(ui->btnAddFunds, &QPushButton::clicked,
            this, &MainWindow::addFunds);
    connect(ui->btnRefill, &QPushButton::clicked,
            this, &MainWindow::refillInventory);
    connect(ui->btnPerformMaintenance, &QPushButton::clicked,
            this, &MainWindow::performMaintenance);
    connect(ui->btnShowLogs, &QPushButton::clicked,
            this, &MainWindow::showLogs);

    connect(brewing, &BrewingModel::brewingStepChanged, this, &MainWindow::appendBrewingStep);
    ui->textLogViewer->setVisible(false);

    // Connect the button click to toggle visibility
    connect(ui->btnShowLogs, &QPushButton::clicked, this, &MainWindow::toggleLogs);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete payment;
    delete inventory;
    delete brewing;
    delete maintenance;
    delete logger;
}

// ================== Coffee Ordering ==================
void MainWindow::appendBrewingStep(const QString &step)
{
    qDebug() << "📌 UI Appending Step:" << step;

    ui->textBrewingSteps->append(step);
    ui->textBrewingSteps->ensureCursorVisible();  // Auto-scroll

    // Start coffee fill animation when dispensing starts
    if (step.contains("Dispensing Coffee")) {
        coffeeFillLevel = 0;
        coffeeFillTimer->start(200);  // Update every 200ms for a smooth effect
    }

    // **Display "Thanks for using our coffee machine" before clearing**
    if (step.contains("Brewing completed!")) {
        QTimer::singleShot(40000, this, [this]() {  // **Delay before showing message**
            ui->textBrewingSteps->clear();
            ui->textBrewingSteps->append("🙏 Thanks for using our coffee machine! ☕");

            // **Clear the message after an additional 5 seconds**
            QTimer::singleShot(5000, this, [this]() {
                ui->textBrewingSteps->clear();
            });
        });
    }

    QCoreApplication::processEvents();  // Immediate UI refresh
}


void MainWindow::updateCoffeeFill()
{
    if (coffeeFillLevel >= 100) {
        coffeeFillTimer->stop();  // Stop when full
        return;
    }

    coffeeFillLevel += 5;  // Increase in steps
    updateCoffeeCup(coffeeFillLevel);
}
void MainWindow::toggleLogs()
{
    // Toggle visibility of the log window
    bool isVisible = ui->textLogViewer->isVisible();
    ui->textLogViewer->setVisible(!isVisible);

    if (!isVisible) {
        // Clear and reload logs when shown
        ui->textLogViewer->clear();
        QStringList logs = logger->getLogs();
        for (const QString &logEntry : logs) {
            ui->textLogViewer->append(logEntry);
        }
    }
}



void MainWindow::updateCoffeeCup(int level)
{
    // Ensure level stays within 0-100 range
    level = qBound(0, level, 100);

    // More refined coffee cup shape and fill effect
    QString coffeeStyle = QString(
                              "QLabel#lblCoffeeCup {"
                              "   font-size: 24px;"  // Slightly reduced for balance
                              "   font-weight: bold;"
                              "   color: white;"
                              "   text-align: center;"
                              "   border-radius: 30px 30px 15px 15px;"  // More rounded cup
                              "   padding: 10px;"
                              "   border: 6px solid rgba(62, 39, 35, 0.8);"  // Semi-transparent brown border
                              "   min-width: 90px;"
                              "   min-height: 140px;"
                              "   background: qlineargradient(x1:0, y1:1, x2:0, y2:0, "
                              "       stop:0 rgba(62, 39, 35, %1), "  // Dark brown base, transparency based on fill
                              "       stop:%2 rgba(111, 78, 55, %3), " // Smooth coffee fill transition
                              "       stop:0.85 rgba(166, 123, 91, %4), " // Light top layer (crema effect)
                              "       stop:1 rgba(210, 180, 140, %5)); " // Transparent at the top
                              "   box-shadow: 5px 5px 12px rgba(0,0,0,0.3);"  // Subtle 3D shadow
                              "}"
                              ).arg(level > 0 ? 1.0 : 0.0)  // Dark base appears only when filling starts
                              .arg(level / 100.0)           // Smooth gradient transition
                              .arg(level > 0 ? 0.9 : 0.0)   // Middle coffee tone opacity
                              .arg(level > 0 ? 0.6 : 0.0)   // Crema opacity
                              .arg(level > 90 ? 0.3 : 0.0); // Very light foam layer at high fill

    ui->lblCoffeeCup->setStyleSheet(coffeeStyle);
}



void MainWindow::updateMenuResources()
{
    QString menuText;

    // Coffee Menu
    menuText += "☕ **Coffee Menu**\n";
    menuText += "------------------------\n";
    menuText += "1. Espresso - $5.00\n";
    menuText += "2. Cappuccino - $6.00\n";
    menuText += "3. Latte - $7.00\n\n";

    // Available Resources
    menuText += "📦 **Available Resources**\n";
    menuText += "------------------------\n";
    menuText += QString("💰 Balance: $%1\n").arg(payment->getBalance());
    menuText += QString("💵 Revenue: $%1\n").arg(payment->getRevenue());
    menuText += QString("☕ Coffee Beans: %1\n").arg(inventory->getCoffeeBeans());
    menuText += QString("💧 Water Level: %1 ml\n").arg(inventory->getWaterLevel());
    menuText += QString("🥤 Cups: %1\n").arg(inventory->getCups());

    // Maintenance Status
    bool needsMaint = maintenance->needsMaintenance();
    menuText += "\n🔧 **Maintenance Status**\n";
    menuText += "------------------------\n";
    menuText += needsMaint ? "⚠️ Maintenance Required!\n" : "✅ All Good\n";

    ui->textMenuRecources->setPlainText(menuText);
}



void MainWindow::orderEspresso()
{
    orderCoffee(CoffeeType::Espresso, 5.0);
}

void MainWindow::orderCappuccino()
{
    orderCoffee(CoffeeType::Cappuccino, 6.0);
}

void MainWindow::orderLatte()
{
    orderCoffee(CoffeeType::Latte, 7.0);
}

void MainWindow::orderCoffee(CoffeeType type, double price)
{
    // 1. Check if maintenance needed
    if (maintenance->needsMaintenance()) {
        QMessageBox::warning(this, "Maintenance Required",
                             "Please perform maintenance before ordering coffee!");
        logger->logEvent("Attempted to order coffee while maintenance was required.");
        return;
    }

    // 2. Check resources
    CoffeeRecipe recipe = getCoffeeRecipe(type);
    if (!inventory->hasSufficientResources(recipe)) {
        QMessageBox::warning(this, "Insufficient Resources",
                             "Not enough resources to brew coffee!");
        logger->logError("Insufficient inventory for selected coffee.");
        return;
    }

    // 3. Process payment
    if (!payment->processPayment(price)) {
        QMessageBox::warning(this, "Payment Failed", "Not enough funds!");
        logger->logError("Payment failed due to insufficient funds.");
        return;
    }

    // 4. Update inventory & brew
    inventory->updateResources(recipe);


    logger->logEvent(QString("Coffee order processed: %1")
                         .arg((type == CoffeeType::Espresso) ? "Espresso" :
                                  (type == CoffeeType::Cappuccino) ? "Cappuccino" : "Latte"));

    brewing->startBrewing();
    brewing->handleBrewStateChange();
    brewing->stopBrewing();

    // 5. Auto maintenance every 2 orders
    orderCount++;
    if (orderCount >= 2) {
        QMessageBox::information(this, "Maintenance Triggered",
                                 "** Automatic Maintenance Triggered due to usage **");
        maintenance->triggerMaintenance();
        logger->logEvent("Automatic maintenance triggered after 2 orders.");
        orderCount = 0;
    }

    updateUI();
}

// ================== Inventory & Funds ==================

void MainWindow::addFunds()
{
    bool ok;
    double amount = QInputDialog::getDouble(this, "Add Funds", "Enter amount to add:",
                                            10.0, 0.0, 999999.0, 2, &ok);
    if (ok) {
        payment->addBalance(amount);
        logger->logEvent(QString("Funds added: $%1").arg(amount));
        updateUI();
    }
}

void MainWindow::refillInventory()
{
    bool ok;
    QStringList items = { "Coffee Beans", "Water", "Cups" };
    QString choice = QInputDialog::getItem(this, "Refill Inventory",
                                           "What do you want to refill?",
                                           items, 0, false, &ok);
    if (!ok || choice.isEmpty()) return;

    int amount = QInputDialog::getInt(this, "Refill", "Enter amount to refill:",
                                      10, 0, 99999, 1, &ok);
    if (!ok) return;

    if (choice == "Coffee Beans") {
        inventory->refillCoffeeBeans(amount);
        logger->logEvent(QString("Refilled coffee beans by %1").arg(amount));
    } else if (choice == "Water") {
        inventory->refillWater(amount);
        logger->logEvent(QString("Refilled water by %1 ml").arg(amount));
    } else if (choice == "Cups") {
        inventory->refillCups(amount);
        logger->logEvent(QString("Refilled cups by %1").arg(amount));
    }

    updateUI();
}

// ================== Maintenance ==================

void MainWindow::checkMaintenance()
{
    if (maintenance->needsMaintenance()) {
        QMessageBox::information(this, "Maintenance", "Maintenance is REQUIRED.");
        logger->logEvent("Checked maintenance status: REQUIRED");
    } else {
        QMessageBox::information(this, "Maintenance", "No maintenance needed.");
        logger->logEvent("Checked maintenance status: NOT required");
    }
}

void MainWindow::performMaintenance()
{
    maintenance->performMaintenance();
    logger->logEvent("Maintenance performed by user.");
    updateUI();
}

// ================== Logs ==================
void MainWindow::appendLog(const QString &entry)
{
    if (ui->textLogViewer->isVisible()) {
        ui->textLogViewer->append(entry);
    }
}


void MainWindow::showLogs()
{

    logger->showLogs();
}

// ================== UI Updates ==================

void MainWindow::updateUI()
{

    updateMenuResources();  // **Update the menu resources display**
}

