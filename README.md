# PowerMeter Library

**Autor**: Ing. Fernando Gambino  
**CEO y Fundador en Electrónica Gambino**  
**Brindamos servicios de ingeniería en software y hardware a medida**  
**Sitio Web**: [electronicagambino.com](https://electronicagambino.com)  
**Whatsapp Business**: [wa.me/541128715389](https://wa.me/541128715389)

## Descripción

La **librería PowerMeter** se ha desarrollado para facilitar el control y la medición de módulos de sensores de voltaje y corriente. Esta librería permite una integración más sencilla y eficiente con los siguientes sensores:

- **Sensor de Voltaje Genérico AC 220V ZMPT101B**
- **Sensor de Corriente AC ZMCT103C**

Con esta librería, puedes medir:

- Tensión AC
- Corriente AC
- Potencia Activa
- Potencia Reactiva
- Potencia Aparente
- Factor de Potencia
- Consumo en kWh

## Instalación

Para instalar la librería, puedes buscarla en el [PlatformIO Library Registry](https://platformio.org/lib) o clonar el repositorio desde GitHub y agregarla manualmente a tu proyecto.

1. **Instalación desde PlatformIO:**
   - Abre PlatformIO en VS Code.
   - Ve a la pestaña "Library Manager" (Administrador de Librerías).
   - Busca "PowerMeter" y haz clic en "Install" (Instalar).

2. **Instalación Manual:**
   - Clona el repositorio desde [GitHub](https://github.com/tuusuario/tu-repositorio).
   - Copia la carpeta `PowerMeter` a la carpeta `lib` de tu proyecto.

## Ejemplo de Uso

Aquí tienes un ejemplo básico de cómo usar la librería:

```cpp
#include <PowerMeter.h>

// Crea una instancia de PowerMeter
PowerMeter meter;

void setup() {
    Serial.begin(115200);
    
    // Inicializa el medidor
    meter.begin();
}

void loop() {
    // Lee los valores de voltaje y corriente
    float voltage = meter.readVoltage();
    float current = meter.readCurrent();

    // Calcula la potencia activa
    float activePower = meter.calculateActivePower(voltage, current);
    
    // Calcula la potencia reactiva
    float reactivePower = meter.calculateReactivePower(voltage, current);
    
    // Calcula la potencia aparente
    float apparentPower = meter.calculateApparentPower(voltage, current);
    
    // Calcula el factor de potencia
    float powerFactor = meter.calculatePowerFactor(activePower, apparentPower);
    
    // Calcula el consumo en kWh
    float consumption = meter.calculateConsumption(activePower);

    // Imprime los resultados
    Serial.print("Voltaje: ");
    Serial.print(voltage);
    Serial.println(" V");
    
    Serial.print("Corriente: ");
    Serial.print(current);
    Serial.println(" A");

    Serial.print("Potencia Activa: ");
    Serial.print(activePower);
    Serial.println(" W");

    Serial.print("Potencia Reactiva: ");
    Serial.print(reactivePower);
    Serial.println(" VAR");

    Serial.print("Potencia Aparente: ");
    Serial.print(apparentPower);
    Serial.println(" VA");

    Serial.print("Factor de Potencia: ");
    Serial.println(powerFactor);

    Serial.print("Consumo: ");
    Serial.print(consumption);
    Serial.println(" kWh");

    delay(1000); // Espera 1 segundo antes de leer de nuevo
}
