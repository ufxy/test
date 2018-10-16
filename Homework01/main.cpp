#include<qDebug>
//定义32位的无符号变量
#define sum 0x12345678
//宏定义——使字符串化，并且为了变量可以正确引用 函数嵌套使用
#define str(m) sstr(m)
#define sstr(m) #m
// 函数宏定义
#define HHI(sum)  (((sum)>>24)&0xff)
#define LHI(sum)  (((sum)>>16)&0xff)
#define HLO(sum)  (((sum)>>8)&0xff)
#define LLO(sum)  ((sum)&0xff)

//定义 最大值 最小值函数
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))

int main(int argc,char *argv[])
{
    int sum_new;
    QList<qint8> values;
    qDebug()<<"原值:"<<str(m)<<"=="<<sum;
    //结果存入QList<qint8> values  添加值
    values.append(HHI(sum));
    values.append(LHI(sum));
    values.append(HLO(sum));
    values.append(LLO(sum));
    qDebug("0x%x==%d 0x%x==%d 0x%x==%d 0x%x==%d",
               values.at(0),values.at(0),values.at(1),values.at(1),
               values.at(2),values.at(2),values.at(3),values.at(3));

    //比较大小
    qDebug("高八位和次高八位最大值: 0x%x",max(values.at(0),values.at(1)));
    qDebug("次低八位和低八位最小值：0x%x",min(values.at(2),values.at(3)));
    //新值（如何用##连接?)
    sum_new=(values.at(2)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+values.at(1);
    qDebug("新值: x%x %d",sum_new,sum_new);
    //排序
    std::sort(values.begin(),values.end(),std::greater<qint8>());
    qDebug()<<"排序后的值:"<<values;
}
