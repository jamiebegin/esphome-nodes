// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using namespace time;
using namespace switch_;
using namespace binary_sensor;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
ota::OTAComponent *ota_otacomponent;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
using namespace sensor;
using namespace mqtt;
using namespace json;
sntp::SNTPComponent *sntp_time;
restart::RestartSwitch *restart_restartswitch;
status::StatusBinarySensor *status_statusbinarysensor;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
ultrasonic::UltrasonicSensorComponent *ultrasonic_ultrasonicsensorcomponent;
mqtt::MQTTSwitchComponent *mqtt_mqttswitchcomponent;
mqtt::MQTTBinarySensorComponent *mqtt_mqttbinarysensorcomponent;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
sensor::LambdaFilter *sensor_lambdafilter;
sensor::MedianFilter *sensor_medianfilter;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_2;
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ===== DO NOT EDIT ANYTHING BELOW THIS LINE =====
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  // esphome:
  //   name: watersoftener
  //   platform: ESP32
  //   board: featheresp32
  //   arduino_version: espressif32@1.12.1
  //   build_path: watersoftener
  //   includes: []
  //   libraries: []
  //   platformio_options: {}
  App.pre_setup("watersoftener", __DATE__ ", " __TIME__);
  // time:
  // switch:
  // binary_sensor:
  // logger:
  //   logs: {}
  //   baud_rate: 115200
  //   id: logger_logger
  //   level: DEBUG
  //   tx_buffer_size: 512
  //   hardware_uart: UART0
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  App.register_component(logger_logger);
  // wifi:
  //   fast_connect: false
  //   reboot_timeout: 15min
  //   domain: !secret 'domain'
  //   manual_ip:
  //     static_ip: 192.168.5.134
  //     gateway: 192.168.5.1
  //     subnet: 255.255.255.0
  //     dns1: 192.168.7.50
  //     dns2: 0.0.0.0
  //   power_save_mode: LIGHT
  //   id: wifi_wificomponent
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_pwd'
  //     priority: 0.0
  //     id: wifi_wifiap
  //   use_address: 192.168.5.134
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.5.134");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("rook");
  wifi_wifiap.set_password("IWantMyPrivacy!");
  wifi_wifiap.set_manual_ip(wifi::ManualIP{
      .static_ip = IPAddress(192, 168, 5, 134),
      .gateway = IPAddress(192, 168, 5, 1),
      .subnet = IPAddress(255, 255, 255, 0),
      .dns1 = IPAddress(192, 168, 7, 50),
      .dns2 = IPAddress(0, 0, 0, 0),
  });
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent->set_fast_connect(false);
  App.register_component(wifi_wificomponent);
  // ota:
  //   port: 3232
  //   id: ota_otacomponent
  //   safe_mode: true
  //   password: ''
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(3232);
  ota_otacomponent->set_auth_password("");
  App.register_component(ota_otacomponent);
  ota_otacomponent->start_safe_mode();
  // mqtt:
  //   broker: !secret 'mqtt_broker'
  //   reboot_timeout: 15min
  //   username: ''
  //   port: 1883
  //   keepalive: 15s
  //   topic_prefix: watersoftener
  //   discovery_prefix: homeassistant
  //   id: mqtt_mqttclientcomponent
  //   discovery: true
  //   password: ''
  //   discovery_retain: true
  //   birth_message:
  //     topic: watersoftener/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: watersoftener/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: watersoftener/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: watersoftener/debug
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
  mqtt_mqttclientcomponent->set_topic_prefix("watersoftener");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "watersoftener/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "watersoftener/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "watersoftener/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "watersoftener/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_keep_alive(15);
  mqtt_mqttclientcomponent->set_reboot_timeout(900000);
  // json:
  // time.sntp:
  //   platform: sntp
  //   id: sntp_time
  //   timezone: EST5EDT4,M3.2.0/2,M11.1.0/2
  //   servers:
  //   - !secret 'ntp_server'
  sntp_time = new sntp::SNTPComponent();
  sntp_time->set_servers("ntp.thebeginfamily.com", "", "");
  App.register_component(sntp_time);
  // switch.restart:
  //   platform: restart
  //   name: Water Softener Sensor Restart
  //   mqtt_id: mqtt_mqttswitchcomponent
  //   icon: mdi:restart
  //   id: restart_restartswitch
  restart_restartswitch = new restart::RestartSwitch();
  App.register_component(restart_restartswitch);
  // binary_sensor.status:
  //   platform: status
  //   name: Water Softener Status
  //   mqtt_id: mqtt_mqttbinarysensorcomponent
  //   device_class: connectivity
  //   id: status_statusbinarysensor
  status_statusbinarysensor = new status::StatusBinarySensor();
  App.register_component(status_statusbinarysensor);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: Water Softener Signal
  //   update_interval: 5min
  //   icon: mdi:wifi
  //   force_update: false
  //   unit_of_measurement: dB
  //   mqtt_id: mqtt_mqttsensorcomponent
  //   accuracy_decimals: 0
  //   id: wifi_signal_wifisignalsensor
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  wifi_signal_wifisignalsensor->set_update_interval(300000);
  App.register_component(wifi_signal_wifisignalsensor);
  // sensor.ultrasonic:
  //   platform: ultrasonic
  //   trigger_pin:
  //     number: 25
  //     inverted: false
  //     mode: OUTPUT
  //   echo_pin:
  //     number: 26
  //     inverted: false
  //     mode: INPUT
  //   name: Brine Tank 1
  //   icon: mdi:barrel
  //   update_interval: 30s
  //   unit_of_measurement: '%'
  //   accuracy_decimals: 0
  //   filters:
  //   - lambda: !lambda |-
  //       return (1.0668-x)*(100/1.0668);
  //     type_id: sensor_lambdafilter
  //   - median:
  //       window_size: 25
  //       send_every: 30
  //       send_first_at: 5
  //     type_id: sensor_medianfilter
  //   pulse_time: 10us
  //   force_update: false
  //   timeout: 2.0
  //   mqtt_id: mqtt_mqttsensorcomponent_2
  //   id: ultrasonic_ultrasonicsensorcomponent
  ultrasonic_ultrasonicsensorcomponent = new ultrasonic::UltrasonicSensorComponent();
  ultrasonic_ultrasonicsensorcomponent->set_update_interval(30000);
  App.register_component(ultrasonic_ultrasonicsensorcomponent);
  sntp_time->set_timezone("EST5EDT4,M3.2.0/2,M11.1.0/2");
  App.register_switch(restart_restartswitch);
  restart_restartswitch->set_name("Water Softener Sensor Restart");
  restart_restartswitch->set_icon("mdi:restart");
  mqtt_mqttswitchcomponent = new mqtt::MQTTSwitchComponent(restart_restartswitch);
  App.register_component(mqtt_mqttswitchcomponent);
  App.register_binary_sensor(status_statusbinarysensor);
  status_statusbinarysensor->set_name("Water Softener Status");
  status_statusbinarysensor->set_device_class("connectivity");
  mqtt_mqttbinarysensorcomponent = new mqtt::MQTTBinarySensorComponent(status_statusbinarysensor);
  App.register_component(mqtt_mqttbinarysensorcomponent);
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("Water Softener Signal");
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dB");
  wifi_signal_wifisignalsensor->set_icon("mdi:wifi");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(wifi_signal_wifisignalsensor);
  App.register_component(mqtt_mqttsensorcomponent);
  App.register_sensor(ultrasonic_ultrasonicsensorcomponent);
  ultrasonic_ultrasonicsensorcomponent->set_name("Brine Tank 1");
  ultrasonic_ultrasonicsensorcomponent->set_unit_of_measurement("%");
  ultrasonic_ultrasonicsensorcomponent->set_icon("mdi:barrel");
  ultrasonic_ultrasonicsensorcomponent->set_accuracy_decimals(0);
  ultrasonic_ultrasonicsensorcomponent->set_force_update(false);
  sensor_lambdafilter = new sensor::LambdaFilter([=](float x) -> optional<float> {
      return (1.0668-x)*(100/1.0668);
  });
  sensor_medianfilter = new sensor::MedianFilter(25, 30, 5);
  ultrasonic_ultrasonicsensorcomponent->set_filters({sensor_lambdafilter, sensor_medianfilter});
  mqtt_mqttsensorcomponent_2 = new mqtt::MQTTSensorComponent(ultrasonic_ultrasonicsensorcomponent);
  App.register_component(mqtt_mqttsensorcomponent_2);
  ultrasonic_ultrasonicsensorcomponent->set_trigger_pin(new GPIOPin(25, OUTPUT, false));
  ultrasonic_ultrasonicsensorcomponent->set_echo_pin(new GPIOPin(26, INPUT, false));
  ultrasonic_ultrasonicsensorcomponent->set_timeout_us(11661.807580174927f);
  ultrasonic_ultrasonicsensorcomponent->set_pulse_time_us(10);
  // =========== AUTO GENERATED CODE END ============
  // ========= YOU CAN EDIT AFTER THIS LINE =========
  App.setup();
}

void loop() {
  App.loop();
}
