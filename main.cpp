#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    w.close();



//    字体设置——a
    QFont font = a.font();
    font.setPointSize(18);
    font.setFamily("Times New Roman");
    a.setFont(font);

    return a.exec();
}
