int btn1 =D0;
int btn2=D1;
int led1=D2;
int led2=D3;

int potentio=D4;


void setup(){

  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(potentio, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  long btn2cnt = 0;
  long starttime = millis();
}

void loop(){

  long button1time = 0;
  long button2time = 0;

  int pot_reading = analogRead(potentio);


  

  if (digitalRead(btn1)==HIGH){
    button1time = millis();
    analogWrite(led1, pot_reading);
  } else{
    analogWrite(led1, 0);
  }

  if (digitalRead(btn2) == HIGH){
    button2time = millis;
    btn2cnt += 1;
  }

  // need to press button 2 within 1 sec

  if (abs(btn1-btn2) >= 1000){
    if (btn2cnt > 2){
      analogWrite(led2, pot_reading);
      btn2cnt = 0;
    }

  } else {
    analogWrite(led2, 0);
  }
  









}
