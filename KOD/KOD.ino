#define Buton 5  // pin tanımlamaları
int sensor=8;
int in1=7;
int in2=9;
int enA=6;
int val=0;

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
val=map( analogRead(A0),0,1023,0,255);
 if(digitalRead(sensor)==false){  // Rain sensörden gelen bilgiyi karşılaştırma.
  val=map( analogRead(A0),0,1023,0,255); // Hız ayarını manuel yapabilmek için potansiyometreden bilgi alıyoruz.
  Serial.println("yagmur var");  // yağmur varsa motor ileri yöde çalışır ve bir motora bağlanmış mil üzerine sarılı olan sıvı geçirmez perde yavaş hızla açılır.
  digitalWrite(in1,HIGH);
  analogWrite(enA,val);
  delay(5000);                 // 5 saniyede tamamen açılır ve motor durur.
  analogWrite(enA,val);
  digitalWrite(in1,LOW);
  if(digitalRead(Buton)== 1 ){ // Butona basılınca  motor geri yönde çalışıyor.
    val=map( analogRead(A0),0,1023,0,255);
    Serial.println("buton basıldı");
    digitalWrite(in1,LOW);  // motor ileri yönde çalışırken butona basılırsa diye alınmış bir önlem.
    analogWrite(in1,0);
    digitalWrite(in2,HIGH);
    analogWrite(enA,val);
    delay(5000);          // 5 saniyede tamamen kapanır ve motor durur.
    analogWrite(enA,val);
    digitalWrite(in2,LOW);
  }
  
 while(digitalRead(sensor)==false);
  
  
  }
  else if(digitalRead(Buton)== 1 ){  // Butona basılınca  motor geri yönde çalışıyor.
    val=map( analogRead(A0),0,1023,0,255);
    Serial.println("buton basildi");
    digitalWrite(in1,LOW);  // motor ileri yönde çalışırken butona basılırsa diye alınmış bir önlem.
    analogWrite(in1,0);
    digitalWrite(in2,HIGH);
    analogWrite(enA,val);
    delay(50000);
    analogWrite(enA,val);
    digitalWrite(in2,LOW);
  }
  
  
}
