/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : Lui Ka Yung
 * Student ID    : 1155160217
 * Class/Section : ENGG1110F
 * Date          : 24/11/2021
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2



/* Initialize the game board by setting all squares to EMPTY */
void initGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
int i, j;
  for (i = 0 ; i < 6 ; i++)
    for (j = 0 ; j < 7 ; j++)
      gameBoard[i][j] = EMPTY;
}



/* Display the game board on the screen.
   You are required to exactly follow the output format stated in the project specification.
   IMPORTANT: Using other output format will result in mark deduction. */
void printGameBoard(int gameBoard[6][7]) {

    // TODO : Complete this part
int i, j;
  for (i = 0 ; i < 6 ; i++)
  {
    for (j = 0 ; j < 7 ; j++)
      {
        printf("|");
        if (gameBoard[i][j] == EMPTY)
          printf(" ");
        else if (gameBoard[i][j] == CIRCLE)
          printf("O");
        else if (gameBoard[i][j] == CROSS)
          printf("X");
      }
    printf("|\n");
  }

  for (i = 1 ; i <= 7 ; i++)
    printf(" %d", i);
  printf("\n");
}



/* Ask the human player to place the mark.
   You can assume that the user input must be an integer. */
void placeMarkByHumanPlayer(int gameBoard[6][7], int mark) {

    // TODO : Complete this part
  int i = 5, input,t = 1;
  scanf("%d", &input);
  while (t == 1)
    if (input < 1 || input > 7)
    {
      printf("Input out of range. Please input again: \n");
      scanf("%d", &input);
    }
    else if  (gameBoard[0][input-1] !=0)
    {
      printf("Column is full. Please input again: \n");

      scanf("%d", &input);
    }
    else
    t = 0;
  while (gameBoard[i][input-1] != EMPTY && i >= 0)
    i--;
  gameBoard[i][input-1] = mark;
  printGameBoard(gameBoard);
}



/* Return 1 if there is a winner in the game, otherwise return 0.
   Note: the winner is the current player indicated in main(). */
int hasWinner(int gameBoard[6][7]){

    // TODO : Complete this part
  //horizontal win
  int i, j;
  for (i = 0 ; i < 6 ; i++)
    for (j = 0 ; j < 4 ; j++)
      if (gameBoard[i][j] == gameBoard[i][j+1] && gameBoard[i][j] == gameBoard[i][j+2] && gameBoard[i][j] == gameBoard[i][j+3] && gameBoard[i][j] != EMPTY)
            return 1;

  //vertical win
  for (j = 0 ; j < 7 ; j++)
    for (i = 0 ; i < 3 ; i++)
      if (gameBoard[i][j] == gameBoard[i+1][j] && gameBoard[i][j] == gameBoard[i+2][j] && gameBoard[i][j] == gameBoard[i+3][j] && gameBoard[i][j] != EMPTY)
            return 1;


  //oblique \ win
  for (j = 6 ; j > 2 ; j--)
    for (i = 5 ; i > 2 ; i--)
      if (gameBoard[i][j] == gameBoard[i-1][j-1] && gameBoard[i][j] == gameBoard[i-2][j-2] && gameBoard[i][j] == gameBoard[i-3][j-3] && gameBoard[i][j] != EMPTY)
            return 1;


  //oblique / win
  for (j = 0 ; j < 4 ; j++)
    for (i = 5 ; i > 2 ; i--)
      if (gameBoard[i][j] == gameBoard[i-1][j+1] && gameBoard[i][j] == gameBoard[i-2][j+2] && gameBoard[i][j] ==  gameBoard[i-3][j+3] && gameBoard[i][j] != EMPTY)
          return 1;
  return 0;
}



/* Return 1 if the game board is full, otherwise return 0. */
int isFull(int gameBoard[6][7]) {

    // TODO : Complete this part
  int i, j;
  for (j = 0 ; j < 7 ; j++)
    for (i = 0 ; i < 6 ; i++)
    {
      if (gameBoard[i][j] == 0)
        return 0;
    }
  return 1;
}



