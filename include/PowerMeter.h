#ifndef POWERMETER_H
#define POWERMETER_H

#include <Arduino.h>

// PowerMeter class for measuring voltage, current, and calculating power metrics
// Clase PowerMeter para medir voltaje, corriente y calcular métricas de potencia
class PowerMeter {
public:
    // Constructor
    // Constructor
    PowerMeter(int voltagePin, int currentPin);

    // Initialization
    // Inicialización
    void begin();

    // Data reading and calculations
    // Lectura de datos y cálculos
    void update();
    float getVoltageAC();
    float getCurrentAC();
    float getPowerActive();
    float getPowerReactive();
    float getPowerApparent();
    float getPowerFactor();

private:
    // Private methods for internal calculations
    // Métodos privados para cálculos internos
    float calculateRMS(float reading, float offset, float gain);
    float calculatePowerActive();
    float calculatePowerReactive();
    float calculatePowerApparent();
    float calculatePowerFactor();

    // Pin variables
    // Variables de pin
    int voltagePin;
    int currentPin;

    // Data storage variables
    // Variables para almacenar datos
    float voltageReading;
    float currentReading;
    float voltageAC;
    float currentAC;
    float powerActive;
    float powerReactive;
    float powerApparent;
    float powerFactor;

    // Sensor-specific constants
    // Constantes específicas del sensor
    static constexpr float referenceVoltage = 3.3;
    static constexpr int adcResolution = 4095;
    static constexpr int sampleCount = 100;
    static constexpr float voltageOffset = 2.5;
    static constexpr float voltageGain = 5.0;
    static constexpr float currentOffset = 2.5;
    static constexpr float currentGain = 5.0;
    static constexpr float phaseAngle = 0.0; // Adjust if measured
    // Ángulo de fase, ajustar si se mide
};

#endif // POWERMETER_H
