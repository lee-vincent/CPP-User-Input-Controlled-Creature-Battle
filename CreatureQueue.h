//
//  CreatureQueue.hpp
//  assignment4
//
//  Created by Vincent Lee on 11/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef CreatureQueue_h
#define CreatureQueue_h

#include <stdio.h>
#include "Creature.h"

struct Node {
    Creature    *creature;
    Node        *next;
};



class CreatureQueue {
    
private:
    Node *front;
    Node *back;
    
public:
    CreatureQueue();
    void Add(Creature *);
    Creature *Remove();
    Creature *GetFront();
};


#endif /* CreatureQueue_h */
