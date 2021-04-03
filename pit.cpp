#include "pit.h"

//pit constructor
Pit::Pit () {
}

//alternate pit constructor
Pit::Pit(int) {

}

//pit copy constructor
Pit::Pit(const Pit& other) {
    //cout << "Pit Copy Constructor Called" << endl;

}

///*functions*///
void Pit::percept() {
    cout << "You feel a breeze." << endl;
}

void Pit::encounter() {
    cout << "You steped into the room and it was trapped with a bottomless pit." << endl;
    cout << "GAME OVER" << endl;
    exit(0);
}