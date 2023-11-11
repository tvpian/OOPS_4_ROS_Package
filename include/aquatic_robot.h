#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
class AquaticRobot : public MobileRobot {
private:
  bool has_fins_;
  double depth_{0.0};
  bool is_diving_{false};
  void dive(double depth);
  void surface();

public:
  AquaticRobot(double x, double y, double orientation, double speed,
               std::string model, std::string sensor_model, std::string battery_model, int battery_charge, bool has_fins, double depth, bool is_diving)
      : MobileRobot(x, y, orientation, speed, model, sensor_model, battery_model, battery_charge), has_fins_{has_fins}, depth_{depth}, is_diving_{is_diving} {}
  void move(double distance, double angle) override;
  void print_Status() override;

protected:
  void rotate(double angle) override;
};
} // namespace RWA2
