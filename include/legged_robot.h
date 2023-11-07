#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
class LeggedRobot : public MobileRobot {
private:
  double height_;
  int leg_strength_;
  int number_of_legs_{2};
  void jump(double amount);
  void kick();

public:
  void move(double distance, double angle);
  void print_Status();
  LeggedRobot(double x, double y, double orientation, double speed,
              std::string model, double height, int leg_strength,
              int number_of_legs)
      : MobileRobot(x, y, orientation, speed, model), height_{height},
        leg_strength_{leg_strength}, number_of_legs_{number_of_legs} {}

protected:
  void rotate(double angle);
};
} // namespace RWA2
