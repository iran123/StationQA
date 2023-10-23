



#include <Adafruit_BMP085.h>
 Adafruit_BMP085 bmp; 
 
#include <dht.h>

// Initialize DHT sensor for normal 16mhz Arduino
#define pinoDHT11 2

dht sensorDHT11;

//Variables

int sensor_CO2 = A0 ;
int sensor_CO = A1 ;

const int ALT = 760;


void setup()
{
    Serial.begin(9600);
    bool success = bmp.begin();

 if (success) {
   // Serial.println("BMP180 iniciado com sucesso");
 }
    pinMode(sensor_CO2, INPUT);
    pinMode(sensor_CO, INPUT);
}



void loop()
{   
//Read Pressure
     String  Pressure_BMP = (String)bmp.readPressure();

      //Serial.println(bmp.readAltitude()); //IMPRIME NO MONITOR SERIAL A ALTITUDE APROXIMADA
    //Serial.println(" m (Metros)"); //IMPRIME O TEXTO NO MONITOR SERIAL
    
    //Read Temperature and Humidity from DHT11 Sensor
    sensorDHT11.read11(pinoDHT11);

  String Temp_DHT = (String)sensorDHT11.temperature;
  String Humid_DHT = (String)sensorDHT11.humidity;
 

  
    //Read data and store it to variables hum and temp
 sensorDHT11.read11(pinoDHT11);


      
    int SensorCO2= analogRead(sensor_CO2);  
    int SensorCO= analogRead(sensor_CO);  
       
      // Serial.print(CO2);
      // Serial.print(",");
      // Serial.print(CO);

      String CO2 = (String)SensorCO2;
      String CO =(String)SensorCO;

      int NData = 6;
      String str_Payload;

      //Criar uma String de Dados

      str_Payload += NData;
     str_Payload += " " + Temp_DHT;
     str_Payload += " " + Humid_DHT;
     str_Payload += " " + CO2;
     str_Payload += " " + CO;
     str_Payload += " " + Pressure_BMP;
     str_Payload += " ";

     byte Payload[str_Payload.length()];
  int LengthFrameAPI = 18 + sizeof(Payload);
  int LengthPayload = sizeof(Payload);
  
  Serial.print(str_Payload);
    
    
    delay(1000); //Delay 2 sec.
}

   
