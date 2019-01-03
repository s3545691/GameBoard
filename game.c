/******************************************************************************
 ** Student name:Morgan Borley 	...
 ** Student number:s3545691 	...
 ** Course: 			Advanced Programming Techniques - S1 2018
 ******************************************************************************/

#include "game.h"
#include <string.h>
#include <stdio.h>
/*forward declaring functions*/
void directionChange(Player * player, TurnDirection turnDirection);
void setupMenuOnly(int *menuNum);
void initalizeMenuOnly(int *menuNum);
void moveCommandOnlyMenu(int *menuNum);
void makeUpper ( char *sPtr );

void playGame() {
    char userInTwo[80];
    Cell myBoard[10][10];
    Player myPlayer;
    int boardNum;
    int xValue;
    int yValue;
    Direction myDirection;
    int i;
    char *cmdEntered;
    char Value;
    char *directionCommand;
    char *pChr;
    /*used to track which menu items are valid*/
    int menuNum = 0;
    Position myPosition;
    
   

    /* Set up an initial board */

    initialiseBoard(myBoard);
    displayBoard(myBoard, &myPlayer);
    initalizeMenuOnly(&menuNum);

    while (TRUE) {
        /* Prompt for the command */
        printf("Please enter your choice: \n");
        /* Get the users input */
        fgets(userInTwo, 100, stdin);
                
        /*  printf("This is THE string entered: <%s>", userInTwo); */

        /* remove newline, if present */
        i = strlen(userInTwo) - 1;
        if (userInTwo[ i ] == '\n')
            userInTwo[i] = '\0';
        pChr = strtok(userInTwo, ", *");

        /*  printf("This is your string: <%s> after enter has been removed\n", userInTwo); */

        /* Iterate over the user input capturing the command and parameters */
        cmdEntered = NULL;

        /* The first token should be the cmd entered */
        if (pChr != NULL) {
         /*   printf("Command Token is <%s> \n", pChr); */
            cmdEntered = pChr;
        } else {
            printf("please enter a correct command");
            return;
        }

        putchar('\n');

        /* We have a command is it valid ? */

        if ((strcmp(cmdEntered, COMMAND_LOAD) == 0)&&((menuNum == 1) || (menuNum == 2))) {
            /* We now expect the board number as the next token */
            pChr = strtok(NULL, ", *");
            if (pChr == NULL) {
                printf("Please enter a valid board number\n");
                return;
            }
            /* covert the token to an integer */
            boardNum = atoi(pChr);
            if (boardNum == 0) {
                printf("<%s> is not a valid board number\n", pChr);
                return;
            }
            if (boardNum == 1) {
                loadBoard(myBoard, BOARD_1);
            } else if (boardNum == 2) {
                loadBoard(myBoard, BOARD_2);
            } else {
                printf("<%d> isn't a valid board number. Please enter a valid board number", boardNum);
                return;
            }
            displayBoard(myBoard, &myPlayer);
            setupMenuOnly(&menuNum);
        }             /*Is it an Init command ? */
        else if ((strcmp(cmdEntered, COMMAND_INIT) == 0)&&(menuNum == 2)) {
            /* We now expect the board number as the next token */
            pChr = strtok(NULL, ", *");
            if (pChr == NULL) {
                printf("Please enter a valid command line\n");
                return;
            }
            /* covert the token to an integer */
            Value = atoi(pChr);
            if (Value == 0) {
                printf("<%s> is not a valid board number\n", pChr);
                return;
            }
            if (Value >= 1 && Value <= 9) {
                xValue = Value;
               /* printf("<%i> This is correct X Value\n", xValue); */
            }

            /*y Value convert */

            pChr = strtok(NULL, ", *");
            if (pChr == NULL) {
                printf("Please enter a valid command line\n");
                return;
            }
            /* covert the token to an integer */
            Value = atoi(pChr);
            if (Value == 0) {
                printf("<%s> is not a valid board number\n", pChr);
                return;
            }
            if (Value >= 1 && Value <= 9) {
                yValue = Value;
           /*     printf("<%i> This is correct Y Value\n", yValue); */
            }

            /*direction Value convert*/
            pChr = strtok(NULL, ", *");
            if (pChr == NULL) {
                printf("Please enter a valid command line\n");
                return;
            }
            if (pChr != NULL) {
                directionCommand = pChr;
                /*   printf ("final token is <%s> \n", directionCommand); */
            }
            makeUpper(directionCommand);
            if (strcmp(directionCommand, "NORTH") == 0) {
                myDirection = NORTH;
            } else if (strcmp(directionCommand, "SOUTH") == 0) {
                myDirection = SOUTH;
            } else if (strcmp(directionCommand, "EAST") == 0) {
                myDirection = EAST;

            } else if (strcmp(directionCommand, "WEST") == 0) {
                myDirection = WEST;
            } else {
                printf("<%s> isn't a valid command.\n", pChr);
                return;
            }
          /*  printf("<%d>my direction is\n", myDirection); */
            myPosition.x = xValue;
            myPosition.y = yValue;
            if (placePlayer(myBoard, myPosition) == TRUE) {
                initialisePlayer(&myPlayer, &myPosition, myDirection);
                displayBoard(myBoard, &myPlayer);
            }
            moveCommandOnlyMenu(&menuNum);
        }
        else if ((strcmp(cmdEntered, COMMAND_TURN_LEFT_SHORTCUT) == 0 || strcmp(cmdEntered, COMMAND_TURN_LEFT) == 0) && (menuNum == 3)) {

            directionChange(&myPlayer, TURN_LEFT);
            printf("\n");
            displayBoard(myBoard, &myPlayer);
            myPlayer.moves++;
            moveCommandOnlyMenu(&menuNum);

        } else if (strcmp(cmdEntered, COMMAND_TURN_RIGHT_SHORTCUT) == 0 || strcmp(cmdEntered, COMMAND_TURN_RIGHT) == 0) {

            directionChange(&myPlayer, TURN_RIGHT);
            printf("\n");
            displayBoard(myBoard, &myPlayer);
            myPlayer.moves++;
            moveCommandOnlyMenu(&menuNum);

        } else if (strcmp(cmdEntered, COMMAND_FORWARD) == 0 || strcmp(cmdEntered, COMMAND_FORWARD_SHORTCUT) == 0) {

            movePlayerForward(myBoard, &myPlayer);
            printf("\n");
            displayBoard(myBoard, &myPlayer);
            myPlayer.moves++;
            moveCommandOnlyMenu(&menuNum);

        }
        else if (strcmp(cmdEntered, COMMAND_QUIT) == 0) {

            return;

        } else {
            printf("invalid input\n");
            if (menuNum == 1) {
                initalizeMenuOnly(&menuNum);
            } else if (menuNum == 2) {
                setupMenuOnly(&menuNum);
            } else if (menuNum == 3) {
                moveCommandOnlyMenu(&menuNum);
            }
            else {
                printf("ERROR");
            }
        }
    }

}


