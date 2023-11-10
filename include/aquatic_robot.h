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

  void move(double distance, double angle);
  void print_Status();

  AquaticRobot(double x, double y, double orientation, double speed, std::string model, bool has_fins, double depth, bool is_diving)
      : MobileRobot(x, y, orientation, speed, model), has_fins_{has_fins},
        depth_{depth}, is_diving_{is_diving} {}

protected:
  void rotate(double angle);
};
} // namespace RWA2
