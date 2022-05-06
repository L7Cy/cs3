int x, y;   // 位置
int vx, vy; // 速度

void setup()
{
  size(320, 240); // 320×240 ピクセルのウィンドウを作成
  x = 160;        // 位置・速度の初期化
  y = 120;
  vx = 2;
  vy = 2;
}

void draw()
{
  background(255); // 背景を塗りつぶすことで画面をリセット
  if (keyPressed == true)
  { // キーが押されたとき
    if (keyCode == LEFT)
    { // 押されたキーが左カーソルキーのとき
      if (vx > 0)
        vx = -vx; // 円の水平方向の速度を左向きに変更
    }
    else if (keyCode == RIGHT)
    { // 押されたキーが左カーソルキーのとき
      if (vx < 0)
        vx = -vx; // 円の水平方向の速度を右向きに変更
    }
    else if (keyCode == UP)
    { // 押されたキーが上カーソルキーのとき
      if (vy > 0)
        vy = -vy; // 円の垂直方向の速度を上向きに変更
    }
    else if (keyCode == DOWN)
    { // 押されたキーが下カーソルキーのとき
      if (vy < 0)
        vy = -vy; // 円の垂直方向の速度を下向きに変更
    }
  }
  else if (mousePressed == true)
  { // マウスのボタンが押されたとき
    if (mouseButton == LEFT)
    {             // 押されたのが左ボタンのとき
      x = mouseX; // 円の位置をマウスカーソルの位置に変更
      y = mouseY;
    }
    else if (mouseButton == RIGHT)
    {          // 押されたのが右ボタンのとき
      x = 160; // 円の位置を画面中央に変更
      y = 120;
    }
  }
  else
  {             // いずれも押されていないとき
    x = x + vx; // 円の位置を更新
    y = y + vy;
    if (x <= 10)
      vx = -vx; // 壁にぶつかった場合は反転
    if (y <= 10)
      vy = -vy;
    if (x >= 310)
      vx = -vx;
    if (y >= 230)
      vy = -vy;
  }
  ellipse(x, y, 20, 20); // 円を描画
}
