#include "event.h"

#ifndef BATS_H
#define BATS_H

class Bats : public Event {
    private:
    public:
        Bats(); //bats constructor
        Bats(int); //bats alternate constructor
        Bats(const Bats& other); //bats copy constructor

        //functions
        virtual void percept();
        virtual void encounter();
};

#endif