byte sensorInterrupt = 0;
byte sensorPin       = 2;
float calibrationFactor = 4.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;

void setup()
{
  pinMode(8, OUTPUT); //Green
  pinMode(9, OUTPUT); //Blue
  pinMode(10, OUTPUT); //Red
  
    pinMode(sensorPin, INPUT);
    digitalWrite(sensorPin, HIGH);

    pulseCount        = 0;
    flowRate          = 0.0;
    flowMilliLitres   = 0;
    totalMilliLitres  = 0;Time
    oldTime           = 0;
    attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
}

void loop()
{
  
     if((millis() - oldTime) > 1000)  
    { 
      detachInterrupt(sensorInterrupt);
      flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
      oldTime = millis();
      flowMilliLitres = (flowRate / 60) * 1000;
      totalMilliLitres += flowMilliLitres;
      unsigned int frac;
      frac = (flowRate - int(flowRate)) * 10;
      attachInterrupt(sensorInterrupt, pulseCounter, FALLING);
    }
    
    if(totalMilliLitres > 946.3525)
    {
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
    }
    
    if(totalMilliLitres > 946.3525)
    {
      digitalWrite(9, HIGH);
      digitalWrite(8, LOW);
      digitalWrite(10, LOW);
    }
    
    if(totalMilliLitres > 946.3525)
    {
      digitalWrite(10, HIGH);
      digitalWrite(9, LOW);
      digitalWrite(8, LOW);
    }

}
void pulseCounter()
{
  pulseCount++;
}
//Caleb Hanneman 2016
//Project Pipeline is licensed under a Creative Commons Attribution-NoDerivatives 4.0 International License.
