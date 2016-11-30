#include "mainwindow.h"
#include "application.h"
#include "version.h"

#include <QApplication>
#include <QStyleFactory>

#include <winsparkle.h>

int canShutdownCallback()
{
    return 1;
}

void shutdownRequestCallback()
{
    QApplication::quit();
}

int main(int argc, char *argv[])
{
    Application a(argc, argv);
    a.setLibraryPaths(a.libraryPaths() << a.applicationDirPath() + "/plugins");
    a.setOrganizationName("OFFIS - Institut fuer Informatik");
    a.setApplicationName("OFFIS Automation Framework");
    a.setOrganizationDomain("http://www.offis.de");
    if(QSysInfo::windowsVersion() < QSysInfo::WV_10_0){
        a.setStyle(QStyleFactory::create("Fusion"));
    }

    // Init winSparkle, Setup update feeds.
    wchar_t charVersion[256];
    swprintf_s(charVersion, L"%d", Version::BUILD_VERSION_NUMBER);

    win_sparkle_set_appcast_url("http://134.106.47.173:8080/userContent/Framework/Framework.rss");
    win_sparkle_set_app_details(L"OFFIS", L"OFFIS Automation Framework", charVersion);
    win_sparkle_set_can_shutdown_callback(canShutdownCallback);
    win_sparkle_set_shutdown_request_callback(shutdownRequestCallback);

    // Initialize the updater and possibly show some UI
    win_sparkle_init();

    MainWindow w;
    w.show();

    // Shut WinSparkle down cleanly when the app exits
    win_sparkle_cleanup();

    // Run
    int retVal = a.exec();

    return retVal;
}
