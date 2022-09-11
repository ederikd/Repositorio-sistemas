
#define PIN_LDR 34
#define PIN_LM35 35
#define PIN_LED 32
#define PIN_BUTTON 33

void setup() {
  Serial.begin(9600);
  pinMode(PIN_LED,OUTPUT);
}

void loop() {
   float ligh_THLD = 300;
    
  Serial.println(analogRead(PIN_LDR)); //lectura LDR
  delay(100);
   
  //Si esta oscuro, enciende LED
//  if (analogRead(PIN_LDR)> 300){
  //    digitalWrite(PIN_LED,LOW);  
    //}
    //else{
      //digitalWrite(PIN_LED,HIGH);
    //}
  

  //5000/(10*4095)= 0.1221 --> conversion grados celsius
  //Serial.println(analogRead(35)*0.1221); //lectura LM35
  //delay(100);
}
