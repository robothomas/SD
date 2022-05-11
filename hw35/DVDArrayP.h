#ifndef __DVDARRAYP_H__
#define __DVDARRAYP_H__

#include "DVD.h"

class DVDArrayP {
    private:
        unsigned int size;
        DVD **elt;
    public:
        static unsigned int DEFAULT_SIZE;
        DVDArrayP(unsigned int sz);
        DVDArrayP();
        DVDArrayP(/*const*/ DVDArrayP &arr);
        ~DVDArrayP();
        int getSize();
        DVDArrayP operator=(/*const*/ DVDArrayP &arr);
        void display();
        DVD &operator[](int i);
};

#endif