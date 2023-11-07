#pragma once
#include "mobile_robot.h"
#include <iostream>
#include <utility>

namespace RWA2 {
class WheeledRobot : public MobileRobot {
private:
  int number_of_wheels_{2};
  double wheel_diameter_;
  double desired_speed_;
  void accelerate(double amount);
  void decelerate(double amount);
  void brake();

public:
  WheeledRobot(double x, double y, double orientation, double speed,
               std::string model, int number_of_wheels, double wheel_diameter,
               double desired_speed)
      : MobileRobot(x, y, orientation, speed, model),
        number_of_wheels_{number_of_wheels}, wheel_diameter_{wheel_diameter},
        desired_speed_{desired_speed} {}
  void move(double distance, double angle);
  void print_Status();

protected:
  void rotate(double angle);
};
} // namespace RWA2
