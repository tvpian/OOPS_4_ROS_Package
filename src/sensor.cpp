#include "sensor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

namespace RWA2 {

Sensor::Sensor(const std::string& model) : model_(model) {
    data_.fill(0);
}

void Sensor::read_data(unsigned int duration) {
    std::cout << "Sensor " << model_ << " gathering data for " << duration << " seconds." << std::endl;

    // Sleep for the duration to simulate data gathering
    std::this_thread::sleep_for(std::chrono::seconds(duration));

    // Seed the random number generator
    srand((unsigned) time(0));

    // Fill the array with random numbers between 0 and 30
    for (double &value : data_) {
        value = static_cast<double>(rand()) / (static_cast<double>(RAND_MAX/30));
    }
}

} // namespace RWA2
