#include "TCA9534.h"
#include "esphome/core/log.h"
#include <Wire.h>

namespace esphome {
namespace tca9534a {



static const char *const TAG = "tca9534a";

void TCA9534AComponent::setup() {
  ESP_LOGCONFIG(TAG, "Setting up TCA9534A...");
  Wire.begin();
  my_GPIO=new TCA9534();
  if (myGPIO.begin(Wire, 0x38) == false)
  {
    ESP_LOGCONFIG(TAG, "Check Connections. No Qwiic GPIO detected");
  }

  myGPIO.pinMode(currentPinMode);//Use GPIO_OUT and GPIO_IN instead of OUTPUT and INPUT_PULLUP
}

void TCA9534AComponent::dump_config() {
  ESP_LOGCONFIG(TAG, "TCA9534A:");
  LOG_I2C_DEVICE(this);
}


}  // namespace i2c_button
}  // namespace esphome