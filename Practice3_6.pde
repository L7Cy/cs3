import processing.serial.*; // シリアル通信を利用するための準備
Serial port; // シリアルポート

void setup() {
  size(256, 256); // 256×256 ピクセルのウィンドウを作成
  port = new Serial(this, "COM3", 9600); // シリアルポート初期化
  port.clear(); // シリアルポートのクリア
}

void draw() {
  if (mousePressed == true) { // マウスのボタンが押されたとき
    port.write('a'); // シリアル通信で「a」を送信
    fill(255, 0, 0); // 塗りつぶしの色を赤に設定
  }
  else{ // マウスのボタンが押されていないとき
    port.write('b'); // シリアル通信で「b」を送信
    fill(255); // 塗りつぶしの色を白に設定
  }
  background(192); // 背景を塗りつぶすことで画面をリセット
  ellipse(127, 127, 100, 100); // 円を描画
}
