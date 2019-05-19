#define Buton 5
int sensor=8;
int in1=7;
int in2=9;
int enA=6;

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode (sensor, INPUT);
  pinMode(Buton,INPUT);
  Serial.begin(9600);

 digitalWrite(in1,LOW);
 digitalWrite(in2,LOW);
 digitalWrite(enA,HIGH);
}

void loop() {
 bool okunan = digitalRead(sensor);
 if(okunan==false){
  Serial.println("yagmur var");
  digitalWrite(in1,HIGH);
  analogWrite(enA,50);
  delay(2000);
  analogWrite(enA,0);
  digitalWrite(in1,LOW);
  
  }
  if else(digitalRead(Buton)== 1 && okunan==true){
    Serial.println("yagmur yok");
    digitalWrite(in2,HIGH);
    analogWrite(enA,50);
    
    }
  if else(digitalRead(Buton)== 0){
    digitalWrite(in2,LOW);
    analogWrite(enA,0);
    
    }  
  
  
  
}
