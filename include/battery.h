#pragma once
#include <string>

namespace RWA2 {

class Battery final {
private:
    std::string model_;
    int current_charge_;
    bool is_charging_;

    void stop_charging();
public:
    explicit Battery(const std::string& model, int initial_charge = 100);
    void start_charging();
    void discharge(double amount);
};

} // namespace RWA2