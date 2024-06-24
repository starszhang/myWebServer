#include "Socket.h"
#include "Logger.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <strings.h>
#include <netinet/tcp.h>
#include <sys/socket.h>

Socket::Socket(int fd) : fd_(fd)
{
}

Socket::~Socket()
{
    close(fd_);
}

// 获取socket的fd
int Socket::fd() const
{
    return fd_;
}

// 绑定InetAddress
void Socket::bind(const InetAddress &servAddr)
{
    if (::bind(fd_, (sockaddr *)servAddr.getSockAddr(), sizeof(sockaddr)) == -1)
    {
        LOG_FATAL("bind sockfd:%d fail\n", fd_);
    }
}

// 监听套接字
void Socket::listen(int fdNum)
{
    if (::listen(fd_, fdNum) == -1)
    {
        LOG_FATAL("listen sockfd:%d fail\n", fd_);
    }
}

// 接受新连接，并返回该连接的文件描述符。还会将客户端的地址信息保存到clientAddr对象中
int Socket::accept(InetAddress &clientAddr)
{
    sockaddr_in addr;
    socklen_t len = sizeof(addr);
    bzero(&addr, sizeof(addr));
    // 接受一个新的客户端连接,指定新连接的套接字应设置为非阻塞模式，并在执行exec系统调用时自动关闭。
    int clientfd = ::accept4(fd_, (sockaddr *)&addr, &len, SOCK_NONBLOCK | SOCK_CLOEXEC);
    if (clientfd > 0)
    {
        clientAddr.setSockAddr(addr);
    }
    else
    {
        LOG_FATAL("accept new connect fail\n");
    }
    return clientfd;
}

// 关闭套接字的写操作
void Socket::shutdown()
{
    if (::shutdown(fd_, SHUT_WR) < 0)
    {
        LOG_ERROR("shutdown write error\n");
    }
}

// 设置复用选项--setsockopt
void Socket::setReuseAddr(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(fd_, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);
}
void Socket::setReusePort(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(fd_, SOL_SOCKET, SO_REUSEPORT, &optval, sizeof optval);
}
void Socket::setTcpNoDelay(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(fd_, IPPROTO_TCP, TCP_NODELAY, &optval, sizeof optval);
}
void Socket::setKeepAlive(bool on)
{
    int optval = on ? 1 : 0;
    ::setsockopt(fd_, SOL_SOCKET, SO_KEEPALIVE, &optval, sizeof optval);
}