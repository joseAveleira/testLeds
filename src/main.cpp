#include <Arduino.h>
#define TOUCH_PIN 32  // Pin capacitivo D32
#define LED_PIN 2     // Pin del LED interno

bool ledState = false; // Estado inicial del LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState); // Inicializar el LED apagado
  Serial.begin(115200);

}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);
  if (touchValue < 20) { // Detecta el toque
    ledState = !ledState; // Cambia el estado del LED
    digitalWrite(LED_PIN, ledState ? HIGH : LOW); // Actualiza el LED
    Serial.print("Estado del LED: ");
Serial.println(ledState ? "ENCENDIDO" : "APAGADO");
    delay(600); // Pequeña pausa para evitar múltiples activaciones
  }
}
