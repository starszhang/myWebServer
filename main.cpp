#include "TimeStamp.h"
#include "Logger.h"
#include <InetAddress.h>
#include <Socket.h>

#include <iostream>
#include <strings.h>
#include <unistd.h>

using namespace std;

int main()
{
    TimeStamp tp;
    cout << tp.now().toString() << endl;

    LOG_INFO("This is an info message: %s", "Hello, World!");
    LOG_ERROR("This is an error message with code: %d", 404);
    // LOG_FATAL("This is a fatal error, program will exit: %s", "Critical failure");

    #ifdef MUDEBUG
    LOG_DEBUG("This is a debug message: %f", 3.1415);
    #endif

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    Socket servSocket(fd);
    InetAddress servAddr(8888, "127.0.0.1");
    servSocket.bind(servAddr);
    servSocket.listen(1024);

    InetAddress clntAddr;
    int clntfd = servSocket.accept(clntAddr);

    cout << "new client, ip=" << clntAddr.toIp() << ", fd=" << clntfd<< endl; 

    while(true) 
    {
        char buf[1024];
        bzero(&buf, sizeof(buf));
        ssize_t read_bytes = recv(clntfd, buf, sizeof(buf), 0);
        if(read_bytes > 0)
        {
            cout << buf << endl;
            send(clntfd, buf, sizeof(buf), 0);
        } 
        else if(read_bytes == 0)
        {
            cout << "clntfd " << clntfd << " disconnected" << endl;
            close(clntfd);
            break;
        } else if(read_bytes == -1){
            close(clntfd);
        }
    }

    return 0;
}