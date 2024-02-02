//
// Author: Aradhya Dang
//

// #include "reversi.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function Definitions
void printInitialBoard(char board[][26], int n);
void boardConfig(char board[][26], int n);
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol);
bool checkingEachDirection(char board[][26], int n, int row, int col,
                           char colour);
void availableMoves(char board[][26], int n, char colour);
void validMove(char board[][26], int n);
void checkAndFlip(char board[][26], int n, int row, int col, char colour,
                  int deltaRow, int deltaCol);
void checkForFlip(char board[][26], int n, int row, int col, char colour);
void flip(char board[][26], int n, int row, int col, char colour);

// Global variables
char x, y, z;

// Main function
int main(void) {
  int n = 0;
  char colour = 'U';
  char board[26][26];
  printf("Enter the board dimension: ");
  scanf("%d", &n);
  printInitialBoard(board, n);
  boardConfig(board, n);
  printBoard(board, n);
  printf("Available moves for W:\n");
  availableMoves(board, n, 'W');
  printf("Available moves for B:\n");
  availableMoves(board, n, 'B');
  validMove(board, n);
  flip(board, n, y - 97, z - 97, x);
  return 0;
}

// This function is used to initialize the board with its initial values
void printInitialBoard(char board[][26], int n) {
  int i = 0;
  int j = 0;
  int c = n / 2;
  printf("  ");
  for (int k = 0; k < n; k++) {
    printf("%c", ('a' + k));
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("%c ", ('a' + i));
    for (j = 0; j < n; j++) {
      board[i][j] = 'U';
      board[c - 1][c - 1] = board[c][c] = 'W';
      board[c - 1][c] = board[c][c - 1] = 'B';
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// This function describes a board configuration that represents a game
// situation
void boardConfig(char board[][26], int n) {
  char colour, row1, col1;
  printf("Enter board configuration:\n");
  do {
    scanf(" %c %c %c", &colour, &row1, &col1);
    if (colour == 'B' || colour == 'W') {
      row1 = row1 - 'a';
      col1 = col1 - 'a';
      board[row1][col1] = colour;
    }
  } while ((colour != '!'));
}

// This function is separately created and used to print the game situation as
// described in the boardConfig function
void printBoard(char board[][26], int n) {
  int i = 0;
  int j = 0;
  int c = n / 2;
  printf("  ");
  for (int k = 0; k < n; k++) {
    printf("%c", ('a' + k));
  }
  printf("\n");
  for (i = 0; i < n; i++) {
    printf("%c ", ('a' + i));
    for (j = 0; j < n; j++) {
      printf("%c", board[i][j]);
    }
    printf("\n");
  }
}

// This is the positionInBounds function that is used to check whether the
// specified row and column lie within the board dimensions or not
bool positionInBounds(int n, int row, int col) {
  if (row < 0 || col < 0 || row >= n || col >= n) {
    return false;
  } else {
    return true;
  }
}

// This function is used to check the legality of the position (row, col) by
// checking the direction specified by deltaRow and deltaCol
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  int row1 = 0, col1 = 0;
  // When the coordinate is outside the board OR of the same colour OR an empty
  // space (U - Unoccupied), then return false
  if (!positionInBounds(n, row + deltaRow, col + deltaCol) ||
      board[row + deltaRow][col + deltaCol] == colour ||
      board[row + deltaRow][col + deltaCol] == 'U') {
    return false;
  }

  // Incrementing row in the direction specified by deltaRow and column in the
  // direction specified by deltaCol
  row1 = row + deltaRow;
  col1 = col + deltaCol;

  // While the coordinate is within the board dimensions
  while (positionInBounds(n, row1, col1)) {
    // Return true when we hit a space with the same colour as the one we are to
    // place
    if (board[row1][col1] == colour) {
      return true;
    } else if (board[row1][col1] == 'U') {
      return false;
    }
    row1 = row1 + deltaRow;
    col1 = col1 + deltaCol;
  }
  return false;
}

// This function helps us check the legality of moves in each of the 8
// directions
bool checkingEachDirection(char board[][26], int n, int row, int col,
                           char colour) {
  if (checkLegalInDirection(board, n, row, col, colour, -1, -1)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, -1, 0)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, -1, 1)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 0, -1)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 0, 1)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, -1)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, 0)) {
    return true;
  } else if (checkLegalInDirection(board, n, row, col, colour, 1, 1)) {
    return true;
  } else {
    return false;
  }
}

