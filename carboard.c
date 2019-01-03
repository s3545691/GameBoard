/******************************************************************************
 ** Student name: Morgan Borley	...
 ** Student number:s3545691 	...
 ** Course: 			Advanced Programming Techniques - S1 2018
 ******************************************************************************/

#include "carboard.h"
#include<string.h>
int main()
 {
    int i = 0;
    char userIn[80];
    Boolean showtheMenu;
    void showPlayMenu();
    showtheMenu = TRUE;

    while (TRUE)
    {
        if (showtheMenu==TRUE)
        {
            printf("Welcome to Car Board:\n"
            "-----------------\n"
            "1. Play game\n"
            "2. Show student's information\n"
            "3. Quit\n");
        }
        printf("Please enter your choice: ");
         fgets(userIn, 80, stdin);
                 
         i = strlen(userIn) - 1;
        if (userIn[ i ] == '\n')
            userIn[i] = '\0';
         if (strcmp(userIn, "1") == 0)
        {
            showPlayMenu();
            playGame();
            showtheMenu=TRUE;
        } else if (strcmp(userIn, "2") == 0) {
            showStudentInformation();
            showtheMenu=FALSE;
        }
        else if (strcmp(userIn, "3") == 0) {
            exit(0);
            break;
        }
        else if (strcmp(userIn, COMMAND_QUIT) == 0) 
            {
                return(0);
            }
        else {
            printf("%s is not a valid choice\n",userIn);
            showtheMenu=TRUE;
        } 
    }
    return (0);
}

void showStudentInformation() {
    printf("--------------------------------------------\n");
    printf("Name: Morgan Borley\n");
    printf("No: s3545691\n");
    printf("Email: s3545691@student.rmit.edu.au\n");
    printf("--------------------------------------------\n");
}

void showPlayMenu() {
    /* The Command Entered by the User */
    printf("You can use the following commands to play the game: \n");
    printf("load <g> \n");
    printf("    g: number of the game board to load \n");
    printf("init <x>,<y>,<direction> \n");
    printf("    x: horizontal position of the car on the board (between 0 & 9) \n");
    printf("    y: vertical position of the car on the board (between 0 & 9)\n");
    printf("    direction: direction of the car's movement (north, east, south, west\n");
    printf("forward (or f) \n");
    printf("turn_left (or l) \n");
    printf("turn_right (or r) \n");
    printf("quit \n");  
}

void showigCommands(){
    printf("forward\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or l)\n");
    printf("quit\n\n");
}

void showinitMenu(){
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n\n");
}