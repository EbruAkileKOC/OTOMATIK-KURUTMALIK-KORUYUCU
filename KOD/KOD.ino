int sensor=8;
void setup() {
  pinMode (sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
 bool okunan = digitalRead(sensor);
 if(okunan==false){
  Serial.println("yagmur var");
  
  }
  else{
    Serial.println("yagmur yok");
    }
  delay(200);
  
  
}
