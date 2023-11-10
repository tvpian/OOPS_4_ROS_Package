// #pragma once
// #include "mobile_robot.h"
// #include <cmath>
// #include <iostream>
// #include <utility>

// namespace RWA2 {
// class AerialRobot : public MobileRobot {
// private:
//   bool has_wings_;
//   double altitude_{0.0};
//   bool is_flying_{false};
//   void take_off(double altitude_);
//   void land();

// public:

//   void move(double distance, double angle);
//   void print_Status();

//   AerialRobot(double x, double y, double orientation, double speed, std::string model, bool has_wings, double altitude, bool is_flying)
//       : MobileRobot(x, y, orientation, speed, model), has_wings_{has_wings},
//         altitude_{altitude}, is_flying_{is_flying} {}

// protected:
//   void rotate(double angle);
// };
// } // namespace RWA2
