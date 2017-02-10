//
//  Goblin.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Goblin.h"
#include <iostream>
#include <sstream>
#include <stdlib.h>

Goblin::Goblin() {
    Construct();
    std::string _name;
    std::ostringstream convert;
    convert << (int)rand() % 1000;
    _name = convert.str();
    this->name = "Goblin_" + _name;
    this->debug = true;
    this->team = -1;
}



Goblin::Goblin(std::string name, bool debug, int team) {
    Construct();
    this->name  = "Goblin_" + name;
    this->debug = debug;
    this->team = team;
}


void Goblin::Construct() {
    strengthPoints  = 8;
    armor           = 3;
    achilles        = false;
}


void Goblin::Attack(Creature *opponent) {  
    int attack = 0;
    attack += rand() % 6 + 1;
    attack += rand() % 6 + 1;
    
    if(debug) std::cout << name << " attacking " << opponent->GetName() << "." << " Attack = " << attack << std::endl;
    
    int opponentDefense = opponent->Defense();

    if(opponentDefense == 0) {
        //Shadow produces 0 if missed
        return;
        
    } else {
        int damage = attack - opponentDefense;
        
        if(damage < 0)
            damage = 0;
        
        bool handicap = (attack == 12) ? true : false;
        opponent->DoDamage(damage, handicap);
    }
}


void Goblin::DoDamage(int damage, bool achillesInjured) {
    int appliedDamage = damage - armor;
    
    //dont apply negative damage
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    if(debug) std::cout << name << " taking damage of = " << appliedDamage << std::endl;
    
    strengthPoints -= appliedDamage;
    
    if(debug) std::cout << name << " strengthPoints = " << strengthPoints << std::endl;
}


int Goblin::Defense() {
    int defense = 0;
    defense += rand() % 6 + 1;
    if(debug) std::cout << name << " defense = " << defense << std::endl;
    return defense;
}


void Goblin::Heal() {
    if(rand() % 10 == 0) {
        strengthPoints = 8;
    } else {
        int healPoints = 0;
        healPoints += rand() % (8 - (strengthPoints -1)) + 1;
    }
    
    if(debug) std::cout << name << " Healed. strengthPoints = " << strengthPoints << std::endl;
}
















