#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include <QTextStream>
#include <QFile>



namespace SK {
enum SortKind{
    col01    =   0x00000001<<0,         //!< 第1列
    col02    =   0x00000001<<1,         //!< 第2列
    col03    =   0x00000001<<2,         //!< 第3列
    col04    =   0x00000001<<3,         //!< 第4列
    col05    =   0x00000001<<4,         //!< 第5列
    col06    =   0x00000001<<5,         //!< 第6列
    col07    =   0x00000001<<6,         //!< 第7列
    col08    =   0x00000001<<7,         //!< 第8列
    col09    =   0x00000001<<8,         //!< 第9列
    col10    =   0x00000001<<9,         //!< 第10列
    col11    =   0x00000001<<10,        //!< 第11列
    col12    =   0x00000001<<11,        //!< 第12列
    col13    =   0x00000001<<12,        //!< 第13列
    col14    =   0x00000001<<13,        //!< 第14列
    col15    =   0x00000001<<14,        //!< 第15列
    col16    =   0x00000001<<15,        //!< 第16列
    col17    =   0x00000001<<16,        //!< 第17列
    col18    =   0x00000001<<17,        //!< 第18列
    col19    =   0x00000001<<18,        //!< 第19列
    col20    =   0x00000001<<19,        //!< 第20列
    col21    =   0x00000001<<20,        //!< 第21列
    col22    =   0x00000001<<21,        //!< 第22列
    col23    =   0x00000001<<22,        //!< 第23列
    col24    =   0x00000001<<23,        //!< 第24列
    col25    =   0x00000001<<24,        //!< 第25列
    col26    =   0x00000001<<25,        //!< 第26列
    col27    =   0x00000001<<26,        //!< 第27列
    col28    =   0x00000001<<27,        //!< 第28列
    col29    =   0x00000001<<28,        //!< 第29列
    col30    =   0x00000001<<29,        //!< 第30列
    col31    =   0x00000001<<30,        //!< 第31列
    col32    =   0x00000001<<31,        //!< 第32列
};
}


typedef struct
{
    QStringList student;

} studData;
//结构体类型定义

QDebug operator<< (QDebug d, const studData &data)
{    int i,j;
     for(i=0;i<=data.student.size();i++)
     {
         d.noquote().nospace()<<QString(data.student);

     }
    // 请补全运算符重载函数，使其可以直接输出studData结构
    return d;
}
//
//QDebug operator<<(QDebug debug, const Coordinate &c)
//{
//    QDebugStateSaver saver(debug);
//    debug.nospace() << '(' << c.x() << ", " << c.y() << ')';

//    return debug;
//}


// 比较类，用于std::sort第三个参数
class myCmp
{
public:
      int currentColumn;
    myCmp(int selectedColumn) { this->currentColumn = selectedColumn; }
    bool operator() (const studData& d1,const studData& d2);
private:

};

bool myCmp::operator()(const studData &d1, const studData &d2)
{
//    bool result = false;
//    quint32 sortedColumn = 0x00000001<<currentColumn;
//    switch (sortedColumn)
//    {
//    case SK::col01:
    // ...
    // 请补全运算符重载函数
    // ...
    //


    return  d1.student.at(curretColumn+1)>d2.student.at(curretColumn+1);

}



class ScoreSorter//定义排序类
{
public:
    ScoreSorter(QString dataFile);
    void  readfile();
    void  dsort();
    // 补全该类，实现上述要求
private:
    QString subjectfile;
    QList<studData>  data;
    studData subject;
    void outfile(quint8 column);
    //return 0;
   //声明

};

// 补全构造函数

//QFile file("in.txt");
//      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
//          return;

//      while (!file.atEnd()) {
//          QByteArray line = file.readLine();
//          process_line(line);
//      }
ScoreSorter::ScoreSorter(QString dataFile)
{
this->subjectfile=dataFile;
}
void ScoreSorter::readfile()
{
    QFile file(this->subjectfile);
    qDebug()<<subjectfile<<"\n";
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
   qDebug()<<"Can't open the file!"<<endl;
}

QString subject(file.readLine());
{
this->subject.student= subject.split(" ", QString::SkipEmptyParts);
studDate currentdata;
while(!file.atEnd())
{
    QByteArray line = file.readLine();
    QString str(line);
    currentdata.stud = str.split(" ", QString::SkipEmptyParts);
     this->data.append(currentdata);
}
    file.close();

}

void ScoreSorter::dosort()
{
    for(int i=1;i<subject.student.stud.size();i++)
    {
        myCmp subjectcmp(i-1);
                std::sort(this->data.begin() , this->data.end() ,  subjectcmp );
                qDebug()<<"排序后输出，当前排序第 "<<i+1 <<" 列：";
                qDebug()<<this->subject;    //qDebug重载输出
                for(int i=0;i<this->data.size();i++)  qDebug()<<this->data.at(i);
                qDebug()<<"................"
                this->outfile(i+1);
    }

void ScoreSorter::outfile(quint8 column)
{

        QFile file("D:/Homework02/data.txt");//位置
        file.open(QIODevice::ReadWrite | QIODevice::Append);
        QTextStream out(&file);
        out.setCodec("UTF-8");  //设置输出编码格式
        out<<QString("排序后输出，当前排序第 ")<<column<<QString(" 列：")<<"\r\n";
        out<<"\t";
        for(int i=0;i<this->subject.student.size();i++)
            out<<this->subject.at(i)<<"\t";
        out<<"\r\n";
        for(int j=0;j<this->data.size();j++)
        {
            for(int i=0;i<this->subject.student.size();i++)
               out<<this->data.at(j).stud.at(i)<<"\t";
            out<<"\r\n";
        }
        out<<"..................."<<"\r\n\r\n";
        file.close();
    }
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    // 自定义qDebug
    QFile file;
    file("sorteddata.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text)
    QTextStream out(&file);
    out<<msg<<endl;
    file.flush();
    file.close();
    QTextStream sbjstu(studentout);
    sbjstu<<msg;

}

int main()
{
    qInstallMessageHandler(myMessageOutput);
    QString datafile = "D:/Homework02/data.txt";

    // 如果排序后文件已存在，则删除之
    QFile f("D:/Homework02");
    if (f.exists()){
        f.remove();
    }

    ScoreSorter s(datafile);
    s.readFile();
    s.doSort();
    return 0;
}


