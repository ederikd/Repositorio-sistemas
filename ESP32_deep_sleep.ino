RTC_DATA_ATTR int bootCount = 0; //Esta cariable se guarda en la memoria del RTC.
                                   //Esta memoria si se mantiene tras un deep sleep

#define uS_TO_S_FACTOR 1000000 //Factor de conversion s a us
#define TIME_TO_SLEEP  5     // Tiempo que el ESP va a dormir en s
#define LED_PIN      32      //Led
#define BUTTON_PIN   33      //Boton

void setup() {
  Serial.begin(115200);
  delay(500);
  pinMode(LED_PIN, OUTPUT);

  bootCount++;
  Serial.println("Numero de veces iniciado: " + String(bootCount));

  print_wakeup_reason();
  
  //Configuracion Light Sleep
  esp_sleep_enable_ext0_wakeup((gpio_num_t)BUTTON_PIN, HIGH);
  esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP*uS_TO_S_FACTOR);
  Serial.println("Configurando ESP32 para dormir por " + String(TIME_TO_SLEEP) + "segundos.");


  if(bootCount%2 == 0){
   Serial.println("ESP32 se va a dormir ahora.");
  esp_deep_sleep_start(); 
  }
  Serial.println("Esta linea solo se imprimira en reinicios impares");
}

void loop() {
  digitalWrite(LED_PIN, LOW);
  esp_light_sleep_start();

  digitalWrite(LED_PIN, HIGH);
  delay(500);

  print_wakeup_reason();
}

void print_wakeup_reason(){
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  switch(wakeup_reason){
    case ESP_SLEEP_WAKEUP_EXT0:
      Serial.println("Inicio causado por señal en el RTC_TO(Perifericos del RTC)");
    break;

    case ESP_SLEEP_WAKEUP_EXT1:
      Serial.println("Inicio causado por señal en el RTC_CNTL");
    break;

    case ESP_SLEEP_WAKEUP_TIMER:
      Serial.println("Inicio causado por señal en un timer");
    break;

    case ESP_SLEEP_WAKEUP_TOUCHPAD:
      Serial.println("Inicio causado por señal en un pin touch");
    break;

    case ESP_SLEEP_WAKEUP_ULP:
      Serial.println("Inicio causado por señal lanzada por el ULP Croprocessor");
    break;

    default:
      Serial.printf("El inicio no fue causado por ninguna razon conocida: %d\n", wakeup_reason);
  }
}
