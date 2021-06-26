#include "pso.h"
#include <QDebug>

#include<qmath.h>//不加也可跑出结果，但是效果会差很多

//#include <QAxObject>
//#include <QtGlobal>//调试nan问题是函数头文件

PSO::PSO()
{
     qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//添加的随机数种子，rand函数生成只会有一次
     start_pso();

//     qDebug()<<"s";

}

void PSO::start_pso(){

    initial();
    iterative();
    show_result();
}

double PSO::rand(){

    return (qrand()%10)/10.00+(qrand()%10)/100.0+(qrand()%10)/1000.0;
}

void PSO::initial(){

    for (int i = 0; i < sizepop; i++){
        for (int j =0; j < psize; j++){
            pop[i][j] = (rand() + 1)/2;//0.5~1
            V[i][j] = 0.5*rand();// 0~0.5 速度和Matlab设置的；有所不同
        }
    }

    g_best_fitness = 200000;

    double arry[psize];

    for (int i = 0; i < sizepop; i++){
        for (int j = 0; j < psize; j++){
            arry[j] = pop[i][j];

            p_best[i][j] = pop[i][j];
        }
        p_best_fitness[i] = func_w(arry);//p_best_fitness[sizepop] = func_w(arry)不可以写成sizepop

        if (p_best_fitness[i] < g_best_fitness){
            g_best_fitness = p_best_fitness[i];

            for (int k = 0; k < psize; k++)
                g_best[k] = p_best[i][k];
        }
    }
}

void PSO::iterative(){

    double arry[psize];
    double temp;

    for (int k = 0; k < maxgen; k++){
        for (int i = 0; i < sizepop; i++){
            for (int j = 0; j < psize; j++){
                V[i][j] = V[i][j] + c1*rand()*(p_best[i][j] - pop[i][j] + c2*rand()*(g_best[j] - pop[i][j]));

                if(V[i][j] > Vmax)
                    V[i][j] = Vmax;
                if(V[i][j] < Vmin)
                    V[i][j] = Vmin;

                pop[i][j] = pop[i][j] + V[i][j];

                if(pop[i][j] > popmax)
                    pop[i][j] = popmax;
                if(pop[i][j] < popmin)
                    pop[i][j] = popmin;
            }
        }

        for (int i = 0; i < sizepop; i++){
            for (int j = 0; j < psize; j++){
                arry[j] = pop[i][j];
            }

            temp = func_w(arry);

            if (temp < p_best_fitness[i]){
                p_best_fitness[i] = temp;
                for (int j = 0; j < psize; j++){
                    p_best[i][j] = pop[i][j];
                }
            }

            if (temp < g_best_fitness){
                g_best_fitness = temp;
                for (int j = 0; j < psize; j++){
                    g_best[j] = pop[i][j];
                }
            }
        }
        timefitness[k] = g_best_fitness;
    }
}



void PSO::show_result(){

    for (int i = 1; i < maxgen; i++){
        if (i == 1)
            qDebug() << "初始最优值" << timefitness[0];
        if (timefitness[i] != timefitness[i-1])
            qDebug() << "第" << i << "代更新最优值" << timefitness[i];
        }

        Remain_16 = func_16(g_best);
        Remain_16_X = func_16_X(g_best);
        Remain_16_Y = func_16_Y(g_best);
        Remain_16_Z = func_16_Z(g_best);

        Bu_16_X = 1 - Remain_16_X /55336;
        Bu_16_Y = 1 - Remain_16_Y /7687;
        Bu_16_Z = 1 - Remain_16_Z /99633;
        Bu_16 = 1 - Remain_16 /162666;

        qDebug() << "16米的磁场补偿为：" << 1 - Remain_16 /162666;

        Remain_32 = func_32(g_best);
        Remain_32_X = func_32_X(g_best);
        Remain_32_Y = func_32_Y(g_best);
        Remain_32_Z = func_32_Z(g_best);

        Bu_32_X = 1 - Remain_32_X /13779;
        Bu_32_Y = 1 - Remain_32_Y /1381;
        Bu_32_Z = 1 - Remain_32_Z /27929;
        Bu_32 = 1 - Remain_32 /43090;

        qDebug() << "32米的磁场补偿为：" << 1 - Remain_32 /43090;

        Remain_48 = func_48(g_best);
        Bu_48 = 1 - Remain_48 /16323;//12323
        qDebug() << "48米的磁场补偿为：" << 1 - Remain_48 /16323;

        Remain = func(g_best);
        Bu = 1 - Remain /(12323+162666+43090);
        qDebug() << "磁总量的磁场补偿为：" << 1 - Remain /(12323+162666+43090);

        for (int i = 0; i < 18; i++){
            qDebug() << "群体最优位置：" << g_best[i];
        }
//ui界面信息的显示是因为mainwindow头文件定义了 void showraozu(),可以在源函数中运行 void showraozu()函数

//        emit showResult();
}


