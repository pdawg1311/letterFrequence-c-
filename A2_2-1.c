#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZEGRID 4

void displayGrid(int grid[SIZEGRID][SIZEGRID]);
void initGrid(int grid[SIZEGRID][SIZEGRID]);
void fire(int gridRef[SIZEGRID][SIZEGRID], int gridEvolv[SIZEGRID][SIZEGRID], int* nPosLeft);

int main()
{
    int gridP1[SIZEGRID][SIZEGRID] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
    int gridP2[SIZEGRID][SIZEGRID] = { {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2}, {2, 2, 2, 2} };
    int nPos = 4; //Two 2-cell long boats = 4 positions to sink

    displayGrid(gridP1);

    initGrid(gridP1);

    displayGrid(gridP1);

    while (nPos != 0) {
        fire(gridP1, gridP2, &nPos);
        displayGrid(gridP2);
    }

    printf("Congratulations, you sank all the ships!");


    return 0;
}

// PART1 : Function to display the grid
void displayGrid(int grid[SIZEGRID][SIZEGRID])
{
    for (int i = 0; i < SIZEGRID; i++) {
        for (int j = 0; j < SIZEGRID; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// PART2 : Function to Initialise the grid with Player 1 inputs
void initGrid(int grid[SIZEGRID][SIZEGRID])
{
    char ship1[1];
    int ship2 = 0;
    char ship3[1];
    int ship4 = 0;


    char alphabet[4] = { "ABCD" };


    for (int i = 0; i < 2; i++) {
        printf("PLAYER 1 \n");
        printf("Enter two valid coordinates of boat %d, separated with a whitespace: ", i + 1);
        scanf(" %c%d %c%d", &ship1, &ship2, &ship3, &ship4);
        printf("\n");
        for (int j = 0; j < 3; j++) {
            if (ship1[0] == alphabet[j]) {
                grid[j][ship2 - 1] = 1;
            }
            if (ship3[0] == alphabet[j]) {
                grid[j][ship4 - 1] = 1;
            }

        }

    }


}


// PART3 : Function to fire to a position inputed by the Player 2 and modify the playing grid as needed
void fire(int gridRef[SIZEGRID][SIZEGRID], int gridEvolv[SIZEGRID][SIZEGRID], int* nPosLeft)
{
    // Enter code for function fire here


    char alphabet[4] = { "ABCD" };

    unsigned char let;
    unsigned char num;
    printf("Enter the coordinate you want to target: ");
    scanf(" %c%c", &let, &num);
    int col = let - 65;
    int row = num - 49;

    if (gridRef[col][row] == 1) {
        printf("Hit! \n");
        gridEvolv[col][row] = 1;
        *nPosLeft -= 1;
    }

    else {
        printf("Missed! \n");
    }
}




