#include "legged_robot.h"

void RWA2::LeggedRobot::jump(double amount) {
  // Height equals leg strength x amount in cm
  height_ = leg_strength_ * amount;
  std::cout << model_ << " jumps at a height of " << height_ * 100
            << " cm. above the ground." << std::endl;
}

void RWA2::LeggedRobot::kick() {
  std::cout << model_ << " kicks with a strength of " << leg_strength_
            << std::endl;
}

void RWA2::LeggedRobot::print_Status() {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Leg Strength: " << leg_strength_ << std::endl;
  std::cout << "Number of Legs: " << number_of_legs_ << std::endl;
  std::cout << "Battery: " << battery_.get_current_charge() << "\n";
}

void RWA2::LeggedRobot::rotate(double angle) {
  // Call the base class rotate method
  MobileRobot::rotate(angle);
  std::cout << "\nLeggedRobot::" << model_ << " rotated " << angle
            << " degrees." << std::endl;
}

void RWA2::LeggedRobot::move(double distance, double angle) {

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "LeggedRobot::" << model_ << " in action." << std::endl;
  // The maximum value for distance is 10 m
  if (distance > 10) {
    std::cout << "\nDistance cannot be greater than 10 m." << std::endl;
    std::cout << "LeggedRobot::" << model_ << " would not move." << std::endl;
    return;
  }
  // For every 1cm of height, the robot requires 1% battery
  // and for every 1m of distance, the robot requires 1% battery
  double battery_required = height_ * 100 + leg_strength_;
  // Check if the battery is sufficient
  if (battery_.get_current_charge() < battery_required) {
    std::cout << "\nInsufficient battery to move " << model_ << " by "
              << distance << " m." << std::endl;
    std::cout << "Charging " << model_ << "..." << std::endl;
    // Start charging the battery
    battery_.start_charging();
  }
  // If battery is sufficient, call the read_data method of the sensor
  // to read the data from the sensor
  get_sensor_Values(5);
  // Rotate the robot by the specified angle
  rotate(angle);
  // Call the jump method with 0.5 as the parameter
  jump(0.5);
  // Call the kick method with leg strength as the parameter
  kick();
  // Discharge the battery
  battery_.discharge(battery_required);
  // Call the print_Status method
  print_Status();
  std::cout << std::endl;
}
