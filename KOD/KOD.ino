#define Buton 5  // pin tanımlamaları
int sensor=8;
int in1=7;
int in2=9;
int enA=6;

void setup() {
  pinMode(in1,OUTPUT);  // pinlerin giriş veya çıkış olma durumları tanımlamaları
  pinMode(in2,OUTPUT);
  pinMode (sensor, INPUT);
  pinMode(Buton,INPUT);
  Serial.begin(9600);  // seri portumuzu 9600 baud olarak ayarlıyoruz.

 digitalWrite(in1,LOW);  // sistem ilk çalıştığında motorun durum tanımlaması.
 digitalWrite(in2,LOW);
 digitalWrite(enA,HIGH);
}

void loop() {

 if(digitalRead(sensor)==false){  // Rain sensörden gelen bilgiyi karşılaştırma.
  Serial.println("yagmur var");  // yağmur varsa motor ileri yöde çalışır ve bir motora bağlanmış mil üzerine sarılı olan sıvı geçirmez perde yavaş hızla açılır.
  digitalWrite(in1,HIGH);
  analogWrite(enA,50);
  delay(2000);                 // 2 dakikada tamamen açılır ve motor durur.
  analogWrite(enA,0);
  digitalWrite(in1,LOW);
  
  }
  if else(digitalRead(Buton)== 1 ){  // Butona basılı tutulduğu sürece motor geri yönde çalışıyor.
    Serial.println("yagmur yok");
    digitalWrite(in1,LOW);  // motor ileri yönde çalışırken butona basılırsa diye alınmış bir önlem.
    analogWrite(in1,0);
    digitalWrite(in2,HIGH);
    analogWrite(enA,50);
    
    }
  if else(digitalRead(Buton)== 0){  // Butona basılmazsa motor duruyor.
    digitalWrite(in2,LOW);
    analogWrite(enA,0);
    
    }  
  
  
  
}
