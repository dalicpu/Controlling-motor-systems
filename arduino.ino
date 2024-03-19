#define ledr 2
#define ledg 3
#define relaya 4
#define relayb 5
#define relayc 6
#define buttona 7
#define buttonb 8
#define buttonc 9
#define sensora A0
#define sensorb A1
#define sensorc A2
int statea,stateb,statec;
int tempa,tempb,tempc;

void setup() {
  
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(relaya, OUTPUT);
  pinMode(relayb, OUTPUT);
  pinMode(relayc, OUTPUT);
  pinMode(buttona, INPUT_PULLUP);
  pinMode(buttonb, INPUT_PULLUP);
  pinMode(buttonc, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //config signal variable:
  tempa=analogRead(sensora);
  tempb=analogRead(sensorb);
  tempc=analogRead(sensorc);
  statea=digitalRead(buttona);
  stateb=digitalRead(buttonb);
  statec=digitalRead(buttonc);

  
  //relay1:
  if (statea==0){
    if(tempa>115){
      digitalWrite(relaya, HIGH);
      digitalWrite(ledg, HIGH);
      digitalWrite(ledr, LOW); 
    }
    else{
      digitalWrite(relaya, LOW);
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, LOW);
    }
  }
  else{
    digitalWrite(relaya, LOW);
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, LOW);
  }

  //relay2:
  if (stateb==0){
    if(tempb>115){
      digitalWrite(relayb, HIGH);
      digitalWrite(ledg, HIGH);
      digitalWrite(ledr, LOW); 
    }
    else{
      digitalWrite(relayb, LOW);
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, LOW);
    }
  }
  else{
    digitalWrite(relayb, LOW);
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, LOW);
  }
  //relay3:
    if (statec==0){
    if(tempc>115){
      digitalWrite(relayc, HIGH);
      digitalWrite(ledg, HIGH);
      digitalWrite(ledr, LOW); 
    }
    else{
      digitalWrite(relayc, LOW);
      digitalWrite(ledr, HIGH);
      digitalWrite(ledg, LOW);
    }
  }
  else{
    digitalWrite(relayc, LOW);
    digitalWrite(ledr, LOW);
    digitalWrite(ledg, LOW);
  }
  //affichage:
  Serial.print("temperatureA: ");
  Serial.print(tempa);
  Serial.print("  etat de boutonA: ");
  Serial.print(statea);
  Serial.print("  temperatureB: ");
  Serial.print( tempb);
  Serial.print("  etat de boutonB: ");
  Serial.print(stateb);
  Serial.print("  temperatureC: ");
  Serial.print( tempc);
  Serial.print("  etat de boutonC: ");
  Serial.println(statec);
  delay(1200);

  
}
  
 