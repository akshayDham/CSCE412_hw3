#include "LoadBalancer.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>


int main() {
    int numServers;
    int runTime;

    std::cout << "Enter number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter runtime (in clock cycles): ";
    std::cin >> runTime;

    LoadBalancer lb(numServers);

    // Generate initial queue
    for (int i = 0; i < numServers * 100; ++i) {
        Request req("192.168.0." + std::to_string(std::rand() % 256), "10.0.0." + std::to_string(std::rand() % 256), std::rand() % 100);
        lb.addRequest(req);
    }

    lb.run(runTime);

    return 0;
}

