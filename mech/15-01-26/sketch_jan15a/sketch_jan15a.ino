int all[8] = {2,3,4,5,6,7,8,9};
int cisla[10][7] = {
  {1,1,1,0,1,1,1}, //0
  {1,0,0,0,1,0,0}, //1
  {1,1,0,1,0,1,1}, //2
  {1,1,0,1,1,1,0}, //3
  {1,0,1,1,1,0,0}, //4
  {0,1,1,1,1,1,0}, //5
  {0,1,1,1,1,1,1}, //6
  {1,1,0,0,1,0,0}, //7
  {1,1,1,1,1,1,1}, //8
  {1,1,1,1,1,0,0}  //9
};
void setup(){

  for(int i = 2; i<=9; i++){

    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  /*for(int i = 0; i<10; i++){
    zapsatCislo(i);
    delay(1000);
  }*/
  zapsatCislo(8);
}
void loop(){
  
}
void zapsatCislo(int cislo){

  for(int i = 0; i<10; i++){
    if(cisla[cislo][i] == 1) digitalWrite(all[i], LOW);
    else digitalWrite(all[i], HIGH);
  }  
}