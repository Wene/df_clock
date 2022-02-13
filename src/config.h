#pragma once

#include <Arduino.h>

#define NUM_ALARM 10
#define NUM_WIFI 5

struct Alarm
{
  int32_t secs_in_day;
  uint8_t sound;
  int hour();
  int min();
  int sec();
  void hour(int new_val);
  void min(int new_val);
  void sec(int new_val);
};

class Config
{
public:
  Config();
  void setup();
  void store_wifi_settings(const String &name, const String &key, int i);
  void store_clock_settings(const String &ntp_server_address, long utc_offset, int dst_offset);
  void store_alarm_settings(const Alarm& alarm, int i);
  const String &get_wifi_ssid(int i);
  const String &get_wifi_psk(int i);
  const String &get_ntp_server();
  long get_utc_offset_secs();
  int get_dst_offset_secs();
  Alarm get_alarm_settings(int i);

private:
  String ssid[NUM_WIFI];
  String psk[NUM_WIFI];
  String ntp_server;
  long utc_offset_secs;
  int dst_offset_secs;
  Alarm alarm[NUM_ALARM];
};

extern Config config;