/* Determine the next move of the computer player.
   You are required to exactly follow the strategy mentioned in the project specification.
   Using other strategies will result in mark deduction. */

// TODO : Write the placeMarkByComputerPlayer(...) function here
void placeMarkByComputer(int gameBoard[6][7])

{
  int i = 5, j;
  //Computer wins
    for (j = 0 ; j < 7 ; j++)
    {
      while (gameBoard[i][j] != 0 && i >= 0)
        i--;
      if (gameBoard[i][j] == 0)
      {
        gameBoard[i][j] = CROSS;
        if (hasWinner(gameBoard) == 1)
          return;
        else
          gameBoard[i][j] = EMPTY;
      }
      i = 5;
    }


  //Human wins and stop that
    for (j = 0 ; j < 7 ; j++)
    {
      while (gameBoard[i][j] != 0 && i >= 0)
        i--;
      if (gameBoard[i][j] == 0)
      {
        gameBoard[i][j] = CIRCLE;
        if (hasWinner(gameBoard) == 1)
        {
          gameBoard[i][j] = CROSS;
          return;
        }
        else
          gameBoard[i][j] = EMPTY;
      }
      i = 5;
    }

  //No win condition
  for (i = 5 ; i >= 0 ; i--)
    for (j = 6 ; j >= 0 ; j--)
      if (gameBoard[i][j] == EMPTY)
      {
        gameBoard[i][j] = CROSS;
        return;
      }
}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[6][7];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1             2: Player 2
    int gameContinue;       // 1: The game continues   0: The game ends
    int numOfHumanPlayers;  // 1 or 2

    /* Initialize the local variables */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameContinue = 1;
    printf("Enter the number of human players [1-2]:\n");
    scanf("%d", &numOfHumanPlayers);    // You can assume that the user input must be valid

    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly.
       You can add more if you wish.
       After testing, you can delete them or move them elsewhere.
    Game start
       If there are two human players, they are Player 1 and Player 2
       If there is only one human player, he/she is Player 1 and another player is the computer player
       For both cases, Player 1 moves first and places the CIRCLE mark; while Player 2 (or the computer player) places the CROSS mark
       Hint: use a while loop */

    // TODO : Complete this part
    initGameBoard(gameBoard);
    printGameBoard(gameBoard);
  if (numOfHumanPlayers == 2)
  {
    //human vs human
    while (hasWinner(gameBoard) == 0)
    {
       printf("Player 1's turn: \n");
        placeMarkByHumanPlayer(gameBoard, currentPlayer);
        if (hasWinner(gameBoard) == 1)
        {
          printf("Congratulations! Player 1 wins! ");
            break;
        }
        currentPlayer++;

        printf("Player 2's turn: \n");
        placeMarkByHumanPlayer(gameBoard, currentPlayer);
         if (hasWinner(gameBoard) == 1)
        {
          printf("Congratulations! Player 2 wins! ");
            break;
        }
        currentPlayer--;

       if(isFull(gameBoard) == 1)
        {
          printf("Draw game.");
          break;
        }
    }
  }

  //computer vs human
  else if (numOfHumanPlayers == 1)
  {
    while (hasWinner(gameBoard) == 0)
    {
      //player's turn
      printf("Player 1's turn: ");
      placeMarkByHumanPlayer(gameBoard, currentPlayer);
      if (hasWinner(gameBoard) == 1)
      {
        printf("Congratulations! Player 1 wins! ");
          break;
      }

      //Computer's turn
      printf("Computer's turn: \n");
      placeMarkByComputer(gameBoard);
      printGameBoard(gameBoard);
      if (hasWinner(gameBoard) == 1)
      {
        printf("Computer wins! ");
          break;
      }

      if(isFull(gameBoard) == 1)
      {
          printf("Draw game.");
          break;
      }
    }
  }
    return 0;
}
