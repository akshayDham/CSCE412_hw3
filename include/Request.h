// Request.h
#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

struct Request {
    std::string ip_in;
    std::string ip_out;
    int time;

    Request(const std::string& in, const std::string& out, int t);
};

#endif // REQUEST_H
