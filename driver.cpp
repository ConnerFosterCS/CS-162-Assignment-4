/**********************************************************************
 ** Program: assignment4.cpp (Hunt The Wumpus)
 ** Author: Conner Foster
 ** Date: 05/27/2019
 ** Decription: The objective of this game is to hunt the wumpus through a cave of hidden traps and events. To kill the wumpus you must shoot him with one of your three arrows. After he is killed you must retrieve the gold and exit the cave.
 ** Ouput: Gameboard, number of arrows, number of gold retrieved, and other useful information so the game runs smoothly.
 *********************************************************************/
#include "game.h"
#include "state.h"
#include "room.h"
#include "event.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

int main(int argc, char** argv) {
    bool tf = false;
    int size = 0;
    //prints #FreeWumpus
    cout << "  ||    ||    ||=====                           ||    ||    ||\n==||====||==  ||      ||====  ||====  ||====    ||    ||    ||  ||   ||  ||===//====   ||===||  ||   ||  //===||\n  ||    ||    ||===   ||      ||==    ||==      ||    ||    ||  ||   ||  ||   ||   ||  ||===//  ||   ||  ||==\n==||====||==  ||      ||      ||      ||        ||    ||    ||  ||   ||  ||   ||   ||  ||       ||   ||      ==||\n  ||    ||    ||      ||      ||====  ||====    ||====//====//  ||===//  ||   ||   ||  ||       ||===//   ||===//" << endl;
    if (argc != 3) {
        cout << "error: Incorrect number of arguments. Please enter three command line arguments." << endl;
        return 0;
    }
    else {
        for (int i = 2; i < argc; i+=2) {
            //finds true or false input
            if (strcmp(argv[i], "true")==0) {
                tf = true;
            } else if (strcmp(argv[i], "false")==0) {
                tf = false;
            }
            //finds size of 
            size = atoi(argv[i-1]);
        } cout << endl;
        Game g(size);
        g.run(tf, size);
    }
}