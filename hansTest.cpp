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

	
	
	
	
	return 0;
}