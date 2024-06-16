#include "Logger.h"
#include <fstream>

void logRequest(const std::string& log) {
    std::ofstream logfile;
    logfile.open("logs/logs.txt", std::ios_base::app); // Append mode
    logfile << log << std::endl;
    logfile.close();
}
 