#include "bats.h"

//bats constructor
Bats::Bats () {
}

//alternate bats constructor
Bats::Bats(int) {

}

//bats copy constructor
Bats::Bats(const Bats& other) {
    //cout << "Bats Copy Constructor Called" << endl;

}

///*functions*///
void Bats::percept() {
    cout << "You hear wings flapping." << endl;
}   

void Bats::encounter() {
    cout << "You ran into a super bat! It picked you up and swiftly flew you into a new room. (press enter)" << endl;
}