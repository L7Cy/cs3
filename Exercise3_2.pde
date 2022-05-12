import processing.serial.*;

Serial port;

void setup() {
  size(512, 512);
  port = new Serial(this, "COM5", 9600);
  port.clear();
}

void draw() {
  int v = 0;
  if (port.available()>0) {
    v = port.read();
    println(v);
    fill(255,255 - v,255 - v);
    background(125);
    rect(0, 100, v, 100);
    //delay(100);
  };
}
