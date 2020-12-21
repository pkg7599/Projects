string Incoming_value = "";

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0)
  {
    Incoming_value += Serial.read();
    Serial.print(Incoming_value);
    Serial.print("\n");
    //Appliance 1
    if(Incoming_value == "11")
      digitalWrite(13, HIGH);
    else if(Incoming_value == "10")
      digitalWrite(13, LOW);
    //Appliance 2
    else if(Incoming_value == "21")
      digitalWrite(12, HIGH);
    else if(Incoming_value == "20")
      digitalWrite(12, LOW);
    //Appliance 3
    else if(Incoming_value == "31")
      digitalWrite(8, HIGH);
    else if(Incoming_value == "30")
      digitalWrite(8, LOW);
  }
}
