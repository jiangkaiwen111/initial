#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "pso.h"
#include <QDebug>//#include "QDebug"也是可以的

#include <QtWidgets>
#include <QString>

//#include <random>//控制变量法，每次修改，都要重构

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
       this->setFixedSize( this->width (),this->height ());//固定窗口大小

//    qDebug() << "123";

    showraozu();

    connect(ui->Pb_sure,&QPushButton::clicked,this,&MainWindow::Pb_sure);
//    connect(&pso,&PSO::showResult,this,&MainWindow::showraozu);

    history_data = new History_data();

    history_data->Chart_Data_Save(1, pso.g_best);
    history_data->Chart_Data_Save(2, pso.g_best);
    history_data->Chart_Data_Save(3, pso.g_best);

    //打开历史数据槽函数
    connect(ui->pB_choose,&QPushButton::clicked,[this]{this->ui->pTE_data->clear();
                                                     this->history_data->pB_Open_Slot(); });
    //  moveCursor 移动 QTextEdit 控件中的光标
    //  光标移动到文本末尾,当接收到大量数据后，不需要手动拉动滑块进行翻页，就可以看到最新的信息
    //  文本框赋值的方式为ui->QTextEdit->setText()，ui->QTextEdit->append()【可以直接到最后面的数据，但是因为逻辑需要，必须采用setText()】
    connect(history_data, &History_data::Data_Show, [this](QString message){this->ui->pTE_data->moveCursor(QTextCursor::End);
                                                                            this->ui->pTE_data->insertPlainText(message); });


}


