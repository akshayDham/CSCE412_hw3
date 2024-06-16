#include "LoadBalancer.h"
#include "Logger.h"
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
/**
 * @brief Logs a request to a log file.
 * @param log The log message.
 */
 
void logRequest(const std::string& log) {
    std::ofstream logfile;
    logfile.open("logs.txt", std::ios_base::app); // Append mode
    logfile << log << std::endl;
    logfile.close();
}

LoadBalancer::LoadBalancer(int numServers) : webservers(numServers), time(0) {
    std::srand(std::time(0));
}

void LoadBalancer::addRequest(const Request& req) {
    requestQueue.push(req);
    std::string log = "Generated request from " + req.ip_in + " to " + req.ip_out + " taking " + std::to_string(req.time) + " cycles.";
    logRequest(log);
}

void LoadBalancer::distributeRequests() {
    while (!requestQueue.empty()) {
        for (auto& server : webservers) {
            if (!requestQueue.empty()) {
                Request req = requestQueue.front();
                server.processRequest(req);
                requestQueue.pop();
                std::string log = "Processing request from " + req.ip_in + " to " + req.ip_out + " taking " + std::to_string(req.time) + " cycles.";
                logRequest(log);
            } else {
                break;
            }
        }
    }
}

void LoadBalancer::run(int cycles) {
    for (int i = 0; i < cycles; ++i) {
        if (std::rand() % 10 < 3) { // Simulate adding requests randomly
            Request req("192.168.0." + std::to_string(std::rand() % 256), "10.0.0." + std::to_string(std::rand() % 256), std::rand() % 100);
            addRequest(req);
        }
        distributeRequests();
        time++;
    }
}