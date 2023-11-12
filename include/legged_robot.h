#pragma once
#include "mobile_robot.h"
#include <cmath>
#include <iostream>
#include <utility>

namespace RWA2 {
/**
 * @brief Class to represent the legged robot
 *
 */
class LeggedRobot final : public MobileRobot {
private:
  double height_;
  int leg_strength_;
  int number_of_legs_{2};
  void jump(double amount);
  void kick();

public:
  /**
   * @brief Overriding function to move the legged robot
   *
   * @param distance // distance to move
   * @param angle // angle to move
   */
  void move(double distance, double angle) override;

  /**
   * @brief Overriding function to print the status of the legged robot
   *
   */
  void print_Status() override;

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
   * @param height // height of the robot
   */
  LeggedRobot(double x, double y, double orientation, double speed,
              std::string model, std::string battery_model, int battery_charge,
              double height)
      : MobileRobot(x, y, orientation, speed, model, battery_model,
                    battery_charge),
        height_{height} {
    // Assign the leg strength and number of legs based on the model
    if (model_ == "Spot") {
      leg_strength_ = 5;
      number_of_legs_ = 4;
    } else if (model_ == "Atlas") {
      leg_strength_ = 3;
      number_of_legs_ = 2;
    } else if (model_ == " Mx-Phoenix") {
      leg_strength_ = 10;
      number_of_legs_ = 6;
    } else {
      std::cout << "\nUnknown model. Assuming the model is Spot." << std::endl;
      leg_strength_ = 5;
      number_of_legs_ = 4;
    }
  }

protected:
  /**
   * @brief Overriding function to rotate the legged robot
   *
   * @param angle // angle to rotate
   */
  void rotate(double angle) override;
}; // end of class LeggedRobot
} // namespace RWA2
