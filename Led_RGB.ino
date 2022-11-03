#define LED_R 14
#define LED_G 27
#define LED_B 12
#define PIN_BUTTON 33

int led_status = 0;


// Debouncing (evita el rebote del boton)
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 200;

void IRAM_ATTR isr_button(){
  if(( millis()- lastDebounceTime) > debounceDelay){
    led_status++;
  if (led_status >= 8) led_status = 0;
  //led_status = (led_status >= 7) ? 0 : led_status+1; //Uso de operadpr ternario
  lastDebounceTime = millis();
  }
}

void setup() {
  //Button
  pinMode(PIN_BUTTON, INPUT);
  attachInterrupt(PIN_BUTTON, isr_button, RISING);

  //Leds
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  switch(led_status){
    case 1:    //Red
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, HIGH);
    break;

    case 2:    //Green
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
    break;

    case 3:    //Blue
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
    break;

    case 4:    //Cyan
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
    break;

    case 5:    //Yellow
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, HIGH);
    break;

    case 6:    //Magenta
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, LOW);
    break;

    case 7:    //White
      digitalWrite(LED_R, LOW);
      digitalWrite(LED_G, LOW);
      digitalWrite(LED_B, LOW);
    break;

    default:    //Off
      digitalWrite(LED_R, HIGH);
      digitalWrite(LED_G, HIGH);
      digitalWrite(LED_B, HIGH);
    break;
  }

}
