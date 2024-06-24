#pragma once

#include "Poller.h"

//使用epoll具体实现IO多路复用
class EPollPoller : public Poller
{
public:
    EPollPoller(EventLoop* loop);
    ~EPollPoller() override;

    //重写基类Poller的抽象方法
    TimeStamp poll(int timeoutMs, ChannelList* activeChannels) override; //内部调用fillActiveChannels
    //根据通道的状态（新添加、修改、删除）选择对应的epoll_ctl操作,内部调用update()
    void updateChannel(Channel* channel) override;
    void removeChannel(Channel* channel) override;

private:
    static const int kInitEventListSize = 16;
    void fillActiveChannels(int numEvents, ChannelList* activeChannels) const; //将发生事件的通道添加到activeChannels中 
    void update(int operation, Channel* channel);

    using EventList = std::vector<struct epoll_event>;
    int epollfd_;
    EventList events_; //epoll_wait中用到的epoll_event类型的events
};
