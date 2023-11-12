#pragma once
#include <array>
#include <string>

namespace RWA2 {
/**
 * @brief Class to represent the sensor
 *
 */
class Sensor final {
private:
  std::string model_;
  std::array<double, 50> data_;

public:
  /**
   * @brief Construct a new Sensor object
   *
   * @param model  // model of the sensor
   */
  explicit Sensor(const std::string &model);
  /**
   * @brief Overriding function to print the status of the sensor
   *
   * @param duration // duration of the sensor reading
   */
  void read_data(unsigned int duration);
}; // end of class Sensor
} // namespace RWA2
