#include "timestamp.h"
#include "logger.h"
#include <iostream>

using namespace std;

int main()
{
    TimeStamp tp;
    cout << tp.now().toString() << endl;

    LOG_INFO("This is an info message: %s", "Hello, World!");
    LOG_ERROR("This is an error message with code: %d", 404);
    LOG_FATAL("This is a fatal error, program will exit: %s", "Critical failure");

    #ifdef MUDEBUG
    LOG_DEBUG("This is a debug message: %f", 3.1415);
    #endif


    return 0;
}