import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import i2c
from esphome.const import CONF_CHANNEL, CONF_CHANNELS, CONF_ID, CONF_SCAN

CODEOWNERS = ["@jdominguez199"]

DEPENDENCIES = ["i2c"]

tca9534a_ns = cg.esphome_ns.namespace("tca9534a")
TCA9534AComponent = tca9534a_ns.class_("TCA9548AComponent", cg.Component, i2c.I2CDevice)

MULTI_CONF = True

CONF_BUS_ID = "bus_id"
CONFIG_SCHEMA = (
    cv.Schema(
        {
            cv.GenerateID(): cv.declare_id(TCA9534AComponent),
            cv.Optional(CONF_SCAN): cv.invalid("This option has been removed"),
        }
    )
    .extend(i2c.i2c_device_schema(0x38))
    .extend(cv.COMPONENT_SCHEMA)
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    await i2c.register_i2c_device(var, config)