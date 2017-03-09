int PIN_FIRST_0 = 4;
int PIN_FIRST_1 = 5;
int PIN_FIRST_2 = 6;
int PIN_FIRST_3 = 7;

int PIN_SECOND_0 = 8;
int PIN_SECOND_1 = 9;
int PIN_SECOND_2 = 10;
int PIN_SECOND_3 = 11;

int PIN_FIRST_A = 35;
int PIN_FIRST_B = 37;
int PIN_FIRST_C = 36;
int PIN_FIRST_D = 32;
int PIN_FIRST_E = 30;
int PIN_FIRST_F = 33;
int PIN_FIRST_G = 31;

int PIN_SECOND_A = 51;
int PIN_SECOND_B = 53;
int PIN_SECOND_C = 52;
int PIN_SECOND_D = 48;
int PIN_SECOND_E = 46;
int PIN_SECOND_F = 49;
int PIN_SECOND_G = 47;

int oldFirstData0 = -1, oldFirstData1 = -1, oldFirstData2 = -1, oldFirstData3 = -1,
    oldSecondData0 = -1, oldSecondData1 = -1, oldSecondData2 = -1, oldSecondData3 = -1;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_FIRST_0, INPUT);
  pinMode(PIN_FIRST_1, INPUT);
  pinMode(PIN_FIRST_2, INPUT);
  pinMode(PIN_FIRST_3, INPUT);

  pinMode(PIN_SECOND_0, INPUT);
  pinMode(PIN_SECOND_1, INPUT);
  pinMode(PIN_SECOND_2, INPUT);
  pinMode(PIN_SECOND_3, INPUT);

  digitalWrite(PIN_FIRST_0, LOW);
  digitalWrite(PIN_FIRST_1, LOW);
  digitalWrite(PIN_FIRST_2, LOW);
  digitalWrite(PIN_FIRST_3, LOW);

  digitalWrite(PIN_SECOND_0, LOW);
  digitalWrite(PIN_SECOND_1, LOW);
  digitalWrite(PIN_SECOND_2, LOW);
  digitalWrite(PIN_SECOND_3, LOW);

  pinMode(PIN_FIRST_A, OUTPUT);
  pinMode(PIN_FIRST_B, OUTPUT);
  pinMode(PIN_FIRST_C, OUTPUT);
  pinMode(PIN_FIRST_D, OUTPUT);
  pinMode(PIN_FIRST_E, OUTPUT);
  pinMode(PIN_FIRST_F, OUTPUT);
  pinMode(PIN_FIRST_G, OUTPUT);

  pinMode(PIN_SECOND_A, OUTPUT);
  pinMode(PIN_SECOND_B, OUTPUT);
  pinMode(PIN_SECOND_C, OUTPUT);
  pinMode(PIN_SECOND_D, OUTPUT);
  pinMode(PIN_SECOND_E, OUTPUT);
  pinMode(PIN_SECOND_F, OUTPUT);
  pinMode(PIN_SECOND_G, OUTPUT);
}

void loop() {
  int firstData0 = digitalRead(PIN_FIRST_0);
  int firstData1 = digitalRead(PIN_FIRST_1);
  int firstData2 = digitalRead(PIN_FIRST_2);
  int firstData3 = digitalRead(PIN_FIRST_3);

  int secondData0 = !digitalRead(PIN_SECOND_0);
  int secondData1 = !digitalRead(PIN_SECOND_1);
  int secondData2 = digitalRead(PIN_SECOND_2);
  int secondData3 = !digitalRead(PIN_SECOND_3);

  if (
    firstData0 != oldFirstData0 ||
    firstData1 != oldFirstData1 ||
    firstData2 != oldFirstData2 ||
    firstData3 != oldFirstData3
  ) {
    int firstBinary[] = { firstData0, firstData1, firstData2, firstData3 };
  
    int firstDecimal = binaryToDecimal(firstBinary);

    Serial.print("First decimal: ");
    Serial.println(firstDecimal);

    Serial.print("First data: ");
    Serial.print(firstData0 ? '1' : '0');
    Serial.print(firstData1 ? '1' : '0');
    Serial.print(firstData2 ? '1' : '0');
    Serial.print(firstData3 ? '1' : '0');
    Serial.println();

    printSymbol(
      firstDecimal,
      PIN_FIRST_A,
      PIN_FIRST_B,
      PIN_FIRST_C,
      PIN_FIRST_D,
      PIN_FIRST_E,
      PIN_FIRST_F,
      PIN_FIRST_G
    );

    oldFirstData0 = firstData0;
    oldFirstData1 = firstData1;
    oldFirstData2 = firstData2;
    oldFirstData3 = firstData3;

    Serial.println();
  }

  if (
    secondData0 != oldSecondData0 ||
    secondData1 != oldSecondData1 ||
    secondData2 != oldSecondData2 ||
    secondData3 != oldSecondData3
  ) {
    int secondBinary[] = { secondData0, secondData1, secondData2, secondData3 };
  
    int secondDecimal = binaryToDecimal(secondBinary);

    Serial.print("Second decimal: ");
    Serial.println(secondDecimal);

    Serial.print("Second data: ");
    Serial.print(secondData0 ? '1' : '0');
    Serial.print(secondData1 ? '1' : '0');
    Serial.print(secondData2 ? '1' : '0');
    Serial.print(secondData3 ? '1' : '0');
    Serial.println();

    printSymbol(
      secondDecimal,
      PIN_SECOND_A,
      PIN_SECOND_B,
      PIN_SECOND_C,
      PIN_SECOND_D,
      PIN_SECOND_E,
      PIN_SECOND_F,
      PIN_SECOND_G
    );

    oldSecondData0 = secondData0;
    oldSecondData1 = secondData1;
    oldSecondData2 = secondData2;
    oldSecondData3 = secondData3;

    Serial.println();
  }
}

int binaryToDecimal(int binaryArray[]) {
  int decimal = 0;
  int i;
  int arraySize = 4;

  for(int i = 0; i < arraySize; i++) {
    int result = binaryArray[i] * (int) round(pow(2, (arraySize - 1 - i)));

    decimal += result;
  }

  return decimal;
}

void printSymbol(
  byte symbol,
  int segmentA,
  int segmentB,
  int segmentC,
  int segmentD,
  int segmentE,
  int segmentF,
  int segmentG
) {
  switch(symbol) {
    case 0:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, LOW);
      break;

    case 1:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case 2:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;

    case 3:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, HIGH);
      break;

    case 4:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case 5:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case 6:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case 7:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;

    case 8:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, HIGH);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    case 9:
      digitalWrite(segmentA, HIGH);
      digitalWrite(segmentB, HIGH);
      digitalWrite(segmentC, HIGH);
      digitalWrite(segmentD, HIGH);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, HIGH);
      digitalWrite(segmentG, HIGH);
      break;

    default:
      digitalWrite(segmentA, LOW);
      digitalWrite(segmentB, LOW);
      digitalWrite(segmentC, LOW);
      digitalWrite(segmentD, LOW);
      digitalWrite(segmentE, LOW);
      digitalWrite(segmentF, LOW);
      digitalWrite(segmentG, LOW);
      break;
  }
}

