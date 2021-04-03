#include "event.h"

#ifndef PIT_H
#define PIT_H

class Pit : public Event {
    private:
    public:
        Pit(); //pit constructor
        Pit(int); //pit alternate constructor
        Pit(const Pit& other); //pit copy constructor

        //functions
        virtual void percept();
        virtual void encounter();
};

#endif