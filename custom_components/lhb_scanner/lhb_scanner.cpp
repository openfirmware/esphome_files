#include "lhb_scanner.h"
#include "esphome/core/log.h"
#include "esphome/core/helpers.h"

#ifdef ARDUINO_ARCH_ESP32

namespace esphome {
namespace lighthouses {

using namespace esp32_ble_tracker;

static const char *TAG = "LHB_SCAN";

bool LHBScanner::parse_device(const ESPBTDevice &device) {
  // Look for names starting with "LHB-"
  std::string name = device.get_name();
  if (name.length() > 4 && name.substr(0,4) == "LHB-") {
    ESP_LOGD(TAG, "Found possible lighthouse: %s", name.c_str());

    this->publish_state("{\"timestamp\":" + to_string(::time(NULL)) +
                        ","
                        "\"address\":\"" +
                        device.address_str() +
                        "\","
                        "\"rssi\":" +
                        to_string(device.get_rssi()) +
                        ","
                        "\"name\":\"" +
                        device.get_name() + "\"}");

  }
  return true;
}

void LHBScanner::dump_config() {
  LOG_TEXT_SENSOR("", "Lighthouse Scanner", this);
}

float LHBScanner::get_setup_priority() {
    return setup_priority::DATA;
}

}  // namespace lighthouses
}  // namespace esphome

#endif