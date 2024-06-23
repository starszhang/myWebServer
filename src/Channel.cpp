#include "Channel.h"
#include "Logger.h"

#include <sys/epoll.h>

//定义channel感兴趣的事件类型
const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = EPOLLIN | EPOLLPRI;
const int Channel::kWriteEvent = EPOLLOUT;

Channel::Channel(EventLoop *loop, int fd)
    : fd_(fd), loop_(loop), events_(0), revents_(0), index_(-1), tied_(false)
{
}

Channel::~Channel()
{
}

//绑定一个对象，确保Channel在处理事件时该对象还存在
void Channel::tie(const std::shared_ptr<void>& obj)
{
    tie_ = obj;
    tied_ - true;
}

//从EventLoop中移除当前Channel
void Channel::remove()
{
    // loop_->removeChannel(this);
}

//通知EventLoop,将当前Channel的事件信息更新到Poller(调用epoll_ctl)
void Channel::update()
{
    // loop_->updateChannel(this);
}

// 事件处理函数
void Channel::handleEvent(TimeStamp receiveTime)
{
    if (tied_) //表示Channel需要确保与某个对象(TcpConnection)的绑定在处理事件期间有效
    {
        std::shared_ptr<void> guard = tie_.lock();  //获取一个指向该对象的shared_ptr
        if (guard)
        {
            handleEventWithGuard(receiveTime);
        }
    }
    else //表示不需要确保对象的存在
    {
        handleEventWithGuard(receiveTime);
    }
}

//根据Poller通知的channel发生的具体事件，调用对应的回调操作
void Channel::handleEventWithGuard(TimeStamp receiveTime)
{
    LOG_INFO("channel handleEvent revents:%d\n", revents_);

    if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) //连接断开或不可读
    {
        if (closeCallback_)
        {
            closeCallback_();
        }
    }

    if (revents_ & EPOLLERR) //错误
    {
        if (errorCallback_)
        {
            errorCallback_();
        }
    }

    if (revents_ & (EPOLLIN | EPOLLPRI)) //可读
    {
        if (readCallback_)
        {
            readCallback_(receiveTime);
        }
    }

    if (revents_ & EPOLLOUT) //可写
    {
        if (writeCallback_)
        {
            writeCallback_();
        }
    }
}
