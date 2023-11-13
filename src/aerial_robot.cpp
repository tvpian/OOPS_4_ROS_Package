#include "aerial_robot.h"
#include <chrono>
#include <cmath>
#include <iostream>
#include <thread>
#include <utility>

void RWA2::AerialRobot::take_off(double altitude) {
  // If the robot is already flying, Abort!
  if (is_flying_) {
    std::cout << "\nThe robot is already flying! Abort!" << std::endl;
    return;
  }

  is_flying_ = true;
  std::cout << "\nThe robot is taking off... ";

  if (has_wings_) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(int(altitude * 1000 / 3)));
    std::cout << "\nThe robot with  wings reached the altitude of " << altitude
              << " in " << altitude / 3 << "seconds @3m/s.\n";
  } else {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(int(altitude_ * 1000 / 1.5)));
    std::cout << "\nThe robot with no wings reached the altitude of "
              << altitude << " in " << altitude / 1.5 << "seconds @1.5m/s.\n";
  }
  altitude_ = altitude;
}

void RWA2::AerialRobot::land() {
  // If the robot is already flying, Abort!
  if (!is_flying_ || altitude_ == 0.0) {
    std::cout << "\nThe robot is not flying! Abort!" << std::endl;
    return;
  }
  std::cout << "\nThe robot is landing... ";
  if (has_wings_) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(int(altitude_ * 1000 / 4)));
    std::cout << "\nThe robot with  wings landed from the altitude of "
              << altitude_ << " in " << altitude_ / 4 << "seconds @4m/s.\n";
  } else {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(int(altitude_ * 1000 / 1.5)));
    std::cout << "\nThe robot with no wings landed from the altitude of "
              << altitude_ << " in " << altitude_ / 2 << "seconds @2m/s.\n";
  }

  is_flying_ = false;
  altitude_ = 0.0;
}

// AerialRobot::<model_> rotated <angle> degrees.
void RWA2::AerialRobot::rotate(double angle) {
  // Call the base class rotate method
  MobileRobot::rotate(angle);
  std::cout << "\nAerialRobot:: " << model_ << " rotated " << angle
            << " degrees." << std::endl;
}

void RWA2::AerialRobot::move(double distance, double angle) {
  std::cout << "----------------------------------------" << std::endl;
  std::cout << "AerialRobot::" << model_ << " in action." << std::endl;
  // Maximum distance that can be travelled is 50 m
  if (distance > 50.0) {
    std::cout << "\nDistance exceeds maximum limit of 50 m." << std::endl;
    std::cout << "AerialRobot::" << model_ << " would not move." << std::endl;
    return;
  }
  // For every 1m, the robot requires 2% battery
  // Assuming total distance travelled is summation of reaching the altitude and
  // coming back(altitude X2)
  double battery_required = distance * 2 * 2;
  // Check if the battery is sufficient
  if (battery_.get_current_charge() < battery_required) {
    std::cout << "\nInsufficient battery to move " << model_ << " by "
              << distance << " m." << std::endl;
    std::cout << "Charging " << model_ << "..." << std::endl;
    // Start charging the battery
    battery_.start_charging();
  }

  // If battery is sufficient, call the read_data method of the sensor
  // to read the data from each sensor in the vector sensors_

  get_sensor_Values(5); // Rotate the robot by the specified angle
  // Call the take_off method with distance/2 as the parameter
  take_off(distance / 2);
  // Call the function rotate
  rotate(angle);
  land();
  // the instruction asked to Print: <model_> reached an altitude of <distance>
  // meters and then landed. but the take off was distance/2. Hence reached an
  // altitude of distance/2. Both the lines are contradicting!
  //**updated reached an altitude of <distance/2>
  std::cout << model_ << " reached an altitude of " << distance / 2
            << " meters and then landed." << std::endl;

  // Discharge the battery
  battery_.discharge(battery_required);

  // Print the status of the robot
  print_Status();
}

void RWA2::AerialRobot::print_Status() {
  MobileRobot::print_Status();
  std::cout << "Has wings: " << has_wings_ << std::endl;
  std::cout << "Altitude: " << altitude_ << std::endl;
  std::cout << "Is flying: " << is_flying_ << std::endl;
  std::cout << "Battery charge: " << battery_.get_current_charge() << std::endl;
  std::cout << std::endl;
}
