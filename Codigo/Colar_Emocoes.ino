/* Colar de Emoções
* 
*/

#include <IRremote.h>
#define UM 3125149440             // Tecla 1
#define DOIS 3108437760           // Tecla 2
#define TRES 3091726080           // Tecla 3
#define QUATRO 3141861120         // Tecla 4
#define CINCO 3208707840          // Tecla 5
#define SEIS 3158572800           // Tecla 6
#define SETE 4161273600           // Tecla 7
#define OITO 3927310080           // Tecla 8
#define NOVE 4127850240           // Tecla 9

int IR_RECEIVE_PIN = 2; 
float armazenavalor;

byte humm[] = { B01010, B10101, B10001, B01010, B00100};
byte dois[] = { B00000, B00000, B11111, B00000, B00000};
byte tres[] = { B00100, B00100, B00100, B00100, B00100};
byte quat[] = { B00001, B00010, B00100, B01000, B10000};
byte cinc[] = { B10000, B01000, B00100, B00010, B00001};
byte seis[] = { B00100, B01010, B11111, B10001, B10001};
byte sete[] = { B11110, B10001, B11110, B10001, B11110};
byte oito[] = { B11111, B10000, B10000, B10000, B11111};
byte nove[] = { B11110, B10001, B10001, B10001, B11110};

const int columnPins[] = {9,10,11,12,13};
const int rowPins[] = {4,5,6,7,8};

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(rowPins[i], OUTPUT);
    pinMode(columnPins[i], OUTPUT);
    digitalWrite(columnPins[i], HIGH);
   }
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
  if (IrReceiver.decode()) {  
    Serial.print("Valor lido : ");  
    Serial.println(IrReceiver.decodedIRData.decodedRawData);  
    armazenavalor = (IrReceiver.decodedIRData.decodedRawData);  
    if (armazenavalor == UM) {
      show(humm, 1000);
      Serial.println("1");
    }
    if (armazenavalor == DOIS) {
      show(dois, 500);
      Serial.println("2");
    }
    if (armazenavalor == TRES) {
      show(tres, 500);
      Serial.println("3");
    }
    if (armazenavalor == QUATRO) {
      show(quat, 500);
      Serial.println("4");
    }
    if (armazenavalor == CINCO) {
      show(cinc, 500);
      Serial.println("5");
    }
    if (armazenavalor == SEIS) {
      show(seis, 500);
      Serial.println("6");
    }
    if (armazenavalor == SETE) {
      show(sete, 500);
      Serial.println("7");
    }
    if (armazenavalor == OITO) {
      show(oito, 500);
      Serial.println("8");
    }
    if (armazenavalor == NOVE) {
      show(nove, 500);
      Serial.println("9");
    }
    IrReceiver.resume();
  }
}

void show( byte * image, unsigned long duration)  {
  unsigned long start = millis();                     // 
  while (start + duration > millis())  {              // 
    for(int row = 0; row < 5; row++)  {               // 
      digitalWrite(rowPins[row], HIGH);               // 
      for(int column = 0; column < 5; column++)  {    // 
        boolean pixel = bitRead(image[row],column);   // 
        if(pixel == 1)  {                             // 
          digitalWrite(columnPins[column], LOW);      //  
        }
        delayMicroseconds(300);                       // 
        digitalWrite(columnPins[column], HIGH);       // 
      } 
      digitalWrite(rowPins[row], LOW);                // 
    }
  }
}
