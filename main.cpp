#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(resources);
    Widget w;
    w.show();
    return a.exec();
}
