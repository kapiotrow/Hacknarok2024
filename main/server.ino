#include <SPI.h>
#include <WiFi.h>
#include <HTTPClient.h>


const char avalanche_message[] = "avalanche";


char* wifi_send_read(const char *send_data, int length, WiFiClient &client)
{
  static char read_data[128] = "";
  Serial.println("sending data to server");

  if (client.connected()) {
    int written = client.print(send_data);
  }

  // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      // Server doesnt send response
      Serial.println(">>> Client Timeout !");
      return nullptr;
    }
  }

  // Serial.println("receiving from remote server");
  int bytes_to_read = client.available(); 

  if (bytes_to_read > 128 - 1)
    return nullptr;

  int i = 0;
  for (; i < bytes_to_read + 1; ++i) {
    read_data[i] = static_cast<char>(client.read());  
    // Serial.println(wifi_read_data[i]);    
  }
  // read_data[i+1] = '\0';
  // Serial.println(read_data);
  
  return read_data;
}


void wifi_send(String send_data, WiFiClient &client)
{
  static char read_data[128] = "";
  Serial.println("sending data to server");

  if (client.connected()) {
    int written = client.print(send_data);
  } 

    // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      // Server doesnt send response
      Serial.println(">>> Client Timeout !");
      return ;
    }
  }

  // Serial.println("receiving from remote server");
  int bytes_to_read = client.available(); 

  if (bytes_to_read > 128 - 1)
    return ;

  int i = 0;
  for (; i < bytes_to_read + 1; ++i) {
    read_data[i] = static_cast<char>(client.read());  
    // Serial.println(wifi_read_data[i]);    
  }
  // read_data[i+1] = '\0';
  Serial.println(read_data);
}

void send_avalanche_msg(WiFiClient &client)
{
  char *read = wifi_send_read(avalanche_message, sizeof(avalanche_message), client);
  if (read == nullptr)
  {
    Serial.println("No data received");
  }
} 

