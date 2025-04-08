// Include necessary libraries +++
#include  // TODO: Wifi
#include  // TODO: ToF sensor library by specific model
#include  // TODO: NRF24 comm library by specific model, hint: RF?
#include  // TODO: For I2C communication
#include  // TODO: For SPI communication

// Define pins and constants
#define TOF_PIN 21  // Pin connected to the ToF sensor's I2C address

// TODO: Utilize SPI for NRF
#define NRF_CE_PIN 5   // Pin for NRF CE (Chip Enable)
#define NRF_CS_PIN 18  // Pin for NRF CS (Chip Select)

// Initialize objects
// Example:
VL53L0X tofSensor;
WiFiClient client;
// TODO: Initialize object for NRF?

// Function prototypes
void setupToFSensor();
void setupNRFModule();
void measureWaterLevel();
// TODO: Send data/measuremens

void setup() {
  Serial.begin(115200);

  // Initialize ToF sensor
  if (!setupToFSensor()) {
    Serial.println("Failed to initialize ToF sensor");
    while (true)
      ;  // Halt the program if initialization fails
  }

  // Initialize NRF module for wireless communication
  if (!setupNRFModule()) {
    Serial.println("Failed to initialize NRF module");
    while (true)
      ;  // Halt the program if initialization fails
  }

  // Connect to WiFi (if needed, probably good start for gateway, or testing without NRF)
  // WiFi.begin("your_SSID", "your_PASSWORD");

  // Wait for WiFi connection
  // while (WiFi.status() != WL_CONNECTED) {
  //     delay(1000);
  //     Serial.println("Connecting to WiFi...");
  // }
}

void loop() {
  // Measure water level using ToF sensor
  measureWaterLevel();

  // Send data via NRF module or WiFi
  // client.print(data);

  delay(1000);  // Adjust the delay as needed
}

bool setupToFSensor() {
  Wire.begin();
  if (!tofSensor.init()) {
    Serial.println("Failed to initialize ToF sensor");
    return false;
  }
  tofSensor.setTimeout(500);
  if (!tofSensor.startRanging(VL53L0X::Long)) {
    Serial.println("Failed to start ranging");
    return false;
  }
  return true;
}

bool setupNRFModule() {
  // Initialize NRF module
  radio.begin();
  radio.setPALevel(RF24_PA_MAX);
  radio.openWritingPipe(0xE8E8F0F0E1LL);  // Example pipe address
  if (!radio.isPVAvailable()) {
    Serial.println("Failed to initialize NRF module");
    return false;
  }
  return true;
}

void measureWaterLevel() {
  // Boilerplate
  VL53L0X_RangingMeasurementData_t measure;

  // Get from sensor lib:
  tofSensor.getRangingMeasurementData(&measure);

  if (measure.RangeStatus != 4) {  // Check for valid measurement
    Serial.print("Distance: ");
    Serial.print(measure.RangeMilliMeter);
    Serial.println(" mm");
  } else {
    Serial.println("Out of range");
  }
}
