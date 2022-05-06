int x, y;     // 位置
int vx, vy; // 速度

void setup()
{
  size(320, 240); // 320×240 ピクセルのウィンドウを作成
  x = 160;      // 位置・速度の初期化
  y = 120;
  vx = 2;
  vy = 2;
}

void draw()
{
  background(255); // 背景を塗りつぶすことで画面をリセット
  x = x + vx;   // 円の位置を更新
  y = y + vy;
  if (x <= 10) vx = -vx; // 壁にぶつかった場合は反転
  if (y <= 10) vy = -vy;
  if (x >= 310) vx = -vx;
  if (y >= 230) vy = -vy;
  ellipse(x, y, 20, 20); // 円を描画
}
