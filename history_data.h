#ifndef HISTORY_DATA_H
#define HISTORY_DATA_H

//新添加的.h和.cpp,需要添加 <QMainWindow>，不然类中public和private会报错
#include <QMainWindow>
#include <QObject>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QDebug>
#include <QReadWriteLock>
#include <QFileDialog>
#include <QTextCodec>

#include "data.h"

class History_data : public QObject
{
    Q_OBJECT

public:
    History_data();

public slots:
    //存储数据
    void Chart_Data_Save(int direct, double datas[]);
    //读取数据
    void Chart_Data_Choose(QString filename);
    //打开历史数据槽函数
    void pB_Open_Slot();

signals:
    void Data_Show(QString message);
    void Data_Finish();




};

#endif // HISTORY_DATA_H
