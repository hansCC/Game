#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"
#include <exception>

using namespace std;

int main(){
	
	Hero Stoner;
	InnKeeper innKeeperObj;
	Merchant merchantObj;
	Enchanter enchanterObj;
	FinalBoss Mithaldra;
	Dealer dealerObj;
	
	Stoner.setGold(10000);
	Stoner.setPotion(200);
	int input;
	
	while(1)
	{		
		//characterCreation(Stoner);
		cout << "\n---------- Evil Mountain ----------\n" << endl;
		cout << "You arrive at a mountain top and overlook the land of Gainesville, NOT FL" << endl;
		cout << "Where do you decide to go?" << endl;
		cout << "1: Anvil (Local town)" << endl;
		cout << "2: Deadlands (Stage 1)" << endl;
		cout << "3: The Plague (Stage 2)" << endl;
		cout << "4: Dragon's Lair (Final Stage)" << endl;
		
		cin >> input;
		if(input == 1)
		{
			HUB(Stoner, innKeeperObj, merchantObj, enchanterObj, dealerObj);	
		} else if(input == 2)
		{
			fightMonster(Stoner);
		} else if(input == 3)
		{
			stage3(Stoner);
		} else if(input == 4)
		{
			Mithaldra.BossBattle(Stoner);
		} else {
			cout << "\nThat is an invalid input, please try again" << endl;
		}	
	}
	return 0;
}

