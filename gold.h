#include "event.h"

#ifndef GOLD_H
#define GOLD_H

class Gold : public Event{
    private:
    public:
        Gold(); //gold constructor
        Gold(int); //gold alternate constructor
        Gold(const Gold& other); //gold copy constructor

        //functions
        virtual void percept();
        virtual void encounter();
};

#endif