double PSO::func(double x[]){

    double Remain = 0;
    Remain = Remain + func_16(x) + func_32(x) + func_48(x);

    return Remain;
}

double PSO::func_w(double x[]){

    double Remain = 0;

    double w_16 = (162666+43090+12323)/162666*2;
    double w_32 = (162666+43090+12323)/43090*0.5;
    double w_48 = (162666+43090+12323)/12312*1.5;

    Remain = w_16*func_16(x) + w_32*func_32(x) + w_48*func_48(x);

    return Remain;
}

double PSO::func_16(double x[]){

    double Remain_16_X = 0;//Remain_X_16逻辑不通，下面会犯错
    double Remain_16_Y = 0;
    double Remain_16_Z = 0;
    double Remain_16 = 0;

    double Coil_16_X = 0;//X_16不行，逻辑不通;16_X也不可以，不能数字开头
    double Coil_16_Y = 0;
    double Coil_16_Z = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){//以一行的为基础，
            Coil_16_X = Coil_16_X + x[j]*xc.XCJZ_16_X[j][i];//18个绕组在X分量，对一个点产生的磁场标量叠加
            Coil_16_Y = Coil_16_Y + x[j]*xc.XCJZ_16_Y[j][i];
            Coil_16_Z = Coil_16_Z + x[j]*xc.XCJZ_16_Z[j][i];
        }
        Remain_16_X = Remain_16_X + qAbs(xc.GYB_16_X[i] - Coil_16_X);
        Remain_16_Y = Remain_16_Y + qAbs(xc.GYB_16_Y[i] - Coil_16_Y);
        Remain_16_Z = Remain_16_Z + qAbs(xc.GYB_16_Z[i] - Coil_16_Z);

        Coil_16_X = 0;
        Coil_16_Y = 0;
        Coil_16_Z = 0;
    }
    Remain_16 = Remain_16_X + Remain_16_Y + Remain_16_Z;

    return Remain_16;
}

double PSO::func_16_X(double *x){

    double Remain_16_X = 0;

    double Coil_16_X = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_16_X = Coil_16_X + x[j]*xc.XCJZ_16_X[j][i];
        }
        Remain_16_X = Remain_16_X + qAbs(xc.GYB_16_X[i] - Coil_16_X);

        Coil_16_X = 0;
    }
    return Remain_16_X;
}

double PSO::func_16_Y(double *x){

    double Remain_16_Y = 0;

    double Coil_16_Y = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_16_Y = Coil_16_Y + x[j]*xc.XCJZ_16_Y[j][i];
        }
        Remain_16_Y = Remain_16_Y + qAbs(xc.GYB_16_Y[i] - Coil_16_Y);

        Coil_16_Y = 0;
    }
    return Remain_16_Y;
}

