#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "hansTest.h"








int main(){
	
	Hero Stoner;
	
	void displayHealthBar()
	{
		float value = ((float)health/(float)maxHealth)*10;
		cout << "Health: " << health << endl;
		cout << "maxHealth: " << maxHealth << endl;
		cout << "Value: " << value << endl;
		cout << "Health: [";
		for(int i = 0; i < value; i++)
		{
			cout << "=";
		}
		for(int i = value; i < 10; i++)
		{
			cout << " ";
		}
		
		cout << "]";
	}
void displayHealthBar()
	{
		float value = ((float)health/(float)maxHealth)*10;
		cout << "Health: " << health << endl;
		cout << "maxHealth: " << maxHealth << endl;
		cout << "Value: " << value << endl;
		cout << "Health: [";
		for(int i = 0; i < value; i++)
		{
			cout << "=";
		}
		for(int i = value; i <= maxHealth/10; i++)
		{
			cout << " ";
		}
		
		cout << "]";
	}
	
	int check = 1;
		
		while(check == 1){
			for(int i = 0; i <= 10; i++)
			{
				Stoner.setHealth(i*10);
				cout << "\nif health is: " << Stoner.getHealth() << endl;
				Stoner.displayHealthBar();
			}
			Stoner.setHealth(110);
			cout << "\nif health is: " << Stoner.getHealth() << endl;
			Stoner.displayHealthBar();
			/*
			cout << "\n------------------------" << endl;
			for(int i = 0; i <= 10; i++)
			{
				Mithaldra.setHealth(i*10);
				cout << "\nFor boss health: " << Mithaldra.getHealth() << endl;
				Mithaldra.displayHealthBar();
			}
			*/
			
		cin >> check;
		}
	//this while loop checks the display health bar functions
	while(check == 1){
			
			Stoner.setMaxHealth(150);
			for(int i = 0; i <= Stoner.getMaxHealth()/10; i++)
			{
				Stoner.setHealth(i*10);
				cout << "\nif health is: " << Stoner.getHealth() << endl;
				Stoner.displayHealthBar();
			}
			
			Mithaldra.setMaxHealth(200);
			cout << "\n------------------------" << endl;
			for(int i = 0; i <= Mithaldra.getMaxHealth()/10; i++)
			{
				Mithaldra.setHealth(i*10);
				cout << "\nFor boss health: " << Mithaldra.getHealth() << endl;
				Mithaldra.displayHealthBar();
			}
		cin >> check;
		}
	
void visitMerchant(Hero& x, Merchant& y){
	int input;
	bool exitFlag = false;
	cout << "\nYou walk into a small shop by the Inn" << endl;
	while(exitFlag == false){
		cout << "How can I help you?, the merchant chirps." << endl;
		cout << "1: to buy a potion" << endl;
		cout << "2: to buy a weapon" << endl;
		cout << "0: Leave merchant" << endl;
		cin >> input;
		if (input == 1){
			y.sellPotion(x);
		} else if (input ==  2){
			y.sellWeapon(x);
		} else if(input == 0){
			exitFlag = true;
		} else {
			cout << "That is an invalid input" << endl;
		}
	}
}



class Enchanter{
private:
	string name;
public:
	Enchanter()
	{
		name = "Catlyn";
	}
	void greeting()
	{
		cout << "Care to buy an enchantment hero?" << endl;
	}
	void provideEnchantment(Hero& x)
	{
		int input;
		bool exitFlag = false;
		while(exitFlag == false)
		{	
			int currentAttack = x.getAttack();	
			cout << "\nI can empower your weapon, for a price\n" << endl;
			cout << "1: Add 5 to your weapon's attack for 500 gold" << endl;
			cout << "2: Add 10 to your weapon's attack for 1000 gold" << endl;
			cout << "3: Add 15 to your weapon's attack for 1500 gold" << endl;
			cout << "4: Add 20 to your weapon's attack for 2000 gold" << endl;
			cout << "5: Add 25 to your weapon's attack for 2500 gold" << endl;
			cout << "0: Return to town" << endl;
			cin >> input;
			if(input == 1)
			{
				if(x.decreaseGold(500) == true)
				{
					x.setAttack(currentAttack+5);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 2)
			{
				if(x.decreaseGold(1000) == true)
				{
					x.setAttack(currentAttack+10);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 3)
			{
				if(x.decreaseGold(1500) == true)
				{
					x.setAttack(currentAttack+15);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 4)
			{
				if(x.decreaseGold(2000) == true)
				{
					x.setAttack(currentAttack+20);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if(input == 5)
			{
				if(x.decreaseGold(2500) == true)
				{
					x.setAttack(currentAttack+25);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if(input == 0)
			{
				cout << "\nYou leave the tent" << endl;
				exitFlag = true;
			} else {
				cout << "\nInvalid Input" << endl;
			}
		}
	}
};



















	
	
	return 0;
}