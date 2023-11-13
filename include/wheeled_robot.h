#pragma once
#include "mobile_robot.h"
#include <iostream>
#include <utility>

namespace RWA2 {
/**
 * @brief Class to represent the wheeled robot
 *
 */
class WheeledRobot final : public MobileRobot {
private:
  int number_of_wheels_{2};
  double wheel_diameter_;
  double desired_speed_;
  void accelerate(double amount);
  void decelerate(double amount);
  void brake();

public:
  /**
   * @brief Construct a new Wheeled Robot object
   *
   * @param x // x coordinate of the robot
   * @param y // y coordinate of the robot
   * @param orientation // orientation of the robot
   * @param speed // speed of the robot
   * @param model // model of the robot
   * @param battery_model // battery model of the robot
   * @param battery_charge // maximum battery charge of the robot
   * @param desired_speed // desired speed of the robot
   */
  WheeledRobot(double x, double y, double orientation, double speed,
               std::string model, std::string battery_model, int battery_charge,
               double desired_speed)
      : MobileRobot(x, y, orientation, speed, model, battery_model,
                    battery_charge),
        desired_speed_{desired_speed} {
    // Assign the wheel diameter and number of wheels based on the robot model
    if (model_ == "Turtlebot") {
      wheel_diameter_ = 0.1;
      number_of_wheels_ = 2;
    } else if (model_ == "Hiwonder") {
      wheel_diameter_ = 0.5;
      number_of_wheels_ = 4;
    } else if (model_ == "Dagu") {
      wheel_diameter_ = 0.8;
      number_of_wheels_ = 6;
    } else {
      std::cout << "\nUnknown model. Assuming the model is Turtlebot."
                << std::endl;
      wheel_diameter_ = 0.1;
      number_of_wheels_ = 2;
    }

    // // Add a sensor to the robot
    // add_Sensor(std::make_unique<RWA2::Sensor>("OSDome"));
  }
  /**
   * @brief Overriding function to move the wheeled robot
   *
   * @param distance // distance to move
   * @param angle  // angle to rotate
   */
  void move(double distance, double angle) override;

  /**
   * @brief Overriding function to print the status of the wheeled robot
   *
   */
  void print_Status() override;

protected:
  /**
   * @brief Overriding function to rotate the wheeled robot
   *
   * @param angle // angle to rotate
   */
  void rotate(double angle) override;
}; // end of class WheeledRobot
} // namespace RWA2
