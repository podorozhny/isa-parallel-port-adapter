int PIN_DATA_1 = 1;
int PIN_DATA_2 = 2;
int PIN_DATA_3 = 3;
int PIN_DATA_4 = 4;

int PIN_CONTROL_1 = 5;
int PIN_CONTROL_2 = 6;
int PIN_CONTROL_3 = 7;
int PIN_CONTROL_4 = 8;

int PIN_SEGMENT_1 = 9;
int PIN_SEGMENT_2 = 10;

int PIN_SEGMENT_A = 11;
int PIN_SEGMENT_B = 12;
int PIN_SEGMENT_C = 13;
int PIN_SEGMENT_D = 14;
int PIN_SEGMENT_E = 15;
int PIN_SEGMENT_F = 16;
int PIN_SEGMENT_G = 17;

void setup() {
    pinMode(PIN_DATA_1, INPUT);
    pinMode(PIN_DATA_2, INPUT);
    pinMode(PIN_DATA_3, INPUT);
    pinMode(PIN_DATA_4, INPUT);

    pinMode(PIN_CONTROL_1, INPUT);
    pinMode(PIN_CONTROL_2, INPUT);
    pinMode(PIN_CONTROL_3, INPUT);
    pinMode(PIN_CONTROL_4, INPUT);

    pinMode(PIN_SEGMENT_1, OUTPUT);
    pinMode(PIN_SEGMENT_2, OUTPUT);

    pinMode(PIN_SEGMENT_A, OUTPUT);
    pinMode(PIN_SEGMENT_B, OUTPUT);
    pinMode(PIN_SEGMENT_C, OUTPUT);
    pinMode(PIN_SEGMENT_D, OUTPUT);
    pinMode(PIN_SEGMENT_E, OUTPUT);
    pinMode(PIN_SEGMENT_F, OUTPUT);
    pinMode(PIN_SEGMENT_G, OUTPUT);
}

void loop() {
    int data1 = digitalRead(PIN_DATA_1);
    int data2 = digitalRead(PIN_DATA_2);
    int data3 = digitalRead(PIN_DATA_3);
    int data4 = digitalRead(PIN_DATA_4);

    int control1 = digitalRead(PIN_CONTROL_1);
    int control2 = digitalRead(PIN_CONTROL_2);
    int control3 = digitalRead(PIN_CONTROL_3);
    int control4 = digitalRead(PIN_CONTROL_4);

    if (data1 && data2 && data3 && data4) {
        int binary[] = { data1, data2, data3, data4 }; 
        printSymbol(PIN_SEGMENT_1, binaryToDecimal(binary));
    }

    if (control1 && control2 && control3 && control4) {
        int binary[] = { control1, control2, control3, control4 }; 
        printSymbol(PIN_SEGMENT_2, binaryToDecimal(binary));
    }

    delay(1000);
}

int binaryToDecimal(int binaryArray[]) {
    int decimal = 0;
    int i;
    int size;

    for(i = 4, size = 4; i < size; i++) {
        decimal += binaryArray[i] * (2 ^ i);
    }

    return decimal;
}

void printSymbol(int segmentPin, byte symbol) {
    digitalWrite(PIN_SEGMENT_1, HIGH);
    digitalWrite(PIN_SEGMENT_2, HIGH);

    digitalWrite(segmentPin, LOW);

    switch(symbol) {
        case 0:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, HIGH);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, LOW);
            break;

        case 1:
            digitalWrite(PIN_SEGMENT_A, LOW);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, LOW);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, LOW);
            digitalWrite(PIN_SEGMENT_G, LOW);
            break;

        case 2:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, LOW);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, HIGH);
            digitalWrite(PIN_SEGMENT_F, LOW);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 3:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, LOW);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 4:
            digitalWrite(PIN_SEGMENT_A, LOW);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, LOW);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 5:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, LOW);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 6:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, LOW);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, HIGH);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 7:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, LOW);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, LOW);
            digitalWrite(PIN_SEGMENT_G, LOW);
            break;

        case 8:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, HIGH);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 9:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 10:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 11:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 12:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;

        case 13:
            digitalWrite(PIN_SEGMENT_A, HIGH);
            digitalWrite(PIN_SEGMENT_B, HIGH);
            digitalWrite(PIN_SEGMENT_C, HIGH);
            digitalWrite(PIN_SEGMENT_D, HIGH);
            digitalWrite(PIN_SEGMENT_E, LOW);
            digitalWrite(PIN_SEGMENT_F, HIGH);
            digitalWrite(PIN_SEGMENT_G, HIGH);
            break;
    }
}
