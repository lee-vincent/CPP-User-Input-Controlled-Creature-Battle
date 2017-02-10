//
//  Goblin.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Goblin_h
#define Goblin_h

#include <stdio.h>
#include <string>
#include "Creature.h"


class Goblin : public Creature {
    
private:
    void Construct();
    
public:
    Goblin();
    Goblin(std::string name, bool debug, int team);
    virtual void            Attack(Creature *opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual int             Defense();
    virtual void            Heal();
};

#endif /* Goblin_h */
