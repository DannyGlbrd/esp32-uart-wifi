# ESP32 UART to WiFi Bridge

## 📌 Описание
Приложение для ESP32, которое:
- принимает данные через UART
- отправляет их на сервер по Wi-Fi в формате JSON

## ⚙️ Используемые компоненты
- ESP32 Dev Board
- UART (Serial2)
- Wi-Fi (HTTP)

## 🚀 Сборка и запуск

1. Установить PlatformIO
2. Клонировать репозиторий:
   git clone https://github.com/DannyGlbrd/esp32-uart-wifi

3. Открыть проект в VS Code
4. Задать Wi-Fi данные в main.cpp
5. Загрузить прошивку:
   PlatformIO: Upload

## 📡 Формат данных

Отправляется JSON:

{
  "data": "example"
}
