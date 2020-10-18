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

This produce a lot of output logging. I recommend disabling Home Assistant API integration for this `text_sensor` by marking it as `internal: true`.

Sample Output:

```
[16:24:29][D][LHB_SCAN:018]: Found possible lighthouse: LHB-ABCDABCD
[16:24:29][D][text_sensor:015]: 'LHB Devices Scanner': Sending state '{"timestamp":4,"address":"AB:CD:EF:AB:CD:EF","rssi":-54,"name":"LHB-ABCDABCD"}'
```

JSON structure:

```json
{
    "timestamp": 4,
    "address": "AB:CD:EF:AB:CD:EF",
    "rssi": -54,
    "name": "LHB-ABCDABCD"
}
```
