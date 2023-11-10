#include "legged_robot.h"
#include "mobile_robot.h"
#include "wheeled_robot.h"

int main() {
  RWA2::MobileRobot robot(0.0, 0.0, 0.0, 0.0, "Mobile Robot", "Mobile Robot Sensor", "Mobile Robot Battery", 100);
  robot.move(2.0, 90.0);
  robot.print_Status();

  RWA2::LeggedRobot legged_robot(0.0, 0.0, 0.0, 0.0, "Legged Robot", "Legged Robot Sensor", "Legged Robot Battery", 100, 0.5, 100, 2);
  legged_robot.move(2.0, 90.0);
  legged_robot.print_Status();

  RWA2::WheeledRobot wheeled_robot(0.0, 0.0, 0.0, 0.0, "Wheeled Robot", "Wheeled Robot Sensor", "Wheeled Robot Battery", 100, 4, 0.5, 10.0);
  wheeled_robot.move(2.0, 90.0);
  wheeled_robot.print_Status();
}
