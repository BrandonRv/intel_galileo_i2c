#include <I2Cdev.h> // Incluir la librería I2Cdev.h para galileo
#define led 11
#define ADDRESS 0x42 // Asignar una dirección al Arduino emisor

void setup() {
  Wire.begin(); // Iniciar la comunicación I2C con la dirección asignada
  Serial.begin(9600);
  delay(50);
  pinMode(led, OUTPUT);

}

void loop() {

  unsigned long currentTime = millis(); 
  static unsigned long previousTime = 0; // para asincronismo delay() duerme el nucleo

  if (currentTime - previousTime >= 200) {
    digitalWrite(led, !digitalRead(led));
    previousTime = currentTime;
  }

  Serial.println("PRUEBA");
  Wire.beginTransmission(ADDRESS); // Iniciar la transmisión al receptor
  Wire.write("PRUEBA"); // Enviar el mensaje 
  Wire.endTransmission(); // Terminar la transmisión
  delay(10);
}