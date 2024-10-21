#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication> //?
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // FINISH HERE to read commandline options.
    qDebug() << "In main.cpp, argc = " << argc << "argv = " << QString(argv[0]);

    MainWindow w;
    w.show();
    return app.exec();
}
