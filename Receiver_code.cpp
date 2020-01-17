#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial HC06(11,10);//declaration de l'utilisation du module (Tx, Rx)
const int ser_1 = 2;
const int ser_2 = 3;
const int ser_3 = 4;  
const int ser_4 = 5;
const int Posi = 90;
const int chg = 7;
int n;
int pos_1 =90;
int pos_2 =90;
int pos_3 =90;
int pos_4 =90;
char messageRecu;
Servo Ser_1, Ser_2, Ser_3, Ser_4;
int l = 8;//pas

void Avance(bool m);
void Recule(bool m);
void Tourne(bool m);
void Prend(bool m);

void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
  Ser_1.attach(ser_1);
  Ser_2.attach(ser_2);
  Ser_3.attach(ser_3);
  Ser_4.attach(ser_4);
  pinMode(chg, INPUT);
  Ser_1.write(Posi);
  Ser_2.write(Posi);
  Ser_3.write(Posi);
  Ser_4.write(Posi);
}

void loop() {
 
                   n = digitalRead(chg);
                   Serial.println(n);
                   while(HC06.available()){
                    delay(5);
                    messageRecu= HC06.read();
                    Serial.println(messageRecu);    
                                          }
                      if(messageRecu=='A'){
                         Avance(1);}          
                         else{ if(messageRecu=='B'){
                                 if (n){
                                 Avance(0);}
                                 else Tourne(1);
                                 }
                                 else{ if(messageRecu=='C'){
                                         Recule(1);}
                                         else{ if(messageRecu=='D'){
                                                 if (n){
                                                 Recule(0);}
                                                 else Tourne(0); 
                                                 }
                                                 //else{ if(messageRecu=='E'){
                                                        // Tourne(1);}
                                                         //else{ if(messageRecu=='F'){
                                                                  //Tourne(0);}                        
                                                                  else{ if(messageRecu=='G'){
                                                                           Prend(0);}
                                                                           else{ if(messageRecu=='H'){
                                                                                    Prend(1);}
                                                                                }
                                                                       }
                                                              //}
                                                       //}
                                               }
                                       }
                                }
              Ser_1.write(pos_1);
              Ser_2.write(pos_2);
              Ser_3.write(pos_3);
              Ser_4.write(pos_4);
              messageRecu = 't';
              delay(50);

}


void Avance(bool m){
  if (m) {
    if (pos_1 < 150) {
        pos_1 +=l;
    }
   
 }
 else {
    if (pos_2 < 150) {
        pos_2 +=l;
    }
  } 
 }

void Recule(bool m){
  if (m) {
    if (pos_1 > 10) {
        pos_1 -=l;
    }
 }
 else {
    if (pos_2 > 80) {
        pos_2 -=l;
    }
  } 
 }
 
void Tourne(bool m){
  if (m) {
    if (pos_3 < 100) {
        pos_3 +=l;
    }
 }
 else {
    if (pos_3 > 40) {
        pos_3 -=l;
    }
  } 
 }
 
void Prend(bool m){
  if (m) {
    if (pos_4 < 150) {
        pos_4 +=l;
    }
 }
 else {
    if (pos_4 > 40) {
        pos_4 -=l;
    }
  } 
 }

   
