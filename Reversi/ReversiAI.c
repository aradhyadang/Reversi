#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Author: Aradhya Dang
//
// #include "reversi.h"

// Function Definitions
void printInitialBoard(char board[][26], int n);
void printBoard(char board[][26], int n);
bool posInboard(int n, int r, int c);
bool checkDir(char board[][26], int n, int row, int col, char clr, int delR,
              int delC);
void checkAndFlipForPlayer(char board[][26], int n, int row, int col, char clr,
                           int delR, int delC);
bool isValid(char board[][26], int n, char colour);
int checkAndFlipForComputer(char board[][26], int n, int row, int col, char clr,
                            int delR, int delC);

// Main Function
int main(void) {
  int n;
  char cpm;
  char board[26][26];

  // Asks the dimensions of the board from the user
  printf("Enter the board dimension: ");
  scanf("%d", &n);

  // Asks for user input regarding the computer's pieces
  printf("Computer plays (B/W): ");
  scanf(" %c", &cpm);

  // Prints the board with the initial values
  printInitialBoard(board, n);

  // Condition for when the computer plays with the black pieces
  if (cpm == 'B') {
    while (1 + 1 == 2) {
      // To check the validity of the move
      if (isValid(board, n, 'B')) {
        int c1 = 0;
        int c2 = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            int counter = 0, check = 0;
            char copyarray[26][26];

            // intializing the duplicate array with the components of the board
            for (int p = 0; p < n; p++) {
              for (int q = 0; q < n; q++) {
                copyarray[p][q] = board[p][q];
              }
            }

            // Checking in each direction and updating the counter as needed
            if (checkDir(board, n, i, j, 'B', -1, 1)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', -1, 0)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', -1, -1)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', 0, -1)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', 0, 1)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', 1, -1)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', 1, 0)) {
              counter++;
            }
            if (checkDir(board, n, i, j, 'B', 1, 1)) {
              counter++;
            }

            // checkAndFlipForComputer in each direction for the duplicate array
            // for black pieces and updating the condition when true
            if (counter > 0) {
              if (checkDir(copyarray, n, i, j, 'B', -1, -1)) {
                check = check + checkAndFlipForComputer(copyarray, n, i, j, 'B',
                                                        -1, -1);
              }
              if (checkDir(copyarray, n, i, j, 'B', -1, 0)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', -1, 0);
              }
              if (checkDir(copyarray, n, i, j, 'B', -1, 1)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', -1, 1);
              }
              if (checkDir(copyarray, n, i, j, 'B', 0, -1)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', 0, -1);
              }
              if (checkDir(copyarray, n, i, j, 'B', 0, 1)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', 0, 1);
              }
              if (checkDir(copyarray, n, i, j, 'B', 1, -1)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', 1, -1);
              }
              if (checkDir(copyarray, n, i, j, 'B', 1, 0)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', 1, 0);
              }
              if (checkDir(copyarray, n, i, j, 'B', 1, 1)) {
                check = check +
                        checkAndFlipForComputer(copyarray, n, i, j, 'B', 1, 1);
              }

              // Updating the best position for the move and the maximum score
              // calculated by comparing it with an initialized variable
              if (check > result) {
                result = check;
                c1 = i;
                c2 = j;
              }
            }
          }
        }

        // To check in each direction for the black pieces and modifying the
        // code as necessary
        if (checkDir(board, n, c1, c2, 'B', -1, -1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', -1, -1);
        }
        if (checkDir(board, n, c1, c2, 'B', -1, 0)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', -1, 0);
        }
        if (checkDir(board, n, c1, c2, 'B', -1, 1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', -1, 1);
        }
        if (checkDir(board, n, c1, c2, 'B', 0, -1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', 0, -1);
        }
        if (checkDir(board, n, c1, c2, 'B', 0, 1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', 0, 1);
        }
        if (checkDir(board, n, c1, c2, 'B', 1, -1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', 1, -1);
        }
        if (checkDir(board, n, c1, c2, 'B', 1, 0)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', 1, 0);
        }
        if (checkDir(board, n, c1, c2, 'B', 1, 1)) {
          checkAndFlipForPlayer(board, n, c1, c2, 'B', 1, 1);
        }

        // Updating or changing the colour for further use
        board[c1][c2] = 'B';
        char row1 = (char)('b' + (c1 - 1));
        char row2 = (char)('b' + (c2 - 1));

        // Printing the computer's move when it is playing with the black pieces
        printf("Computer places B at %c%c.\n", row1, row2);
        printBoard(board, n);
      }

      // Else printing that it has no valid move
      else {
        printf("B player has no valid move.\n");
      }

      /*Counts the number of black and white pieces to determine the one with
       * the maximum no. of pieces. Can also be done by checking if the board is
       * full and no one can make move*/
      int countBlackPieces = 0, countWhitePieces = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == 'B') {
            countBlackPieces = countBlackPieces + 1;
          } else if (board[i][j] == 'W') {
            countWhitePieces = countWhitePieces + 1;
          }
        }
      }

      // Prints the following statements based upon the conditions that are
      // primarily dependent upon the no. of black pieces and the no. of white
      // pieces
      if (countBlackPieces + countWhitePieces == pow(n, 2)) {
        if (countBlackPieces > countWhitePieces) {
          printf("B player wins.");
        }
        if (countBlackPieces < countWhitePieces) {
          printf("W player wins.");
        }
        if (countBlackPieces == countWhitePieces) {
          printf("Draw!");
        }
        break;
      }

      char copyarray1[100];

      // checks for the validity of the move
      if (isValid(board, n, 'W')) {
        // User input for white pieces
        printf("Enter move for colour W (RowCol): ");
        scanf("%s", copyarray1);

        // Row and column conversion from char to int
        int row1 = (int)(copyarray1[0] - 'a');
        int col1 = (int)(copyarray1[1] - 'a');

        int counter = 0;

        if (checkDir(board, n, row1, col1, 'W', -1, -1)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', -1, 0)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', -1, 1)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', 0, -1)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', 0, 1)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', 1, -1)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', 1, 0)) {
          counter++;
        }
        if (checkDir(board, n, row1, col1, 'W', 1, 1)) {
          counter++;
        }

        // If the player with the white pieces enters an invalid move, then the
        // player - human or computer - with the black pieces wins
        if (counter == 0) {
          printf("Invalid move.\n");
          printf("B player wins.");
          break;
        }

        // checking in each direction for the white pieces with subsequent
        // modification as necessary
        else {
          if (checkDir(board, n, row1, col1, 'W', -1, -1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', -1, -1);
          }
          if (checkDir(board, n, row1, col1, 'W', -1, 0)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', -1, 0);
          }
          if (checkDir(board, n, row1, col1, 'W', -1, 1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', -1, 1);
          }
          if (checkDir(board, n, row1, col1, 'W', 0, -1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', 0, -1);
          }
          if (checkDir(board, n, row1, col1, 'W', 0, 1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', 0, 1);
          }
          if (checkDir(board, n, row1, col1, 'W', 1, -1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', 1, -1);
          }
          if (checkDir(board, n, row1, col1, 'W', 1, 0)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', 1, 0);
          }
          if (checkDir(board, n, row1, col1, 'W', 1, 1)) {
            checkAndFlipForPlayer(board, n, row1, col1, 'W', 1, 1);
          }
          board[row1][col1] = 'W';
        }
        printBoard(board, n);
      }  // isValid condition ends

      else {
        printf("W player has no valid move.\n");
      }

      /*Counts the number of black and white pieces to determine the one with
       * the maximum no. of pieces. Can also be done by checking if the board is
       * full and no one can make move*/
      int countbp = 0, countwp = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == 'B') {
            countbp = countbp + 1;
          } else if (board[i][j] == 'W') {
            countwp = countwp + 1;
          }
        }
      }

      // Prints the following statements based upon the conditions that are
      // primarily dependent upon the no. of black pieces and the no. of white
      // pieces
      if (countbp + countwp == pow(n, 2)) {
        if (countbp > countwp) {
          printf("B player wins.");
        }
        if (countbp < countwp) {
          printf("W player wins.");
        }
        if (countbp == countwp) {
          printf("Draw!");
        }
        break;
      }
    }
  }

  // When the computer is assigned to play with the white pieces
  else if (cpm == 'W') {
    while (1 + 1 == 2) {
      // to check for the validity of the move
      if (isValid(board, n, 'B')) {
        char copyarray[100];

        // Use input for the black pieces
        printf("Enter move for colour B (RowCol): ");
        scanf("%s", copyarray);
        int row2 = (int)(copyarray[0] - 'b' + 1);
        int col2 = (int)(copyarray[1] - 'b' + 1);

        int count = 0;

        // Checking in each direction and updating the counter when the
        // condition is true
        if (checkDir(board, n, row2, col2, 'B', -1, -1)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', -1, 0)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', -1, 1)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', 0, -1)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', 0, 1)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', 1, -1)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', 1, 0)) {
          count++;
        }
        if (checkDir(board, n, row2, col2, 'B', 1, 1)) {
          count++;
        }

        if (count == 0) {
          printf("Invalid move.\n");
          printf("W player wins.");
          break;
        }

        // Checking in each direction and flipping for the player - black pieces
        // - when the condition checkDir is true
        else {
          if (checkDir(board, n, row2, col2, 'B', -1, -1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', -1, -1);
          }
          if (checkDir(board, n, row2, col2, 'B', -1, 0)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', -1, 0);
          }
          if (checkDir(board, n, row2, col2, 'B', -1, 1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', -1, 1);
          }
          if (checkDir(board, n, row2, col2, 'B', 0, -1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', 0, -1);
          }
          if (checkDir(board, n, row2, col2, 'B', 0, 1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', 0, 1);
          }
          if (checkDir(board, n, row2, col2, 'B', 1, -1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', 1, -1);
          }
          if (checkDir(board, n, row2, col2, 'B', 1, 0)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', 1, 0);
          }
          if (checkDir(board, n, row2, col2, 'B', 1, 1)) {
            checkAndFlipForPlayer(board, n, row2, col2, 'B', 1, 1);
          }
          board[row2][col2] = 'B';
        }
        printBoard(board, n);
      }

      else {
        printf("B player has no valid move.\n");
      }

      /*Counts the number of black and white pieces to determine the one with
       * the maximum no. of pieces. Can also be done by checking if the board is
       * full and no one can make move*/
      int countb = 0, countw = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == 'B') {
            countb = countb + 1;
          } else if (board[i][j] == 'W') {
            countw = countw + 1;
          }
        }
      }

      // Prints the following statements based upon the conditions that are
      // primarily dependent upon the no. of black pieces and the no. of white
      // pieces
      if (countb + countw == pow(n, 2)) {
        if (countb > countw) {
          printf("B player wins.");
        }
        if (countb < countw) {
          printf("W player wins.");
        }
        if (countb == countw) {
          printf("Draw!");
        }
        break;
      }

      // Checking validity of the move
      if (isValid(board, n, 'W')) {
        int c1 = 0;
        int c2 = 0;
        int result = 0;
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            int ct = 0;
            int check = 0;
            char copyarray[26][26];

            // initializing copyarray with board
            for (int x = 0; x < n; x++) {
              for (int y = 0; y < n; y++) {
                copyarray[x][y] = board[x][y];
              }
            }

            // For loop with condition for checking the direction such that the
            // loop helps check in each direction and updating the counter
            for (int p = -1; p <= 1; p++) {
              for (int q = -1; q <= 1; q++) {
                if (p != 0 || q != 0) {
                  if (checkDir(board, n, i, j, 'W', p, q)) {
                    ct++;
                  }
                }
              }
            }

            // Checking and flipping for the computer
            if (ct > 0) {
              for (int a = -1; a <= 1; a++) {
                for (int b = -1; b <= 1; b++) {
                  if (a != 0 || b != 0) {
                    if (checkDir(copyarray, n, i, j, 'W', a, b)) {
                      check = check + checkAndFlipForComputer(copyarray, n, i,
                                                              j, 'W', a, b);
                    }
                  }
                }
              }

              // Calculating the max index and the max score
              if (check > result) {
                result = check;
                c1 = i;
                c2 = j;
              }
            }
          }
        }

        // Checking and flipping for the player
        for (int p = -1; p <= 1; p++) {
          for (int q = -1; q <= 1; q++) {
            if (p != 0 || q != 0) {
              if (checkDir(board, n, c1, c2, 'W', p, q))
                checkAndFlipForPlayer(board, n, c1, c2, 'W', p, q);
            }
          }
        }

        board[c1][c2] = 'W';
        char crow = (char)('a' + c1);
        char ccol = (char)('a' + c2);
        printf("Computer places W at %c%c.\n", crow, ccol);
        printBoard(board, n);
      }

      else {
        printf("W player has no valid move.\n");
      }

      /*Counts the number of black and white pieces to determine the one with
       * the maximum no. of pieces. Can also be done by checking if the board is
       * full and no one can make move*/
      int ctblack = 0, ctwhite = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (board[i][j] == 'B') {
            ctblack = ctblack + 1;
          } else if (board[i][j] == 'W') {
            ctwhite = ctwhite + 1;
          }
        }
      }

      // Prints the following statements based upon the conditions that are
      // primarily dependent upon the no. of black pieces and the no. of white
      // pieces
      if (ctblack + ctwhite == pow(n, 2)) {
        if (ctblack > ctwhite) {
          printf("B player wins.");
        }
        if (ctblack < ctwhite) {
          printf("W player wins.");
        }
        if (ctblack == ctwhite) {
          printf("Draw!");
        }
        break;
      }
    }
  }
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

