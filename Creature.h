//
//  Creature.hpp/Users/Vincent_Lee/Desktop/Oregon State/cs162/assignment3/assignment3/Creature.h
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Creature_h
#define Creature_h

#include <stdio.h>
#include <string>
#include <stdlib.h>


class Creature {

protected:

    int         team;
    int         armor;
    int         strengthPoints;
    bool        achilles;
    std::string name;
    bool        debug;

    
public:
    virtual void            Attack(Creature *opponent)          = 0;
    virtual void            DoDamage(int damage, bool achilles) = 0;
    virtual int             Defense()                           = 0;
    std::string             GetName();
    int                     GetStrengthPoints();
    virtual void            Heal()                              = 0;
    void                    TieBreaker();
    int                     GetTeam();
};





#endif /* Creature_h */
