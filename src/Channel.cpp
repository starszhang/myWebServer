#include "Channel.h"

Channel::Channel(EventLoop *loop, int fd)
    : fd_(fd), loop_(loop), events_(0), revents_(0), index_(-1), tied_(false)
{
}

Channel::~Channel()
{
}

// 事件处理函数
void Channel::handleEvent(TimeStamp receiveTime)
{
    
}