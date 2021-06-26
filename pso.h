#ifndef PSO_H
#define PSO_H

#include <QMainWindow>
#include <data.h>
#include <QTime>//随机种子
#include <QObject>

//注释依然可以出结果
//#include <vector>

//class PSO :——是原始的，新建的头文件和源文件是没有的，要在后面加上
//public QObject
//Q_OBJECT，才可以使用信号和槽

//此处定义的变量，在源文件中可以直接用

class PSO : public QObject
{
    Q_OBJECT

public:
    PSO();

    Data xc;

    double rand();

    static const int maxgen = 200;// 100
    static const int sizepop = 200;//粒子群种群数量.50
    static const int psize = 18;// 粒子维数，绕组数量
    static const int point = 101;

    const double Vmax = 1;//0.5
    const double Vmin = -1;//-0.5
    const double popmax = 2;//个体变化范围
    const double popmin = -1;

    const double ws = 0.9;
    const double we = 0.4;

    const double c1 = 1.49445;
    const double c2 = 1.49445;

    double pop[sizepop][psize];//50*18，位置矩阵
    double V[sizepop][psize];//50*18，速度矩阵

    double p_best[sizepop][psize];//50*18  所有个体最优位置
    double g_best[psize];//1*18            群体最优位置
    double p_best_fitness[sizepop];//1*50  所有个体最优适应度值
    double g_best_fitness;//1*1            群体最优适应度值

    double timefitness[maxgen];//1*100

signals:
//    void showResult();



public:
    void start_pso();
    void initial();
    void iterative();//迭代  
    void show_result();

    double func_w(double x[]);
    double func(double x[]);

    double func_16(double x[]);
    double func_16_X(double x[]);
    double func_16_Y(double x[]);
    double func_16_Z(double x[]);

    double func_32(double x[]);
    double func_32_X(double x[]);
    double func_32_Y(double x[]);
    double func_32_Z(double x[]);

    double func_48(double x[]);

public:
//        在mainwindow中有指向pso的语句，所以必须定义在类中，而不是start_pso
//        剩余磁场
        double Remain_16 = 0;//仅定义，或者初始化为0都可以
        double Remain_16_X = 0;
        double Remain_16_Y = 0;
        double Remain_16_Z = 0;

        double Remain_32 = 0;
        double Remain_32_X = 0;
        double Remain_32_Y = 0;
        double Remain_32_Z = 0;

        double Remain_48 = 0;

        double Remain = 0;
//        补偿磁场
        double Bu_16_X = 0;
        double Bu_16_Y = 0;
        double Bu_16_Z = 0;
        double Bu_16 = 0;

        double Bu_32_X = 0;
        double Bu_32_Y = 0;
        double Bu_32_Z = 0;
        double Bu_32 = 0;

        double Bu_48 = 0;

        double Bu = 0;

};

#endif // PSO_H
