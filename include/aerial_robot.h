#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
class AerialRobot : public MobileRobot {
private:
  bool has_wings_;
  double altitude_{0.0};
  bool is_flying_{false};
  void take_off(double altitude_);
  void land();

public:
  AerialRobot(double x, double y, double orientation, double speed,
               std::string model, std::string sensor_model, std::string battery_model, int battery_charge, bool has_wings, double altitude, bool is_flying)
      : MobileRobot(x, y, orientation, speed, model, sensor_model, battery_model, battery_charge), has_wings_{has_wings}, altitude_{altitude}, is_flying_{is_flying} {}
  void move(double distance, double angle) override;
  void print_Status() override;

protected:
  void rotate(double angle) override;
};
} // namespace RWA2
