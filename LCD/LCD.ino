// Hayden Feddock
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int VRx = A0;
int VRy = A1;

int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

char field [4][16] = { {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
                       {'2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2', '2'},
                       {'3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3', '3'},
                       {'4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4', '4'} };
int currentRow = 0;

char row0[16];
char row1[16];

void setup() {
  Serial.begin(9600);
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  
  lcd.init();
  lcd.backlight();
}

void loop() {

  // Read the data from the joystick
  xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  mapX = map(xPosition, 0, 900, -450, 450);
  mapY = map(yPosition, 0, 900, -450, 450);
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.println(mapY);

  // Adjust the field based on the joystick
  if (mapY > 250) currentRow++;
  if (mapY < -250) currentRow--;

  // Restrict the index to the boundaries of the field
  if (currentRow < 0) currentRow = 0;
  if (currentRow > 2) currentRow = 2;

  Serial.print("Current Row: ");
  Serial.println(currentRow);

  // setCursor(col, row)
  lcd.clear();
  for (int i=0;i<16;i++) {
    lcd.print(field[currentRow+1][i]);
  }
  lcd.setCursor(0, 1);
  for (int i=0;i<16;i++) {
    lcd.print(field[currentRow][i]);
    Serial.print(field[currentRow][i]);
  }
  
  delay(200);
}
