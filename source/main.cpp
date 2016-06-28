#include "handgesturedialog.h"
#include "./utils/log.h"
#include "./utils/utils.h"

#include <QApplication>
#include <QTextCodec>

map<string, string> g_ConfigMap;
map<string, vector<string>> g_TargetMap;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    string configure_path = "/Users/liuguiyang/Documents/CodeProj/QtProj/HandGesture/conf/configure.json";
    read_config_Json(configure_path, g_ConfigMap, g_TargetMap);
    HandGestureDialog w;
    w.show();
    return a.exec();
}
