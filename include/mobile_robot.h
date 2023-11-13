#pragma once
#include "battery.h"
#include "sensor.h"
#include <iostream>
#include <memory>
#include <vector>

namespace RWA2 {
/**
 * @brief Class to represent the mobile robot
 *
 */
class MobileRobot {
public:
  /**
   * @brief Construct a new Mobile Robot object
   *
   * @param x // x coordinate of the robot
   * @param y // y coordinate of the robot
   * @param orientation // orientation of the robot
   * @param speed // speed of the robot
   * @param model // model of the robot
   * @param battery_model // battery model of the robot
   * @param battery_charge // battery charge of the robot
   */
  MobileRobot(double x, double y, double orientation, double speed,
              std::string model, std::string battery_model, int battery_charge)
      : position_{x, y},
        orientation_{orientation}, speed_{speed}, model_{model},
        battery_(battery_model, battery_charge) {}
  /**
   * @brief Function to accelerate the robot
   *
   * @param distance // distance to move
   * @param angle // angle to move
   */
  virtual void move(double distance, double angle) = 0;
  /**
   * @brief Function to print the status of the robot
   *
   */
  virtual void print_Status();
  // Add a method to add sensors to the robot
  /**
   * @brief Function to add sensors to the robot
   *
   * @param sensor // Pointer to the sensor object to be added
   */
  void add_Sensor(std::unique_ptr<RWA2::Sensor> sensor);
  // Add a method to read the sensor values
  /**
   * @brief Get the sensor Values object
   *
   * @param duration // duration for which the sensor values are to be read
   */
  void get_sensor_Values(uint duration);
  /**
   * @brief Destroy the Mobile Robot object
   *
   */
  virtual ~MobileRobot() {
    std::cout << "Destroying the parent MobileRobot object\n";
    std::cout << std::endl;
  }

protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  std::string model_;
  /**
   * @brief Function to rotate the robot
   *
   * @param angle // angle to rotate
   */
  virtual void rotate(double angle);
  RWA2::Battery battery_;
  // Create a vector of unique pointers to Sensor objects
  std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;
}; // end of class MobileRobot
} // namespace RWA2
