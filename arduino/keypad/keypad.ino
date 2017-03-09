#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int PIN_DATA_0 = 50;
int PIN_DATA_1 = 51;
int PIN_DATA_2 = 52;
int PIN_DATA_3 = 53;
 
int PIN_RESET = 30;
 
int PIN_ADDR_0 = 31;
int PIN_ADDR_1 = 33;
int PIN_ADDR_2 = 35;
int PIN_ADDR_3 = 37;
int PIN_ADDR_4 = 39;
int PIN_ADDR_5 = 41;
int PIN_ADDR_6 = 43;
int PIN_ADDR_7 = 45;
int PIN_ADDR_8 = 47;
int PIN_ADDR_9 = 49;

char keyPressed = -1;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_DATA_0, OUTPUT);
  pinMode(PIN_DATA_1, OUTPUT);
  pinMode(PIN_DATA_2, OUTPUT);
  pinMode(PIN_DATA_3, OUTPUT);

  pinMode(PIN_RESET, OUTPUT);

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
}

void loop() {
  char key = keypad.getKey();
  int value;

  if (key == NO_KEY) {
    return;
  }

  Serial.println();

  Serial.print("Key pressed: ");
  Serial.println(key);

  value = key - '0';

  if (0 <= value && value <= 9) {
    keyPressed = key;
    
    return;
  }

  if (keyPressed != -1 && (key == '*' || key == '#')) {
    digitalWrite(PIN_RESET, HIGH);
    delay(25);
    digitalWrite(PIN_RESET, LOW);

    if (key == '*') {
      setupAddress(888);
    } else {
      setupAddress(890);
    }

    Serial.print("Sending data: ");
    Serial.print(keyPressed);
    Serial.print(" (");
    Serial.print(((keyPressed >> 3) & B1) ? '1' : '0');
    Serial.print(((keyPressed >> 2) & B1) ? '1' : '0');
    Serial.print(((keyPressed >> 1) & B1) ? '1' : '0');
    Serial.print(((keyPressed >> 0) & B1) ? '1' : '0');
    Serial.println(")");

    digitalWrite(PIN_DATA_0, HIGH && ((keyPressed >> 3) & B1));
    digitalWrite(PIN_DATA_1, HIGH && ((keyPressed >> 2) & B1));
    digitalWrite(PIN_DATA_2, HIGH && ((keyPressed >> 1) & B1));
    digitalWrite(PIN_DATA_3, HIGH && ((keyPressed >> 0) & B1));
  }
}

void setupAddress(int address) {
  Serial.print("Address: ");
  Serial.print(((address >> 9) & B1) ? '1' : '0');
  Serial.print(((address >> 8) & B1) ? '1' : '0');
  Serial.print(((address >> 7) & B1) ? '1' : '0');
  Serial.print(((address >> 6) & B1) ? '1' : '0');
  Serial.print(((address >> 5) & B1) ? '1' : '0');
  Serial.print(((address >> 4) & B1) ? '1' : '0');
  Serial.print(((address >> 3) & B1) ? '1' : '0');
  Serial.print(((address >> 2) & B1) ? '1' : '0');
  Serial.print(((address >> 1) & B1) ? '1' : '0');
  Serial.print(((address >> 0) & B1) ? '1' : '0');
  Serial.println();

  digitalWrite(PIN_ADDR_9, HIGH && ((address >> 9) & B1));
  digitalWrite(PIN_ADDR_8, HIGH && ((address >> 8) & B1));
  digitalWrite(PIN_ADDR_7, HIGH && ((address >> 7) & B1));
  digitalWrite(PIN_ADDR_6, HIGH && ((address >> 6) & B1));
  digitalWrite(PIN_ADDR_5, HIGH && ((address >> 5) & B1));
  digitalWrite(PIN_ADDR_4, HIGH && ((address >> 4) & B1));
  digitalWrite(PIN_ADDR_3, HIGH && ((address >> 3) & B1));
  digitalWrite(PIN_ADDR_2, HIGH && ((address >> 2) & B1));
  digitalWrite(PIN_ADDR_1, HIGH && ((address >> 1) & B1));
  digitalWrite(PIN_ADDR_0, HIGH && ((address >> 0) & B1));
}

