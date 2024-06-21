#pragma once

#include "Noncopyable.h"
#include "InetAddress.h"

// 通信套接字Socket类,bind,listen,accept,shutdown
class Socket
{
public:
    Socket(int fd);
    ~Socket();

    // 获取socket的fd
    int fd() const;
    // 绑定InetAddress
    void bind(const InetAddress &servAddr);
    // 监听套接字
    void listen(int fdNum);
    // 接受新连接，保存新连接的地址信息到clientAddr对象中
    int accept(InetAddress &clientAddr);

    // 关闭套接字的写操作
    void shutdown();

    // 设置复用选项setsockopt
    void setReuseAddr(bool on);
    void setReusePort(bool on);
    void setTcpNoDelay(bool on);
    void setKeepAlive(bool on);

private:
    const int fd_;
};