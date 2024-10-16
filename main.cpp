#include "mainwindow.h"

#include <QApplication>
#include <QGuiApplication> //?

#include <KAboutData>
#include <KDBusService>

// #include <KDBusAddons>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //------------------------------
    //Example from https://api.kde.org/frameworks/kcoreaddons/html/classKAboutData.html
    // setup translation string domain for the i18n calls
    // KLocalizedString::setApplicationDomain("foo");
    // create a KAboutData object to use for setting the application metadata
    KAboutData aboutData(
        "chemcalc",  // componentName
        "ChemCalc",  // displayName
        "0.1",       // version
        "A Chemical Calculator",  // shortDescription
        KAboutLicense::GPL_V3,    // licenseType
        "Copyright 2024 Chris Baba",  // copyrightStatement
        QString(),   // otherText
        "https://github.com/Chris-Baba/ChemCalc",  // homePageAddress
        "https://github.com/Chris-Baba/ChemCalc/issues"  //bugAddress
        );

    // overwrite default-generated values of organizationDomain & desktopFileName
    // Note: Qt has identical functions, but these are from KAboutData.
    aboutData.setOrganizationDomain("github.com.chris_baba");
    aboutData.setDesktopFileName("chris-baba.com.github.ChemCalc");

    // set the application metadata
    KAboutData::setApplicationData(aboutData);
    // in GUI apps set the window icon manually, not covered by KAboutData
    // needed for environments where the icon name is not extracted from
    // the information in the application's desktop file
    QApplication::setWindowIcon(QIcon::fromTheme(QStringLiteral("chris-baba.com.github.ChemCalc")));

    // integrate with commandline argument handling
    QCommandLineParser parser;
    aboutData.setupCommandLine(&parser);
    // setup of app specific commandline args
    // [...]
        parser.process(app);
    aboutData.processCommandLine(&parser);

    // with the application metadata set, register to the D-Bus session
    KDBusService programDBusService(KDBusService::Multiple | KDBusService::NoExitOnFailure);
    //------------------------------

    MainWindow w;
    w.show();
    return app.exec();
}
