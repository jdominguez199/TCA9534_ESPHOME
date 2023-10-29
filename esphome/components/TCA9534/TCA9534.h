// #pragma once

// #include "esphome/core/component.h"
// #include "esphome/components/i2c/i2c.h"
// /*
// Using Platformio library: "sparkfun/SparkFun Qwiic GPIO TCA9534 Arduino Library@ 1.0.0"
// */
// #include "Sparkfun_TCA9534.h"
// #include <Wire.h>

// namespace esphome {
// namespace tca9534a {

// class TCA9534AComponent : public Component, public i2c::I2CDevice {
//  public:
//   void setup() override;
//   void dump_config() override;

//  protected:
//   TCA9534 *myGPIO;
//   bool currentPinMode[8] = {GPIO_OUT, GPIO_IN, GPIO_OUT, GPIO_IN, GPIO_OUT, GPIO_OUT, GPIO_OUT, GPIO_OUT};
// };

// }  // namespace dht
// }  // namespace esphome

#pragma once

#include "esphome/core/component.h"
#include "esphome/components/i2c/i2c.h"

namespace esphome {
namespace empty_i2c_component {

class TCA9534AComponent : public i2c::I2CDevice, public Component {
 public:
  void setup() override;
  void loop() override;
  void dump_config() override;
};


}  // namespace empty_i2c_component
}  // namespace esphome