double PSO::func_16_Z(double *x){

    double Remain_16_Z = 0;

    double Coil_16_Z = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_16_Z = Coil_16_Z + x[j]*xc.XCJZ_16_Z[j][i];
        }
        Remain_16_Z = Remain_16_Z + qAbs(xc.GYB_16_Z[i] - Coil_16_Z);

        Coil_16_Z = 0;
    }
    return Remain_16_Z;
}

double PSO::func_32(double x[]){

    double Remain_32_X = 0;
    double Remain_32_Y = 0;
    double Remain_32_Z = 0;
    double Remain_32 = 0;

    double Coil_32_X = 0;
    double Coil_32_Y = 0;
    double Coil_32_Z = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_32_X = Coil_32_X + x[j]*xc.XCJZ_32_X[j][i];
            Coil_32_Y = Coil_32_Y + x[j]*xc.XCJZ_32_Y[j][i];
            Coil_32_Z = Coil_32_Z + x[j]*xc.XCJZ_32_Z[j][i];
        }
        Remain_32_X = Remain_32_X + qAbs(xc.GYB_32_X[i] - Coil_32_X);
        Remain_32_Y = Remain_32_Y + qAbs(xc.GYB_32_Y[i] - Coil_32_Y);
        Remain_32_Z = Remain_32_Z + qAbs(xc.GYB_32_Z[i] - Coil_32_Z);

        Coil_32_X = 0;
        Coil_32_Y = 0;
        Coil_32_Z = 0;
    }
    Remain_32 = Remain_32_X + Remain_32_Y + Remain_32_Z;

    return Remain_32;
}

double PSO::func_32_X(double *x){

    double Remain_32_X = 0;

    double Coil_32_X = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_32_X = Coil_32_X + x[j]*xc.XCJZ_32_X[j][i];
        }
        Remain_32_X = Remain_32_X + qAbs(xc.GYB_32_X[i] - Coil_32_X);

        Coil_32_X = 0;
    }
    return Remain_32_X;
}

double PSO::func_32_Y(double *x){

    double Remain_32_Y = 0;

    double Coil_32_Y = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_32_Y = Coil_32_Y + x[j]*xc.XCJZ_32_Y[j][i];
        }
        Remain_32_Y = Remain_32_Y + qAbs(xc.GYB_32_Y[i] - Coil_32_Y);

        Coil_32_Y = 0;
    }
    return Remain_32_Y;
}

double PSO::func_32_Z(double *x){

    double Remain_32_Z = 0;

    double Coil_32_Z = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_32_Z = Coil_32_Z + x[j]*xc.XCJZ_32_Z[j][i];
        }
        Remain_32_Z = Remain_32_Z + qAbs(xc.GYB_32_Z[i] - Coil_32_Z);

        Coil_32_Z = 0;
    }
    return Remain_32_Z;
}

double PSO::func_48(double x[]){

    double Remain_48_X = 0;
    double Remain_48_Y = 0;
    double Remain_48_Z= 0;
    double Remain_48 = 0;

    double Coil_48_X = 0;
    double Coil_48_Y = 0;
    double Coil_48_Z = 0;

    for (int i = 0; i < point; i++){
        for (int j = 0; j < psize; j++){
            Coil_48_X = Coil_48_X + x[j]*xc.XCJZ_48_X[j][i];
            Coil_48_Y = Coil_48_Y + x[j]*xc.XCJZ_48_Y[j][i];
            Coil_48_Z = Coil_48_Z + x[j]*xc.XCJZ_48_Z[j][i];
        }
        Remain_48_X = Remain_48_X + qAbs(xc.GYB_48_X[i] - Coil_48_X);
        Remain_48_Y = Remain_48_Y + qAbs(xc.GYB_48_Y[i] - Coil_48_Y);
        Remain_48_Z = Remain_48_Z + qAbs(xc.GYB_48_Z[i] - Coil_48_Z);

        Coil_48_X = 0;
        Coil_48_Y = 0;
        Coil_48_Z = 0;
    }
    Remain_48 = Remain_48_X + Remain_48_Y + Remain_48_Z;

    return Remain_48;
}








