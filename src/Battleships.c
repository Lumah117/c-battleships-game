/*
 * Battleships - Completed Portfolio Implementation
 *
 * Original university project by Christopher Mitchell.
 * Revisited and completed for portfolio presentation.
 *
 * The original university implementation is preserved separately
 * in the /original directory.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 6

typedef enum {
    WATER,
    SHIP,
    MISS,
    HIT
} CellState;


/* Function declarations */
void initialise_board(CellState board[MAX_ROWS][MAX_COLUMNS]);
void place_ships(
    CellState board[MAX_ROWS][MAX_COLUMNS],
    int rows,
    int columns,
    int number_of_ships
);

void print_board(
    const CellState board[MAX_ROWS][MAX_COLUMNS],
    int rows,
    int columns,
    int reveal_ships
);

int get_integer_in_range(
    const char *prompt,
    int minimum,
    int maximum
);

int get_target(
    int *target_row,
    int *target_column,
    int rows,
    int columns
);

int all_ships_destroyed(int ships_remaining);


/*
 * Main game
 */
int main(void)
{
    CellState board[MAX_ROWS][MAX_COLUMNS];

    int rows;
    int columns;
    int board_size;

    int number_of_ships;
    int missiles;

    int ships_remaining;

    printf("=====================================\n");
    printf("             BATTLESHIPS             \n");
    printf("=====================================\n\n");

    printf("Welcome to Battleships!\n\n");

    /*
     * Battlefield configuration
     */
    rows = get_integer_in_range(
        "Enter battlefield rows (1-5): ",
        1,
        MAX_ROWS
    );

    columns = get_integer_in_range(
        "Enter battlefield columns (1-6): ",
        1,
        MAX_COLUMNS
    );

    board_size = rows * columns;

    number_of_ships = get_integer_in_range(
        "Enter number of ships: ",
        1,
        board_size
    );

    missiles = get_integer_in_range(
        "Enter number of missiles: ",
        1,
        board_size
    );

    ships_remaining = number_of_ships;

    /*
     * Initialise game
     */
    initialise_board(board);

    srand((unsigned int)time(NULL));

    place_ships(
        board,
        rows,
        columns,
        number_of_ships
    );

    printf("\nBattlefield created.\n");
    printf("%d ships have been hidden.\n", number_of_ships);
    printf("You have %d missiles.\n\n", missiles);

    /*
     * Main game loop
     */
    while (missiles > 0 && !all_ships_destroyed(ships_remaining)) {

        int target_row;
        int target_column;

        print_board(
            board,
            rows,
            columns,
            0
        );

        printf("\nShips remaining: %d\n", ships_remaining);
        printf("Missiles remaining: %d\n\n", missiles);

        /*
         * Keep requesting a target until the player selects
         * a valid cell that has not previously been fired upon.
         */
        while (1) {

            if (!get_target(
                    &target_row,
                    &target_column,
                    rows,
                    columns)) {

                printf("Invalid target. Example: A3\n\n");
                continue;
            }

            if (board[target_row][target_column] == HIT ||
                board[target_row][target_column] == MISS) {

                printf(
                    "You have already fired at that location.\n"
                    "Choose another target.\n\n"
                );

                continue;
            }

            break;
        }

        /*
         * A valid shot consumes one missile.
         */
        missiles--;

        /*
         * Process shot
         */
        if (board[target_row][target_column] == SHIP) {

            board[target_row][target_column] = HIT;
            ships_remaining--;

            printf("\n*** HIT AND SUNK! ***\n");

        } else {

            board[target_row][target_column] = MISS;

            printf("\nMiss!\n");
        }

        printf(
            "Target: %c%d\n\n",
            'A' + target_row,
            target_column + 1
        );
    }

    /*
     * Final result
     */
    printf("\n=====================================\n");

    if (all_ships_destroyed(ships_remaining)) {

        printf("              YOU WIN!               \n");
        printf("=====================================\n\n");

        printf("All enemy ships have been destroyed.\n");

    } else {

        printf("             GAME OVER               \n");
        printf("=====================================\n\n");

        printf("You have run out of missiles.\n");
        printf(
            "%d ship%s remain%s.\n",
            ships_remaining,
            ships_remaining == 1 ? "" : "s",
            ships_remaining == 1 ? "s" : ""
        );
    }

    /*
     * Reveal final battlefield.
     */
    printf("\nFinal battlefield:\n");

    print_board(
        board,
        rows,
        columns,
        1
    );

    printf("\n");

    return 0;
}


