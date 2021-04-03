#include "event.h"
#include "blank.h"
#include "wumpus.h"
#include "bats.h"
#include "pit.h"
#include "gold.h"

#ifndef ROOM_H
#define ROOM_H

class Room {
    private:
    
    public:
        int id;
        int check;
        Event* e; //event pointer

        Room(); //room constructor
        Room(const Room& other); //room copy constructor
        
        //acsessors and mutators
        void print_check();
        void get_blank();
        void get_wumpus(int& num_wumpus);
        void get_bats(int& num_bats);
        void get_pit(int& num_pit);
        void get_gold(int& num_gold);
        int return_event();

        //functions
        void call_percept();
        int call_encounter();
        int check_blank();

};

#endif