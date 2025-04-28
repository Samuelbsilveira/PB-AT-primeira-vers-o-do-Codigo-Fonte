#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Endereço I2C do LCD 16x2

void setup() {
    lcd.init();         // Inicializa o LCD
    lcd.backlight();    // Liga a luz de fundo
    lcd.setCursor(0, 0);
    lcd.print("Teste LCD OK!");
}

void loop() {
    static int contador = 0;

    lcd.setCursor(0, 1); // Segunda linha
    lcd.print("Contador: ");
    lcd.print(contador++);
    
    delay(1000); // Atualiza a cada 1 segundo
}

código sensor PIR

#define PIR_PIN 2  // Pino ao qual o sensor PIR está conectado

void setup() {
    Serial.begin(9600);    // Inicializa o monitor serial
    pinMode(PIR_PIN, INPUT); // Define o pino do PIR como entrada
}

void loop() {
    int estadoPIR = digitalRead(PIR_PIN); // Lê o estado do sensor PIR

    if (estadoPIR == HIGH) {
        Serial.println("Movimento Detectado!");
    } else {
        Serial.println("Sem Movimento");
    }

    delay(1000); // Aguarda 1 segundo antes da próxima leitura
}


Código MicroSD card

#include <SPI.h>
#include <SD.h>

#define CS_PIN 10  // Pino Chip Select do SD Card

void setup() {
    Serial.begin(9600);
    while (!Serial);  // Aguarda o monitor serial abrir

    Serial.print("Inicializando o SD Card...");

    if (!SD.begin(CS_PIN)) {
        Serial.println("Falha na inicialização!");
        return;
    }
    
    Serial.println("SD Card pronto!");

    // Criar e abrir um arquivo
    File arquivo = SD.open("test.txt", FILE_WRITE);

    if (arquivo) {
        arquivo.println("Teste de gravação no SD Card");
        arquivo.close();
        Serial.println("Escrita no SD Card concluída.");
    } else {
        Serial.println("Erro ao abrir o arquivo para escrita.");
    }

    // Ler o arquivo
    arquivo = SD.open("test.txt");

    if (arquivo) {
        Serial.println("Conteúdo do arquivo:");
        while (arquivo.available()) {
            Serial.write(arquivo.read());
        }
        arquivo.close();
    } else {
        Serial.println("Erro ao abrir o arquivo para leitura.");
    }
}

void loop() {
    // Nada a fazer no loop
}