void MainWindow::showraozu(){

    qDebug() << "MainWindow::showraozu()";

    ui->IE_X1_I_2->setText(tr("%1").arg(pso.g_best[0]));
    ui->IE_X2_I_2->setText(tr("%1").arg(pso.g_best[1]));
    ui->IE_X3_I_2->setText(tr("%1").arg(pso.g_best[2]));
    ui->IE_X4_I_2->setText(tr("%1").arg(pso.g_best[3]));
    ui->IE_X5_I_2->setText(tr("%1").arg(pso.g_best[4]));
    ui->IE_X6_I_2->setText(tr("%1").arg(pso.g_best[5]));
    ui->IE_X7_I_2->setText(tr("%1").arg(pso.g_best[6]));
    ui->IE_X8_I_2->setText(tr("%1").arg(pso.g_best[7]));
    ui->IE_X9_I_2->setText(tr("%1").arg(pso.g_best[8]));

    ui->IE_Y1_I_2->setText(tr("%1").arg(pso.g_best[9]));
    ui->IE_Y2_I_2->setText(tr("%1").arg(pso.g_best[10]));
    ui->IE_Y3_I_2->setText(tr("%1").arg(pso.g_best[11]));

    ui->IE_Z1_I_2->setText(tr("%1").arg(pso.g_best[12]));
    ui->IE_Z2_I_2->setText(tr("%1").arg(pso.g_best[13]));
    ui->IE_Z3_I_2->setText(tr("%1").arg(pso.g_best[14]));
    ui->IE_Z4_I_2->setText(tr("%1").arg(pso.g_best[15]));
    ui->IE_Z5_I_2->setText(tr("%1").arg(pso.g_best[16]));
    ui->IE_Z6_I_2->setText(tr("%1").arg(pso.g_best[17]));


    //X自尾部向头部 29~21
    ui->IE_X1_I->setText(tr("%1").arg(pso.g_best[0]));
    ui->IE_X1_IN->setText(tr("%1").arg(pso.g_best[0]*100));

    ui->IE_X2_I->setText(tr("%1").arg(pso.g_best[1]));
    ui->IE_X2_IN->setText(tr("%1").arg(pso.g_best[1]*91));

    ui->IE_X2_IN->setMaxLength(5);//带有小数点和正负号，21.25；-21.2

    ui->IE_X3_I->setText(tr("%1").arg(pso.g_best[2]));
    ui->IE_X3_IN->setText(tr("%1").arg(pso.g_best[2]*98));

    ui->IE_X4_I->setText(tr("%1").arg(pso.g_best[3]));
    ui->IE_X4_IN->setText(tr("%1").arg(pso.g_best[3]*98));

    ui->IE_X5_I->setText(tr("%1").arg(pso.g_best[4]));
    ui->IE_X5_IN->setText(tr("%1").arg(pso.g_best[4]*133));

    ui->IE_X6_I->setText(tr("%1").arg(pso.g_best[5]));
    ui->IE_X6_IN->setText(tr("%1").arg(pso.g_best[5]*112));

    ui->IE_X7_I->setText(tr("%1").arg(pso.g_best[6]));
    ui->IE_X7_IN->setText(tr("%1").arg(pso.g_best[6]*102));

    ui->IE_X8_I->setText(tr("%1").arg(pso.g_best[7]));
    ui->IE_X8_IN->setText(tr("%1").arg(pso.g_best[7]*98));

    ui->IE_X9_I->setText(tr("%1").arg(pso.g_best[8]));
    ui->IE_X9_IN->setText(tr("%1").arg(pso.g_best[8]*112));

    //Y自尾部向头部 8、9、3
    ui->IE_Y1_I->setText(tr("%1").arg(pso.g_best[9]));
    ui->IE_Y1_IN->setText(tr("%1").arg(pso.g_best[9]*200));

    ui->IE_Y2_I->setText(tr("%1").arg(pso.g_best[10]));
    ui->IE_Y2_IN->setText(tr("%1").arg(pso.g_best[10]*200));

    ui->IE_Y3_I->setText(tr("%1").arg(pso.g_best[11]));
    ui->IE_Y3_IN->setText(tr("%1").arg(pso.g_best[11]*200));

    //Z 17、16、2、14、45、5
    ui->IE_Z1_I->setText(tr("%1").arg(pso.g_best[12]));
    ui->IE_Z1_IN->setText(tr("%1").arg(pso.g_best[12]*(-160)));

    ui->IE_Z2_I->setText(tr("%1").arg(pso.g_best[13]));
    ui->IE_Z2_IN->setText(tr("%1").arg(pso.g_best[13]*250));

    ui->IE_Z3_I->setText(tr("%1").arg(pso.g_best[14]));
    ui->IE_Z3_IN->setText(tr("%1").arg(pso.g_best[14]*100));

    ui->IE_Z4_I->setText(tr("%1").arg(pso.g_best[15]));
    ui->IE_Z4_IN->setText(tr("%1").arg(pso.g_best[15]*220));

    ui->IE_Z5_I->setText(tr("%1").arg(pso.g_best[16]));
    ui->IE_Z5_IN->setText(tr("%1").arg(pso.g_best[16]*100));

    ui->IE_Z6_I->setText(tr("%1").arg(pso.g_best[17]));
    ui->IE_Z6_IN->setText(tr("%1").arg(pso.g_best[17]*140));


    ui->Bu_16_X->setText(tr("%1").arg(pso.Bu_16_X));
    ui->Bu_16_Y->setText(tr("%1").arg(pso.Bu_16_Y));
    ui->Bu_16_Z->setText(tr("%1").arg(pso.Bu_16_Z));
    ui->Bu_16->setText(tr("%1").arg(pso.Bu_16));

    ui->Bu_32_X->setText(tr("%1").arg(pso.Bu_32_X));
    ui->Bu_32_Y->setText(tr("%1").arg(pso.Bu_32_Y));
    ui->Bu_32_Z->setText(tr("%1").arg(pso.Bu_32_Z));
    ui->Bu_32->setText(tr("%1").arg(pso.Bu_32));

    ui->Bu_48->setText(tr("%1").arg(pso.Bu_48));
    ui->Bu->setText(tr("%1").arg(pso.Bu));

    ui->Remain_16_X->setText(tr("%1").arg(pso.Remain_16_X));
    ui->Remain_16_Y->setText(tr("%1").arg(pso.Remain_16_Y));
    ui->Remain_16_Z->setText(tr("%1").arg(pso.Remain_16_Z));
    ui->Remain_16->setText(tr("%1").arg(pso.Remain_16));

    ui->Remain_32_X->setText(tr("%1").arg(pso.Remain_32_X));
    ui->Remain_32_Y->setText(tr("%1").arg(pso.Remain_32_Y));
    ui->Remain_32_Z->setText(tr("%1").arg(pso.Remain_32_Z));
    ui->Remain_32->setText(tr("%1").arg(pso.Remain_32));

    ui->Remain_48->setText(tr("%1").arg(pso.Remain_48));

    ui->Remain->setText(tr("%1").arg(pso.Remain));
//    磁场值
    ui->Mag_16_X->setText(tr("%1").arg(55336));
    ui->Mag_16_Y->setText(tr("%1").arg(7687));
    ui->Mag_16_Z->setText(tr("%1").arg(99633));

    ui->Mag_32_X->setText(tr("%1").arg(13779));
    ui->Mag_32_Y->setText(tr("%1").arg(1381));
    ui->Mag_32_Z->setText(tr("%1").arg(27929));

    ui->Mag_16->setText(tr("%1").arg(162666));
    ui->Mag_32->setText(tr("%1").arg(43090));
    ui->Mag_48->setText(tr("%1").arg(12323));
    ui->Mag->setText(tr("%1").arg(12323+162666+43090));

}

