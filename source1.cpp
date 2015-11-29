#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>
#include "source1.h"

int main(){
	
	Hero Stoner;
	InnKeeper Will;
	Merchant Frank;
	
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
	return 0;
}



