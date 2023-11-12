#include "legged_robot.h"
#include "mobile_robot.h"
#include "wheeled_robot.h"
#include <memory>
#include <vector>

int main() {
  auto wheeled_robot = std::make_unique<RWA2::WheeledRobot>(
      0.0, 0.0, 0.0, 0.0, "Turtlebot", "Lithium", 100, 10);
  // Add a sensor to the robot
  wheeled_robot->add_Sensor(std::make_unique<RWA2::Sensor>("Lidar"));
  // Add another sensor to the robot
  wheeled_robot->add_Sensor(std::make_unique<RWA2::Sensor>("Camera"));
  wheeled_robot->move(5, 90.0);
  auto legged_robot = std::make_unique<RWA2::LeggedRobot>(
      0.0, 0.0, 0.0, 0.0, "Atlas", "Lithium", 300, 0.5);
  // Add a sensor to the robot
  legged_robot->add_Sensor(std::make_unique<RWA2::Sensor>("Lidar"));
  // Add another sensor to the robot
  legged_robot->add_Sensor(std::make_unique<RWA2::Sensor>("Camera"));
  legged_robot->move(5.0, 90.0);
  legged_robot->move(1.0, 340.0);
  return 0;
}
