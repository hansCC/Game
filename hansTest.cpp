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
	
	
	return 0;
}