# G2_Hardware
G2 - Hårdvara och sensor


Prototype of a portable water level measuring devicem using an NRF module for wireless communication, a Time-of-Flight (ToF) sensor for precise distance measurement, and an ESP32 microcontroller for data processing and control.
This setup allows the ToF sensor to be positioned pointing downwards into the container, providing accurate and reliable water level readings while maintaining portability and ease of integration with a battery-powered system.
Moreover plug and play installation for non-technical person.

# To-Do List

- [ ] Refactor `G2_Hardware.ino` for modularity.
- [ ] Write code for the sensor module by implementing functionality in `sensor.cpp`.
- [ ] Vattennivåsensorn ska mäta max 2 m ner med 1 cm felmarginal
- [ ] Vattennivåsensorn ska testas i fuktiga miljöer
- [ ] Vattennivåsensorn och batterisensor ska skicka data var 15:de minut med konfigurbar uppdatering
- [ ] Vattennivåsensorn ska skicka signal innan översvämmning sker
- [ ] Visuell- och ljudvarning vid översvämmning via HTTP-anrop, API direkt för att aktivera larm, oberoende av Raspberry Pi eller nätverksstatus
- [ ] Develop a unified SPI communication module in `spi.cpp`.
- [ ] Implement NRF communication protocol in `nrf.cpp`, utilizing the unified SPI module.
- [x] Implement battery management functions in `battery.cpp`.
- [ ] Create I2C communication routines in `i2c.cpp` for ToF sensor hardware.
- [ ] Write WiFi connectivity code in `wifi.cpp`.
- [ ] Implement utility functions in `utils.cpp`, (e.g. different levels of debugging)
- [ ] Varning för låg batterinivå 
