byte LED = 13;
byte sensorInterrupt = 0;
byte sensorPin       = 2;
float calibrationFactor = 4.5;
volatile byte pulseCount;  
float flowRate;
unsigned int flowMilliLitres;
unsigned long totalMilliLitres;
unsigned long oldTime;
unsigned long Gallons;
long conversionFactor = 0.000264172;
void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);

  pulseCount        = 0;
  flowRate          = 0.0;
  flowMilliLitres   = 0;
  totalMilliLitres  = 0;
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

  Gallons = totalMilliLitres * conversionFactor;

  if(Gallons > 1)
  {
    
   }
}
void pulseCounter()
{
  pulseCount++;
}
