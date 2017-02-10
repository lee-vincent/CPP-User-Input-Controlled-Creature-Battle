////
////  main.cpp
////  assignment3
////
////  Created by Vincent Lee on 11/8/15.
////  Copyright © 2015 10k Bulbs. All rights reserved.
////
//
//#include <iostream>
//#include <sstream>
//#include <stdlib.h>
//#include "Creature.h"
//#include "Goblin.h"
//#include "Barbarian.h"
//#include "Reptile.h"
//#include "BlueMen.h"
//#include "Shadow.h"
//
//
//void Battle(Creature &, Creature &);
//void PrintWinner(Creature &);
//
//int main() {
//    
//
//    
//    srand((unsigned)time(0));
//
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Goblin vs. Goblin Battle " << i << std::endl;
//        Goblin *gb1 = new Goblin;
//        Goblin *gb2 = new Goblin;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Goblin vs. Barbarian Battle " << i << std::endl;
//        Goblin *gb1 = new Goblin;
//        Barbarian *gb2 = new Barbarian;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Goblin vs. BlueMen Battle " << i << std::endl;
//        Goblin *gb1 = new Goblin;
//        BlueMen *gb2 = new BlueMen;
//        Battle(*gb1, *gb2);
//    }
//
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Goblin vs. Reptile Battle " << i << std::endl;
//        Goblin *gb1 = new Goblin;
//        Reptile *gb2 = new Reptile;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Goblin vs. Shadow Battle " << i << std::endl;
//        Goblin *gb1 = new Goblin;
//        Shadow *gb2 = new Shadow;
//        Battle(*gb1, *gb2);
//    }
//    
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Barbarian vs. Reptile Battle " << i << std::endl;
//        Barbarian *gb1 = new Barbarian;
//        Reptile *gb2 = new Reptile;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Barbarian vs. BlueMen Battle " << i << std::endl;
//        Barbarian *gb1 = new Barbarian;
//        BlueMen *gb2 = new BlueMen;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Barbarian vs. Barbarian Battle " << i << std::endl;
//        Barbarian *gb1 = new Barbarian;
//        Barbarian *gb2 = new Barbarian;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Barbarian vs. Shadow Battle " << i << std::endl;
//        Barbarian *gb1 = new Barbarian;
//        Shadow *gb2 = new Shadow;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Reptile vs. Reptile Battle " << i << std::endl;
//        Reptile *gb1 = new Reptile;
//        Reptile *gb2 = new Reptile;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Reptile vs. BlueMen Battle " << i << std::endl;
//        Reptile *gb1 = new Reptile;
//        BlueMen *gb2 = new BlueMen;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "Reptile vs. Shadow Battle " << i << std::endl;
//        Reptile *gb1 = new Reptile;
//        Shadow *gb2 = new Shadow;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "BlueMen vs. BlueMen Battle " << i << std::endl;
//        BlueMen *gb1 = new BlueMen;
//        BlueMen *gb2 = new BlueMen;
//        Battle(*gb1, *gb2);
//    }
//    
//    for(int i = 0; i < 100; i++) {
//        std::cout << "BlueMen vs. Shadow Battle " << i << std::endl;
//        BlueMen *gb1 = new BlueMen;
//        Shadow *gb2 = new Shadow;
//        Battle(*gb1, *gb2);
//    }
//    
//    
//    
//    
//    return 0;
//}
//
//
//void Battle(Creature &opp_1, Creature &opp_2) {
//    bool switchAttacker = true;
//    
//    while(opp_1.GetStrengthPoints() > 0 && opp_2.GetStrengthPoints() > 0) {
//    
//        if(switchAttacker) {
//            opp_1.Attack(opp_2);
//        } else {
//            opp_2.Attack(opp_1);
//        }
//        
//        switchAttacker = !switchAttacker;
//    }
//    
//     PrintWinner(opp_1.GetStrengthPoints() > opp_2.GetStrengthPoints() ? opp_1 : opp_2);
//    
//    
//}
//
//
//void PrintWinner(Creature &winner) {
//    std::cout << "The winner is " << winner.ToString() << '\n' << std::endl;
//}
//
//
