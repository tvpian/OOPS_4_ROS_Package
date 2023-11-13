#include "aerial_robot.h"
#include "aquatic_robot.h"
#include "legged_robot.h"
#include "mobile_robot.h"
#include "sensor.h"
#include "wheeled_robot.h"

#include <iostream>
#include <memory>
#include <vector>

void move_robot(const std::vector<std::unique_ptr<RWA2::MobileRobot>> &robots,
                double distance, double angle) {
  for (const auto &robot : robots) {
    robot->move(distance, angle);
  }
}

int main() {
  // Creating a vector of unique pointers to MobileRobot
  std::vector<std::unique_ptr<RWA2::MobileRobot>> mobile_robots;

  // Initiating the mobile robots
  // Initiating the wheeled robot
  std::unique_ptr<RWA2::WheeledRobot> wheeled_robot_ptr =
      std::make_unique<RWA2::WheeledRobot>(0.0, 0.0, 0.0, 0.0, "Turtlebot",
                                           "Li-ion", 5, 10);
  // Adding a sensor to the wheeled robot
  wheeled_robot_ptr->add_Sensor(std::make_unique<RWA2::Sensor>("OSDome"));
  // Initiating the legged robot
  std::unique_ptr<RWA2::LeggedRobot> legged_robot_ptr =
      std::make_unique<RWA2::LeggedRobot>(0.0, 0.0, 0.0, 0.0, "Atlas", "Li-ion",
                                          100, 0.5);
  // Adding a sensor to the legged robot
  legged_robot_ptr->add_Sensor(std::make_unique<RWA2::Sensor>("OSDome"));
  // Initiating the aerial robot
  std::unique_ptr<RWA2::AerialRobot> aerial_robot_ptr =
      std::make_unique<RWA2::AerialRobot>(0.0, 0.0, 0.0, 0.0, "Crazyflie",
                                          "Li-ion", 100, 0.5);
  // Adding a sensor to the aerial robot
  aerial_robot_ptr->add_Sensor(std::make_unique<RWA2::Sensor>("OSDome"));
  // Initiating the aquatic robot
  std::unique_ptr<RWA2::AquaticRobot> aquatic_robot_ptr =
      std::make_unique<RWA2::AquaticRobot>(0.0, 0.0, 0.0, 0.0, "HoloOcean",
                                           "Li-ion", 100, 0.5);
  // Adding a sensor to the aquatic robot
  aquatic_robot_ptr->add_Sensor(std::make_unique<RWA2::Sensor>("OSDome"));

  // Adding the mobile robots to the vector
  mobile_robots.push_back(std::move(wheeled_robot_ptr));
  mobile_robots.push_back(std::move(legged_robot_ptr));
  mobile_robots.push_back(std::move(aerial_robot_ptr));
  mobile_robots.push_back(std::move(aquatic_robot_ptr));

  // Calling the move_robot function
  move_robot(mobile_robots, 2.0, 90.0);

  return 0;
}
