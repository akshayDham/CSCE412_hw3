/**
 * @file LoadBalancer.h
 * @brief Header file for the LoadBalancer class.
 */

#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <queue>
#include "Request.h"
#include "Webserver.h"

/**
 * @class LoadBalancer
 * @brief Manages a queue of requests and distributes them to web servers.
 */
class LoadBalancer {
public:
    /**
     * @brief Constructor to initialize the LoadBalancer with a number of servers.
     * @param numServers Number of web servers.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Adds a request to the queue.
     * @param req The request to add.
     */
    void addRequest(const Request& req);

    /**
     * @brief Distributes requests from the queue to the web servers.
     */
    void distributeRequests();

    /**
     * @brief Runs the load balancer for a specified number of cycles.
     * @param cycles Number of clock cycles to run.
     */
    void run(int cycles);

private:
    std::vector<Webserver> webservers; /**< Vector of web servers. */
    std::queue<Request> requestQueue; /**< Queue of requests. */
    int time; /**< Simulation time. */
};

#endif // LOADBALANCER_H
