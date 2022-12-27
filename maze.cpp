// Hayden Feddock
#include <iostream>
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 4

#define FIELD_WIDTH 25
#define FIELD_HEIGHT 25

using namespace std;


// Create game field and store important coordinates
int start[2] = {8, 0};
int stop[2] = {0, 9};
int field[25][25] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {3, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0}, {0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0}, {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0}, {0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
char screen [SCREEN_WIDTH * SCREEN_HEIGHT];


// Function to return game screen
void getScreen (int* coordinate) {
  
  int i = 0;

  for (int y = (coordinate[1] - SCREEN_HEIGHT + 2); y <= (coordinate[1] + 1) ; y++) {

    for (int x = (coordinate[0] - SCREEN_WIDTH/2) ; x < (coordinate[0] + SCREEN_WIDTH/2) ; x++) {
      
      char c = ' ';

      if (x < 0 or x >= FIELD_WIDTH or y < 0 or y >= FIELD_HEIGHT) {
        c = ' ';
      } else if (field[x][y] == 0) {
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

int main() {

  while (1) {

    // Take input to determine direction
    string direction;
    cin >> direction;
    //direction = "down";

    // Take direction and modify coordinates
    if (direction == "right") coordinate[0]++;
    if (direction == "left") coordinate[0]--;
    if (direction == "up") coordinate[1]--;
    if (direction == "down") coordinate[1]++;

    // Bound coordinates within field
    if (coordinate[0] < 0) coordinate[0] = 0;
    if (coordinate[0] >= FIELD_WIDTH) coordinate[0] = FIELD_WIDTH - 1;
    if (coordinate[1] < 0) coordinate[1] = 0;
    if (coordinate[1] >= FIELD_HEIGHT) coordinate[1] = FIELD_HEIGHT - 1;

    if (field[coordinate[0]][coordinate[1]] == 0) {
      coordinate[0] = lastCoordinate[0]; 
      coordinate[1] = lastCoordinate[1];
    }

    if (coordinate[0] != lastCoordinate[0] || coordinate[1] != lastCoordinate[1]) {

      getScreen(coordinate);

      for (int y = 0 ; y < SCREEN_HEIGHT ; y++) {
        for (int x = 0 ; x < SCREEN_WIDTH ; x ++) {
          cout << screen[x + (y * SCREEN_WIDTH)];
        }
        cout << endl;
      }
      cout << endl;

    }

    lastCoordinate[0] = coordinate[0];
    lastCoordinate[1] = coordinate[1];

  }

  return 0;

}