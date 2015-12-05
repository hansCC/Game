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
	
	Stoner.setGold(0);
	Stoner.setPotion(200);
	int input;
	while(1)
	{		
		cout << "You arrive at a mountain top and overlook the land of Gainesville, NOT FL" << endl;
		cout << "Where do you decide to go?" << endl;
		cout << "1: Anvil (Local town)" << endl;
		cout << "2: Deadlands (Stage 1)" << endl;
		cout << "3: Dragon's Lair (Final Stage)" << endl;
		
		cin >> input;
		if(input == 1)
		{
			HUB(Stoner, innKeeperObj, merchantObj, enchanterObj, dealerObj);	
		} else if(input == 2)
		{
			fightMonster(Stoner);
		} else if(input == 3)
		{
			Mithaldra.BossBattle(Stoner);
		} else {
			cout << "\nThat is an invalid input, please try again" << endl;
		}
		
		
		
	}
	//take in user input to know where to travel.
	/*
	while(a){
		if(input == 1){
			visitHUB(Hero, W.);
		}else if(input == 2){
			visitFinalBost();
		}
	}
	while(hub==true){
		//menu where you wanna go?
		//if you want to  go to innkepper
		visitInnKeeper(Stoner, innKeeper);	
	}
	
	*/
	//characterCreation(Stoner);
	cout << "Check outside the function" << endl;
	Stoner.printAll();
	
	cout << "Do damage to hero" << endl;
	Stoner.setHealth(5);
	Stoner.printAll();
	cout << "Go to the Inn" << endl;
	visitInn(Stoner, innKeeperObj);
	Stoner.printAll();
	cout << "Visiting the merchant" << endl;
	visitMerchant(Stoner, merchantObj);
	Stoner.printAll();
	visitEnchanter(Stoner, enchanterObj);

	Mithaldra.BossBattle(Stoner);
	return 0;
}

