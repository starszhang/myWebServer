#include "Logger.h"
#include "TimeStamp.h"
#include <iostream>

using namespace std;

// 获取日志的单例对象
Logger& Logger::getInstance()
{
    static Logger log;
    return log;
}

// 设置日志级别
void Logger::setLogLevel(int level)
{
    logLevel_ = level;
}

// 写日志，格式:[级别]time: msg
void Logger::log(std::string msg)
{
    switch (logLevel_)
    {
        case INFO:
            cout << "[INFO]";
            break;
        case ERROR:
            cout << "[ERROR]";
            break;
        case FATAL:
            cout << "[FATAL]";
            break;
        case DEBUG:
            cout << "[DEBUG]";
            break;
        default:
            break;
    }
    cout << TimeStamp::now().toString() << ": " << msg << endl;
}