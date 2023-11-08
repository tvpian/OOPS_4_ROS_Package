#include "wheeled_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

void RWA2::WheeledRobot::accelerate(double amount) {
  speed_ += amount;
  std::cout << "\nAccelerating " << model_ << " to " << speed_ << " m/s."
            << std::endl;
}

void RWA2::WheeledRobot::decelerate(double amount) {
  speed_ -= amount;
  std::cout << "\nDecelerating " << model_ << " to " << speed_ << " m/s."
            << std::endl;
}

void RWA2::WheeledRobot::brake() {
  speed_ = 0.0;
  std::cout << "\nBraking " << model_ << "." << std::endl;
}

void RWA2::WheeledRobot::rotate(double angle) {
  orientation_ += angle;
  std::cout << "\nRotating " << model_ << " to " << orientation_ << "degrees."
            << std::endl;
}

void RWA2::WheeledRobot::move(double distance, double angle) {
  rotate(angle);
  position_.first += distance * cos(orientation_ * M_PI / 180);
  position_.second += distance * sin(orientation_ * M_PI / 180);
  std::cout << "\nMoving " << model_ << " to " << position_.first << ", "
            << position_.second << std::endl;
}

void RWA2::WheeledRobot::print_Status() {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Number of wheels: " << number_of_wheels_ << std::endl;
  std::cout << "Wheel diameter: " << wheel_diameter_ << std::endl;
  std::cout << "Desired speed: " << desired_speed_ << std::endl;
}
