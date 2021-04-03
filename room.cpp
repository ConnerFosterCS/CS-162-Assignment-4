#include "room.h"

///*room constructor*///
Room::Room () {
    //cout << "def called" << endl;
    this -> e = NULL;
    this -> id = 0;
    this -> check = 0;
}

///*room copy constructor*///
Room::Room(const Room& other) {
    //cout << "Room Copy Constructor Called" << endl;
}

///*acsessors and mutators*///
void Room::print_check() {
    cout << "test ";
}

void Room::get_blank() {
    e = new Blank();
    this -> id = 0;
}

void Room::get_wumpus(int& num_wumpus) {
    //cout << "wumpus test" << endl;
    e = new Wumpus();
    num_wumpus--;
    this -> id = 1;
}

void Room::get_bats(int& num_bats) {
    //cout << "bats test" << endl;
    e = new Bats();
    num_bats--;
    this -> id = 2;
    check = 1;
}

void Room::get_pit(int& num_pit) {
    //cout << "pit test" << endl;
    e = new Pit();
    num_pit--;
    this -> id = 3;
}

void Room::get_gold(int& num_gold) {
    //cout << "gold test" << endl;
    e = new Gold();
    num_gold--;
    this -> id = 4;
    check = 2;
}

int Room::return_event() {
    //cout << "return event called" << endl;
    //cout << "id is " << id << endl;
    return id;
}

//*functions*//
void Room::call_percept() {
    if(e != NULL)
        e -> percept();
}

int Room::call_encounter() {
    if(e != NULL)
        e -> encounter();
    return check;
}

int Room::check_blank() {
    if(e == NULL)
        return 0;
    else
        return 9;
}