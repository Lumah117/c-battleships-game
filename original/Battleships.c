/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// code to include libraries
#include <stdio.h>
#include <stdlib.h>

// code to define rows and columns
#define ROWS 5
#define COLUMNS 6

// declared functions and variables
int **create_array (int m, int n);
void shoot (int grid[ROWS][COLUMNS], int hit, int Ships);
void gen_ships ();
void print_grid ();
void print_secret_grid ();
int rows;
int columns;

// code for main function
int
main ()
{
// declared variables
  rand ();
  int Rows = 0;
  int Columns = 0;
  int Missiles;
  int Ships;
  int board;
  int rows;
  int m;
  int n;
 


  // code to greet the user
  printf ("Hello & Welcome to Battleships. \n");


  // code to make the user enter battlefield dimensions- no. of rows
  printf ("Please enter Battlefield dimensions (no. of Rows): \n");

  // code for a do-while loop
  do
    {
      // code to read and store players input dimensions
      scanf ("%d", &Rows);

      // code to make the user re-enter if entry is not in the correct range
      if (Rows <= 0 || Rows > 5)
	printf ("Please enter a number of Rows from 1 to 5: \n");
    }

  // code to make sure loop continues asking for a valid number
  while (Rows <= 0 || Rows > 5);
  
  

  // code to ask user for Battlefield dimensions- no. of columns
  printf ("Please enter Battlefield dimensions (no. of Columns): \n");

  // code for a do-while loop
  do
    {
      // code to read and store players input dimensions
      scanf ("%d", &Columns);

      // code to make the user re-enter if entry is not in the correct range
      if (Columns <= 0 || Columns > 6)
	printf ("Please enter a number of Columns from 1 to 6: \n");
    }

  // code to make sure loop continues asking for a valid number
  while (Columns <= 0 || Columns > 6);

// code to designate size of board
  board = (Rows * Columns);
  
  // code to ask the user for the number of ships
  printf ("Please enter the number of ships of size 1: \n");

  // code for a do-while loop
  do
    {
      // code to read and store players input 
      scanf ("%d", &Ships);

      // code to make the user re-enter if entry is not in the correct range
      if (Ships > board);
      printf ("Please enter a valid number of Ships \n");
    }

  // code to make sure loop continues asking for a valid number
  while (Ships > board);


  // code to ask the user for the number of ships
  printf ("Please enter the number of missiles you wish to fire: \n");

  // code for a do-while loop
  do
    {
      // code to read and store players input 
      scanf ("%d", &Missiles);

      // code to make the user re-enter if entry is not in the correct range
      if (Missiles > board);
      printf ("Please enter a valid number of Missiles \n");
    }

  // code to make sure loop continues asking for a valid number
  while (Missiles > board);


  int **grid = create_array (Rows, Columns);
  void gen_ships ();
  void print_grid ();
  void shoot (int grid[ROWS][COLUMNS], int hit, int Ships);
  void print_secret_grid ();
  
  
}
// code for function to generate and print the battlefield to the screen
int **create_array (int m, int n)
{

    for (int i=1; i<=m; i++){
        printf("\n");
        
        switch(i)
        {
        case 1: printf("A | ");
                break;
        case 2: printf("B | ");
                break;
        case 3: printf("C | ");
                break;
        case 4: printf("D | ");
                break;
        case 5: printf("E | ");
                break;

        }
        for (int j=1; j<=n; j++)
            printf(" * ");
    }
}

// code for function to randomly generate the ships
void
gen_ships ()
{

}

// code for function to reprint the grid aftr each shot
void
print_grid ()
{

}

// code for function to reveal the positions of any remaining ships at the end of the game
void
print_secret_grid ()
{

}

// code for function to take a shot
void
shoot (int grid[ROWS][COLUMNS], int hit, int Ships)
{

  int x, y;

  printf ("\nLine --> ");
  scanf ("%d", &x);
  printf ("Column --> ");
  scanf ("%d", &y);

  do
    {
      if (grid[x - 1][y - 1] == 1)
	{
	  grid[x - 1][y - 1] = 2;	//We assign value 2 because we want to print only the ones the user hits, it will print X which means "hit and sunk".
	  hit++;
	  printf ("\nHit and sunk\n");
	  printf ("Sunk ships:%d \n\n", hit);
	}
      else if (grid[x - 1][y - 1] == -1)
	{			//It will print "*" which means "discovered water".
	  grid[x - 1][y - 1] = 0;
	  printf ("\nMiss\n\n");
	}
    }
  while (hit != Ships);
}

