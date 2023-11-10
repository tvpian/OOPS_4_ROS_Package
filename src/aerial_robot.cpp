// #include "aerial_robot.h"

// void RWA2::AerialRobot::move(double distance, double angle) {
//   rotate(angle);
//   position_.first += distance * cos(orientation_ * M_PI / 180);
//   position_.second += distance * sin(orientation_ * M_PI / 180);
//   std::cout << "\nMoving " << model_ << " to " << position_.first << ", "
//             << position_.second << std::endl;
// }
// void RWA2::AerialRobot::print_Status() {
//   std::cout << "\nStatus of " << model_ << ":" << std::endl;
//   std::cout << "Position: " << position_.first << ", " << position_.second
//             << std::endl;
//   std::cout << "Orientation: " << orientation_ << std::endl;
//   std::cout << "Speed: " << speed_ << std::endl;
//   std::cout << "Has wings: " << has_wings_ << std::endl;
//   std::cout << "Altitude: " << altitude_ << std::endl;
//   std::cout << "Is flying: " << is_flying_ << std::endl;
// }
// void RWA2::AerialRobot::rotate(double angle) {
//   orientation_ += angle;
//   std::cout << "\nRotating " << model_ << " to " << orientation_ << "degrees."
//             << std::endl;
// }
// // void RWA2::AquaticRobot::jump(double amount) {
// //   position_.second += amount;
// //   std::cout << "\nJumping " << model_ << " to " << position_.second
// //             << " meters." << std::endl;
// // }
// // void RWA2::AquaticRobot::kick() {
// //   std::cout << "\nKicking with " << model_ << "." << std::endl;
// // }
