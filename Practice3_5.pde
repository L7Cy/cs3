import processing.serial.*; // シリアル通信を利用するための準備
Serial port; // シリアルポート

void setup() {
  size(256, 256); // 256×256 ピクセルのウィンドウを作成
  port = new Serial(this, "COM3", 9600); // シリアルポート初期化
  port.clear(); // シリアルポートのクリア
}

void draw() {
  int v;
  if(port.available() > 0) { // データが送られてきたとき
    v = port.read(); // シリアル通信の入力を読み取る
    fill(255, 255 - v, 255 - v); // 塗りつぶしの色を入力値に応じて設定
    background(192); // 背景を塗りつぶすことで画面をリセット
    ellipse(127, 127, 100, 100); // 円を描画
  }
}
