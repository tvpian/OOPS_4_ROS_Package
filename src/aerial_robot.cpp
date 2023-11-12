#include "aerial_robot.h"
#include <cmath>
#include <iostream>
#include <utility>
#include <chrono>
#include <thread>

void RWA2::AerialRobot::take_off(double altitude) {
  // If the robot is already flying, Abort!
    if (is_flying_) {
        std::cout << "\nThe robot is already flying! Abort!" << std::endl;
        return;
    }

    is_flying_=true;
    if(has_wings_){
        std::this_thread::sleep_for(std::chrono::milliseconds(int(altitude*1000/3)));
        std::cout << "\nThe robot with  wings reached the altitude of " << altitude<<"in"<<altitude/3<< "seconds @3m/s.\n";
    }
    else {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(altitude_*1000/1.5)));
        std::cout << "\nThe robot with no wings reached the altitude of " << altitude <<"in"<<altitude/1.5<< "seconds @1.5m/s.\n";
    }
    altitude_=altitude;
}


void RWA2::AerialRobot::land() {
  // If the robot is already flying, Abort!
    if (!is_flying_ || altitude_==0.0) {
        std::cout << "\nThe robot is not flying! Abort!" << std::endl;
        return;
    }

    if(has_wings_){
        std::this_thread::sleep_for(std::chrono::milliseconds(int(altitude_*1000/4)));
        std::cout << "\nThe robot with  wings landed from the altitude of " << altitude_ <<"in"<<altitude_/4<< "seconds @4m/s.\n";
    }
    else {
        std::this_thread::sleep_for(std::chrono::milliseconds(int(altitude_*1000/1.5)));
        std::cout << "\nThe robot with no wings landed from the altitude of " << altitude_ <<"in"<<altitude_/2<< "seconds @2m/s.\n";
    }

    is_flying_=false;
    altitude_=0.0;

}

//AerialRobot::<model_> rotated <angle> degrees.
void RWA2::AerialRobot::rotate(double angle)  {
  std::cout << "\nLeggedRobot::" << model_ << "rotated " << angle << " degrees." << std::endl;
}

void RWA2::AerialRobot::move(double distance, double angle) {
  // Maximum distance that can be travelled is 50 m
  if (distance > 50.0) {
    std::cout << "\nDistance exceeds maximum limit of 50 m." << std::endl;
    return;
  }
  // For every 1m, the robot requires 2% battery
  //Assuming total distance travelled is summation of reaching the altitude and coming back(altitude X2)
  double battery_required = distance*2*2;
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
  take_off(distance/2);
  rotate(angle);
  land();
  std::cout << model_ << "  reached an altitude of " << distance << " m." << std::endl;
  // Print the status of the robot
  print_Status();
}

void RWA2::AerialRobot::print_Status()  {
  std::cout << "\nStatus of " << model_ << ":" << std::endl;
  std::cout << "Position: " << position_.first << ", " << position_.second
            << std::endl;
  std::cout << "Orientation: " << orientation_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
  std::cout << "Has wings: " << has_wings_ << std::endl;
  std::cout << "Altitude: " << altitude_ << std::endl;
  std::cout << "Is flying: " << is_flying_ << std::endl;
}