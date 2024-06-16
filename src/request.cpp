// Request.cpp
#include "Request.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
Request::Request(const std::string& in, const std::string& out, int t)
    : ip_in(in), ip_out(out), time(t) {}
 