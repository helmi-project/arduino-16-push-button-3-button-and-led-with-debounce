/*
   TUTORIAL PUSH BUTTON PADA ARDUINO
   PUSH BUTTON DAN LED
   PENGGUNAAN DEBOUNCE

   Pinout :
   Tombol 1 -> D9
   Tombol 2 -> D8

   D4 -> Led Merah
   D5 -> Led Hijau
   D6 -> Led Biru
   D7 -> Led Kuning
*/

#define TOMBOL1 9
#define TOMBOL2 8

#define merah 4
#define hijau 5
#define biru 6
#define kuning 7

int statusLed = LOW;
int statusTombolTerakhir = HIGH;
int statusTombol;

unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;


void setup()
{
  pinMode(TOMBOL1, INPUT); //set menjadi input
  pinMode(biru, OUTPUT);
  digitalWrite(TOMBOL1, HIGH); //pull high sebagai default awal

  digitalWrite(biru, statusLed);
}

void loop()
{
  int a = digitalRead(TOMBOL1);

  if (a != statusTombolTerakhir) {
    // reset debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (a != statusTombol) {
      statusTombol = a;

      if (statusTombol == LOW) {
        statusLed = !statusLed;
      }
    }
  }
  digitalWrite(biru, statusLed);
  statusTombolTerakhir = a;
}
