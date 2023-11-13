#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
/**
 * @brief Class to represent the aerial robot
 *
 */
class AerialRobot final : public MobileRobot {
private:
  bool has_wings_;
  double altitude_{0.0};
  bool is_flying_{false};
  void take_off(double altitude_);
  void land();

public:
  /**
   * @brief Construct a new Legged Robot object
   *
   * @param x // x coordinate of the robot
   * @param y // y coordinate of the robot
   * @param orientation // orientation of the robot
   * @param speed // speed of the robot
   * @param model // model of the robot
   * @param battery_model // battery model of the robot
   * @param battery_charge // battery charge of the robot
   * @param altitude_ // altitude of the robot in meter
   */

  AerialRobot(double x, double y, double orientation, double speed,
              std::string model, std::string battery_model, int battery_charge,
              double altitude)
      : MobileRobot(x, y, orientation, speed, model, battery_model,
                    battery_charge),
        altitude_{altitude} {
    // Assign the has fin based on the model
    if (model_ == "Crazyflie") {
      has_wings_ = false;
    } else if (model_ == "Erle-Plane") {
      has_wings_ = true;
    } else {
      std::cout << "\nUnknown model. Assuming the model is Crazyflie."
                << std::endl;
      has_wings_ = false;
    }
  }

  /**
   * @brief Overriding function to move the aerial robot
   *
   * @param distance // distance to move
   * @param angle // angle to move
   */

  void move(double distance, double angle) override;

  /**
   * @brief Overriding function to print the status of the aerial robot
   *
   */

  void print_Status() override;

  // Add destructor method
  ~AerialRobot() { std::cout << model_ << " is destroyed." << std::endl; }

protected:
  /**
   * @brief Overriding function to rotate the aquatic robot
   *
   * @param angle // angle to rotate
   */
  void rotate(double angle) override;
}; // end of class AquaticRobot
} // namespace RWA2
