int L2 = 2;
int L3 = 3;
int L4 = 4;
int L5 = 5;
int L6 = 6;
int L7 = 7;

void setup() {
  // put your setup code here, to run once kys:
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);
  pinMode(L4, OUTPUT);
  pinMode(L5, OUTPUT);
  pinMode(L6, OUTPUT);
  pinMode(L7, OUTPUT);
  
  digitalWrite(L2, LOW);
  digitalWrite(L3, LOW);
  digitalWrite(L4, LOW);
  digitalWrite(L5, LOW);
  digitalWrite(L6, LOW);
  digitalWrite(L7, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  int pmValue = analogRead(A0);
  int brigth = map(pmValue, 0, 1032, 0, 255);

  
}
