#include "wheeled_robot.h"
#include <cmath>
#include <iostream>
#include <utility>
#include <chrono>
#include <thread>

void RWA2::WheeledRobot::accelerate(double amount) {
  while (speed_ <= desired_speed_) {
    speed_ += amount;
    std::cout << "\nAccelerating " << model_ << " to " << speed_ << " m/s."
              << std::endl;
    // Sleep for 0.5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void RWA2::WheeledRobot::decelerate(double amount) {
  while (speed_ >- 0.0){
    speed_ -= amount;
    std::cout << "\nDecelerating " << model_ << " to " << speed_ << " m/s."
              << std::endl;
    // Sleep for 0.5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
}

void RWA2::WheeledRobot::brake() {
  speed_ = 0.0;
  std::cout << "\nBraking " << model_ << "." << std::endl;
}

void RWA2::WheeledRobot::rotate(double angle)  {
  std::cout << "\nWheeledRobot::" << model_ << "rotated by " << angle
            << " degrees." << std::endl;
}

void RWA2::WheeledRobot::move(double distance, double angle) {
  // Maximum distance that can be travelled is 100 m
  if (distance > 100.0) {
    std::cout << "\nDistance exceeds maximum limit of 100 m." << std::endl;
    return;
  }
  // For every 1m, the robot requires 1% battery
  double battery_required = distance;
  // Check if the battery is sufficient
  while(battery_.get_current_charge() < battery_required){
    std::cout << "\nInsufficient battery to move " << model_ << " by "
              << distance << " m." << std::endl;
    std::cout << "Charging " << model_ << "..." << std::endl;
    // Start charging the battery
    battery_.start_charging();
  }

  // If battery is sufficient, call the read_data method of the sensor
  // to read the data from the sensor
  sensors_->read_data(5);
  // Rotate the robot by the specified angle
  rotate(angle);
  // Call the accelerate method with 2 as the parameter
  accelerate(0.5);
  // Sleep for distance-2 seconds
  long int time = distance-2;
  std::this_thread::sleep_for(std::chrono::milliseconds((time)*1000));
  // Call the decelearate method with 2 as the parameter
  decelerate(2);
  // Call the brake method
  brake();
  std::cout << model_ << " drove " << distance << " m." << std::endl;
  // Print the status of the robot
  print_Status();
}

void RWA2::WheeledRobot::print_Status()  {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Number of wheels: " << number_of_wheels_ << std::endl;
  std::cout << "Wheel diameter: " << wheel_diameter_ << std::endl;
  std::cout << "Desired speed: " << desired_speed_ << std::endl;
}