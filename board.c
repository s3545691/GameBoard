/******************************************************************************
** Student name: Morgan Borley	...
** Student number:s3545691 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"
#include "player.h"
 
Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])

{
    int i, j;
    

    for (j = 0; j < BOARD_WIDTH; j++)
      
    for ( i = 0; i < BOARD_HEIGHT; i++){       
        for (j = 0; j < BOARD_WIDTH; j++){
            board[i][j] = EMPTY;
        }        
    }
    
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{
         int i, j;
    
    for ( i = 0; i < BOARD_HEIGHT; i++){
        for (j = 0; j < BOARD_WIDTH; j++)
            board[i][j] = boardToLoad[i][j];
        
        
    }
    
}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
    if(board[position.y][position.x] == BLOCKED) {
        return FALSE;
    }
    else
      board[position.y][position.x] = PLAYER;
    return TRUE;
}
PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
                             Player * player)
{
    Position tempPosition; 
    
    tempPosition= getNextForwardPosition(player);
    
    /*new potential position calculated check whether blocked or still on the board*/
    if((tempPosition.y <0 || tempPosition.y > 9)||(tempPosition.x <0 || tempPosition.x > 9))
    {
        printf("Error: cannot move forward because at the edge of the board.\n");
        return OUTSIDE_BOUNDS;
    }
   /* printf("%d\n",board[tempPosition.x][tempPosition.y]);*/
    if(board[tempPosition.y][tempPosition.x] == BLOCKED)
    {
        printf("Error: cannot move forward because the road is blocked.\n");
        return CELL_BLOCKED;
    }
    /*change position of player on board*/
    placePlayer(board,tempPosition);
    /*set original position to EMPTY*/
    board[player->position.y][player->position.x] = EMPTY;
    /*remember the players new position*/
    player->position = tempPosition;
    /*printf("%d,%d %d,%d \n", player->position.x, player->position.y, tempPosition.x, tempPosition.y); */
    return PLAYER_MOVED;
}

void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player * player)
{
    int i, j;
    
    printf("| |");
    for (j = 0; j < BOARD_WIDTH; j++)
        printf("%d|", j);
    printf("\n");
    
    for ( i = 0; i < BOARD_HEIGHT; i++){       
        printf("|%d|", i);
        for (j = 0; j < BOARD_WIDTH; j++){
            
            if (board[i][j] == EMPTY)
            {
                printf("%s|", EMPTY_OUTPUT);
                
            }
            else if (board[i][j] == BLOCKED)
            {
                printf("%s|", BLOCKED_OUTPUT);
            }
            else if (board[i][j] == PLAYER)
            {
                 displayDirection(player->direction);
            }
            else 
            {
                printf("%s|", "?");
            }
        }
        printf("\n");
    }
    

    
}


