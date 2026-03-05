int R = A0;
int G = A1;
int B = A2;

void setup() {
  // put your setup code here, to run once:
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  analogWrite(R, 150);
  analogWrite(G, 150);
  analogWrite(B, 255);

  Serial.begin(9600);
  pinMode(A5, INPUT);

  setColor(255,255,255);
}

void loop() {

  int input = analogRead(A5);
  Serial.println(input);

  if(input >= 1000){
    setColor(0,0,0);
  
  }else if(input >= 800){
    setColor(map(input, 750, 900, 0, 255) ,0 ,0);
    Serial.println("cervena");
  
  }else if(input >= 750){
    setColor(0 ,map(input, 700, 800, 0, 255), 0);
    Serial.println("zelena");

  }else if(input >= 650){
    setColor(0, 0, map(input, 600, 700, 0, 255));
    Serial.println("modra");

  }else{

    setColor(255,255,255);
  }
  delay(10);
}
void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
  #endif
  analogWrite(R, red);
  analogWrite(G, green);
  analogWrite(B, blue);
}
