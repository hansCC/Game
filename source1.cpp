#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"
#include <exception>

using namespace std;

int main(){
	
	Hero Stoner;
	InnKeeper Will;
	Merchant Frank;
	Enchanter Catlyn;
	
	/*
	//take in user input to know where to travel.
	while(a){
		if(input == 1){
			visitHUB(Hero..sdaspfafas);
		}else if(input == 2){
			visitFinalBost();
		}
	
	}
	
	
	
	while(hub==true){
		//menu where you wanna go?
		//if you want to  go to innkepper
		visitInnKeeper(Stoner, Will);
		
		
		
	}
	
	*/
	
	//characterCreation(Stoner);
	cout << "Check outside the function" << endl;
	Stoner.printAll();
	
	cout << "Do damage to hero" << endl;
	Stoner.setHealth(5);
	Stoner.printAll();
	cout << "Go to the Inn" << endl;
	visitInn(Stoner, Will);
	Stoner.printAll();
	cout << "Visiting the merchant" << endl;
	visitMerchant(Stoner, Frank);
	Stoner.printAll();
	visitEnchanter(Stoner, Catlyn);

	//pls do not edit below
	FinalBoss Mithaldra; //find way to continue program with exceptions
	int input;
	int x = 0; //gold??????
	int attackOption = 0;
	int temp = 0;
	bool healthRegain = false;
	cout << "Congratulations on completing all 3 stages. Now you are ready to face the ultimate test.\n";
	cout << Stoner.getName() << " enters the Cave of Destruction. You see a weird inscription on the ground and proceed to investigate.\n";
	cout << "During investigation of the inscription, you hear a loud roar.\n";
	cout << "Out of the darkness, a one-eyed creature drops from the ceiling, blocking your escape.\n";
	cout << "You look for another exit, but there is no way out. You \n";
	cout << "\n";
	cout << "1. Play dead.\n";
	cout << "2. Hide in the shadows.\n";
	cout << "3. Fight.\n";
	cout << "\n";
	try
	{
		cin >> input;
	}
	catch(exception e)
	{
		cout << "Invalid input. Please enter a number.\n";
	}

	if(input == 1)
	{
		cout << "Creature approaches your body, you notice that this creature is a mythical dragon, thought to be extinct.\n";
		cout << "The creature, not believing you are dead, eats you.\n";
		cout << "Now, you are dead. Return to the HUB and try again.\n";
		cout << "You have lost " << x << " gold.\n"; 
		Mithaldra.HeroDeath(Stoner);
		//return to HUB
	}
	else if(input == 2)
	{
		cout << "Creature looks around and moves deeper into the cave. You notice that this creature is a mythical dragon, thought to be extinct.\n";
		cout << "The dragon, knowing you are still in the cave, shoots a fireball into the air to create light.\n";
		cout << "The fireball startles you and you are unable to move. The dragon can now see you and runs at you.\n";
		cout << "Still paralyzed with fear, you do not move and the dragon crushes you.\n";
		cout << "Now, you are dead. Return to the HUB and try again.\n";
		cout << "You have lost " << x << " gold.\n"; 
		Mithaldra.HeroDeath(Stoner);
		//return to HUB
	}
	else if(input == 3)
	{
		cout << "You draw your weapon. The creature moves towards you, and you notice that it is a mythical dragon, thought to be extinct.\n";
		cout << "The dragon roars in your direction, and you brace yourself for battle.\n";
		while(Mithaldra.getHealth() != 0 && Stoner.getHealth() != 0)
		{
			cout << "Your health is: " << Stoner.getHealth() <<endl;
			cout << "The dragon's health is: " << Mithaldra.getHealth() << endl;
			cout << "\n";
			cout << "What would you like to do?\n";
			cout << "1. Use a potion.\n";
			cout << "2. Attack.\n";
			cout << "\n";
			try
			{
				cin >> attackOption;
			}
			catch(exception e)
			{
				cout << "Invalid input. Please enter a number.\n";
			}

			if(attackOption == 1)
			{
				if(Stoner.getPotion() != 0)
				{
					temp = Stoner.getHealth(); 
					Stoner.setHealth(temp + 1); //check how much potions regain
					temp = Stoner.getPotion();
					Stoner.setPotion(temp - 1);
				}
			}
			if(attackOption == 2)
			{
				if(Mithaldra.dodgeChance() >= 95)
				{
					cout << "The dragon dodged your attack.\n";
				}
				else{
					cout << "You do " << Stoner.getAttack() << " damage to the dragon.\n";
					temp = Mithaldra.getHealth();
					Mithaldra.setHealth(temp-Stoner.getAttack());
					cout << "The dragon's health is now: " << Mithaldra.getHealth() << "\n";
				}
				if(Mithaldra.getHealth() < 8 && !healthRegain){
					cout << "The dragon flies to the ceiling and eats some kind of glowing berries. These berries restore some of its health \n";
					temp = Mithaldra.getHealth();
					Mithaldra.setHealth(temp + 5);
					cout << "The dragon's health is now: " << Mithaldra.getHealth() << "\n";
					healthRegain = true;
				}
			}

			temp = Mithaldra.attackNum();

			if(temp == 1){
				Mithaldra.Attack1(Stoner);
			}
			if(temp == 2){
				Mithaldra.Attack2(Stoner);
			}
			if(temp == 3){
				Mithaldra.Attack3(Stoner);
			}





		}




		// cout << "Now, you are dead. Return to the HUB and try again.\n";
		// cout << "You have lost " << x << " gold.\n"; 
		// Mithaldra.HeroDeath(Stoner);
		//return to HUB
	}
	else
	{
		cout << "Invalid input. Try again.\n";
		cin >> input;
	}


	return 0;
}