// This function lists the available moves for the player with the White pieces
// followed by the player with the Black pieces
void availableMoves(char board[][26], int n, char colour) {
  int row, col;
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      // Checks for the available moves only if the specified cell is unoccupied
      // and there is a legal move in one of the directions
      if (board[row][col] == 'U' &&
          checkingEachDirection(board, n, row, col, colour)) {
        printf("%c%c\n", row + 'a', col + 'a');
      }
    }
  }
}

// This function checks whether the given input of a sequence of moves is valid
// or not
void validMove(char board[][26], int n) {
  int row, col;
  int ct = 0;
  char ch1, ch2, ch3, ch4;
  char a, b, c;
  printf("Enter a move:\n");
  scanf(" %c %c %c", &a, &b, &c);

  // employs the use of global variables
  x = a;
  y = b;
  z = c;

  // The same logic is applied for when the pieces are white or black
  for (row = 0; row < n; row++) {
    for (col = 0; col < n; col++) {
      if (board[row][col] == 'U' &&
          checkingEachDirection(board, n, row, col, 'W')) {
        ch1 = row + 'a';
        ch2 = col + 'a';
      } else if (board[row][col] == 'U' &&
                 checkingEachDirection(board, n, row, col, 'B')) {
        ch3 = row + 'a';
        ch4 = col + 'a';
      }
      if (((b == ch1) && (c == ch2)) || ((b == ch3) && (c == ch4))) {
        ct = 1;
        break;
      } else {
        ct = 0;
      }
    }
  }
  // Prints valid if the counter is 1 else prints invalid
  if (ct == 1) {
    printf("Valid move.\n");
  } else {
    printf("Invalid move.\n");
  }
}

// The validMove function checks whether the move is valid or not while this
// function changes the desired tiles accordingly
void checkAndFlip(char board[][26], int n, int row, int col, char colour,
                  int deltaRow, int deltaCol) {
  int row1 = 0;
  int col1 = 0;
  // When the coordinate is within the board AND is the opposite colour AND is
  // not Unoccupied
  if (positionInBounds(n, row + deltaRow, col + deltaCol) &&
      board[row + deltaRow][col + deltaCol] != colour &&
      board[row + deltaRow][col + deltaCol] != 'U') {
    // Changing the input tile to the colour specified by the user
    board[row][col] = colour;
    row1 = row + deltaRow;
    col1 = col + deltaCol;

    // To change the tiles is the specified direction
    while (positionInBounds(n, row1, col1)) {
      if (board[row1][col1] == colour) {
        while (board[row + deltaRow][col + deltaCol] != colour) {
          board[row + deltaRow][col + deltaCol] = colour;
          row = row + deltaRow;
          col = col + deltaCol;
        }
        break;
      } else if (board[row1][col1] == 'U') {
        break;
      }
      row1 = row1 + deltaRow;
      col1 = col1 + deltaCol;
    }
  }
}

// Checks if the tiles can be flipped in each of the 8 directions
void checkForFlip(char board[][26], int n, int row, int col, char colour) {
  checkAndFlip(board, n, row, col, colour, -1, -1);
  checkAndFlip(board, n, row, col, colour, -1, 0);
  checkAndFlip(board, n, row, col, colour, -1, 1);
  checkAndFlip(board, n, row, col, colour, 0, -1);
  checkAndFlip(board, n, row, col, colour, 0, 1);
  checkAndFlip(board, n, row, col, colour, 1, -1);
  checkAndFlip(board, n, row, col, colour, 1, 0);
  checkAndFlip(board, n, row, col, colour, 1, 1);
}

// Flips the tiles based on the colour of the piece specified in the input
// sequence
void flip(char board[][26], int n, int row, int col, char colour) {
  if ((colour == 'W')) {
    checkForFlip(board, n, row, col, 'W');
    printBoard(board, n);
  } else if ((colour == 'B')) {
    checkForFlip(board, n, row, col, 'B');
    printBoard(board, n);
  }
}