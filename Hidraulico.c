const int sensorPin = A0; // Pin analógico donde está conectado el sensor
const int relayPin = 2;   // Pin digital donde está conectado el relé

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Asegurarse de que el relé esté apagado al inicio
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  Serial.print("Valor del sensor: ");
  Serial.println(sensorValue);

  if (sensorValue > umbral) {
    // Activar el relé (encender la salida de energía)
    digitalWrite(relayPin, HIGH);
    Serial.println("Generador encendido");
  } else {
    // Desactivar el relé (apagar la salida de energía)
    digitalWrite(relayPin, LOW);
    Serial.println("Generador apagado");
  }

  delay(1000); // Puedes ajustar el tiempo de espera según tus necesidades
}
