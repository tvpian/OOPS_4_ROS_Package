// Define an abstract class for a mobile robot
// Date: 04/01/2021

#include "../include/mobile_robot.h"
#include <cmath>

void RWA2::MobileRobot::rotate(double angle) {
  orientation_ += angle;
  std::cout << "\nRotating " << model_ << " to " << orientation_ << " degrees."
            << std::endl;
}

void RWA2::MobileRobot::move(double distance, double angle) {
  rotate(angle);
  position_.first += distance * cos(orientation_ * M_PI / 180);
  position_.second += distance * sin(orientation_ * M_PI / 180);
  std::cout << "\nMoving " << model_ << " to " << position_.first << ", "
            << position_.second << std::endl;
}

void RWA2::MobileRobot::print_Status() {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
}
