# Lighthouse Scanner

Debug component that will publish possible [Valve lighthouse base stations](https://www.valvesoftware.com/en/index/base-stations) (v2) as a JSON text sensor.

## Requirements

* esphome 1.15.1
* `esp32_ble_tracker` component

## Usage

```yaml
esp32_ble_tracker:

text_sensor:
  - platform: lhb_scanner
    name: "LHB Devices Scanner"

```

At the moment, any BLE device that has the name prefix "LHB-" is matched. Support for GATT interrogation of BLE devices is not yet available in esphome.
