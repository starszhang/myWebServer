#include "TimeStamp.h"
#include <time.h>

using namespace std;

TimeStamp::TimeStamp() : microSecondsSinceEpoch_(0)
{
}

TimeStamp::TimeStamp(int64_t microSecondsSinceEpoch) : microSecondsSinceEpoch_(microSecondsSinceEpoch)
{
}

// 静态方法，获取当前时间戳，精度：秒
TimeStamp TimeStamp::now()
{
    // 获取当前系统时间
    time_t t = time(NULL);
    return TimeStamp(t);
}

// 将时间戳转换为字符串
string TimeStamp::toString() const
{
    char buf[128] = {0};
    // 将表示时间的time_t值转换为表示本地时间的tm结构
    tm *lt = localtime(&microSecondsSinceEpoch_);
    // 格式化输出时间格式
    snprintf(buf, 128, "%04d/%02d/%02d %02d:%02d:%02d", lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
    return buf;
}