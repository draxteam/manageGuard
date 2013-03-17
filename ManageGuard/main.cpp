#include <QtGui/QApplication>
#include "Caserne.h"
#include "Member.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    // Configuration des codec en UTF-8.
    #if QT_VERSION < 0x050000
        QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
        QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
    #endif

    window.setWindowTitle("Manage Guard v0.0317 alpha");
    window.setMinimumSize(500, 400);

    window.show();
    
    return app.exec();
}
