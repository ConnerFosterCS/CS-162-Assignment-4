#include "game.h"

///*game constructor*///
Game::Game (int& size) {
    srand (time(NULL));
    this -> start_x = 0;
    this -> start_y = 0;
    this -> player_x = 0;
    this -> player_y = 0;
    this -> num_wumpus = 1;
    this -> num_bats = 2;
    this -> num_pit = 2;
    this -> num_gold = 1;
    this -> num_blank = 1;
    this -> quiver = 3;
    this -> gold = 0;
    this -> wumpus_life = 1;
    this -> input = "blank";

    for(int i = 0; i < size; i++) {
        vector<Room>tmp;
        for(int j = 0; j < size; j++) {
            tmp.push_back(Room());
        } rooms.push_back(tmp);
    }
}

///*acsessors and mutators*///
void Game::set_player_x(int x_cord) {
    this -> player_x = x_cord;
}

int Game::get_player_x() const{
    return player_x;
}

void Game::set_player_y(int y_cord) {
    this -> player_y = y_cord;
}

int Game::get_player_y() const{
    return player_y;
}

///*functions*///
/*********************************************************************
** Function: run
** Description: This function runs the game in the odrder it is supposed to be ran.
** Parameters: tf, size
** Pre-Conditions: user chooses game mode and size of cave.
** Post-Conditions: game runs in correct order
*********************************************************************/ 
void Game::run(bool& tf, int& size){
    this -> start_x = rand()%size;
    this -> start_y = rand()%size;
    player_x = start_x;
    player_y = start_y;
    while ((num_wumpus + num_bats + num_pit + num_gold) > 0) {
        randomize_rooms(size);
    } 
    while (true) {
        print_info();
        check_percept(size);
        print_room(size, tf);
        check_encounter(size);
        shoot_arrow(size);
        check_end();
        cout << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << "\n" <<  "\n" << "\n" << "\n" << "\n" << "\n" << "\n" <<  "\n" << "\n" << "\n" << "\n" << "\n" << "\n" << endl;
    }
}

/*********************************************************************
** Function: randomize_rooms
** Description: This function randomly generates rooms to fill for the cave vector
** Parameters: size
** Pre-Conditions: the size of the cave is set
** Post-Conditions: rooms are randomly choosen for cave so game is different every time.
*********************************************************************/ 
void Game::randomize_rooms(int& size) {
    event_x = rand()%size;
    event_y = rand()%size;
    //cout << event_x << endl;
    //cout << event_y << endl;
    if (num_wumpus == 1) {
        rooms[event_x][event_y].get_wumpus(num_wumpus);
        wum_x = event_x;
        wum_y = event_y;
        cout << "wum xy: " << wum_x << wum_y << endl;
    } else if (num_bats > 0) {
        rooms[event_x][event_y].get_bats(num_bats);
        if(num_bats == 1) {
            bat1_x = event_x;
            bat1_y = event_y;
            cout << "bat1 xy: " << bat1_x << bat1_y << endl;
        } else {
            bat2_x = event_x;
            bat2_y = event_y;
            cout << "bat2 xy: " << bat2_x << bat2_y << endl;
        }
    } else if (num_pit > 0) {
        rooms[event_x][event_y].get_pit(num_pit);
        if(num_pit == 1) {
            pit1_x = event_x;
            pit1_y = event_y;
            cout << "pit1 xy: " << pit1_x << pit1_y << endl;
        } else {
            pit2_x = event_x;
            pit2_y = event_y;
            cout << "pit2 xy: " << pit2_x << pit2_y << endl;
        }
    } else if (num_gold == 1) {
        rooms[event_x][event_y].get_gold(num_gold);
        gold_x = event_x;
        gold_y = event_y;
        cout << "gold xy: " << gold_x << gold_y << endl;
    }
}

/*********************************************************************
** Function: print info
** Description: This function prints valueable info for the user to be aware of durring their game.
** Post-Conditions: number of arrows left and ammount of gold collected reports to screen above game board.
*********************************************************************/ 
void Game::print_info() {
    cout << "///" << quiver << " arrows///" << endl;
    cout << "/// " << gold << " gold ///" << endl;
} 

