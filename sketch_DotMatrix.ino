// sketch_DotMatrix.ino by J-H Ahn 2023
#include "LedControl.h" // 도트매트릭스 제어용 라이브러리
LedControl lc = LedControl(8, 10, 9, 1); // (DIN,CLK,CS,number)
byte heart[] = {        // 하트 모양의 배열
  B01100110,
  B10011001,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000,
  B00000000,
  B00000000,
  B00000000
};
int maxRowCount = sizeof(heart);
int offset = 0;

void setup() {
  // put your setup code here, to run once:
  lc.shutdown(0, false);    // 0=도트매트릭스 번호, false=wake up MAX7219
  lc.setIntensity(0, 1);    // 0=도트매트릭스 번호, 1=LED 밝기
  lc.clearDisplay(0);       // 0=도트매트릭스 번호 (LED 모두 지우기)
}

void loop() {
  // put your main code here, to run repeatedly:
//  lc.setLed(0, 0, 1, 1);  // row=0번줄, col=1번칸 LED 켜기
//  lc.setRow(0, 1, 0B11111111);// row=1번줄 모두 켜기
//  lc.setColumn(0, 1, 0B11111111);// col=1칸 모두 켜기
  showLED(0, heart, offset);    // dev=0, 하트모양 보이기
  delay(1000);                  // 1초 기다리기
//  lc.clearDisplay(nDevice);   // 모두 지우기
//  delay(1000);                // 1초 기다리기
  offset = (offset + 1) % maxRowCount;  // 한 줄 올리기
}

// lc.setLed(nDevice, row, col, isTurnOn);
// lc.setRow(nDevice, row, rowValue);
// lc.setColumn(nDevice, col, colValue);
void showLED(int nDevice, byte rowValue[], int offset)
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(nDevice, i, rowValue[(i+offset)%maxRowCount]);
  }
}
