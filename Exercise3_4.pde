import  processing.serial.*;

Serial  port;

void setup() {
  size(400, 250);
  port = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
  background(0);
  if (port.available() >= 3) {  // ヘッダ + 上位バイト + 下位バイト で合計３バイト
    if (port.read() == 'H') {  // ヘッダ文字を見つけたところから読み取る
      int high = port.read();   // 上位バイト読み込み
      int low = port.read();    // 下位バイト読み込み
      int recv_data = high * 256 + low;  // 上位・下位を合体させる
      text(str(recv_data),160,120);
    }
  }
}
