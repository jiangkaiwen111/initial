#include "history_data.h"
#include <QRegExp>
#include<QVector>

History_data::History_data()
{

}

void getLine(QString filename, QVector<double> &array)
{
    QFile file(filename);

    if(file.open(QFile::ReadOnly))
    {

      int i = 0;
      while (!file.atEnd()){
        QString lineString_array = QString(file.readLine()).trimmed();
        array << (double)(i++,lineString_array.toDouble());
        }
    }
    else
       qDebug()<<"getline file open failed!!";
}

void History_data::Chart_Data_Save(int direct, double datas[])
{

    QString tmp_settg_kind;
    switch (direct)
    {
      case 1: tmp_settg_kind = "x方向绕组";break;
      case 2: tmp_settg_kind = "y方向绕组";break;
      case 3: tmp_settg_kind = "z方向绕组";break;
      default: break;
    }
    QString day_time = QDateTime::currentDateTime().toString("yyyy年MM月dd日hh时mm分ss秒");

    QFile file( QDir::currentPath().append("/datas/").append(QString("xc")).append("_").append(tmp_settg_kind).append("_").append(day_time).append(QString(".txt")) );
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "write failed!";
        return;
    }

    QString Datas;
    switch (direct)
    {
      case 1:
        for(uint i=0; i<9; ++i )
        {
            Datas.append( QString("%1").arg( datas[i], 1,'f',3 ) ).append( QString("\n"));
        }
        break;
      case 2:
        for(uint i=9; i<12; ++i )
        {
            Datas.append( QString("%1").arg( datas[i], 1,'f',3 ) ).append( QString("\n"));
        }
        break;
      case 3:
        for(uint i=12; i<18; ++i )
        {
            Datas.append( QString("%1").arg( datas[i], 1,'f',3 ) ).append( QString("\n"));
        }
        break;
      default: break;
    }

    file.write( Datas.toLocal8Bit() );
    file.close();
    qDebug() << "write success!";

}

void History_data::Chart_Data_Choose(QString filename)
{
    QVector<double> mydata;
    getLine(filename, mydata);
    qDebug() << mydata;
    QString datas_all;
    for(uint i=0; i<mydata.size(); ++i )
    {
        datas_all.append( QString("%1").arg( mydata[i], 1,'f',3 ) ).append( QString("\n"));
    }

//    QRegExp reg("z方向绕组");
//    if(reg.indexIn(filename) != -1)
//    {
//        QString mystr = reg.cap(1);
//        qDebug() << "mystr:";
//        qDebug() << mystr;
//    }

    if(filename.contains("z方向绕组"))
    {
        qDebug() << "123123123123:";
    }

  //  datas_all.append(filename);
    emit Data_Show(datas_all);

}

void History_data::pB_Open_Slot()
{
    QString filename = QFileDialog::getOpenFileName(Q_NULLPTR,tr("文件对话框"),QDir::currentPath().append("/datas"),tr("文本文件( *.txt)"));
    Chart_Data_Choose( filename );
}
