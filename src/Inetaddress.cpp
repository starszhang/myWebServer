#include "InetAddress.h"
#include <strings.h>
#include <string.h>

using namespace std;

//构造函数:协议族+端口号+ip地址
InetAddress::InetAddress(uint16_t port = 0, string ip = "127.0.0.1")
{
    bzero(&addr_, sizeof(addr_));
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}

InetAddress::InetAddress(const sockaddr_in &addr):addr_(addr)
{
}

//获取ip
string InetAddress::toIp() const
{
    char buf[64] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    return buf;
}

//获取ip+port
string InetAddress::toIpPort() const
{
    // ip:port
    char buf[64] = {0};
    inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    size_t end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buf+end, ":%u", port);
    return buf;
}

//获取端口
uint16_t InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}

//获取sockaddr
const sockaddr_in* InetAddress::getSockAddr() const
{
    return &addr_;
}

//设置sockaddr
void InetAddress::setSockAddr(const sockaddr_in &addr)
{
    addr_ = addr;
}