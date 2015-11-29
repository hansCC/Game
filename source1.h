#pragma once
#ifndef source1_h
#define source1_h

#include <string>
using namespace std;

class Hero {
private:
	int health;
	int maxHealth;
	int attack;
	string name;
	string gender;
	string weapon;
	int potion;
	int gold;
public:
	Hero() {
		cout << "I'm a hero" << endl;
		maxHealth = 10;
		health = 10;
		attack = 10;
		name = "Spencer";
		gender = "male";
		weapon = "knife";
		potion = 0;
		gold = 100;
	}
	bool decreaseGold(int x){ //untested
		if(x > gold){
			cout << "You cannot afford this" << endl;
			return false;
		} else {
			gold = gold - x;
			return true;
		}
	}
	void setMaxHealth(int x){
		maxHealth = x;
	}
	int getMaxHealth(){
		return maxHealth;
	}
	void setGender(string x) {
		gender = x;
	}
	string getGender() {
		return gender;
	}
	void setHealth(int x) {
		health = x;
	}
	int getHealth() {
		return health;
	}
	void setAttack(int x) {
		attack = x;
	}
	int getAttack() {
		return attack;
	}
	void setName(string x) {
		name = x;
	}
	string getName() {
		return name;
	}
	void setWeapon(string x) {
		weapon = x;
	}
	string getWeapon() {
		return weapon;
	}
	void setPotion(int x) {
		potion = x;
	}
	int getPotion(){
		return potion;
	}
	void incrementPotion(){
		potion++;
	}
	void setGold(int x){
		gold = x;
	}
	int getGold(){
		return gold;
	}

	void takeDamage(int x){
		health -= x;
	}
	void printAll(){ //THIS FUNCTION IS FOR TESTING
		cout << "\nHero's current parameters" << endl;
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Weapon: " << weapon << endl;
		cout << "Health: " << health << endl;
		cout << "Potions: " << potion << endl;
		cout << "Gold: " << gold << endl;
		cout << "Attack: " << attack << endl;
	}
};
	
class Merchant {
private: 
	string name;
	//string inventory[] = {"Golden Gun", "Grand Battle Axe",
	//"Bow and Arrow", "Golden Short Sword", "Bronze Pole Arm"};
	int cost;
public:
	Merchant(){
		name = "Frank";
		cost = 5;
	}
	void setName(string x){
		name = x;	
	}
	string getName(){
		return name;
	}
	void setCost(int x){
		cost = x;
	}
	int getCost(){
		return cost;
	}
	void sellPotion(Hero& x){
		x.incrementPotion();
	}
};

void visitMerchant(Hero& x, Merchant& y){
	int input;
	cout << "You walk into a small shop by the Inn" << endl;
	cout << "1: to buy a potion" << endl;
	cin >> input;
	if (input == 1){
		y.sellPotion(x);
	} else{
		cout << "That is an invalid input" << endl;
	}
}



/*
class BobRoss {
private:

	string name = "Hans is Illuminati";

	string show = "The Joy of Painting";
	string age = "dead";
public:
	string getName() {
		return name;
	}
	string show() {
		return show;
	}
	string age() {
		return name + " is " + age;
	}
};
*/
class Teacher{

private:
     string name; 
     string question;
     int answer;
     int attack;

public: 
   
     Teacher(){
          cout<< "I am yout Teacher"<<std::endl;
          string name =" Clarissa";
          string question= " What is 2+2?";
          int answer =4;
          int attack;
     }

     void setName(string x){
          name = x;
  
     }

};

void characterCreation(Hero& x){
	string tempString;
	string input = "no";
	while(input == "no" && input != "yes"){
		cout << " -------------- Welcome to *insert game name here* --------------" << endl;
		cout << "It is time to customize your character and begin your journey!" << endl;
		
		cout << "Please enter yor characters name: ";
		cin >> tempString;
		x.setName(tempString);
		
		cout << "Set gender: ";
		cin >> tempString;
		x.setGender(tempString);
		
		cout << "Select your starting weapon " << endl;
		cin >> tempString;
		x.setGender(tempString);
		cout << "Your current character is: " << endl;
		cout << "Name: " << x.getName() << endl;
		cout << "Gender: " << x.getGender() << endl;
		cout << "Weapon: " << x.getWeapon() << endl;
		cout << "If this is correct enter 'yes', otherwise enter 'no' " << endl;
		cin >> input;
	}
}

void HUB(Hero& x){ //this is incomplete
	int input;
	cout << "---------- Welcome to the city of Anvil ----------" << endl;
	cout << "Where would you like to go?" << endl;
	cout << "1: Inn" << endl;
	cin >> input;
	if (input == 1){
		
	}
}


class InnKeeper{
private:
	string name;
	
public:
	InnKeeper(){
		name = "Will";
	}
	void healPlayer(Hero& x){
		x.setHealth(x.getMaxHealth());
	}
	void greeting(){
		cout << "Hello Hero!, the Merchant bellows from behind the bar." << endl;
		cout << "Come and spend the night, free of charge for helping our city." << endl;
	}
};



void visitInn(Hero& x, InnKeeper& y){
	cout << "\n----- You enter the Leaky Cauldren looking for a place to sleep -----\n";
	y.greeting();
	y.healPlayer(x);
	cout << "After a quite night of rest you feel refreshed!" << endl;
	cout << "Your health is now full" << endl;
}




#endif
