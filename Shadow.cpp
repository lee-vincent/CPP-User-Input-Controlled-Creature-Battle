//
//  Shadow.cpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include "Shadow.h"
#include <stdlib.h>
#include <sstream>
#include <iostream>


Shadow::Shadow() {
    Construct();
    std::string _name;
    std::ostringstream convert;
    convert << (int)rand() % 1000;
    _name = convert.str();
    this->name = "Shadow_" + _name;
    this->debug = true;
    this->team = -1;
}


Shadow::Shadow(std::string name, bool debug, int team) {
    Construct();
    this->name = "Shadow_" + name;
    this->debug = debug;
    this->team = team;
}


void Shadow::Construct() {
    strengthPoints  = 12;
    armor           = 0;
    achilles        = false;
}


void Shadow::Attack(Creature *opponent) {
    int attack = 0;
    attack += rand() % 10 + 1;
    attack += rand() % 10 + 1;
    
    if(debug) std::cout << name << " attacking " << opponent->GetName() << "." << " Attack = " << attack << std::endl;
    
    if (achilles) {
        attack /= 2;
        if(debug) std::cout << name << " Achilles injured, Attack = " << attack << std::endl;
    }
    
    int opponentDefense = opponent->Defense();
    
    if(opponentDefense == 0) {
        //Shadow produces 0 if missed
        return;
        
    } else {
        int damage = attack - opponentDefense;
        
        if(damage < 0)
            damage = 0;
        
        opponent->DoDamage(damage, false);
    }
}



void Shadow::DoDamage(int damage, bool achillesInjured) {
    if(achillesInjured)
        this->achilles = true;
    
    int appliedDamage = damage - armor;
    
    if(appliedDamage < 0)
        appliedDamage = 0;
    
    if(debug) std::cout << name << " taking damage of = " << appliedDamage << std::endl;
    
    strengthPoints -= appliedDamage;
    
    if(debug) std::cout << name << " strengthPoints = " << strengthPoints << std::endl;
}



int Shadow::Defense() {
    if(rand() % 2 == 0) {
        if(debug) std::cout << name << " Special Defense!" << std::endl;
        return 0;
    } else {
        int defense = 0;
        defense += rand() % 6 + 1;
        if(debug) std::cout << name << " defense = " << defense << std::endl;
        return defense;
    }
}


void Shadow::Heal() {
    if(rand() % 15 == 0) {
        strengthPoints = 12;
    } else {
        int healPoints = 0;
        healPoints += rand() % (12 - (strengthPoints -1)) + 1;
    }
    
    if(debug) std::cout << name << " Healed. strengthPoints = " << strengthPoints << std::endl;
}
