// Hayden Feddock
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 4
#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25


// LiquidCrystal_I2C for LCD I2C display
#include <LiquidCrystal_I2C.h>


// Create and initialize the LCD I2C object
LiquidCrystal_I2C lcd(0x27, SCREEN_WIDTH, SCREEN_HEIGHT);

int VRx = A0;
int VRy = A1;

int xPosition = 0;
int yPosition = 0;
int mapX = 0;
int mapY = 0;

// Create game field and store important coordinates
int start[2] = {8, 0};
int stop[2] = {0, 9};
const byte field[25][25] PROGMEM = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {3, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
char screen [SCREEN_WIDTH * SCREEN_HEIGHT];

byte wall[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte player[8] = {
  0b00100,
  0b01010,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010,
  0b10001
};

// Function to return game screen
void getScreen (int* coordinate) {
  
  int i = 0;

  for (int y = (coordinate[1] - SCREEN_HEIGHT + 2); y <= (coordinate[1] + 1) ; y++) {

    for (int x = (coordinate[0] - SCREEN_WIDTH/2) ; x < (coordinate[0] + SCREEN_WIDTH/2) ; x++) {
      
      char c = ' ';

      if (x < 0 or x >= FIELD_WIDTH or y < 0 or y >= FIELD_HEIGHT) {
        c = ' ';
      } else if (pgm_read_byte_near(&field[x][y]) == 0) {
        c = 'X';
      } else {
        c = ' ';
      }
      
      screen[i] = c;
      i++;
    }
  }
}


int* coordinate = start;
int lastCoordinate[2];

void setup() {
  Serial.begin(9600);

  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, wall);
  lcd.createChar(1, player);
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

  // Change coordinate based on joystick position
  if (mapX < -200) coordinate[0]++;
  else if (mapX > 200) coordinate[0]--;
  else if (mapY < -200) coordinate[1]++;
  else if (mapY > 200) coordinate[1]--;

  // Bound coordinates within field
  if (coordinate[0] < 0) coordinate[0] = 0;
  if (coordinate[0] >= FIELD_WIDTH) coordinate[0] = FIELD_WIDTH - 1;
  if (coordinate[1] < 0) coordinate[1] = 0;
  if (coordinate[1] >= FIELD_HEIGHT) coordinate[1] = FIELD_HEIGHT - 1;

  if (pgm_read_byte_near(&field[coordinate[0]][coordinate[1]]) == 0) {
    coordinate[0] = lastCoordinate[0];
    coordinate[1] = lastCoordinate[1];
  }

  if (coordinate[0] != lastCoordinate[0] || coordinate[1] != lastCoordinate[1]) {

    getScreen(coordinate);
  
    Serial.print("Field: ");
  
    lcd.clear();
    for (int y = 0 ; y < SCREEN_HEIGHT ; y++) {
      lcd.setCursor(0, y);
      for (int x = 0 ; x < SCREEN_WIDTH ; x ++) {
        char c = screen[x + (y * SCREEN_WIDTH)];
        lcd.setCursor(x, y);
        if (x == SCREEN_WIDTH/2 && y == SCREEN_HEIGHT/2) {
          lcd.write(byte(1));
        } else if (c == 'X') {
          lcd.write(byte(0));
        } else {
          lcd.print(' ');
        }
        Serial.print(screen[x + (y * SCREEN_WIDTH)]);
      }
    }
    Serial.print('\n');

    delay(200);
  }

  lastCoordinate[0] = coordinate[0];
  lastCoordinate[1] = coordinate[1];

}
