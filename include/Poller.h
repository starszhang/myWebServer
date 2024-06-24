#pragma once

#include "Noncopyable.h"
#include "EventLoop.h"
#include "Channel.h"
#include "TimeStamp.h"

#include <vector>
#include <unordered_map>


//抽象基类，定义了事件多路复用的接口
class Poller: noncopyable
{
public:
    using ChannelList = std::vector<Channel*>;  //存储被检测到有事件发生的Channel

    Poller(EventLoop* loop);
    virtual ~Poller() = default;

    //基类覆写的，IO复用统一的接口
    virtual TimeStamp poll(int timeoutMs, ChannelList *activeChannels) = 0; //在指定的超时时间内等待事件发生，并将发生事件的通道添加到activeChannels中。
    virtual void updateChannel(Channel *channel) = 0; //在事件多路复用器中添加、更新、删除通道
    virtual void removeChannel(Channel *channel) = 0; //在事件多路复用器中移除通道

    // 判断参数channel是否在当前Poller的channels_当中
    bool hasChannel(Channel *channel) const;

    // EventLoop可以通过该接口获取默认的IO复用的具体实现
    static Poller* newDefaultPoller(EventLoop *loop);

protected:
    using ChannelMap = std::unordered_map<int, Channel*>; //key:socketfd, value:Channel*
    ChannelMap channels_; //存储所有被监视的Channel

private:
    EventLoop* ownerLoop_; //Poller所属的事件循环EventLoop
};