# C Battleships Game

An early C programming project developed during my university studies, exploring procedural programming, arrays, functions, user input and grid-based game logic through a Battleships-style application.

The repository preserves both the original source code and the handwritten program flowchart produced during the design stage.

## Project Overview

The project was designed as a configurable Battleships-style console game.

The user selects:

- Battlefield rows
- Battlefield columns
- Number of ships
- Number of missiles

The program then creates the battlefield and was intended to randomly distribute ships before allowing the player to enter coordinates representing missile strikes.

Each shot would be evaluated as either a hit or miss and the battlefield updated accordingly.

## Original Design

![Original Battleships program flowchart](docs/original_flowchart.jpg)

The flowchart was produced before/during implementation to map the intended program behaviour, including:

1. Battlefield dimension input
2. Dimension validation
3. Board-size calculation
4. Ship-count input and validation
5. Missile-count input and validation
6. Random ship placement
7. Battlefield display
8. Target-coordinate input
9. Hit/miss evaluation
10. Battlefield update

## Technologies

- C
- Standard C Library
- Console I/O

## Concepts Explored

The project introduced and reinforced:

- Procedural programming
- Functions and function declarations
- Variables and constants
- `#define` preprocessor constants
- `for` loops
- `do...while` loops
- Conditional logic
- `switch` statements
- User-input validation
- Arrays and 2D indexing
- Grid-based data representation
- Basic game-state logic
- Program decomposition
- Algorithm planning using flowcharts

## Battlefield Configuration

The original implementation allows the user to select a battlefield containing up to:

- 5 rows
- 6 columns

The total board size is calculated from the selected dimensions and used when validating the requested number of ships and missiles.

## Battlefield Representation

The battlefield display uses alphabetical row identifiers:

```text id="iwvs3r"
    1  2  3  4  5  6

A | *  *  *  *  *  *
B | *  *  *  *  *  *
C | *  *  *  *  *  *
D | *  *  *  *  *  *
E | *  *  *  *  *  *
```

The original design intended the underlying grid state to distinguish between ships, water and successful hits.

## Shot Processing

The `shoot()` function accepts target coordinates and checks the corresponding grid location.

The intended state transitions include:

```text id="2rwss9"
Target Coordinate
       |
       v
Inspect Grid Cell
       |
   +---+---+
   |       |
   v       v
 Ship     Water
   |       |
   v       v
  Hit     Miss
   |       |
   +---+---+
       |
       v
 Update Battlefield
```

Successful hits increment the number of sunk ships, while misses update the corresponding grid location.

## Program Structure

The original program was divided into several planned functions:

```text id="c8nyzk"
main()
│
├── create_array()
├── gen_ships()
├── print_grid()
├── shoot()
└── print_secret_grid()
```

This represents an early attempt to decompose a larger program into functions with separate responsibilities.

## Original Source Code

The recovered university implementation is preserved in:

`original/Battleships.c`

The source has intentionally been retained in its original state rather than modified to appear complete.

## Implementation Status

## Implementation Status

The repository contains two versions of the project.

### Original University Implementation

The original university source code is preserved unchanged in:

`original/Battleships.c`

The recovered version is incomplete. Several functions were planned and declared but were not implemented in the surviving source code, including:

- Random ship generation
- Battlefield re-rendering after shots
- Final hidden-grid display

The original implementation does, however, contain the initial battlefield configuration, input-validation logic, grid rendering and partial shot-processing logic.

It has deliberately been preserved in its original state to provide an accurate record of my early C programming work.

### Completed Portfolio Implementation

The project was revisited and completed later as part of my coding portfolio.

The completed implementation is available in:

`src/battleships.c`

Rather than modifying the original university source, the completed version was developed separately while retaining the original project concept and design.

The completed game includes:

- Configurable battlefield dimensions
- User-selectable ship and missile counts
- Random ship placement
- Prevention of overlapping ships
- Coordinate-based targeting using inputs such as `A3`
- Hit and miss detection
- Battlefield updates after each shot
- Detection of previously targeted locations
- Remaining ship and missile tracking
- Input and coordinate validation
- Win and loss conditions
- Final battlefield reveal
- Explicit battlefield cell states

The completed implementation therefore represents both the completion of the original project concept and a retrospective application of the programming practices I developed after the original coursework was undertaken.

## Retrospective

Reviewing this project with considerably more programming experience highlights both useful early design decisions and several implementation issues.

### Program Decomposition

Separating functionality into functions such as ship generation, grid rendering and shot processing was a useful step toward modular program design.

The implementation would benefit from completing this separation and defining clear interfaces between each component.

### Input Validation

The battlefield dimensions use `do...while` loops to repeatedly request values until they fall within the permitted ranges.

However, the original ship and missile validation conditions contain stray semicolons following their `if` statements, causing the following messages to execute independently of the condition.

### Grid Representation

The project begins working with a two-dimensional battlefield representation, but the surviving implementation does not fully initialise or manage the underlying game board.

A modern implementation would define explicit cell states, for example:

```text id="kxjq8q"
WATER
SHIP
MISS
HIT
```

rather than relying directly on numeric values.

### Randomisation

Although random ship generation was planned, the corresponding `gen_ships()` function is empty in the recovered source.

A completed implementation would initialise a pseudo-random number generator and ensure ships were placed only within valid, unoccupied grid cells.

### Game State

The game would benefit from explicit state tracking for:

- Remaining missiles
- Remaining ships
- Previous shots
- Win/loss conditions
- Invalid or repeated target coordinates

### Testing

A modern version would separate game logic from console interaction so that individual components could be tested independently.

## How I Would Approach It Today

A modern implementation could separate responsibilities into modules such as:

```text id="xk44ze"
Battleships
│
├── Board
│   ├── Initialise grid
│   ├── Place ships
│   └── Render battlefield
│
├── Game
│   ├── Track missiles
│   ├── Track ships
│   └── Determine game state
│
├── Input
│   └── Validate coordinates
│
└── Shot Processing
    ├── Hit
    ├── Miss
    └── Repeated shot
```

This would make the game easier to maintain, test and extend.

## Portfolio Context

This project is retained as an example of my early C programming and algorithm-design experience.

It demonstrates progression beyond small calculation exercises toward a larger interactive program requiring input validation, grid representation, function decomposition, game-state logic and up-front algorithm planning.
