#include "legged_robot.h"
#include "mobile_robot.h"
#include "wheeled_robot.h"
#include <memory>
#include <vector>

int main() {
  auto wheeled_robot = std::make_unique<RWA2::WheeledRobot>(
      0.0, 0.0, 0.0, 0.0, "Turtlebot", "ss", 5, 10);
  wheeled_robot->move(2, 90.0);
  wheeled_robot->move(2, 90.0);
  wheeled_robot->move(200, 90.0);
  auto legged_robot = std::make_unique<RWA2::LeggedRobot>(
      0.0, 0.0, 0.0, 0.0, "Atlas", "ss", 100, 0.5);
  legged_robot->move(2.0, 90.0);
  return 0;
}
