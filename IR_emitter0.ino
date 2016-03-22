#include <IRremote.h>

IRsend irsend; // IRRemote限定使用數位腳位3

void setup()
{
  Serial.begin(115200);
}

void loop() {
  int d;
  if(true) { // 讀取序列埠
    d = '1';
    unsigned long v = 0x0;

    /*
    switch(d){ // 根據讀取到的資料，換成代表六個按鍵的紅外線編碼
      case '1':
        v = 0x77E14050;
      break;
      case '2':
        v = 0x77E12050;
      break;
      case '3':
        v = 0x77E1D050;
      break;
      case '4':
        v = 0x77E1B050;
      break;
      case '5':
        v = 0x77E1E050;
      break;
      case '6':
        v = 0x77E11050;
      break;
    }
    */
    
    v = 0x77E14050;
    if(v != 0x0){
      //Serial.print("read ");
      //Serial.print(d);
      Serial.print(", IR send ");
      Serial.println(v, HEX);
      irsend.sendNEC(v, 32); // 輸出紅外線訊號
      delay(31);
    }
  }
}
