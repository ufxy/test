#include <QCoreApplication>
#include<QDebug>

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    int i,j;
    //下面使用Qlist来存储数据
    //Qlist<Qstring> list;
   //list<<"one"  <<"two" <<"three"


    QList<QString>studentid,name,course1score,course2score;

    studentid<< "1403130209" << "1403140101" << "1403140102" << "1403140103" ;

    name<<"鲁智深"<<"林冲"<<"宋江"<<"武松";

    course1score<<"80"<<"82"<<"76"<<"88";

    course2score<<"72"<<"76"<<"85"<<"80";
    //生成总表
    QList< QList<QString> > totallist;

    totallist<<studentid<<name<<course1score<<course2score;

    //按姓名排序
    std::sort(name.begin(),name.end(),std::greater<QString>());

    qDebug()<<"姓名排序的成绩单:";

    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";

    for(int i=0;i<name.size();i++)

    {

        for(j=0;j<name.size();j++)

            if(name.at(i)==totallist.at(1).at(j)) break;

        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'

                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';

    }


     //按课程1成绩排序

    std::sort(course1score.begin(),course1score.end(),std::greater<QString>());

    qDebug()<<"课程1成绩排序的成绩单:";

    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";

    for(int i=0;i<course1score.size();i++)

    {

        for(j=0;j<course1score.size();j++)

            if(course1score.at(i)==totallist.at(2).at(j)) break;

        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'

                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';

    }

    //按课程2成绩排序

    std::sort(course2score.begin(),course2score.end(),std::greater<QString>());

    qDebug()<<"课程2成绩排序的成绩单:";

    qDebug()<<"学号"<<"\t\t"<<"姓名"<<"\t\t"<<"课程1"<<'\t'<<"课程2";

    for(int i=0;i<course2score.size();i++)

    {

        for(j=0;j<course2score.size();j++)

            if(course2score.at(i)==totallist.at(3).at(j)) break;

        qDebug()<<totallist.at(0).at(j)<<'\t'<<totallist.at(1).at(j)<<'\t'

                  <<totallist.at(2).at(j)<<'\t'<<totallist.at(3).at(j)<<'\t';
  }


    return a.exec();

}
