#include <SPI.h>

const int slaveSelectPin = 10; // Пин выбора активного устройства на шине SPI
const int chipSelectPin = 9;   // Пин выбора конкретного чипа на шине SPI

void setup() {
  Serial.begin(9600); // Инициализация последовательного порта
  SPI.begin();        // Инициализация шины SPI
  pinMode(slaveSelectPin, OUTPUT);
  digitalWrite(slaveSelectPin, HIGH); // Начальное состояние пина выбора активного устройства
}

void loop() {
  digitalWrite(slaveSelectPin, LOW); // Активируем устройство на шине SPI
  
  byte data = SPI.transfer(chipSelectPin, 0x00); // Чтение данных из выбранного чипа
  
  digitalWrite(slaveSelectPin, HIGH); // Выключаем устройство на шине SPI
  
  Serial.println(data); // Выводим данные в последовательный порт
  delay(1000);          // Задержка между чтениями
}