/*********************************************************************
** Function: print_room
** Description: This function prints the cave to the screen without cheats in the normal game mode.
** Parameters: tf, size
** Pre-Conditions: user chooses regular game mode and size of cave.
** Post-Conditions: a grid is printed to the screen in the width and length choosen by user
*********************************************************************/ 
void Game::print_room(int& size, bool& tf) {
    if (tf == true) {
        print_room_debug(tf, size);
    } else {
        for (int i = 0; i < 2*size+1; i++) {
            for (int j = 0; j < 2*size+1; j++) {
                if (i%2 == 0 && j%2 == 0) {
                    cout << '+';
                } else if (i%2 == 0 && j%2 != 0) {
                    cout << "-";
                } else if (i%2 != 0 && j%2 == 0) {
                    cout << "|";
                } else if (i%2 != 0 && j%2 != 0) {
                    int x = (j-1)/2;
                    int y = (i-1)/2;
                
                    if (x == player_x && y == player_y) {
                        cout << '*';
                    } else {
                        cout << ' ';
                    }
                }
            } cout << endl;
        }
    }
}

/*********************************************************************
** Function: print_room_debug
** Description: This function prints the cave to the screen with cheats.
** Parameters: tf, size
** Pre-Conditions: user chooses the debugger game mode and size of cave.
** Post-Conditions: a grid is printed to the screen in the width and length choosen by user and icons for the event are also displayed.
*********************************************************************/ 
void Game::print_room_debug(bool& tf, int& size) {
    //cout << "AKJFBKFHVAWFOBAKFHVAKSFBk" << endl;
    for (int i = 0; i < 2*size+1; i++) {
        for (int j = 0; j < 2*size+1; j++) {
            int x = (j-1)/2;
            int y = (i-1)/2;
            if (i%2 == 0 && j%2 == 0) {
                cout << '+';
            } else if (i%2 == 0 && j%2 != 0) {
                cout << "-";
            } else if (i%2 != 0 && j%2 == 0) {
                cout << "|";
            } else if (x == wum_x && y == wum_y) {
                cout << 'W';
            } else if (x == bat1_x && y == bat1_y) {
                cout << 'B';
            } else if (x == bat2_x && y == bat2_y) {
                cout << 'B';
            } else if (x == pit1_x && y == pit1_y) {
                cout << 'P';
            } else if (x == pit2_x && y ==pit2_y) {
                cout << 'P';
            } else if (x == gold_x && y == gold_y) {
                cout << 'G';
            } else if (i%2 != 0 && j%2 != 0) {
                if (x == player_x && y == player_y) {
                    cout << '*';
                } else {
                    cout << ' ';
                }
            }
        } cout << endl;
    }
}

/*********************************************************************
** Function: shoot_arrow
** Description: This function checks if the user has put a space before their direction to see if they chose to shoot an arrow.
** Parameters: size
** Pre-Conditions: user puts space before key input.
** Post-Conditions: an arrow is shot in the direction of the users choosing.
*********************************************************************/ 
void Game::shoot_arrow(int& size) {
    getline(cin, input);
    if (quiver == 0 && (input == " w" || input == " a" || input == " s" || input == " d")) {
        cout << "You do not have any arrows to shoot." << endl;
        shoot_arrow(size);
    } else if (input == " w") {
        quiver--;
        //cout << "You shot an arrow north "<< endl;
        arrow_check(size);
        shoot_arrow(size);
    } else if (input == " a") {
        quiver--;
        //cout << "You shot an arrow west" << endl;
        arrow_check(size);
        shoot_arrow(size);
    } else if (input == " s") {
        quiver--;
        //cout << "You shot an arrow south" << endl;
        arrow_check(size);
        shoot_arrow(size);
    } else if (input == " d") {
        quiver--;
        //cout << "You shot an arrow east" << endl;
        arrow_check(size);
        shoot_arrow(size);
    } else 
        move(size);
}

