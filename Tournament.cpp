//
//  Tournament.cpp
//  assignment4
//
//  Created by Vincent Lee on 11/22/15.
//  Copyright © 2015 10k Bulbs. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include "Creature.h"
#include "Goblin.h"
#include "Barbarian.h"
#include "Reptile.h"
#include "BlueMen.h"
#include "Shadow.h"
#include "CreatureQueue.h"
#include "CreatureStack.h"

#define ATTACK_BONUS 0.5f
#define WIN 3.5f

void SetFighters(int fighters, CreatureQueue *queue, bool _debug, int &team);
void Battle(CreatureQueue *c1, CreatureQueue *c2, CreatureStack *loserStack, float &score1, float &score2);


int main() {
    int team = 0;
    float team_1_score = 0.0f;
    float team_2_score = 0.0f;
    bool debugOn;
    CreatureQueue *fighters_1 = new CreatureQueue;
    CreatureQueue *fighters_2 = new CreatureQueue;
    CreatureStack *losers = new CreatureStack;
    
    int fighters = 0;
    int debugMode = 1;
    
    while(true) {
        std::cout << "Do you want to run the tournament in Debug Mode? Enter 0 for NO or 1 for YES: ";
        std::cin >> debugMode;
        
        if(debugMode < 0 || debugMode > 1) {
            std::cout << "Invalid Value." << std::endl;
            continue;
        } else {
            debugOn = debugMode;
            break;
        }
    }



    std::cout << "Enter number of fighters for each team: ";
    std::cin >> fighters;
    
    std::cout << "\nFighter Menu\n";
    std::cout << "--------------\n";
    std::cout << "Goblin\t\t- 1\n";
    std::cout << "Barbarian\t- 2\n";
    std::cout << "Reptile\t\t- 3\n";
    std::cout << "BlueMen\t\t- 4\n";
    std::cout << "Shadow\t\t- 5\n";
    
    std::cout << "\nPlayer 1 - Select your fighters. Enter a number followed by a space and a name.\n\n";
    SetFighters(fighters, fighters_1, debugOn, team);
    
    std::cout << "\nPlayer 2 - Select your fighters. Enter a number followed by a space and a name.\n\n";
    SetFighters(fighters, fighters_2, debugOn, team);
    
    
    while(fighters_1->GetFront() != NULL && fighters_2->GetFront() != NULL) {
        Battle(fighters_1, fighters_2, losers, team_1_score, team_2_score);
    }
    
    
    int finisher = 1;
    if(team_1_score > team_2_score) {
        std::cout << "\n\nPlayer 1 won with a score of " << team_1_score << " to " << team_2_score << "." << std::endl;
        
        while(fighters_1->GetFront() != NULL) {
            std::cout << "Finishing in position " << finisher << " is " << fighters_1->GetFront()->GetName() << " from team " << fighters_1->GetFront()->GetTeam() << std::endl;
            fighters_1->Remove();
            finisher++;
        }
        
    } else if(team_1_score < team_2_score) {
        std::cout << "\n\nPlayer 2 won with a score of " << team_2_score << " to " << team_1_score << "." << std::endl;

        while(fighters_2->GetFront() != NULL) {
            std::cout << "Finishing in position " << finisher << " is " << fighters_2->GetFront()->GetName() << " from team " << fighters_2->GetFront()->GetTeam() << std::endl;
            fighters_2->Remove();
            finisher++;
        }
    } else {
        std::cout << "\n\nThe Tournament ended in a tie with a score of " << team_1_score << " to " << team_2_score << "." << std::endl;
        

        while(fighters_1->GetFront() != NULL) {
            std::cout << "Finishing in position " << finisher << " is " << fighters_1->GetFront()->GetName() << " from team " << fighters_1->GetFront()->GetTeam() << std::endl;
            fighters_1->Remove();
            finisher++;
        }
        
        while(fighters_2->GetFront() != NULL) {
            std::cout << "Finishing in position " << finisher << " is " << fighters_2->GetFront()->GetName() << " from team " << fighters_2->GetFront()->GetTeam() << std::endl;
            fighters_2->Remove();
            finisher++;
        }
    }
    
    if(finisher < 4 && fighters > 2) {
        while(finisher < 4) {
            Creature *cr =losers->Pop();
            std::cout << "Finishing in position " << finisher << " is " << cr->GetName() << " from team " << cr->GetTeam() << std::endl;
            finisher++;
        }
    }
    
    int displayChoice = 0;
    std::cout << "Would you like to view the losers? Enter 1 for YES or 0 for NO: ";
    std::cin >> displayChoice;
    
    if(displayChoice != 1)
        return 0;
    
    
    Creature *cp;
    
    while((cp = losers->Pop()) != NULL) {
        std::cout << "Finishing in position " << finisher << " is " << cp->GetName() << " from team " << cp->GetTeam() << std::endl;
        finisher++;
    }

    std::cout << "Game Over" << std::endl;

}



void Battle(CreatureQueue *c1, CreatureQueue *c2, CreatureStack *loserStack, float &score1, float &score2) {
    static int round = 0;
    round++;

    while(c1->GetFront()->GetStrengthPoints() > 0 && c2->GetFront()->GetStrengthPoints() > 0) {
        c1->GetFront()->Attack(c2->GetFront());
        c2->GetFront()->Attack(c1->GetFront());
        score1 += ATTACK_BONUS;
        score2 += ATTACK_BONUS;
    }
    
    if(c1->GetFront()->GetStrengthPoints() > c2->GetFront()->GetStrengthPoints()) {
        std::cout << c1->GetFront()->GetName() << " from team " << c1->GetFront()->GetTeam() << " is the winner of Round " << round << std::endl;
        c1->GetFront()->Heal();
        score1 += WIN;
        c1->Add(c1->Remove());
        loserStack->Push(c2->Remove());
        
        
    
    } else if(c2->GetFront()->GetStrengthPoints() > c1->GetFront()->GetStrengthPoints()) {
        std::cout << c2->GetFront()->GetName() << " from team " << c2->GetFront()->GetTeam() << " is the winner of Round " << round << std::endl;
        c2->GetFront()->Heal();
        score2 += WIN;
        c2->Add(c2->Remove());
        loserStack->Push(c1->Remove());
    
    } else {
        std::cout << "Round " << round << " ended in a tie between " << c1->GetFront()->GetName() << " and " << c2->GetFront()->GetName() << "." <<std::endl;
        c1->GetFront()->TieBreaker();
        c2->GetFront()->TieBreaker();
        Battle(c1, c2, loserStack, score1, score2);
    }
}



void SetFighters(int fighters, CreatureQueue *queue, bool _debug, int &team) {
    team++;

    int index = 1;
    while (index <= fighters) {
        int choice = 0;
        std::string name;
        std::cout << "Fighter " << index << ": ";
        std::cin >> choice >> name;
        
        if(choice < 1 || choice > 5) {
            std::cout << "Invalid fighter selection. Select a number 1 - 5." << std::endl;
            continue;
        }
        
        Creature *newCreature;
        
        switch(choice) {
                
            case(1): newCreature = new Goblin(name, _debug, team);
                break;
                
            case(2): newCreature = new Barbarian(name, _debug, team);
                break;
                
            case(3): newCreature = new Reptile(name, _debug, team);
                break;
                
            case(4): newCreature = new BlueMen(name, _debug, team);
                break;
                
            case(5): newCreature = new Shadow(name, _debug, team);
                break;
                
        }
        
        queue->Add(newCreature);

        index++;
    }
}








