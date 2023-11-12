#include "mobile_robot.h"
#include <cmath>
#include <memory>
#include <vector>

void RWA2::MobileRobot::rotate(double angle) {
  orientation_ += angle;
  // Normalize the orientation
  orientation_ = std::fmod(orientation_, 360.0);
  // std::cout << "\nRotating " << model_ << " to " << orientation_ << "
  // degrees."
  //           << std::endl;
}

void RWA2::MobileRobot::print_Status() {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
}

void RWA2::MobileRobot::add_Sensor(std::unique_ptr<RWA2::Sensor> sensor) {
  sensors_.push_back(std::move(sensor));
}

void RWA2::MobileRobot::get_sensor_Values(uint duration) {
  for (auto &sensor : sensors_) {
    sensor->read_data(duration);
  }
}