/*********************************************************************
** Function: arrow_check
** Description: This function checks for the wumpus in the direction of the arrow shot
** Parameters: size
** Pre-Conditions: wumpus is on the map and user shoots and arrow
** Post-Conditions: if wumpus is hit it dies. if wumpus misses it might move.
*********************************************************************/ 
void Game::arrow_check(int& size) {
    for (int x = 1; x <= 3; x++) {
        if (input == " a") {
            if (player_x == (wum_x+x) && player_y == wum_y) { //checks left position
                cout << "You shot and killed the wumpus now you must return to your starting position with the gold." << endl;
                wumpus_life = 0;
                break;
            }
        } if (input == " d") {
            if (player_x == (wum_x-x) && player_y == wum_y) { //checks right position
                cout << "You shot and killed the wumpus now you must return to your starting position with the gold." << endl;
                wumpus_life = 0;
                break;
            }
        } if (input == " w") {
            if (player_y == (wum_y+x) && player_x == wum_x) { // checks top position
                cout << "You shot and killed the wumpus now you must return to your starting position with the gold." << endl;
                wumpus_life = 0;
                break;
            }
        } if (input == " s") {
            if (player_y == (wum_y-x) && player_x == wum_x) { // checks bottom position
                cout << "You shot and killed the wumpus now you must return to your starting position with the gold." << endl;
                wumpus_life = 0;
                break;
            }
        }
    } if (wumpus_life == 1) {
        move_wumpus(size);
    }
}

/*********************************************************************
** Function: move
** Description: This function checks if the use enters w, a, s, d, to see if they want to move
** Parameters: tf, size
** Pre-Conditions: user enters w, a, s, d
** Post-Conditions: user (*) moved on cave grid
*********************************************************************/ 
void Game::move(int& size) {
    if (input == "w") {
        if (player_y == 0) {
            //cout << "You can not move here" << endl;
            shoot_arrow(size);
        } else
            this -> player_y--;
    } else if (input == "a") {
        if (player_x == 0) {
            //cout << "You can not move here" << endl;
            shoot_arrow(size);
        } else
            this -> player_x--;
    } else if (input == "s") {
        if (player_y == size-1) {
            //cout << "You can not move here" << endl;
            shoot_arrow(size);
        } else
            this -> player_y++;
    } else if (input == "d") {
        if (player_x == size-1) {
            //cout << "You can not move here" << endl;
            shoot_arrow(size);
        } else
            this -> player_x++;
    }
}

/*********************************************************************
** Function: check_percept
** Description: This function checks if there is an event in the surrounding rooms and notifies the player
** Parameters: size
** Pre-Conditions: user moves next to an event.
** Post-Conditions: a wisper is displayed ont he users screen.
*********************************************************************/ 
void Game::check_percept(int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (player_x == (i-1) && player_y == j) { //checks left position
                rooms[i][j].call_percept();
            } else if (player_x == (i+1) && player_y == j) { //checks right position
                rooms[i][j].call_percept();
            } else if (player_y == (j-1) && player_x == i) { // checks top position
                rooms[i][j].call_percept();
            } else if (player_y == (j+1) && player_x == i) { // checks bottom position
                rooms[i][j].call_percept();
            }
        }
    }
}

/*********************************************************************
** Function: check_percept
** Description: This function checks if the user moves into an event room
** Parameters: size
** Pre-Conditions: user moves into an event.
** Post-Conditions: the corresponding event is ran.
*********************************************************************/ 
void Game::check_encounter(int& size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (player_x == i && player_y == j) {
                int check = rooms[i][j].call_encounter();
                if (check == 1) {
                    player_x = rand()%size;
                    player_y = rand()%size;
                } else if (check == 2) {
                    gold++;
                }
            }
        }
    }
}

/*********************************************************************
** Function: move_wumpus
** Description: This function moves the wumpus on a 75% chance if the user misses their arrow.
** Parameters: size
** Pre-Conditions: user misses and arrow
** Post-Conditions: wumpus might move.
*********************************************************************/ 
void Game::move_wumpus(int& size) {
    int x = rand()%size;
    int y = rand()%size;
    int z = rand()%4;
    cout << "Your arrow missed" << endl;
    if (z == 1 || 2 || 3) {
        if (rooms[x][y].check_blank() == 0) {
        wum_x = x;
        wum_y = y;
        cout << "Your shot woke up the wumpus and it ran to a different room. (hit enter)" << endl;
        } else
            move_wumpus(size);
    } else {
        cout << "Your shot did not wake up the wumpus. (hit enter)" << endl;
    }
}

/*********************************************************************
** Function: check_end
** Description: This function checks if the user has met all requireents to win the game.
** Post-Conditions: either the game ends or the game continues.
*********************************************************************/ 
void Game::check_end() {
    if (player_x == start_x && player_y == start_y && wumpus_life == 0 && gold > 0) {
        cout << "Congratulations you won!" << endl;
        exit(0);
    }
}