//
//  CreatureQueue.cpp
//  assignment4
//
//  Created by Vincent Lee on 11/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "CreatureQueue.h"


CreatureQueue::CreatureQueue() {
    front = back = NULL;
}

void CreatureQueue::Add(Creature *creature) {
    if(front == NULL) {
        Node *newNode = new Node;
        front = back = newNode;
        newNode->creature = creature;
        newNode->next = NULL;
    } else {
        Node *newNode = new Node;
        back->next = newNode;
        back = newNode;
        newNode->creature = creature;
        newNode->next = NULL;
    }
}


Creature * CreatureQueue::Remove() {
    if(front == NULL) {
        return NULL;
        
    } else if (front->next != NULL) {
        Node *temp = front;
        front = front->next;
        Creature *cp = temp->creature;
        delete temp;
        return cp;

    } else {
        Creature *cp = front->creature;
        delete front;
        front = back = NULL;
        return cp;
    }
}


Creature * CreatureQueue::GetFront() {
    if(front == NULL) {
        return NULL;
    } else {
        return front->creature;
    }
}












