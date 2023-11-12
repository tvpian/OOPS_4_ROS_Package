#pragma once
#include "battery.h"
#include "sensor.h"
#include <iostream>
#include <memory>
#include <vector>

namespace RWA2 {

class MobileRobot {
public:
  MobileRobot(double x, double y, double orientation, double speed,
              std::string model, std::string battery_model, int battery_charge)
      : position_{x, y},
        orientation_{orientation}, speed_{speed}, model_{model},
        battery_(battery_model, battery_charge) {}
  virtual void move(double distance, double angle) = 0;
  virtual void print_Status();
  // Add a method to add sensors to the robot
  void add_Sensor(std::unique_ptr<RWA2::Sensor> sensor);
  // Add a method to read the sensor values
  void get_sensor_Values(uint duration);

protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  std::string model_;
  virtual void rotate(double angle);
  RWA2::Battery battery_;
  // Create a vector of unique pointers to Sensor objects
  std::vector<std::unique_ptr<RWA2::Sensor>> sensors_;
};
} // namespace RWA2
