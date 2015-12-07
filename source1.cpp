#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"
#include <exception>

using namespace std;

int main(){
	//create all objects
	Hero Stoner;
	InnKeeper innKeeperObj;
	Merchant merchantObj;
	Enchanter enchanterObj;
	FinalBoss Mithaldra;
	Dealer dealerObj;
	
	Stoner.setGold(0);
	Stoner.setPotion(200);
	string input;
	/*
	This while loop allows the user to navigate between levels.
	It also serves as the respawn point in the event the user dies.
	*/
	characterCreation(Stoner);
	while(1)
	{		
		
		cout << "\n---------- Evil Mountain ----------\n" << endl;
		cout << "You arrive at a mountain top and overlook the land of Gainesville, NOT FL" << endl;
		cout << "Where do you decide to go?" << endl;
		cout << "1: Anvil (Local town)" << endl;
		cout << "2: Deadlands (Stage 1)" << endl;
		cout << "3: The Plague (Stage 2)" << endl;
		cout << "4: Dragon's Lair (Final Stage)" << endl;
		
		cin >> input; //Take in input to know where to go
		if(input.compare("1") == 0) //Go to the town(HUB area)
		{
			HUB(Stoner, innKeeperObj, merchantObj, enchanterObj, dealerObj);	
		} else if(input.compare("2") == 0)//Go to Deadlands
		{
			fightMonster(Stoner);
		} else if(input.compare("3") == 0)//Go to The Plague
		{
			stage3(Stoner);
		} else if(input.compare("4") == 0)//Face the final boss
		{
			Mithaldra.BossBattle(Stoner);
		} else { //error capture
			cout << "\nThat is an invalid input, please try again" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
	}
	return 0;
}

