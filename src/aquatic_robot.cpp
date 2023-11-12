#include "aquatic_robot.h"
#include <cmath>
#include <iostream>
#include <utility>
#include <chrono>
#include <thread>

void RWA2::AquaticRobot::dive(double depth) {
  // If the robot is already diving, Abort!
    if (is_diving_) {
        std::cout << "\nThe robot is already diving! Abort!" << std::endl;
        return;
    }

    is_diving_=true;
    if(has_fins_){
        std::this_thread::sleep_for(std::chrono::milliseconds(int(depth*1000/2)));
        std::cout << "\nThe robot with fins reached the depth of " << depth<<"in"<<depth/2<< "seconds @2m/s.\n";
    }
    else {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(depth_*1000/1)));
        std::cout << "\nThe robot with no fins reached the depth of " << depth <<"in"<<depth/1<< "seconds @1m/s.\n";
    }
    depth_=depth;
}


void RWA2::AquaticRobot::surface() {
  // If the robot is already flying, Abort!
    if (!is_diving_ || depth_==0.0) {
        std::cout << "\nThe robot is not diving! Abort!" << std::endl;
        return;
    }

    if(has_fins_){
        std::this_thread::sleep_for(std::chrono::milliseconds(int(depth_*1000/4)));
        std::cout << "\nThe robot with  fins landed from the depth of " << depth_ <<"in"<<depth_/4<< "seconds @4m/s.\n";
    }
    else {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(depth_*1000/1.5)));
        std::cout << "\nThe robot with no fins landed from the depth of " << depth_ <<"in"<<depth_/2<< "seconds @2m/s.\n";
    }

    is_diving_=false;
    depth_=0.0;

}

//AquaticRobot::<model_> rotated <angle> degrees.
void RWA2::AquaticRobot::rotate(double angle)  {
  std::cout << "\nLeggedRobot::" << model_ << "rotated " << angle << " degrees." << std::endl;
}

void RWA2::AquaticRobot::move(double distance, double angle) {
  // Maximum distance that can be travelled is 100 m
  if (distance > 100.0) {
    std::cout << "\nDistance exceeds maximum limit of 100 m." << std::endl;
    return;
  }
  // For every 1m, the robot requires 1% battery
  //Assuming distance travelled is summation of reaching the depth and coming back(depth X2)
  double battery_required = distance*2;
  // Check if the battery is sufficient
  while(battery_.get_current_charge() < battery_required){
    std::cout << "\nInsufficient battery to move " << model_ << " by "
              << distance << " m." << std::endl;
    std::cout << "Charging " << model_ << "..." << std::endl;
    // Start charging the battery
    battery_.start_charging();
  }

  // If battery is sufficient, call the read_data method of the sensor
  // to read the data from the sensor
  sensors_->read_data(5);
  // Rotate the robot by the specified angle
    rotate(angle);
  dive(distance/2);
  surface();
  std::cout << model_ << "  reached an depth of " << distance << " m." << std::endl;
  // Print the status of the robot
  print_Status();
}

void RWA2::AquaticRobot::print_Status()  {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Has fins: " << has_fins_ << std::endl;
  std::cout << "depth: " << depth_ << std::endl;
  std::cout << "Is diving: " << is_diving_ << std::endl;
}