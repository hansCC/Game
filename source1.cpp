#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"
#include <exception>

using namespace std;

int main(){
	
	Hero Stoner;
	InnKeeper innKeeper;
	Merchant merchant;
	Enchanter enchanter;
	FinalBoss Mithaldra;
	
	
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
	visitInn(Stoner, innKeeper);
	Stoner.printAll();
	cout << "Visiting the merchant" << endl;
	visitMerchant(Stoner, merchant);
	Stoner.printAll();
	visitEnchanter(Stoner, enchanter);

	Mithaldra.BossBattle(Stoner);
	return 0;
}

