#pragma once

#include "esphome/core/component.h"
#include "esphome/components/esp32_ble_tracker/esp32_ble_tracker.h"
#include "esphome/components/text_sensor/text_sensor.h"

#ifdef ARDUINO_ARCH_ESP32

namespace esphome {
namespace lighthouses {

class LHBScanner : public text_sensor::TextSensor, public esp32_ble_tracker::ESPBTDeviceListener, public Component {
 public:
  bool parse_device(const esp32_ble_tracker::ESPBTDevice &device) override;

  void dump_config() override;
  float get_setup_priority();

 protected:
};

}  // namespace lighthouses
}  // namespace esphome

#endif