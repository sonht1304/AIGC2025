int led1_pin = 11;
int led2_pin = 10;
int led3_pin = 9;
int butt = 12;
int cnt = 0;

void blink_led(int led_pin, int count) {
  
  for (int i = 1; i <= count; ++i) {
    digitalWrite(led_pin, HIGH);
    delay(100);
    digitalWrite(led_pin, LOW);
    delay(100);
  }
  
}

void setup()
{
  
  Serial.begin(9600);
  //pinMode(butt, INPUT);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  
}

void loop()
{
  
  analogWrite(led1_pin, 30);
  analogWrite(led2_pin, 100);
  digitalWrite(led3_pin, HIGH);
  delay(10);
  
}
