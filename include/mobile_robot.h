#pragma once
#include <iostream>

namespace RWA2 {

class MobileRobot {
public:
  MobileRobot(double x, double y, double orientation, double speed,
              std::string model)
      : position_{x, y}, orientation_{orientation}, speed_{speed}, model_{
                                                                       model} {}

  void move(double distance, double angle);
  void print_Status();

protected:
  std::pair<double, double> position_;
  double orientation_;
  double speed_{0.0};
  std::string model_;
  void rotate(double angle);
};
} // namespace RWA2
