/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnEspresso;
    QPushButton *btnCappuccino;
    QPushButton *btnLatte;
    QPushButton *btnAddFunds;
    QPushButton *btnRefill;
    QPushButton *btnCheckMaintenance;
    QPushButton *btnPerformMaintenance;
    QPushButton *btnShowLogs;
    QTextEdit *textLogViewer;
    QTextEdit *textBrewingSteps;
    QTextEdit *textMenuRecources;
    QLabel *lblCoffeeCup;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(992, 631);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget#centralwidget {\n"
"	background-image: url(:/new/prefix1/MainScreenApp (1).jpg);\n"
"    background-position: center;\n"
"    background-repeat: no-repeat;\n"
"    background-size: cover;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnEspresso = new QPushButton(centralwidget);
        btnEspresso->setObjectName("btnEspresso");
        btnEspresso->setGeometry(QRect(559, 81, 141, 51));
        btnEspresso->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4E342E;  /* Dark Coffee Brown */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    border: 2px solid #3E2723;  /* Slightly darker brown for depth */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #6D4C41;  /* Slightly lighter brown */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* Clicked effect */\n"
"QPushButton:pressed {\n"
"    background-color: #3E2723;  /* Dark brown when pressed */\n"
"    transform: scale(0.95);\n"
"}\n"
"\n"
"/* Disable effect */\n"
"QPushButton:disabled {\n"
"    background-color: #A1887F;  /* Light brown when disabled */\n"
"    color: #ECEFF1;\n"
"    border: 2px solid #8D6E63;\n"
"}\n"
""));
        btnCappuccino = new QPushButton(centralwidget);
        btnCappuccino->setObjectName("btnCappuccino");
        btnCappuccino->setGeometry(QRect(560, 158, 141, 51));
        btnCappuccino->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4E342E;  /* Dark Coffee Brown */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    border: 2px solid #3E2723;  /* Slightly darker brown for depth */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #6D4C41;  /* Slightly lighter brown */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* Clicked effect */\n"
"QPushButton:pressed {\n"
"    background-color: #3E2723;  /* Dark brown when pressed */\n"
"    transform: scale(0.95);\n"
"}\n"
"\n"
"/* Disable effect */\n"
"QPushButton:disabled {\n"
"    background-color: #A1887F;  /* Light brown when disabled */\n"
"    color: #ECEFF1;\n"
"    border: 2px solid #8D6E63;\n"
"}\n"
""));
        btnLatte = new QPushButton(centralwidget);
        btnLatte->setObjectName("btnLatte");
        btnLatte->setGeometry(QRect(559, 126, 141, 41));
        btnLatte->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #4E342E;  /* Dark Coffee Brown */\n"
