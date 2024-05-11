//
#ifndef DIE_H
#define DIE_H

#include <cstdlib>

class Die
{

public:
    int roll();

private: 
    int sides{6};

};
#endif