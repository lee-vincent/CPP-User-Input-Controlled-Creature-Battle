//
//  BlueMen.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef BlueMen_h
#define BlueMen_h

#include <stdio.h>
#include "Creature.h"
#include <string>


class BlueMen : public Creature {
    
private:
    void Construct();
    
public:
    BlueMen();
    BlueMen(std::string name, bool debug, int team);
    virtual void            Attack(Creature *opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual int             Defense();
    virtual void            Heal();
};

#endif /* BlueMen_h */
