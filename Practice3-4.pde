import processing.serial.*; // シリアル通信を利用するための準備
Serial port; // シリアルポート

void setup() {
  size(256, 256); // 256×256 ピクセルのウィンドウを作成
  port = new Serial(this, "COM3", 9600); // シリアルポート初期化
  port.clear(); // シリアルポートのクリア
}

void draw() {
  int c;
  if (port.available() > 0) { // データが送られてきたとき
    c = port.read(); // シリアル通信の入力を読み取る
    if (c == 'r') { // 入力が「r」の場合
      fill(255, 0, 0); // 塗りつぶしの色を赤に設定
    }
    else if (c == 'w') { // 入力が「w」の場合
      fill(255); // 塗りつぶしの色を赤に設定
    }
    background(192); // 背景を塗りつぶすことで画面をリセット
    ellipse(127, 127, 100, 100); // 円を描画
  }
}
