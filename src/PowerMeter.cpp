#include "PowerMeter.h"
#include <math.h>

// Constructor to initialize pin variables
// Constructor para inicializar las variables de pin
PowerMeter::PowerMeter(int voltagePin, int currentPin)
    : voltagePin(voltagePin), currentPin(currentPin),
      voltageReading(0.0), currentReading(0.0),
      voltageAC(0.0), currentAC(0.0),
      powerActive(0.0), powerReactive(0.0),
      powerApparent(0.0), powerFactor(0.0) {}

// Setup pin modes
// Configura los modos de los pines
void PowerMeter::begin() {
    pinMode(voltagePin, INPUT);
    pinMode(currentPin, INPUT);
}

// Read sensor data and perform calculations
// Leer datos del sensor y realizar cálculos
void PowerMeter::update() {
    // Average readings for voltage sensor
    // Promediar lecturas para el sensor de voltaje
    float voltageSum = 0.0;
    for (int i = 0; i < sampleCount; i++) {
        voltageSum += analogRead(voltagePin);
        delay(10);
    }
    voltageReading = voltageSum / sampleCount;

    // Average readings for current sensor
    // Promediar lecturas para el sensor de corriente
    float currentSum = 0.0;
    for (int i = 0; i < sampleCount; i++) {
        currentSum += analogRead(currentPin);
        delay(10);
    }
    currentReading = currentSum / sampleCount;

    // Calculate AC voltage and current (RMS)
    // Calcular voltaje y corriente AC (RMS)
    voltageAC = calculateRMS(voltageReading, voltageOffset, voltageGain);
    currentAC = calculateRMS(currentReading, currentOffset, currentGain);

    // Calculate power metrics
    // Calcular métricas de potencia
    powerApparent = calculatePowerApparent();
    powerActive = calculatePowerActive();
    powerReactive = calculatePowerReactive();
    powerFactor = calculatePowerFactor();
}

// Convert ADC reading to RMS value
// Convertir lectura del ADC a valor RMS
float PowerMeter::calculateRMS(float reading, float offset, float gain) {
    return (reading / adcResolution) * referenceVoltage - offset / gain / (2 * sqrt(2));
}

// Calculate apparent power
// Calcular potencia aparente
float PowerMeter::calculatePowerApparent() {
    return voltageAC * currentAC;
}

// Calculate active power
// Calcular potencia activa
float PowerMeter::calculatePowerActive() {
    return powerApparent * cos(phaseAngle);
}

// Calculate reactive power
// Calcular potencia reactiva
float PowerMeter::calculatePowerReactive() {
    return powerApparent * sin(phaseAngle);
}

// Calculate power factor
// Calcular factor de potencia
float PowerMeter::calculatePowerFactor() {
    return cos(phaseAngle);
}

// Get AC voltage
// Obtener voltaje AC
float PowerMeter::getVoltageAC() {
    return voltageAC;
}

// Get AC current
// Obtener corriente AC
float PowerMeter::getCurrentAC() {
    return currentAC;
}

// Get active power
// Obtener potencia activa
float PowerMeter::getPowerActive() {
    return powerActive;
}

// Get reactive power
// Obtener potencia reactiva
float PowerMeter::getPowerReactive() {
    return powerReactive;
}

// Get apparent power
// Obtener potencia aparente
float PowerMeter::getPowerApparent() {
    return powerApparent;
}

// Get power factor
// Obtener factor de potencia
float PowerMeter::getPowerFactor() {
    return powerFactor;
}
