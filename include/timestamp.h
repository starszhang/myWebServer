#pragma once
#include <iostream>
#include <string>

// 时间戳类
class TimeStamp
{
public:
    TimeStamp();
    TimeStamp(int64_t microSecondsSinceEpoch);
    // 获取当前时间戳
    static TimeStamp now();
    // 将时间戳转换为字符串
    std::string toString() const;

private:
    int64_t microSecondsSinceEpoch_;
};