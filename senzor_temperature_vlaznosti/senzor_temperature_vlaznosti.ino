#include <dht.h>

const int senzor_temperature_pin = 7;
const int dioda_upozorenje_pin = 2;

const int MAX_TEMPERATURA_UPOZORENJE = 30;
const int MAX_VLAZNOST_UPOZORENJE = 80;

float humidity;  //Stores humidity value
float temperature; //Stores temperature value

dht DHT;

void setup()
{
    pinMode(dioda_upozorenje_pin, OUTPUT);
    Serial.begin(9600);
}

void ispisiTemperaturu(float temperatura, float vlaznost)
{
    //Print temp and humidity values to serial monitor
    Serial.print("Vlaznost: ");
    Serial.print(vlaznost);
    Serial.print("%, Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" Celsius");
}

void loop()
{
    //Read data and store it to variables hum and temp
    int status_senzora = DHT.read22(senzor_temperature_pin);

    humidity = DHT.humidity;
    temperature = DHT.temperature;

    if (temperature > MAX_TEMPERATURA_UPOZORENJE) {
      digitalWrite(dioda_upozorenje_pin, HIGH);
    } else {
      digitalWrite(dioda_upozorenje_pin, LOW);
    }

    ispisiTemperaturu(temperature, humidity);

    delay(1000); //Delay 2 sec.
}
