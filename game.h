#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "room.h"

using namespace std;

#ifndef GAME_H
#define GAME_H

class Game {
    private:
        //used in game.cpp
        int start_x;
        int start_y;
        int player_x;
        int player_y;
        int quiver;
        int gold;
        int wumpus_life;
        string input;
        vector<vector<Room>> rooms;

        //used in room.cpp
        int num_wumpus;
        int num_bats;
        int num_pit;
        int num_gold;
        int num_blank;
        int id;
        int event_x;
        int event_y;
        int wum_x,wum_y,pit1_x,pit1_y,pit2_x,pit2_y,bat1_x,bat1_y,bat2_x,bat2_y,gold_x,gold_y;

    public:
        Game(int& size); //game constructor
        
        //acsessors and mutators
        void set_player_x(int x_cord);
        int get_player_x() const;
        void set_player_y(int y_cord);
        int get_player_y() const;
        
        //functions
        void run(bool& tf, int& size);
        void randomize_rooms(int& size);
        void print_info();
        void print_room(int& size, bool& tf);
        void print_room_debug(bool& tf, int& size);
        void shoot_arrow(int& size);
        void arrow_check(int& size);
        void move(int& size);
        void check_percept(int& size);
        void check_encounter(int& size);
        void move_wumpus(int& size);
        void check_end();
};

#endif