// This function is separately created and used to print without the
// initializations in the beginning specifically
void printBoard(char board[][26], int n) {
  int i = 0;
  int j = 0;
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

// This is the positionInBoard function that is used to check whether the
// specified row and column lie within the board dimensions or not
bool posInboard(int n, int row, int col) {
  if (col < 0 || col >= n || row < 0 || row >= n)
    return false;
  else
    return true;
}

// This function check the legality of the moves in a specific direction
bool checkDir(char board[][26], int n, int row, int col, char clr, int delR,
              int delC) {
  int col1 = col + delC;
  int row1 = row + delR;
  if (board[row][col] != 'U') return false;
  if (board[row1][col1] == 'U' || !posInboard(n, row1, col1) ||
      board[row1][col1] == clr) {
    return false;
  }
  col1 = col1 + delC;
  row1 = row1 + delR;

  while (posInboard(n, row1, col1)) {
    if (board[row1][col1] == clr) {
      return true;
    } else if (board[row1][col1] == 'U') {
      return false;
    }
    col1 = col1 + delC;
    row1 = row1 + delR;
  }
  return false;
}

// This is a modification of the checkDir function to flip the tiles according
// the their respective directions for the player
void checkAndFlipForPlayer(char board[][26], int n, int row, int col, char clr,
                           int delR, int delC) {
  int row1 = row + delR;
  int col1 = col + delC;
  while (posInboard(n, row1, col1) == true) {
    if (board[row1][col1] == clr) {
      break;
    } else if (board[row1][col1] != clr) {
      board[row1][col1] = clr;
    }
    row1 += delR;
    col1 += delC;
  }
}

// Checks the validity of the move in all 8 directions
bool isValid(char board[][26], int n, char colour) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int counter = 0;

      if (checkDir(board, n, i, j, colour, -1, -1)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, -1, 0)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, -1, 1)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, 0, -1)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, 0, 1)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, 1, -1)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, 1, 0)) {
        counter++;
      }
      if (checkDir(board, n, i, j, colour, 1, 1)) {
        counter++;
      }
      if (counter > 0) return true;
    }
  }
  return false;
}

// Checks and flips the tiles in the specified direction and is used
// specifically for the computer
int checkAndFlipForComputer(char board[][26], int n, int row, int col, char clr,
                            int delR, int delC) {
  int val = 0;
  int col1 = col + delC;
  int row1 = row + delR;
  // While the move is within bounds as specified by the posInBoard function
  while (posInboard(n, row1, col1)) {
    if (board[row1][col1] == clr)
      break;
    else if (clr != board[row1][col1]) {
      board[row1][col1] = clr;
      val++;
    }
    col1 = col1 + delC;
    row1 = row1 + delR;
  }
  return val;
}
