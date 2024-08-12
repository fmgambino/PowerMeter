#include <Arduino.h>
#include <PowerMeter.h>

// Define the pins for the voltage and current sensors
// Definir los pines para los sensores de voltaje y corriente
const int voltagePin = 34;  // Pin for the ZMPT101B voltage sensor
const int currentPin = 35;  // Pin for the ZMCT103C current sensor

PowerMeter powerMeter(voltagePin, currentPin);

void setup() {
    // Initialize serial communication
    // Inicializar comunicación serial
    Serial.begin(115200);
    powerMeter.begin();
}

void loop() {
    // Update power meter readings
    // Actualizar lecturas del medidor de potencia
    powerMeter.update();

    // Print voltage, current, and power metrics to the serial monitor
    // Imprimir voltaje, corriente y métricas de potencia en el monitor serial
    Serial.print("AC Voltage (Vrms): ");
    Serial.println(powerMeter.getVoltageAC(), 3);

    Serial.print("AC Current (RMS): ");
    Serial.println(powerMeter.getCurrentAC(), 3);

    Serial.print("Active Power (W): ");
    Serial.println(powerMeter.getPowerActive(), 3);

    Serial.print("Reactive Power (VAR): ");
    Serial.println(powerMeter.getPowerReactive(), 3);

    Serial.print("Apparent Power (VA): ");
    Serial.println(powerMeter.getPowerApparent(), 3);

    Serial.print("Power Factor: ");
    Serial.println(powerMeter.getPowerFactor(), 3);

    // Wait for a second before updating the readings again
    // Espera un segundo antes de actualizar las lecturas nuevamente
    delay(1000);
}
