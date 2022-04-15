//kadai1-1
//Please set Red LED->9
//Please set Red LED->10

const int SWITCH = 2;
const int LED_red = 9;
const int LED_blue = 10;


void setup(){
  pinMode(SWITCH,INPUT);
  pinMode(LED_red,OUTPUT);
  pinMode(LED_blue,OUTPUT);
}

void loop(){
  int v;
  v = digitalRead(SWITCH);

  if(v == HIGH){
    
   
    digitalWrite(LED_blue,LOW);
    digitalWrite(LED_red,HIGH);
  }
   else{
    digitalWrite(LED_red,LOW);
    digitalWrite(LED_blue,HIGH);
    
    }
  
}
