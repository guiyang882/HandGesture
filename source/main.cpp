#include "handgesturedialog.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    HandGestureDialog w;
    w.show();
    return a.exec();
}
