// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace switch_;
using namespace binary_sensor;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
using namespace sensor;
using namespace mqtt;
using namespace i2c;
i2c::I2CComponent *bus_a;
using namespace json;
restart::RestartSwitch *restart_restartswitch;
status::StatusBinarySensor *status_statusbinarysensor;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
bme280::BME280Component *bme280bathoom;
mqtt::MQTTSwitchComponent *mqtt_mqttswitchcomponent;
mqtt::MQTTBinarySensorComponent *mqtt_mqttbinarysensorcomponent;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
sensor::Sensor *bathroom_temp;
sensor::MedianFilter *sensor_medianfilter;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_2;
sensor::Sensor *sensor_sensor;
sensor::MedianFilter *sensor_medianfilter_2;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_3;
sensor::Sensor *sensor_sensor_2;
sensor::MedianFilter *sensor_medianfilter_3;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_4;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: bathroom
  //   platform: ESP8266
  //   board: nodemcuv2
  //   esp8266_restore_from_flash: false
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   build_path: bathroom
  //   arduino_version: espressif8266@2.2.3
  //   board_flash_mode: dout
  App.pre_setup("bathroom", __DATE__ ", " __TIME__);
  // switch:
  // binary_sensor:
  // logger:
  //   hardware_uart: UART0
  //   tx_buffer_size: 512
  //   esp8266_store_log_strings_in_flash: true
  //   id: logger_logger
  //   logs: {}
  //   level: DEBUG
  //   baud_rate: 115200
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // wifi:
  //   fast_connect: false
  //   reboot_timeout: 15min
  //   domain: !secret 'domain'
  //   manual_ip:
  //     static_ip: 192.168.5.110
  //     gateway: 192.168.5.1
  //     subnet: 255.255.255.0
  //     dns1: 192.168.7.50
  //     dns2: 0.0.0.0
  //   output_power: 20.0
  //   id: wifi_wificomponent
  //   power_save_mode: NONE
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_pwd'
  //     priority: 0.0
  //     id: wifi_wifiap
  //   use_address: 192.168.5.110
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.5.110");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("rook");
  wifi_wifiap.set_password("IWantMyPrivacy!");
  wifi_wifiap.set_manual_ip(wifi::ManualIP{
      .static_ip = IPAddress(192, 168, 5, 110),
      .gateway = IPAddress(192, 168, 5, 1),
      .subnet = IPAddress(255, 255, 255, 0),
      .dns1 = IPAddress(192, 168, 7, 50),
      .dns2 = IPAddress(0, 0, 0, 0),
  });
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  App.register_component(wifi_wificomponent);
  // ota:
  //   port: 8266
  //   password: ''
  //   id: ota_otacomponent
  //   safe_mode: true
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("");
  App.register_component(ota_otacomponent);
  ota_otacomponent->start_safe_mode();
  // mqtt:
  //   broker: !secret 'mqtt_broker'
  //   port: 1883
  //   topic_prefix: bathroom
  //   discovery: true
  //   password: ''
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   discovery_retain: true
  //   id: mqtt_mqttclientcomponent
  //   discovery_prefix: homeassistant
  //   username: ''
  //   birth_message:
  //     topic: bathroom/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: bathroom/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: bathroom/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: bathroom/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent = new mqtt::MQTTClientComponent();
  App.register_component(mqtt_mqttclientcomponent);
  // sensor:
  mqtt_mqttclientcomponent->set_broker_address("192.168.7.60");
  mqtt_mqttclientcomponent->set_broker_port(1883);
  mqtt_mqttclientcomponent->set_username("");
  mqtt_mqttclientcomponent->set_password("");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant", true);
  mqtt_mqttclientcomponent->set_topic_prefix("bathroom");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "bathroom/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "bathroom/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "bathroom/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "bathroom/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_keep_alive(15);
  mqtt_mqttclientcomponent->set_reboot_timeout(900000);
  // i2c:
  //   scan: true
  //   id: bus_a
  //   sda: 4
  //   scl: 5
  //   frequency: 50000.0
  bus_a = new i2c::I2CComponent();
  App.register_component(bus_a);
  // json:
  // switch.restart:
  //   platform: restart
  //   name: Bathroom Sensor Restart
  //   mqtt_id: mqtt_mqttswitchcomponent
  //   icon: mdi:restart
  //   id: restart_restartswitch
  restart_restartswitch = new restart::RestartSwitch();
  App.register_component(restart_restartswitch);
  // binary_sensor.status:
  //   platform: status
  //   name: Bathroom Sensor Status
  //   mqtt_id: mqtt_mqttbinarysensorcomponent
  //   device_class: connectivity
  //   id: status_statusbinarysensor
  status_statusbinarysensor = new status::StatusBinarySensor();
  App.register_component(status_statusbinarysensor);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: Bathroom Sensor Signal
  //   update_interval: 60s
  //   icon: mdi:wifi
  //   force_update: false
  //   mqtt_id: mqtt_mqttsensorcomponent
  //   unit_of_measurement: dB
  //   id: wifi_signal_wifisignalsensor
  //   accuracy_decimals: 0
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  wifi_signal_wifisignalsensor->set_update_interval(60000);
  App.register_component(wifi_signal_wifisignalsensor);
  // sensor.bme280:
  //   platform: bme280
  //   id: bme280bathoom
  //   temperature:
  //     name: Bathroom Temperature
  //     id: bathroom_temp
  //     oversampling: 16X
  //     filters:
  //     - median:
  //         window_size: 5
  //         send_every: 6
  //         send_first_at: 1
  //       type_id: sensor_medianfilter
  //     mqtt_id: mqtt_mqttsensorcomponent_2
  //     force_update: false
  //     unit_of_measurement: °C
  //     icon: mdi:thermometer
  //     accuracy_decimals: 1
  //   pressure:
  //     name: Bathroom Pressure
  //     oversampling: 16X
  //     filters:
  //     - median:
  //         window_size: 15
  //         send_every: 60
  //         send_first_at: 1
  //       type_id: sensor_medianfilter_2
  //     mqtt_id: mqtt_mqttsensorcomponent_3
  //     force_update: false
  //     unit_of_measurement: hPa
  //     icon: mdi:gauge
  //     id: sensor_sensor
  //     accuracy_decimals: 1
  //   humidity:
  //     name: Bathroom Humidity
  //     oversampling: 16X
  //     filters:
  //     - median:
  //         window_size: 5
  //         send_every: 6
  //         send_first_at: 1
  //       type_id: sensor_medianfilter_3
  //     mqtt_id: mqtt_mqttsensorcomponent_4
  //     force_update: false
  //     unit_of_measurement: '%'
  //     icon: mdi:water-percent
  //     id: sensor_sensor_2
  //     accuracy_decimals: 1
  //   address: 0x77
  //   update_interval: 5s
  //   i2c_id: bus_a
  //   iir_filter: 'OFF'
  bme280bathoom = new bme280::BME280Component();
  bme280bathoom->set_update_interval(5000);
  App.register_component(bme280bathoom);
  bus_a->set_sda_pin(4);
  bus_a->set_scl_pin(5);
  bus_a->set_frequency(50000);
  bus_a->set_scan(true);
  App.register_switch(restart_restartswitch);
  restart_restartswitch->set_name("Bathroom Sensor Restart");
  restart_restartswitch->set_icon("mdi:restart");
  mqtt_mqttswitchcomponent = new mqtt::MQTTSwitchComponent(restart_restartswitch);
  App.register_component(mqtt_mqttswitchcomponent);
  App.register_binary_sensor(status_statusbinarysensor);
  status_statusbinarysensor->set_name("Bathroom Sensor Status");
  status_statusbinarysensor->set_device_class("connectivity");
  mqtt_mqttbinarysensorcomponent = new mqtt::MQTTBinarySensorComponent(status_statusbinarysensor);
  App.register_component(mqtt_mqttbinarysensorcomponent);
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("Bathroom Sensor Signal");
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dB");
  wifi_signal_wifisignalsensor->set_icon("mdi:wifi");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(wifi_signal_wifisignalsensor);
  App.register_component(mqtt_mqttsensorcomponent);
  bme280bathoom->set_i2c_parent(bus_a);
  bme280bathoom->set_i2c_address(0x77);
  bathroom_temp = new sensor::Sensor();
  App.register_sensor(bathroom_temp);
  bathroom_temp->set_name("Bathroom Temperature");
  bathroom_temp->set_unit_of_measurement("\302\260C");
  bathroom_temp->set_icon("mdi:thermometer");
  bathroom_temp->set_accuracy_decimals(1);
  bathroom_temp->set_force_update(false);
  sensor_medianfilter = new sensor::MedianFilter(5, 6, 1);
  bathroom_temp->set_filters({sensor_medianfilter});
  mqtt_mqttsensorcomponent_2 = new mqtt::MQTTSensorComponent(bathroom_temp);
  App.register_component(mqtt_mqttsensorcomponent_2);
  bme280bathoom->set_temperature_sensor(bathroom_temp);
  bme280bathoom->set_temperature_oversampling(bme280::BME280_OVERSAMPLING_16X);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Bathroom Pressure");
  sensor_sensor->set_unit_of_measurement("hPa");
  sensor_sensor->set_icon("mdi:gauge");
  sensor_sensor->set_accuracy_decimals(1);
  sensor_sensor->set_force_update(false);
  sensor_medianfilter_2 = new sensor::MedianFilter(15, 60, 1);
  sensor_sensor->set_filters({sensor_medianfilter_2});
  mqtt_mqttsensorcomponent_3 = new mqtt::MQTTSensorComponent(sensor_sensor);
  App.register_component(mqtt_mqttsensorcomponent_3);
  bme280bathoom->set_pressure_sensor(sensor_sensor);
  bme280bathoom->set_pressure_oversampling(bme280::BME280_OVERSAMPLING_16X);
  sensor_sensor_2 = new sensor::Sensor();
  App.register_sensor(sensor_sensor_2);
  sensor_sensor_2->set_name("Bathroom Humidity");
  sensor_sensor_2->set_unit_of_measurement("%");
  sensor_sensor_2->set_icon("mdi:water-percent");
  sensor_sensor_2->set_accuracy_decimals(1);
  sensor_sensor_2->set_force_update(false);
  sensor_medianfilter_3 = new sensor::MedianFilter(5, 6, 1);
  sensor_sensor_2->set_filters({sensor_medianfilter_3});
  mqtt_mqttsensorcomponent_4 = new mqtt::MQTTSensorComponent(sensor_sensor_2);
  App.register_component(mqtt_mqttsensorcomponent_4);
  bme280bathoom->set_humidity_sensor(sensor_sensor_2);
  bme280bathoom->set_humidity_oversampling(bme280::BME280_OVERSAMPLING_16X);
  bme280bathoom->set_iir_filter(bme280::BME280_IIR_FILTER_OFF);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
