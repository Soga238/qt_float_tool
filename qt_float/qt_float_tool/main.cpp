#include "qtfloattool.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtFloatTool w;
    w.setWindowTitle("FloatConverter(by 张建航)");
    w.show();

    return a.exec();
}
