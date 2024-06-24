#pragma once

#include "Noncopyable.h"
#include "EventLoop.h"
#include "TimeStamp.h"

#include <functional>
#include <memory>

//通道类，
//封装了sockfd及其感兴趣的event(如EPOLLIN、EPOLLOUT等)；
//还绑定了poller返回的实际发生的事件(即epoll_wait返回的事件数组),负责调用相应的回调函数
class TimeStamp;
class EventLoop;
class Channel:noncopyable
{
public:
    using EventCallback = std::function<void()>;
    using ReadEventCallback = std::function<void(TimeStamp)>;

    Channel(EventLoop* loop, int fd);
    ~Channel();

    //事件处理函数
    void handleEvent(TimeStamp receiveTime);

    //设置回调函数
    void setReadCallback(ReadEventCallback cb) { readCallback_ = std::move(cb); }
    void setWriteCallback(EventCallback cb) { writeCallback_ = std::move(cb); }
    void setCloseCallback(EventCallback cb) { closeCallback_ = std::move(cb); }
    void setErrorCallback(EventCallback cb) { errorCallback_ = std::move(cb); }

    //绑定一个对象，确保Channel在处理事件时该对象还存在
    void tie(const std::shared_ptr<void>& obj);

    int fd() const { return fd_; }
    int events() const { return events_; }
    void set_revents(int revent) { revents_ = revent; }

    //设置fd的事件状态
    void enableReading() { events_ |= kReadEvent; update(); }     //启用读事件，并更新到Poller
    void disableReading() { events_ &= ~kReadEvent; update(); }   //禁用读事件，...
    void enableWriting() { events_ |= kWriteEvent; update(); }    //启用写事件，...
    void disableWriting() { events_ &= ~kWriteEvent; update(); }  //禁用写事件，...
    void disableAll() { events_ = kNoneEvent; update(); }         //禁用所有事件，...

    // 返回fd当前的事件状态
    bool isNoneEvent() const { return events_ == kNoneEvent; }
    bool isWriting() const { return events_ & kWriteEvent; }
    bool isReading() const { return events_ & kReadEvent; }

    int index() { return index_; }  
    void set_index(int index) { index_ = index; }  //设置channel在Poller中的状态

    EventLoop* ownerLoop() { return loop_; }
    void remove(); //从EventLoop中移除当前Channel
    
private:
    void update(); //通知EventLoop,将当前Channel的事件信息更新到Poller
    void handleEventWithGuard(TimeStamp receiveTime); //确保在处理事件时，相关对象不会被销毁

    //定义channel感兴趣的事件类型
    static const int Channel::kNoneEvent = 0; //无事件，用于初始化
    static const int Channel::kReadEvent = EPOLLIN | EPOLLPRI; //读事件
    static const int Channel::kWriteEvent = EPOLLOUT; //写事件

    EventLoop* loop_; //事件循环
    const int fd_; //该channel绑定的fd
    int events_; //channel该兴趣的事件类型
    int revents_; //poller返回的实际发生的事件类型
    int index_; //记录该channel在Poller中的状态

    std::weak_ptr<void> tie_; //解决Channel对象生命周期问题的弱指针
    bool tied_; //标记Channel是否已绑定。如果为true，表示Channel和某个对象（通过tie_）已绑定，处理事件时需要确保该对象存在

    ReadEventCallback readCallback_; //读事件回调函数，文件描述符上有可读事件时调用
    EventCallback writeCallback_; //写事件回调函数。文件描述符上有可写事件时调用
    EventCallback closeCallback_; //关闭事件回调函数。文件描述符关闭时调用
    EventCallback errorCallback_; //错误事件回调函数，文件描述符上发生错误时调用
};