// //    double value = ui->IE_X1_I_2->value();//spinBox可以，IineEdit不可以
// //    QString value = ui->IE_X1_I_2->text();//获取LineEdit中的值.是QString类型，不能直接用double
// //    double value = ui->IE_X1_I_2->text().toDouble();//类型转化也是可以的


void MainWindow::Pb_sure()
{
    qDebug()<<"MainWindow::Pb_sure()";//确定Pb_sure函数可以输出

    pso.g_best[0] = ui->IE_X1_I_2->text().toDouble();
    pso.g_best[1] = ui->IE_X2_I_2->text().toDouble();
    pso.g_best[2] = ui->IE_X3_I_2->text().toDouble();
    pso.g_best[3] = ui->IE_X4_I_2->text().toDouble();
    pso.g_best[4] = ui->IE_X5_I_2->text().toDouble();
    pso.g_best[5] = ui->IE_X6_I_2->text().toDouble();
    pso.g_best[6] = ui->IE_X7_I_2->text().toDouble();
    pso.g_best[7] = ui->IE_X8_I_2->text().toDouble();
    pso.g_best[8] = ui->IE_X9_I_2->text().toDouble();

    pso.g_best[9] = ui->IE_Y1_I_2->text().toDouble();
    pso.g_best[10] = ui->IE_Y2_I_2->text().toDouble();
    pso.g_best[11] = ui->IE_Y3_I_2->text().toDouble();

    pso.g_best[12] = ui->IE_Z1_I_2->text().toDouble();
    pso.g_best[13] = ui->IE_Z2_I_2->text().toDouble();
    pso.g_best[14] = ui->IE_Z3_I_2->text().toDouble();
    pso.g_best[15] = ui->IE_Z4_I_2->text().toDouble();
    pso.g_best[16] = ui->IE_Z5_I_2->text().toDouble();
    pso.g_best[17] = ui->IE_Z6_I_2->text().toDouble();

    qDebug() << "X1 = " << pso.g_best[0] << "; X2 = " << pso.g_best[1] << "; X3 = " << pso.g_best[2];

    double ret_16 = pso.func_16(pso.g_best);
    ui->Remain_16->setText(tr("%1").arg(ret_16));
    double Bu_16 = 1 - ret_16 /162666;
    ui->Bu_16->setText(tr("%1").arg(Bu_16));

    qDebug() << "ret_16:" << ret_16;

    double ret_32 = pso.func_32(pso.g_best);
    ui->Remain_32->setText(tr("%1").arg(ret_32));
    double Bu_32 = 1 - ret_32 /43090;
    ui->Bu_32->setText(tr("%1").arg(Bu_32));

    double ret_48 = pso.func_48(pso.g_best);
    ui->Remain_48->setText(tr("%1").arg(ret_48));
    double Bu_48 = 1 - ret_48 /12323 + 0.1;
    ui->Bu_48->setText(tr("%1").arg(Bu_48));

    double ret = pso.func(pso.g_best);
    ui->Remain->setText(tr("%1").arg(ret));
    double Bu = 1 - ret /218079;
    ui->Bu->setText(tr("%1").arg(Bu));

    qDebug() << "ret:" << ret;


//    showraozu();

}


void MainWindow::on_Pb_quit_clicked()
{
    close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
