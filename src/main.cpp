#include <Arduino.h>
#define TOUCH_PIN 32  // Pin capacitivo D32
#define LED_PIN 2     // Pin del LED interno

bool ledState = false; // Estado inicial del LED

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, ledState); // Inicializar el LED apagado

}

void loop() {
  int touchValue = touchRead(TOUCH_PIN);
  if (touchValue < 20) { // Detecta el toque
    ledState = !ledState; // Cambia el estado del LED
    digitalWrite(LED_PIN, ledState ? HIGH : LOW); // Actualiza el LED
    delay(300); // Pequeña pausa para evitar múltiples activaciones
  }
}
