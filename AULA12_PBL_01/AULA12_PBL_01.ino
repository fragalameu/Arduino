//Programa : Arduino Ethernet Shield W5100 e HC-SR04
 
#include <Ultrasonic.h>
#include <SPI.h>
#include <Ethernet.h>
 
//Define os parametros para o sensor ultrasonico HC-SR04
#define PINO_TRIGGER  6 //Porta ligada ao pino Trigger do sensor
#define PINO_ECHO     7 //Porta ligada ao pino Echo do sensor

//Inicializa o sensor ultrasonico
Ultrasonic ultrasonic(PINO_TRIGGER, PINO_ECHO);
 
//Definicoes de IP, mascara de rede e gateway
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192,168,0,190);            //Define o endereco IP
IPAddress gateway(192,168,0,1);        //Define o gateway
IPAddress subnet(255, 255, 255, 0);    //Define a máscara de rede
 
//Inicializa o servidor web na porta 80
EthernetServer server(80);
 
void setup()
{
  //Inicializa a interface de rede
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}
 
void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();
  
  //Le e armazena as informacoes do sensor ultrasonico
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
 
  //Aguarda conexao do browser
  EthernetClient client = server.available();
  if (client) {
    // Um Request HTTP termina com uma linha em branco
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        
        //Se recebeu uma nova linha e a linha eh branca, a HTTP Request eh finalizada
        //Então pode enviar um reply 
        if (c == 'n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println("Refresh: 2"); //Recarrega a pagina a cada 2seg
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          
          //Configura o texto e imprime o titulo no browser
          client.print("<font color=#FF0000><b><u>");
          client.print("Envio de informacoes pela rede utilizando Arduino");
          client.print("</u></b></font>");
          client.println("<br />");
          client.println("<br />");
          
          //Mostra o estado da porta digital 3
          int porta_digital = digitalRead(3);
          client.print("Porta Digital 3 : ");
          client.print("<b>");
          client.print(porta_digital);
          client.println("</b>");
          client.print("  (0 = Desligada, 1 = Ligada)");
          client.println("<br />");
          
          //Mostra as informacoes lidas pelo sensor ultrasonico
          client.print("Sensor Ultrasonico : ");
          client.print("<b>");
          client.print(cmMsec);
          client.print(" cm");
          client.println("</b></html>");
          break;
        }
        
        if (c == 'n') {
          // Inicia uma nova linha
          currentLineIsBlank = true;
        } 
        else if (c != 'r') {
          // Recebeu um caracter na nova linha
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    
    // close the connection:
    client.stop();
  }
}
