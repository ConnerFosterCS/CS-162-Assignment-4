#include "event.h"

#ifndef BLANK_H
#define BLANK_H

class Blank : public Event {
    private:
    public:
        Blank(); //blank constructor
        Blank(int); //blank alternate constructor
        Blank(const Blank& other); //blank copy constructor
        
        //functions
        virtual void percept();
        virtual void encounter();
};

#endif