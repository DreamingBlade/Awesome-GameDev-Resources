#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cell {
  int row = 0;
  int column = 0;
  bool alive = false;
  bool newState = false;
};

int main() {
  const int UNDERPOPULATED = 1;
  const int OVERPOPULATED = 4;
  const int REPRODUCTION = 3;

  int rows = 5;
  int columns = 5;
  int turns = 4;
  char startState;
  string junkCatch;

  // Collecting the game rules
  cin >> columns;
  cin >> rows;
  cin >> turns;

  // Creating the dyanmic array
  cell** grid = new cell*[rows];

  // Setting up the dynamic array
  for (int i = 0; i < rows; i++) {
    grid[i] = new cell[columns];
  }

  // Gets rid of the new line character that will affect input
  getline(cin, junkCatch);

  // Inputting the starting information into the array.
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      cin >> startState;
      grid[i][j].row = i;
      grid[i][j].column = j;
      if (startState == '#') {
        grid[i][j].alive = true;
      } else {
        grid[i][j].alive = false;
      }
    }
  }

  // Running through the turns
  for (int i = 0; i < turns; i++) {
    // Checking the eight neighbors of every cell.
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < columns; k++) {
        int neighbours = 0;
        int currentRow = j;
        int currentColumn = k;

        // Checking upper left
        currentRow--;
        if (currentRow < 0) {
          currentRow = rows - 1;
        }

        currentColumn--;
        if (currentColumn < 0) {
          currentColumn = columns - 1;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking upper
        currentColumn = k;

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking upper right
        currentColumn++;

        if (currentColumn >= columns) {
          currentColumn = 0;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking right
        currentRow = j;
        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking left
        currentColumn = k - 1;

        if (currentColumn < 0) {
          currentColumn = columns - 1;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }
        // Checking lower left
        currentRow++;

        if (currentRow >= rows) {
          currentRow = 0;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking lower
        currentColumn++;

        if (currentColumn >= columns) {
          currentColumn = 0;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Checking lower right
        currentColumn++;

        if (currentColumn >= columns) {
          currentColumn = 0;
        }

        if (grid[currentRow][currentColumn].alive) {
          neighbours++;
        }

        // Determining the new state
        if (neighbours <= UNDERPOPULATED) {
          grid[j][k].newState = false;
        } else if (neighbours == REPRODUCTION) {
          grid[j][k].newState = true;
        } else if (neighbours >= OVERPOPULATED) {
          grid[j][k].newState = false;
        } else if (neighbours > UNDERPOPULATED && neighbours < OVERPOPULATED) {
          grid[j][k].newState = grid[j][k].alive;
        }
      }
    }

    // Setting every cell to its new state
    for (int j = 0; j < rows; j++) {
      for (int k = 0; k < columns; k++) {
        grid[j][k].alive = grid[j][k].newState;
        grid[j][k].newState = false;
      }
    }
  }

  // Outputting what cells have living entities;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (grid[i][j].alive) {
        cout << '#';
      } else {
        cout << '.';
      }
    }
    cout << "\n";
  }

  // Cleaning up the dynamic allowcations.
  for (int i = 0; i < rows; i++) {
    delete[] grid[i];
  }
  delete[] grid;

  return 0;
}