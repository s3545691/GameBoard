/******************************************************************************
** Student name:Morgan Borley 	...
** Student number:s3545691 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"
#include "carboard.h"

void initialisePlayer(Player * player, Position * position, Direction direction)
{
     player->position = *position;
     player->direction = direction;
     player->moves = 0;   
}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /* TODO */
}

Position getNextForwardPosition(const Player * player)
{
    Position tempPosition = player->position;
    
    if (player->direction == NORTH)
    {
        tempPosition.y--;
    }
    if (player->direction == SOUTH)
    {
       tempPosition.y++;
    }
    if (player->direction == EAST)
    {
        tempPosition.x++;
    }
    if (player->direction == WEST)
    {
       tempPosition.x--;
    }
    return tempPosition;
}

void updatePosition(Player * player, Position position)
{
    player->position = position;
}

void displayDirection(Direction direction)
{
   /* printf("<%d> display \n", direction); */
    if (direction == NORTH)
    {
      /*  printf("N|"); */
        printf("%s|", DIRECTION_ARROW_OUTPUT_NORTH);
    }
    if (direction == SOUTH)
    {
     /*  printf("S|");*/
       printf("%s|", DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    if (direction == EAST)
    {
       /* printf("E|");*/
        printf("%s|", DIRECTION_ARROW_OUTPUT_EAST);
    }
    if (direction == WEST)
    {
       /*printf("W|");*/
       printf("%s|", DIRECTION_ARROW_OUTPUT_WEST);
    }
}


