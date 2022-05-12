import processing.serial.*;

Serial port;

final int CAN_W = 256;
final int CAN_H = 256;
int data[] = new int[CAN_W];

void setup() {
  size(256, 256);
  port = new Serial(this, "COM5", 9600);
  port.clear();
}

void draw() {
  int c;
  int i;
  if (port.available() > 0) {
    c = port.read();

    // update
    for (i = 1; i < CAN_W; i++) data[i - 1] = data[i];
    data[CAN_W - 1] = c;

    // draw
    background(192);
    stroke(0);
    for (i = 0; i < CAN_W; i++) line(i, CAN_H - 1, i, CAN_H - data[i]);
  }
}
