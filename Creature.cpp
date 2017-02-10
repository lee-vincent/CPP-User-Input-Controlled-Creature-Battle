//
//  Creature.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Creature.h"

int Creature::GetStrengthPoints() {
    return strengthPoints;
}

std::string Creature::GetName() {
    return name;
}


void Creature::TieBreaker() {
    strengthPoints = 1;
}

int Creature::GetTeam() {
    return team;
}