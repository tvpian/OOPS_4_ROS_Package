#include "wheeled_robot.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <utility>

void RWA2::WheeledRobot::accelerate(double amount) {
  while (speed_ < desired_speed_) {
    speed_ += amount;
    std::cout << "\nAccelerating " << model_ << " to " << speed_ << " m/s.";
    // Sleep for 0.5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  std::cout << "\n"
            << model_ << " has reached the desired speed of " << desired_speed_
            << " m/s." << std::endl;
}

void RWA2::WheeledRobot::decelerate(double amount) {
  while (speed_ > -0.0) {
    speed_ -= amount;
    std::cout << "\nDecelerating " << model_ << " to " << speed_ << " m/s.";
    // Sleep for 0.5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
  std::cout << "\n" << model_ << " has stopped accelerating." << std::endl;
}

void RWA2::WheeledRobot::brake() {
  speed_ = 0.0;
  std::cout << "\nBraking " << model_ << "." << std::endl;
}

void RWA2::WheeledRobot::rotate(double angle) {
  // Call the base class rotate method
  MobileRobot::rotate(angle);
  std::cout << "\nWheeledRobot::" << model_ << " rotated " << angle
            << " degrees." << std::endl;
}

void RWA2::WheeledRobot::move(double distance, double angle) {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "WheeledRobot::" << model_ << " in action." << std::endl;
  // Maximum distance that can be travelled is 100 m
  if (distance > 100) {
    std::cout << "\nDistance cannot be greater than 100 m." << std::endl;
    std::cout << "WheeledRobot::" << model_ << " would not move." << std::endl;
    return;
  }
  // For every 1m, the robot requires 1% battery
  double battery_required = distance;
  // Check if the battery is sufficient
  if (battery_.get_current_charge() < battery_required) {
    std::cout << "\nInsufficient battery to move " << model_ << " by "
              << distance << " m." << std::endl;
    std::cout << "Charging " << model_ << "..." << std::endl;
    // Start charging the battery
    battery_.start_charging();
  }
  // If battery is sufficient, call the get_sensor_Values method of the sensor
  // to read the data from each sensor in the vector sensors_
  get_sensor_Values(5);
  // Rotate the robot by the specified angle
  rotate(angle);
  // Call the accelerate method with 2 as the parameter
  accelerate(0.5);
  // Sleep for distance-2 seconds
  std::chrono::seconds duration(static_cast<int>(distance - 2));
  std::this_thread::sleep_for(duration);
  // Call the decelearate method with 2 as the parameter
  decelerate(2);
  // Call the brake method
  brake();
  std::cout << model_ << " drove " << distance << " m." << std::endl;
  // Discharge the battery
  battery_.discharge(battery_required);
  // Print the status of the robot
  print_Status();
}

void RWA2::WheeledRobot::print_Status() {
  MobileRobot::print_Status();
  std::cout << "Number of wheels: " << number_of_wheels_ << std::endl;
  std::cout << "Wheel diameter: " << wheel_diameter_ << std::endl;
  std::cout << "Desired speed: " << desired_speed_ << std::endl;
  std::cout << "Battery charge: " << battery_.get_current_charge() << std::endl;
  std::cout << std::endl;
}
