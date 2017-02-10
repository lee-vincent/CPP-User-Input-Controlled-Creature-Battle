//
//  Die.cpp
//  
//  Created by Vincent Lee on 10/15/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//


#include "Die.h"
#include <stdlib.h>
#include <time.h>

#define  MAX_SIDES 500


//create fair 6 sided Die object
Die::Die() {
    numSides = 6;
}


//create Die object with number of sides
Die::Die(int sides) {
    int lowerLimit = 1;
    
    //prevent illegal side selections
    if(sides <= lowerLimit || sides > MAX_SIDES) {
        numSides = 6;
    } else {
        numSides = sides;
    }
}


int Die::RollDie() {
    int result = rand() % numSides + 1;
    return result;
}


int Die::GetSides() {
    return numSides;
}
