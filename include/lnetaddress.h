#pragma once

#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>

// 封装socket的sockaddr类
class InetAddress
{
public:
    InetAddress(uint16_t port = 0, std::string ip = "127.0.0.1");
    InetAddress(const sockaddr_in &addr);

    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const;

    const sockaddr_in* getSockAddr() const;
    void setSockAddr(const sockaddr_in &addr);

private:
    sockaddr_in addr_;
};