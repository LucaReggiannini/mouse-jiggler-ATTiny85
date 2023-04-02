#include <DigiMouse.h>

void setup() {
  
  randomSeed(analogRead(0)); /* Seed for random number generator is generated from background noise on analog pin */
  pinMode(1, OUTPUT);
  DigiMouse.begin(); /* Start */
}

void loop() {
  /* Moves mouse 'n' pixel "up", "down", "left" and "right"  */
  int n = 1;
  moveMouse(0   , n   );
  moveMouse(n   , 0   );
  moveMouse(0   , 0-n );
  moveMouse(0-n , 0   );
}

void moveMouse(int x, int y) {

  /* Make movement */
  DigiMouse.moveX(x);
  DigiMouse.moveY(y);

  /* Turn on the Led for 100ms */
  digitalWrite(1, HIGH);
  DigiMouse.delay(100);
  digitalWrite(1, LOW);

  /* Wait a random value between 10 and 30 seconds  */
  DigiMouse.delay(random(
    10*1000,
    30*1000));
}
