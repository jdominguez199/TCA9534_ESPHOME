import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_CHANNEL, CONF_CHANNELS, CONF_ID, CONF_SCAN

CODEOWNERS = ["@jdominguez199"]

DEPENDENCIES = ["i2c"]
CONF_I2C_ADDR = 0x38
tca9534a_ns = cg.esphome_ns.namespace("tca9534a")
TCA9534AComponent = tca9534a_ns.class_("TCA9548AComponent", cg.Component, i2c.I2CDevice)

MULTI_CONF = True

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(tca9534a_ns)
}).extend(cv.COMPONENT_SCHEMA).extend(i2c.i2c_device_schema(CONF_I2C_ADDR))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)