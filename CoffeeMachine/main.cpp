#include "mainwindow.h"

#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QPixmap pixmap(":/new/prefix1/Splashscreen.png");

    QSplashScreen splash(pixmap.scaled(800, 600, Qt::KeepAspectRatio));
    splash.setFixedSize(800, 600);
    splash.show();
    w.setWindowTitle("Coffee Machine App");
    w.setFixedSize(1000, 800);
    QTimer::singleShot(3000, &splash, &QSplashScreen::close);

    QTimer::singleShot(3000, &w, &MainWindow::show);
    return a.exec();
}