/*
 * Initialise every possible board location as water.
 */
void initialise_board(CellState board[MAX_ROWS][MAX_COLUMNS])
{
    for (int row = 0; row < MAX_ROWS; row++) {

        for (int column = 0;
             column < MAX_COLUMNS;
             column++) {

            board[row][column] = WATER;
        }
    }
}


/*
 * Randomly place size-1 ships on the battlefield.
 *
 * A new location is generated until an unused water
 * cell is found, preventing ships from overlapping.
 */
void place_ships(
    CellState board[MAX_ROWS][MAX_COLUMNS],
    int rows,
    int columns,
    int number_of_ships
)
{
    int ships_placed = 0;

    while (ships_placed < number_of_ships) {

        int row = rand() % rows;
        int column = rand() % columns;

        if (board[row][column] == WATER) {

            board[row][column] = SHIP;
            ships_placed++;
        }
    }
}


/*
 * Display the battlefield.
 *
 * During normal gameplay:
 *
 *   ~ = unknown location
 *   O = miss
 *   X = hit
 *
 * If reveal_ships is true:
 *
 *   S = remaining ship
 */
void print_board(
    const CellState board[MAX_ROWS][MAX_COLUMNS],
    int rows,
    int columns,
    int reveal_ships
)
{
    printf("\n    ");

    for (int column = 0; column < columns; column++) {

        printf("%d   ", column + 1);
    }

    printf("\n");

    for (int row = 0; row < rows; row++) {

        printf("%c | ", 'A' + row);

        for (int column = 0;
             column < columns;
             column++) {

            char symbol;

            switch (board[row][column]) {

                case HIT:
                    symbol = 'X';
                    break;

                case MISS:
                    symbol = 'O';
                    break;

                case SHIP:
                    symbol = reveal_ships ? 'S' : '~';
                    break;

                case WATER:
                default:
                    symbol = '~';
                    break;
            }

            printf("%c | ", symbol);
        }

        printf("\n");
    }
}


/*
 * Read an integer from the user and ensure that it falls
 * within the requested range.
 */
int get_integer_in_range(
    const char *prompt,
    int minimum,
    int maximum
)
{
    int value;
    int result;

    while (1) {

        printf("%s", prompt);

        result = scanf("%d", &value);

        if (result == 1 &&
            value >= minimum &&
            value <= maximum) {

            return value;
        }

        printf(
            "Please enter a whole number from %d to %d.\n",
            minimum,
            maximum
        );

        /*
         * Clear invalid characters from stdin.
         */
        int character;

        while ((character = getchar()) != '\n' &&
               character != EOF) {
            /* discard input */
        }
    }
}


/*
 * Read a battlefield coordinate such as:
 *
 * A1
 * B4
 * E6
 *
 * A space between the row and column is also accepted.
 */
int get_target(
    int *target_row,
    int *target_column,
    int rows,
    int columns
)
{
    char row_character;
    int column;

    printf("Enter target (for example A3): ");

    if (scanf(" %c%d", &row_character, &column) != 2) {

        int character;

        while ((character = getchar()) != '\n' &&
               character != EOF) {
            /* discard invalid input */
        }

        return 0;
    }

    row_character =
        (char)toupper((unsigned char)row_character);

    int row = row_character - 'A';

    column--;

    if (row < 0 ||
        row >= rows ||
        column < 0 ||
        column >= columns) {

        return 0;
    }

    *target_row = row;
    *target_column = column;

    return 1;
}


/*
 * Return true when no ships remain.
 */
int all_ships_destroyed(int ships_remaining)
{
    return ships_remaining == 0;
}
