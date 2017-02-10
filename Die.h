//
//  Die.hpp
//
//  Created by Vincent Lee on 10/15/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#ifndef Die_h
#define Die_h

class Die {
    
    protected:
    int         numSides;
   
        
    public:
        Die();      ///default constructor initializes sides to 6
        
        Die        (int sides); //initializes sides to what user enters
        
        int        RollDie();
        
        int        GetSides();
    
};

#endif /* Die_hpp */
