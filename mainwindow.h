#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "history_data.h"
#include "pso.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 PSO pso;//在头文件中添加，才可以qDebug出s
//signals:
//    void get_data(double);

private slots:
    void on_Pb_quit_clicked();
  //  void getshow();


//    void on_Pb_sure_clicked();//如果不用就要注释掉
    void Pb_sure();

private:
    Ui::MainWindow *ui;
    //类 对象，仅仅是声明，未初始化，但是依然可以运行


    void showraozu();
//和添加信号一样，直接添加不用头文件;写法也一样
    History_data *history_data;

};
#endif // MAINWINDOW_H
