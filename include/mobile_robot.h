#pragma once
#include <iostream>
#include <memory>
#include "battery.h"
#include "sensor.h" 

namespace RWA2 {

class MobileRobot {
public:
  MobileRobot(double x, double y, double orientation, double speed,
              std::string model, std::string sensor_model, std::string battery_model, int battery_charge)
      : position_(std::make_pair(x, y)), orientation_(orientation),
        speed_(speed), model_(model), battery_(battery_model, battery_charge), sensors_(std::make_unique<Sensor>(sensor_model)) {}

  virtual void move(double distance, double angle);
  virtual void print_Status();

protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  std::string model_;
  virtual void rotate(double angle);
  Battery battery_;
  std::unique_ptr<Sensor> sensors_;
};
} // namespace RWA2
