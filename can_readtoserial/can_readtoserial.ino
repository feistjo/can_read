#include <can.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!can_setup()) {
    Serial.println("CAN init fail!");
    while(1);
  }
  Serial.println("CAN init success");
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  String toPrint = "";
  toPrint += "Brake temp FL: ";
  toPrint += can_read(2);
  toPrint += "\tFR: ";
  toPrint += can_read(3);
  toPrint += "\tRL: ";
  toPrint += can_read(4);
  toPrint += "\tRR: ";
  toPrint += can_read(5);
  toPrint += "\tBrake press front: ";
  toPrint += can_read(0);
  toPrint += "\tRear: ";
  toPrint += can_read(1);
  toPrint += "\tCoolant temp: ";
  toPrint += can_read(53);
  Serial.println(toPrint);
}
