#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // **Create a fixed-size splash screen**
    QPixmap splashImage(":/new/prefix1/Splashscreen.png");  // Make sure this image is in resources
    QSplashScreen splash(splashImage.scaled(600, 600, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Fixed size
    splash.setFixedSize(600, 600);  // Set exact size
    splash.show();

    // **Delay for 5 seconds before showing the main window**
    QTimer::singleShot(5000, [&]() {
        MainWindow *w = new MainWindow();
        w->show();
        splash.finish(w);  // Hide splash when main window appears
    });

    return a.exec();
}
