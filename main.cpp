#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication> //?

#include <KAboutData>
// #include <KDBusService>
// #include <KDBusAddons>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //------------------------------
    //Example from https://api.kde.org/frameworks/kcoreaddons/html/classKAboutData.html
    // setup translation string domain for the i18n calls
    // KLocalizedString::setApplicationDomain("foo");
    // create a KAboutData object to use for setting the application metadata
    KAboutData aboutData("com.github.Chris-Baba.ChemCalc", "ChemCalc", "0.1",
                         "A Chemical Calculator",
                         KAboutLicense::GPL_V3,
                         "Copyright 2024 Chris Baba", QString(),
                         "https://github.com/Chris-Baba/ChemCalc");
    // overwrite default-generated values of organizationDomain & desktopFileName
    aboutData.setOrganizationDomain("github.com.Chris-Baba");
    aboutData.setDesktopFileName("com.github.Chris-Baba.ChemCalc");

    // set the application metadata
    KAboutData::setApplicationData(aboutData);
    // in GUI apps set the window icon manually, not covered by KAboutData
    // needed for environments where the icon name is not extracted from
    // the information in the application's desktop file
    QApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("com.github.Chris-Baba.ChemCalc")));

    // integrate with commandline argument handling
    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    // setup of app specific commandline args
    // [...]
        parser.process(app);
    aboutData.processCommandLine(&parser);

    // with the application metadata set, register to the D-Bus session
    // KDBusService programDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);
    //------------------------------

    MainWindow w;
    w.show();
    return app.exec();
}
