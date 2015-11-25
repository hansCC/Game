#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"








int main(){
	
	Hero Stoner;
	cout << Stoner.getGender() << " BEFORE" << endl;
	Stoner.setGender("male");
	cout << Stoner.getGender() << " AFTER" << endl;
	return 0;
}