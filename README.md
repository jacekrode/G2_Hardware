# G2_Hardware
G2 - Hårdvara och sensor


Prototype of a portable water level measuring devicem using an NRF module for wireless communication, a Time-of-Flight (ToF) sensor for precise distance measurement, and an ESP32 microcontroller for data processing and control.
This setup allows the ToF sensor to be positioned pointing downwards into the container, providing accurate and reliable water level readings while maintaining portability and ease of integration with a battery-powered system.
Moreover plug and play installation for non-technical person.

# To-Do List

- [ ] Refactor `G2_Hardware.ino` for modularity.
- [ ] Write code for the sensor module by implementing functionality in `sensor.cpp`.
- [ ] Waterlevel sensor should measure a maximum of 2 m down with a 1 cm margin of error
- [ ] Waterlevel sensor to be tested in humid environments
- [ ] Waterlevel sensor och battery sensor will send data every 15 minutes with configurable update
- [ ] Waterlevel should send a signal before flooding occurs
- [ ] Visual and audio flood warning via HTTP calls, API directly to activate alarms, independent of Raspberry Pi or network status
- [ ] Develop a unified SPI communication module in `spi.cpp`.
- [ ] Implement NRF communication protocol in `nrf.cpp`, utilizing the unified SPI module.
- [x] Implement battery management functions in `battery.cpp`.
- [ ] Create I2C communication routines in `i2c.cpp` for ToF sensor hardware.
- [ ] Write WiFi connectivity code in `wifi.cpp`.
- [ ] Implement utility functions in `utils.cpp`, (e.g. different levels of debugging)
- [ ] Varning för låg batterinivå 
