//
//  Shadow.hpp
//  assignment3
//
//  Created by Vincent Lee on 11/8/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Shadow_h
#define Shadow_h

#include <stdio.h>
#include "Creature.h"
#include <string>


class Shadow : public Creature {
    
private:
    void Construct();
    
public:
    Shadow();
    Shadow(std::string name, bool debug, int team);
    virtual void            Attack(Creature *opponent);
    virtual void            DoDamage(int damage, bool achilles);
    virtual int             Defense();
    virtual void            Heal();
};
#endif /* Shadow_h */
