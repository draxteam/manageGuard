#include <QtGui/QApplication>
#include "Caserne.h"
#include "Member.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.setWindowTitle("Manage Guard v0.11108 alpha");
    window.setMinimumSize(500, 400);

    window.show();
    
    return app.exec();
}