"    color: white;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    border-radius: 8px;\n"
"    padding: 8px 16px;\n"
"    border: 2px solid #3E2723;  /* Slightly darker brown for depth */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QPushButton:hover {\n"
"    background-color: #6D4C41;  /* Slightly lighter brown */\n"
"    transform: scale(1.05);\n"
"}\n"
"\n"
"/* Clicked effect */\n"
"QPushButton:pressed {\n"
"    background-color: #3E2723;  /* Dark brown when pressed */\n"
"    transform: scale(0.95);\n"
"}\n"
"\n"
"/* Disable effect */\n"
"QPushButton:disabled {\n"
"    background-color: #A1887F;  /* Light brown when disabled */\n"
"    color: #ECEFF1;\n"
"    border: 2px solid #8D6E63;\n"
"}\n"
""));
        btnAddFunds = new QPushButton(centralwidget);
        btnAddFunds->setObjectName("btnAddFunds");
        btnAddFunds->setGeometry(QRect(820, 10, 161, 86));
        btnAddFunds->setStyleSheet(QString::fromUtf8("QPushButton#btnAddFunds {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #FFD700, stop:0.5 #FFC107, stop:1 #B8860B); /* Gold gradient */\n"
"    color: black;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border-radius: 50px;  /* Circular button */\n"
"    padding: 15px 20px;\n"
"    border: 3px solid #DAA520; /* Golden border */\n"
"    min-width: 100px;\n"
"    min-height: 50px;\n"
"    text-align: center;\n"
"    image: url(:/icons/coin.png);  /* Add a coin icon */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 35px; /* Space for icon */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton#btnAddFunds:hover {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #FFC107, stop:0.5 #FFD700, stop:1 #FFD700); /* Brighter gold */\n"
"    border: 3px solid #FFBF00;\n"
"}\n"
"\n"
"QPushButton#btnAddFunds:"
                        "pressed {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #B8860B, stop:0.5 #DAA520, stop:1 #FFD700); /* Darker gold */\n"
"    border: 3px solid #8B7500;\n"
"    transform: scale(0.97);  /* Click effect */\n"
"}\n"
""));
        btnRefill = new QPushButton(centralwidget);
        btnRefill->setObjectName("btnRefill");
        btnRefill->setGeometry(QRect(830, 520, 161, 86));
        btnRefill->setStyleSheet(QString::fromUtf8("QPushButton#btnRefill {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #00BFFF, stop:0.5 #1E90FF, stop:1 #4169E1); /* Blue water gradient */\n"
"    color: white;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border-radius: 25px;  /* Rounded button */\n"
"    padding: 15px 20px;\n"
"    border: 3px solid #4682B4; /* Blue border */\n"
"    min-width: 100px;\n"
"    min-height: 50px;\n"
"    text-align: center;\n"
"    image: url(:/icons/water-drop.png);  /* Add a water drop icon */\n"
"    background-repeat: no-repeat;\n"
"    background-position: left center;\n"
"    padding-left: 35px; /* Space for icon */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"QPushButton#btnRefill:hover {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #1E90FF, stop:0.5 #00BFFF, stop:1 #87CEEB); /* Lighter blue */\n"
"    border: 3px solid #00BFFF;\n"
"}\n"
"\n"
"QPushButton#bt"
                        "nRefill:pressed {\n"
"    background: qradialgradient(cx:0.5, cy:0.5, radius:0.8,\n"
"                stop:0 #4682B4, stop:0.5 #1E90FF, stop:1 #00BFFF); /* Darker blue */\n"
"    border: 3px solid #1E90FF;\n"
"    transform: scale(0.97);  /* Click effect */\n"
"}\n"
""));
        btnCheckMaintenance = new QPushButton(centralwidget);
        btnCheckMaintenance->setObjectName("btnCheckMaintenance");
        btnCheckMaintenance->setGeometry(QRect(800, 110, 83, 83));
        btnCheckMaintenance->setStyleSheet(QString::fromUtf8("QPushButton#btnCheckMaintenance {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #5A5A5A, stop:0.5 #777777, stop:1 #B5B5B5); /* Metallic gradient */\n"
"    color: white;\n"
"    font-size: 10px;  /* Adjusted for better fit */\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border-radius: 30px;  /* More rounded */\n"
"    padding: 6px;\n"
"    border: 3px solid #444444; /* Darker metallic border */\n"
"    min-width: 65px;\n"
"    min-height: 65px;\n"
"    max-width: 65px;\n"
"    max-height: 65px;\n"
"    text-align: center;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    transition: all 0.2s ease-in-out;\n"
"    border-image: url(:/new/prefix1/OIP.jpeg); /* Correct way */\n"
"}\n"
"\n"
"QPushButton#btnCheckMaintenance:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #777777, stop:0.5 #B5B5B5, stop:1 #D9D9D9); /* Brighter metallic */\n"
"    border: 3px sol"
                        "id #777777;\n"
"}\n"
"\n"
"QPushButton#btnCheckMaintenance:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #3E3E3E, stop:0.5 #5A5A5A, stop:1 #777777); /* Darker when pressed */\n"
"    border: 3px solid #5A5A5A;\n"
"    transform: scale(0.92);  /* Press animation */\n"
"}\n"
""));
        btnPerformMaintenance = new QPushButton(centralwidget);
        btnPerformMaintenance->setObjectName("btnPerformMaintenance");
        btnPerformMaintenance->setGeometry(QRect(890, 110, 94, 94));
        btnPerformMaintenance->setStyleSheet(QString::fromUtf8("QPushButton#btnPerformMaintenance {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #4A4A4A, stop:0.5 #666666, stop:1 #8A8A8A); /* Metallic look */\n"
"    color: white;\n"
"    font-size: 12px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border-radius: 35px;  /* More rounded */\n"
"    padding: 8px;\n"
"    border: 4px solid #333333; /* Dark metallic border */\n"
"    min-width: 70px;\n"
"    min-height: 70px;\n"
"    max-width: 70px;\n"
"    max-height: 70px;\n"
"    text-align: center;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    transition: all 0.2s ease-in-out;\n"
"    border-image: url(:/new/prefix1/OIP (1).jpeg); /* Correct way */\n"
"}\n"
"\n"
"QPushButton#btnPerformMaintenance:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #666666, stop:0.5 #888888, stop:1 #AAAAAA); /* Brighter metallic */\n"
"    border: 4px solid #666666;\n"
"}\n"
"\n"
"QP"
                        "ushButton#btnPerformMaintenance:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #2E2E2E, stop:0.5 #4A4A4A, stop:1 #666666); /* Darker when pressed */\n"
"    border: 4px solid #4A4A4A;\n"
"    transform: scale(0.92);  /* Press animation */\n"
"}\n"
""));
        btnShowLogs = new QPushButton(centralwidget);
        btnShowLogs->setObjectName("btnShowLogs");
        btnShowLogs->setGeometry(QRect(760, 210, 126, 71));
        btnShowLogs->setStyleSheet(QString::fromUtf8("QPushButton#btnShowLogs {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #3E3E3E, stop:0.5 #5A5A5A, stop:1 #7A7A7A); /* Dark gray metallic */\n"
"    color: white;\n"
"    font-size: 14px;  /* Adjusted for better readability */\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    border-radius: 18px;\n"
"    padding: 10px;\n"
"    border: 3px solid #2A2A2A; /* Darker contrast border */\n"
"    min-width: 100px;\n"
"    min-height: 45px;\n"
"    max-width: 110px;\n"
"    max-height: 50px;\n"
"    text-align: center;\n"
"    transition: all 0.2s ease-in-out;\n"
"}\n"
"\n"
"QPushButton#btnShowLogs:hover {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #5A5A5A, stop:0.5 #7A7A7A, stop:1 #A0A0A0); /* Lighter metallic */\n"
"    border: 3px solid #5A5A5A;\n"
"}\n"
"\n"
"QPushButton#btnShowLogs:pressed {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                stop:0 #2A2A2A, stop:0.5 #3E"
                        "3E3E, stop:1 #5A5A5A); /* Darker pressed effect */\n"
"    border: 3px solid #3E3E3E;\n"
"    transform: scale(0.95); /* Subtle press animation */\n"
"}\n"
""));
        textLogViewer = new QTextEdit(centralwidget);
        textLogViewer->setObjectName("textLogViewer");
        textLogViewer->setGeometry(QRect(710, 300, 274, 201));
        textLogViewer->setStyleSheet(QString::fromUtf8("QTextEdit#textLogViewer {\n"
"    background-color: rgba(20, 20, 20, 180); /* Dark semi-transparent background */\n"
"    color: white; /* White text for readability */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 12px;\n"
"    border: 2px solid rgba(255, 255, 255, 80); /* Subtle white border */\n"
"    border-radius: 10px; /* Rounded corners */\n"
"    padding: 10px;\n"
"    min-width: 250px;\n"
"    min-height: 120px;\n"
"    max-height: 180px;\n"
"    text-align: left;\n"
"}\n"
""));
        textBrewingSteps = new QTextEdit(centralwidget);
        textBrewingSteps->setObjectName("textBrewingSteps");
        textBrewingSteps->setGeometry(QRect(320, 80, 241, 131));
        textMenuRecources = new QTextEdit(centralwidget);
        textMenuRecources->setObjectName("textMenuRecources");
        textMenuRecources->setGeometry(QRect(0, 10, 311, 591));
        textMenuRecources->setStyleSheet(QString::fromUtf8("QTextEdit#textMenuRecources {\n"
"    background-color: rgba(20, 14, 10, 200); /* Darker coffee brown background */\n"
"    color: #FFD700;  /* Soft golden text for a premium feel */\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"    font-size: 18px;\n"
"    font-weight: bold;\n"
"    border: 2px solid #D2B48C;  /* Light brown border */\n"
"    border-radius: 12px;\n"
"    padding: 12px;\n"
"    text-align: left;\n"
"    text-shadow: 1px 1px 3px rgba(0, 0, 0, 0.7);  /* Subtle text shadow */\n"
"}\n"
""));
        lblCoffeeCup = new QLabel(centralwidget);
        lblCoffeeCup->setObjectName("lblCoffeeCup");
        lblCoffeeCup->setGeometry(QRect(450, 390, 141, 172));
        lblCoffeeCup->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        textLogViewer->raise();
        btnEspresso->raise();
        btnCappuccino->raise();
        btnLatte->raise();
        btnAddFunds->raise();
        btnRefill->raise();
        btnCheckMaintenance->raise();
        btnPerformMaintenance->raise();
        btnShowLogs->raise();
        textBrewingSteps->raise();
        textMenuRecources->raise();
        lblCoffeeCup->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnEspresso->setText(QCoreApplication::translate("MainWindow", "Espresso", nullptr));
        btnCappuccino->setText(QCoreApplication::translate("MainWindow", "Cappuccino", nullptr));
        btnLatte->setText(QCoreApplication::translate("MainWindow", "Latte", nullptr));
        btnAddFunds->setText(QCoreApplication::translate("MainWindow", "Add Funds", nullptr));
        btnRefill->setText(QCoreApplication::translate("MainWindow", "Refill", nullptr));
        btnCheckMaintenance->setText(QString());
        btnPerformMaintenance->setText(QString());
        btnShowLogs->setText(QCoreApplication::translate("MainWindow", "Show Logs", nullptr));
        lblCoffeeCup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
