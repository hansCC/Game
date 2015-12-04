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
	
	
	return 0;
}