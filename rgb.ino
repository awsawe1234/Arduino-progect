esphome:
  name: esp8266+
  platform: ESP8266
  board: nodemcuv2

wifi:
  ssid: "название_вашей_сети"
  password: "ваш_пароль"

# Настройки OTA (Over-The-Air) для беспроводной загрузки
ota:
  password: "пароль_для_OTA_обновлений"

# Объявляем 4 пина для управления реле
output:
  - platform: gpio
    pin: D1
    id: relay_1
  - platform: gpio
    pin: D2
    id: relay_2
  - platform: gpio
    pin: D3
    id: relay_3
  - platform: gpio
    pin: D4
    id: relay_4

# Создаем веб-интерфейс для управления реле
web_server:
  port: 80

# Добавляем графический интерфейс для управления
api:
  password: "пароль_API"

# Создаем интерфейс для обновлений прошивки через HTTP
ota:
  password: "пароль_OTA"
