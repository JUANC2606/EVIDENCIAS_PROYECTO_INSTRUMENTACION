#include <WiFi.h>//Incluir la libreria WiFi(Es necesario descargarla desde el repositorio)
#include <WiFiClient.h>//Incluir la libreria WiFi(Es necesario descargarla desde el repositorio)
#include <WiFiServer.h>//Incluir la libreria WiFi(Es necesario descargarla desde el repositorio)
#include <WiFiUdp.h>//Incluir la libreria WiFi(Es necesario descargarla desde el repositorio)
#include"ThingSpeak.h" //Incluir la libreria ThingSpeak(Es necesario descargarla)
#include "WiFi.h"
float T= 3;
const char* ssid = "ssid";// se deifine el ssid de la red a la que queremos conectarnos, es nesesario cambiar lo que esta entre comillas para los datos propios de la red

const char* password = "pasword";// se deifine el pasword de la red a la que queremos conectarnos, es nesesario cambiar lo que esta entre comillas para los datos propios de la red

unsigned long channelID = "2175200";//se asigna el cahnnelID del canal de ThingSpeak 
const char* writeAPIKey = "XY67RKWVSULK266R";//se asigna el write API Key del canal de ThingSpeak necesario para poder subir datos  

WiFiClient Client; // se le asigna al WiFi un objeto llamdo cliente 

void setup() {
WiFi.begin(ssid,password);//nos conectamos al WiFi esto solo se realiza una vez sele ingresa como parametros el ssid y la contraseña ya definidas anteriormente
while(WiFi.status()!= WL_CONNECTED){ //mientras este desconectada la tarjeta del WiFi es necesario esperar un segundo y reintentar la conexion
 delay(1000);                         // una vez este cionectado podra seguirse ejecutantdo el programa
}
ThingSpeak.begin(Client); // se inicializa el ThingSpeak y se le entra como argumento el objeto asigando para el WiFi

}

void loop() {
  ThingSpeak.setField (1,T);//se asignan los valores a cada campo del ThingSpeak como argumento recibe (campo de visualizacion de ThingSpeak,variable que se quiere trasmitir)
  ThingSpeak.writeFields(channelID,writeAPIKey);//se envian todos los datos almacenados localmente en cada campo
  delay(28000);// la maxima velocidad a la que podemos trasmitir datos es de 14 segundos entonces hay que hacer esperar al programa 28 segundos entra cada transmision de datos


}
