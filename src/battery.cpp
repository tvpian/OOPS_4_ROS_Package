#include "battery.h"
#include <iostream>
#include <thread>

namespace RWA2 {

Battery::Battery(const std::string &model, int initial_charge)
    : model_(model), current_charge_(initial_charge), is_charging_(false) {}

void Battery::start_charging() {
  if (!is_charging_) {
    is_charging_ = true;
    std::cout << "Battery " << model_ << " is charging." << std::endl;
    int charge_time = (model_ == "Li-ion") ? (100 - current_charge_) * 0.5
                                           : (100 - current_charge_) * 0.25;

    std::this_thread::sleep_for(std::chrono::seconds(charge_time));
    current_charge_ = 100;
    stop_charging();
  }
}

void Battery::discharge(double amount) {
  if (current_charge_ - static_cast<int>(amount) >= 0) {
    current_charge_ -= static_cast<int>(amount);
  } else {
    current_charge_ = 0;
  }
}

void Battery::stop_charging() {
  is_charging_ = false;
  std::cout << "Battery " << model_ << " is fully charged." << std::endl;
}

int Battery::get_current_charge() const { return current_charge_; }
} // namespace RWA2
