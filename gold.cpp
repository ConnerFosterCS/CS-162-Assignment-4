#include "gold.h"

//gold constructor
Gold::Gold () {
}

//alternate gold constructor
Gold::Gold(int) {

}

//gold copy constructor
Gold::Gold(const Gold& other) {
    //cout << "Gold Copy Constructor Called" << endl;

}

///*functions*///
void Gold::percept() {
    cout << "You see a glimmer nearby." << endl;
}

void Gold::encounter() {
    cout << "You found the gold!" << endl;
}