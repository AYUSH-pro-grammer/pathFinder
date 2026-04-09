int btn1 = D0;
int btn2 = D1;
int led1 = D2;
int led2 = D3;

int potentio = D4;

long btn2cnt = 0;
long button1time = 0;
long button2time = 0;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(potentio, INPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {

  int pot_reading = analogRead(potentio);
  int brightness = map(pot_reading, 0, 1023, 0, 255);

 // button 1 preess
  if (digitalRead(btn1) == LOW) {
    button1time = millis();
    analogWrite(led1, brightness);
  } else {
    analogWrite(led1, 0);
  }

 // button 2 preess

  if (digitalRead(btn2) == LOW) {
    button2time = millis();
    btn2cnt += 1;
  }

  // checking for  1 second
  if (abs(button1time - button2time) <= 1000) {
    if (btn2cnt > 2) {
      analogWrite(led2, brightness);
      btn2cnt = 0;
    }
  } else {
    analogWrite(led2, 0);
  }
}