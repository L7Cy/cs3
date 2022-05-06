import processing.serial.*; // シリアル通信を利用するための準備
Serial port; // シリアルポート

void setup() {
  size(256, 256); // 256×256 ピクセルのウィンドウを作成
  port = new Serial(this, "COM3", 9600); // シリアルポート初期化
  port.clear(); // シリアルポートのクリア
}

void draw() {
  int c = 0;
  int v[] = new int[2];
  if (port.available() > 2) { // 3 バイト以上のデータが送られてきたとき
    c = port.read(); // シリアル通信の入力を読み取る
    if (c == 'a') { // 入力が「a」の場合
      v[0] = port.read(); // シリアル通信の入力を読み取る
      v[1] = port.read(); // シリアル通信の入力を読み取る
      fill(255, 255 – v[0], 255 – v[1]); // 塗りつぶしの色を入力値に応じて設定
      background(192); // 背景を塗りつぶすことで画面をリセット
      ellipse(127, 127, 100, 100); // 円を描画
    }
  }
}
