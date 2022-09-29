#include <SD.h>
#include <sd_defines.h>
#include <sd_diskio.h>
#include <Adafruit_BMP085.h>

#define PIN_LED 32

Adafruit_BMP085 bmp;
File readings;
char payload[50]; //Datos a escribir en SD y serial

void setup() {
  Serial.begin(115200); //inicializar serial UART_USB
  bmp.begin(0x77); //Inicializar comunicacion I2C con el sensor barometrico
  SD.begin(); //Inicializar SD

  pinMode(PIN_LED,OUTPUT);


}

void loop() {
  //Hacer: Columna 1:termperatura; columna 2: presion.
  //Serial.print(bmp.readTemperature());//(idea primera)
  //Serial.print(",");
  //Serial.println(bmp.readPressure());

  //Escribo las lecturas en payload
  sprintf(payload,"%.2f,%.2f", bmp.readTemperature(),bmp.readPressure());
  Serial.println(payload);

  //Abro archivo y escribo
  digitalWrite(PIN_LED,HIGH);
    readings = SD.open("/readings.csv", FILE_APPEND);
    readings.println(payload);
    readings.close();
  digitalWrite(PIN_LED,LOW);

  delay(500);
}
