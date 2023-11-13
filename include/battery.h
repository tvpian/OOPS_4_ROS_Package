#pragma once
#include <string>

namespace RWA2 {
/**
 * @brief Class to represent the battery of the robot
 *
 */
class Battery final {
private:
  std::string model_;
  int current_charge_;
  bool is_charging_;

  /**
   * @brief Method to stop charging the battery
   *
   */
  void stop_charging();

public:
  /**
   * @brief Construct a new Battery object
   *
   * @param model // model of the battery
   * @param initial_charge // initial charge of the battery
   */
  explicit Battery(const std::string &model, int initial_charge = 100);
  /**
   * @brief Method to start charging the battery
   *
   */
  void start_charging();
  /**
   * @brief Method to discharge the battery
   *
   * @param amount  // amount of battery to discharge
   */
  void discharge(double amount);
  /**
   * @brief Get the current charge object
   *
   * @return int // current charge of the battery
   */
  int get_current_charge() const;

  /**
   * @brief Destroy the Battery object
   *
   */
  ~Battery() = default;
}; // end of class Battery
} // namespace RWA2
