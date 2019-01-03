MORGAN BORLEY
S3545691

These files implement a game called Car Board. The rules for the game are simple: a car can move around inside a board; 
the player can move the car by entering a set of specific commands; and the car must stay within the board boundaries and must not hit the roadblocks.

the program implements two menus one is used to play the game or show the student menu. 

when you start the program the avaliable commands are

1. Play game
2. Show student’s information
3. Quit



when you play the game avaliable commands are 
· load <g>
· init <x>,<y>,<direction>
· forward
· turn_left (or l)
· turn_right (or r)
· quit

Install files
The following files make up the package for the game program
board.c, carboard.c, game.c, helpers.c, player.c, board.h, game.h, carboard.h, player.h

Current Known bugs
1. Navigation around the board can fail when running into boundries
2. Some illegal command sequences can crash the program

Coding and design
1.The playGame(); function needs to be restructured into smaller functions due to time constraints I havent been able to do this.


COMPILED BY USING THE FOLLOWING COMMAND
gcc -ansi -pedantic -Wall -o CarBoard board.c carboard.c game.c helpers.c player.c

ZIPPED USING THE FOLLOWING COMMAND
zip ${USER}-a1 \

user being s3545691
