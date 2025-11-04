int led1_pin = 10;
int led2_pin = 9;
int led3_pin = 8;
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
  pinMode(12, INPUT);
  pinMode(led1_pin, OUTPUT);
  
}

void loop()
{
  
  if (digitalRead(12) == HIGH) {
    ++cnt;
    Serial.println(cnt);
    delay(100);
    blink_led(led1_pin, cnt);
    blink_led(led2_pin, cnt);
    blink_led(led3_pin, cnt);
  }
  
}
