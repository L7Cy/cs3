#include <Wire.h>           // I2C を使用するためにインクルード
const int ADDRESS = 0x1D;   // センサの I2C スレーブアドレス
const int OUT_X_MSB = 0x01; // 以下,センサ内部レジスタ設定
const int XYZ_DATA_CFG = 0x0E;
const int CTRL_REG1 = 0x2A;
const int CTRL_REG1_ACTV_BIT = 0x01;

void setup()
{
  byte tmp;
  Serial.begin(9600);        // シリアル通信の速度を設定
  Wire.begin();              // I2C 通信の開始
  tmp = readByte(CTRL_REG1); // 以下,センサ初期化
  writeByte(CTRL_REG1, tmp & ~(CTRL_REG1_ACTV_BIT));
  writeByte(XYZ_DATA_CFG, 0);
  tmp = readByte(CTRL_REG1);
  writeByte(CTRL_REG1, tmp | CTRL_REG1_ACTV_BIT);
}

void loop()
{
  byte buf[6];                                             // バッファ
  float g[3];                                              // 加速度
  readByteArray(OUT_X_MSB, 6, buf);                        // センサからデータを読み込む
  g[0] = -(float(int(buf[0] * 256 + buf[1]) / 16)) / 1024; // X 軸方向の加速度
  g[1] = -(float(int(buf[2] * 256 + buf[3]) / 16)) / 1024; // Y 軸方向の加速度
  g[2] = -(float(int(buf[4] * 256 + buf[5]) / 16)) / 1024; // Z 軸方向の加速度
  Serial.print(g[0], 4);                                   // シリアル通信で X 軸方向の加速度を送信(小数点以下 4 桁)
  Serial.print(", ");                                      // シリアル通信で文字列を送信
  Serial.print(g[1], 4);                                   // シリアル通信で X 軸方向の加速度を送信(小数点以下 4 桁)
  Serial.print(", ");                                      // シリアル通信で文字列を送信
  Serial.println(g[2], 4);                                 // シリアル通信で Z 軸方向の加速度を送信(小数点以下 4 桁)
  delay(100);                                              // 100 ミリ秒待機
}

void readByteArray(byte adrs, int datlen, byte *dest)
{ // 複数バイトの読み込み
  Wire.beginTransmission(ADDRESS);
  Wire.write(adrs);
  Wire.endTransmission(false);
  Wire.requestFrom(ADDRESS, datlen);
  while (Wire.available() < datlen)
    ;
  for (int x = 0; x < datlen; x++)
  {
    dest[x] = Wire.read();
  }
}

byte readByte(byte adrs)
{ // 1 バイトの読み込み
  Wire.beginTransmission(ADDRESS);
  Wire.write(adrs);
  Wire.endTransmission(false);
  Wire.requestFrom(ADDRESS, 1);
  while (!Wire.available())
    ;
  return (Wire.read());
}

void writeByte(byte adrs, byte dat)
{ // 1 バイトの書き込み
  Wire.beginTransmission(ADDRESS);
  Wire.write(adrs);
  Wire.write(dat);
  Wire.endTransmission();
}
