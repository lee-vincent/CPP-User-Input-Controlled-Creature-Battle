//
//  CreatureStack.hpp
//  assignment4
//
//  Created by Vincent Lee on 11/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef CreatureStack_h
#define CreatureStack_h

#include <stdio.h>
#include "Creature.h"

struct StackNode {
    Creature    *creature;
    StackNode        *prev;
};


class CreatureStack {
    
private:
    StackNode *top;
    StackNode *bottom;
    
public:
    CreatureStack();
    void Push(Creature *);
    Creature *Pop();
    
};

#endif /* CreatureStack_h */
