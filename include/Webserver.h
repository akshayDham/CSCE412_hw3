  

// Webserver.h
#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"
#include <queue>

class Webserver {
public:
    void processRequest(Request& req);
};

#endif // WEBSERVER_H
