struct Button {
   const int PIN;
   int numTimesButtonPressed;
   bool pressed;
};

Button button1 = {33,0,false};

void IRAM_ATTR isr_button(){
  button1.numTimesButtonPressed += 1;
  button1.pressed = true; 
}

void setup() {
  Serial.begin(9600);
  pinMode(button1.PIN, INPUT);
  attachInterrupt(button1.PIN, isr_button,RISING);

}

void loop() {

  if(button1.pressed == true){
    Serial.printf("El boton se ha presionado %u veces \n", button1.numTimesButtonPressed);
    button1.pressed = false;
  }

}
