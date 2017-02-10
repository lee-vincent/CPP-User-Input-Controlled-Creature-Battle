//
//  CreatureStack.cpp
//  assignment4
//
//  Created by Vincent Lee on 11/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "CreatureStack.h"


CreatureStack::CreatureStack() {
    top = bottom = NULL;
}

void CreatureStack::Push(Creature *creature) {
    if(bottom == NULL) {
        StackNode *newNode = new StackNode;
        newNode->creature = creature;
        top = bottom = newNode;
        newNode->prev = NULL;
    } else {
        StackNode *newNode = new StackNode;
        newNode->creature = creature;
        newNode->prev = top;
        top = newNode;
    }
}


Creature * CreatureStack::Pop() {
    if(top == NULL) {
        return NULL;

    } else if( top->prev != NULL) {
        StackNode *temp = top;
        top = top->prev;
        Creature *cp = temp->creature;
        delete temp;
        return cp;
    } else {
        Creature *cp = top->creature;
        delete top;
        top = bottom = NULL;
        return cp;
    }
    
    return NULL;
}