#ifndef STM32F103_LIB_LED_H_
#define STM32F103_LIB_LED_H_

#include <cstdint>
#include <memory>
#include <stm32f10x.h>

#include "config.h"
#include "gpio.h"
#include "util.h"

#if !defined(LIB_USE_LED) || LIB_USE_LED < 1
#error "This configuration is not specified to use this library"
#endif  // !defined(LIB_USE_LED) || LIB_USE_LED < 1

/**
 * @brief Implements LED-related features.
 */
class Led {
 public:
  /**
   * @brief Configuration for LED.
   */
  struct Config {
    /**
     * @brief ID of LED.
     */
    uint8_t id;
    /**
     * @brief If true, LED is assumed to be active low.
     */
    bool polarity = false;
  };

  /**
   * @brief Constructor for LED
   *
   * @note LED will always be in off state after constructor is called. If it isn't, your board may have a pull-up
   * resistor, and this feature will be implemented later.
   *
   * @param config LED configuration
   */
  explicit Led(const Config& config);

  /**
   * Sets the state of the LED.
   *
   * @param flag True if LED should be on.
   */
  void SetEnable(const bool flag);
  /**
   * @brief Switches the state of the LED.
   */
  void Switch();

 protected:
  /**
   * @return Pinout of button
   */
  Pin* GetPin() { return &pin_; }

  /**
   * @return GPIO object underlying the button
   */
  GPIO* GetGpio() { return gpio_.get(); }

 private:
  bool polarity_;
  Pin pin_;
  std::unique_ptr<GPIO> gpio_;
};

#endif  // STM32F103_LIB_LED_H_
