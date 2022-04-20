#include<Yamst.h>


void setup()
{
  Serial.begin(115200);

  Serial.println();
  Serial.println("Yamst demo - blink");
  blink_setup();
}
/* ---------- End of setup ---------- */

void loop()
{
  blink_loop();
}
/* ---------- End of loop ---------- */
