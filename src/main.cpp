#include <WiFi.h>
#include <HTTPClient.h>

// WiFi настройки
const char* ssid = "Wifiname";
const char* password = "Wifipassword";

// Сервер
const char* serverUrl = "http://webhook.site/420828ef-e88b-402a-bb37-6d41ef35e24f";

// Буфер UART
void sendData(String data);
String receivedData = "";

void setup() {
    Serial.begin(115200);      // Debug
    Serial2.begin(9600);       // UART2 (RX2=16, TX2=17)

    WiFi.begin(ssid, password);

    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nConnected!");
}

void loop() {
    // Чтение данных из UART
    while (Serial2.available()) {
        char c = Serial2.read();
        if (c == '\n') {
            sendData(receivedData);
            receivedData = "";
        } else {
            receivedData += c;
        }
    }
}

void sendData(String data) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;

        http.begin(serverUrl);
        http.addHeader("Content-Type", "application/json");

        String json = "{\"data\":\"" + data + "\"}";

        int httpResponseCode = http.POST(json);

        Serial.print("Response: ");
        Serial.println(httpResponseCode);

        http.end();
    } else {
        Serial.println("WiFi not connected");
    }
}