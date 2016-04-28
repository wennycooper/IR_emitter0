#include <CppList.h>

//#include <IRremote.h>
//#include <IRremoteInt.h>

#include <IRremote.h>
IRsend irsend; // IRRemote限定使用數位腳位3

void setup()
{
  Serial.begin(115200);
}

unsigned long v;
void loop() {
  v = 0x77E14050;

  while (1) {
    irsend.sendNEC(v, 32); // 輸出紅外線訊號
    delay(31);
  }
}
