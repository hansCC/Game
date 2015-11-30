#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "hansTest.h"








int main(){
	
	Hero Stoner;
	characterCreation(Stoner);
	cout << "Check outside the function" << endl;
	Stoner.printAll();
	
	
	
class Enemy{
private:
	virtual int health;
	virtual int maxHealth;
	
public:
	virtual void attack(Hero& x);
};


class Tiger: public Enemy {
private:
	health = 10;
	maxHealth = 10;
public:
	void attack(Hero& x){
		x.takeDamage(10);
	}
};


	
	
	
	
	return 0;
}