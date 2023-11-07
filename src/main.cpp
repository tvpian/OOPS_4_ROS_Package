#include "legged_robot.cpp"
#include "mobile_robot.cpp"
#include "wheeled_robot.cpp"

int main() {
  RWA2::MobileRobot robot(0.0, 0.0, 0.0, 0.0, "R2D2");
  robot.print_Status();
  robot.move(10.0, 90.0);
  robot.print_Status();

  RWA2::WheeledRobot wheeled_robot(0.0, 0.0, 0.0, 0.0, "R2D5", 3, 0.5, 1.0);
  wheeled_robot.print_Status();
  wheeled_robot.move(10.0, 90.0);
  wheeled_robot.print_Status();

  // RWA2::LeggedRobot legged_robot(0.0, 0.0, 0.0, 0.0, "R2D6", 1.0, 1, 2);
  //   legged_robot.print_Status();
  //   legged_robot.move(10.0, 90.0);
  //   legged_robot.print_Status();
}
