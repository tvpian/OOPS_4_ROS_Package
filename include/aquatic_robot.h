#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
/**
 * @brief Class to represent the aquatic robot
 *
 */
class AquaticRobot final : public MobileRobot {
private:
  bool has_fins_;
  double depth_{0.0};
  bool is_diving_{false};
  void dive(double depth);
  void surface();

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
   * @param depth // depth of the robot in meter
   */

  AquaticRobot(double x, double y, double orientation, double speed,
               std::string model, std::string battery_model, int battery_charge,
               double depth)
      : MobileRobot(x, y, orientation, speed, model, battery_model,
                    battery_charge),
        depth_{depth} {

    // Assign the has fin based on the model
    if (model_ == "HoloOcean") {
      has_fins_ = false;
    } else if (model_ == "SoFi") {
      has_fins_ = true;
    } else {
      std::cout << "\nUnknown model. Assuming the model is HoloOcean."
                << std::endl;
      has_fins_ = false;
    }
  }

  /**
   * @brief Overriding function to move the aquatic robot
   *
   * @param distance // distance to move
   * @param angle // angle to move
   */
  void move(double distance, double angle) override;

  /**
   * @brief Overriding function to print the status of the aquatic robot
   *
   */
  void print_Status() override;

protected:
  /**
   * @brief Overriding function to rotate the aquatic robot
   *
   * @param angle // angle to rotate
   */
  void rotate(double angle) override;
}; // end of class AquaticRobot
} // namespace RWA2