/*convert a string to all uppercase*/
void makeUpper ( char *sPtr )
{
    while ( *sPtr != '\0' )
    {
    *sPtr = toupper ( ( unsigned char ) *sPtr );
    ++sPtr;
    }
}

/* Show conditional menus */

void moveCommandOnlyMenu(int *menuNum) {
    printf("At this stage only these commands are acceptable:\n");
    printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n\n");
    *menuNum = 3;
}

void setupMenuOnly(int *menuNum) {
    printf("At this stage only these commands are acceptable:\n");
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n\n");
    *menuNum = 2;
}

void initalizeMenuOnly(int *menuNum) {
    printf("At this stage only these commands are acceptable:\n");
    printf("load <g>\n");
    printf("quit\n\n");
    *menuNum = 1;
}


/*make a change in direction and determine new direction*/
void directionChange(Player * player, TurnDirection turnDirection)
{
    if(turnDirection == TURN_LEFT){

        if(player->direction == NORTH){

            player->direction = WEST;
        }

        else if(player->direction == WEST){

            player->direction = SOUTH;
        }

        else if(player->direction == SOUTH){

            player->direction = EAST;
        }

        else if(player->direction == EAST){

            player->direction = NORTH;
        }
    }

    if(turnDirection == TURN_RIGHT){

        if(player->direction == NORTH){

            player->direction = EAST;
        }

        else if(player->direction == EAST){

            player->direction = SOUTH;
        }

        else if(player->direction == SOUTH){

            player->direction = WEST;
        }

        else if(player->direction == WEST){

            player->direction = NORTH;
        }
    }
}
