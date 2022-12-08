#include "Simulatron.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling, true);
    QApplication a(argc, argv);
    Simulatron w;
    w.show();
    return a.exec();
}
