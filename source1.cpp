#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"








int main(){
	
	Hero Stoner;
	characterCreation(Stoner);
	cout << "Check outside the function" << endl;
	Stoner.printAll();
	return 0;
}