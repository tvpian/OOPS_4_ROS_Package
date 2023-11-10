#include "legged_robot.h"

void RWA2::LeggedRobot::jump(double amount) {
  // Convert the amount to cm
  double amount_in_cm = amount * 100;
  // Height equals leg strength x amount in cm
  height_ = leg_strength_ * amount_in_cm;
  std::cout << model_ << " jumps at a height of " << height_ << " cm. above the ground."
            << std::endl;
}

void RWA2::LeggedRobot::kick() {
  std::cout << model_ << " kicks with a strength of " << leg_strength_
            << std::endl;
}

void RWA2::LeggedRobot::print_Status()  {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Height: " << height_ << std::endl;
  std::cout << "Leg Strength: " << leg_strength_ << std::endl;
  std::cout << "Number of Legs: " << number_of_legs_ << std::endl;
}

void RWA2::LeggedRobot::rotate(double angle)  {
  std::cout << "\nLeggedRobot::" << model_ << "rotated " << angle
            << " degrees." << std::endl;
}

void RWA2::LeggedRobot::move(double distance, double angle)  {
  // The maximum value for distance is 10 m
  if (distance > 10.0) {
    std::cout << "\nMaximum distance that can be travelled is 10 m." << std::endl;
    std::cout << "Moving " << model_ << " by 10 m." << std::endl;
    distance = 10.0;
  }
  // For every 1cm of height, the robot requires 1% battery
  // and for every 1m of distance, the robot requires 1% battery
  double battery_required = height_*100 + leg_strength_;
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
  // Call the jump method with 0.5 as the parameter
  jump(0.5);
  // Call the kick method with leg strength as the parameter
  kick();
  // Call the print_Status method
  print_Status();

}