#pragma once
#include <string>
#include <array>

namespace RWA2 {

class Sensor final {
private:
    std::string model_;
    std::array<double, 50> data_;

public:
    explicit Sensor(const std::string& model);
    void read_data(unsigned int duration);
};

} // namespace RWA2
    