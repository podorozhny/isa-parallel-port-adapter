#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

byte keys[ROWS][COLS] = {
    { 1,  2, 3,  10 },
    { 4,  5, 6,  11 },
    { 7,  8, 9,  12 },
    { 14, 0, 15, 13 }
};

byte rowPins[ROWS] = { 1, 2, 3, 4 };
byte colPins[COLS] = { 5, 6, 7, 8 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

byte keyPressed = 0;
 
int PIN_DATA_0 = 9;
int PIN_DATA_1 = 10;
int PIN_DATA_2 = 11;
int PIN_DATA_3 = 12;
 
int PIN_RESET = 13;
int PIN_IOR = 14;
int PIN_IOW = 15;
int PIN_AEN = 16;
 
int PIN_ADDR_0 = 17;
int PIN_ADDR_1 = 18;
int PIN_ADDR_2 = 19;
int PIN_ADDR_3 = 20;
int PIN_ADDR_4 = 21;
int PIN_ADDR_5 = 22;
int PIN_ADDR_6 = 23;
int PIN_ADDR_7 = 24;
int PIN_ADDR_8 = 25;
int PIN_ADDR_9 = 26;

void setup() {
    Serial.begin(9600);

    pinMode(PIN_DATA_0, OUTPUT);
    pinMode(PIN_DATA_1, OUTPUT);
    pinMode(PIN_DATA_2, OUTPUT);
    pinMode(PIN_DATA_3, OUTPUT);
 
    pinMode(PIN_RESET, OUTPUT);
    pinMode(PIN_IOR, OUTPUT);
    pinMode(PIN_IOW, OUTPUT);
    pinMode(PIN_AEN, OUTPUT);
 
    pinMode(PIN_ADDR_0, OUTPUT);
    pinMode(PIN_ADDR_1, OUTPUT);
    pinMode(PIN_ADDR_2, OUTPUT);
    pinMode(PIN_ADDR_3, OUTPUT);
    pinMode(PIN_ADDR_4, OUTPUT);
    pinMode(PIN_ADDR_5, OUTPUT);
    pinMode(PIN_ADDR_6, OUTPUT);
    pinMode(PIN_ADDR_7, OUTPUT);
    pinMode(PIN_ADDR_8, OUTPUT);
    pinMode(PIN_ADDR_9, OUTPUT);
 
    digitalWrite(PIN_IOR, HIGH);
    digitalWrite(PIN_IOW, LOW);
    digitalWrite(PIN_AEN, LOW);
}

void loop() {
    byte key = keypad.getKey();

    if (key != NO_KEY) {
        Serial.println(key);

        if (key == 14 || key == 15) {
            digitalWrite(PIN_RESET, HIGH);
            delay(10);
            digitalWrite(PIN_RESET, LOW);

            if (key == 14) {
                // data register
                digitalWrite(PIN_ADDR_0, HIGH);
                digitalWrite(PIN_ADDR_1, HIGH);
                digitalWrite(PIN_ADDR_2, LOW);
                digitalWrite(PIN_ADDR_3, HIGH);
                digitalWrite(PIN_ADDR_4, HIGH);
                digitalWrite(PIN_ADDR_5, HIGH);
                digitalWrite(PIN_ADDR_6, HIGH);
                digitalWrite(PIN_ADDR_7, LOW);
                digitalWrite(PIN_ADDR_8, LOW);
                digitalWrite(PIN_ADDR_9, LOW);
            } else {
                // control register
                digitalWrite(PIN_ADDR_0, HIGH);
                digitalWrite(PIN_ADDR_1, HIGH);
                digitalWrite(PIN_ADDR_2, LOW);
                digitalWrite(PIN_ADDR_3, HIGH);
                digitalWrite(PIN_ADDR_4, HIGH);
                digitalWrite(PIN_ADDR_5, HIGH);
                digitalWrite(PIN_ADDR_6, HIGH);
                digitalWrite(PIN_ADDR_7, LOW);
                digitalWrite(PIN_ADDR_8, HIGH);
                digitalWrite(PIN_ADDR_9, LOW);
            }

            digitalWrite(PIN_DATA_0, HIGH && (keyPressed & B1000));
            digitalWrite(PIN_DATA_1, HIGH && (keyPressed & B0100));
            digitalWrite(PIN_DATA_2, HIGH && (keyPressed & B0010));
            digitalWrite(PIN_DATA_3, HIGH && (keyPressed & B0001));
        } else {
            keyPressed = key;
        }
    }
}
