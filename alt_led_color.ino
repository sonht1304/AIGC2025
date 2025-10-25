const int PIN_R = 8;
const int PIN_G = 9;
const int PIN_B = 10;

void setup() {

  Serial.begin(9600);

  pinMode(A0, INPUT);

  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);

}

void alt_color(int x, int y, int z) {

  analogWrite(PIN_R, x);
  analogWrite(PIN_G, y);
  analogWrite(PIN_B, z);

}

void loop() {
  
  int val = analogRead(A0);

  if (val <= 255)
    alt_color(0, 0, val);
  else if (val > 255 and val <= 510)
    alt_color(0, val - 255, 0);
  else if (val > 510 and val <= 735)
    alt_color(0, 255, 0);
  else
    alt_color(val - 735, 0, 0);

}
