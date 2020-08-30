# ESP32
ESP32 Application Framework for PlatformIO (C++17)

Requred Libraries:
- ArduinoWebsockets by Gil Maimon
- Adafruit SSD1306 by Adafruit
- Adafruit BusIO by Adafruit
- Adafruit GFX Library by Adafruit

platform.ini

```
[env:esp32dev]
platform = espressif32
board = esp32dev
framework = arduino
monitor_speed = 115200
platform_packages =
    ${esp32.platform_packages}
; not given in examples
;lib_deps =
;    ${common.lib_deps}
build_flags =
    ${common.build_flags}
build_unflags =
	${common.build_unflags}
lib_deps = 
    Adafruit BusIO
    Adafruit GFX Library
    Adafruit SSD1306

[esp32]
; upgrade XTensa32 GCC/G++ compiler to 8.2.0
; use bleeding edge arduino-esp32
platform_packages =
    toolchain-xtensa32 @ 2.80200.200226
    framework-arduinoespressif32 @ https://github.com/espressif/arduino-esp32.git#idf-release/v4.0

[common]
build_flags =
    -std=c++17
    -std=gnu++17
build_unflags =
    -std=gnu++11
```
