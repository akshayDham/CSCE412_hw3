// Webserver.cpp
#include "Webserver.h"
#include <vector>
#include <queue>


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

void Webserver::processRequest(Request& req) {
    // Simulate processing request
    std::cout << "Processing request from " << req.ip_in << " to " << req.ip_out << " taking " << req.time << " cycles.\n";
}
   