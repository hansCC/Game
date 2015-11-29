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
	bool decreaseGold(int x){ //Checks to see if the hero can afford to buy something.
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
	void incPotion(){
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
		cout << "Max Health" << maxHealth << endl;
		cout << "Potions: " << potion << endl;
		cout << "Gold: " << gold << endl;
		cout << "Attack: " << attack << endl;
	}
};
	
class Merchant {
private: 
	string name;
	string inventory[5];
	//, "Grand Battle Axe","Bow and Arrow", "Golden Short Sword", "Bronze Pole Arm"
	int cost;
public:
	Merchant(){
		name = "Frank";
		cost = 5;
		inventory[0] = "Golden Gun";
		inventory[1] = "Grand Battle Axe";
		inventory[2] = "Bow and Arrow";
		inventory[3] = "Golden Short Sword";
		inventory[4] = "Bronze Pole Arm";
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
		x.incPotion();
	}
	void sellWeapon(Hero& x){ 
		int input;
		cout << "Which weapon would you like hero?" << endl;
		if(x.decreaseGold(25)==true){
			for (int i = 0; i < 5; i++){
				cout << i << ": " << inventory[i] << endl;
			}
			cin >> input;
			if(input == 0){
				x.setWeapon(inventory[0]);
			} else if(input == 1){
				x.setWeapon(inventory[0]);
			} else if(input == 2){
				x.setWeapon(inventory[0]);
			} else if(input == 3){
				x.setWeapon(inventory[0]);
			} else if(input == 4){
				x.setWeapon(inventory[0]);
			}
		} else {
			cout << "I'm afraid you don't have the hold to purchase that item." << endl;
		}
	}
};

void visitMerchant(Hero& x, Merchant& y){
	int input;
	cout << "You walk into a small shop by the Inn" << endl;
	cout << "1: to buy a potion" << endl;
	cout << "2: to buy a weapon" << endl;
	cin >> input;
	if (input == 1){
		y.sellPotion(x);
	} else if (input ==  2){
		y.sellWeapon(x);
	} else {
		cout << "That is an invalid input" << endl;
	}
}


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

class Enchanter{
private:
	string name;
public:
	Enchanter(){
		name = "Catlyn";
	}
	void greeting(){
		cout << "Care to buy an enchantment hero?" << endl;
	}
	void provideEnchantment(Hero& x){//untested
		int input;
		int currentAttack = x.getAttack();
		cout << "I can empower your weapon, for a price" << endl;
		cout << "1: Add 5 to your weapon's attack" << endl;
		cout << "2: Add 10 to your weapon's attack" << endl;
		cout << "3: Add 15 to your weapon's attack" << endl;
		cout << "4: Add 20 to your weapon's attack" << endl;
		cout << "5: Add 25 to your weapon's attack" << endl;
		cin >> input;
		if(input == 1 && x.decreaseGold(500) == true){
			x.setAttack(currentAttack+5);
		}else if (input == 2 && x.decreaseGold(1000) == true){
			x.setAttack(currentAttack+10);
		}else if (input == 3 && x.decreaseGold(1500) == true){
			x.setAttack(currentAttack+15);
		}else if (input == 4 && x.decreaseGold(2000) == true){
			x.setAttack(currentAttack+20);
		}else if(input == 5 && x.decreaseGold(2500) == true){
			x.setAttack(currentAttack+25);
		}else if(input > 5){
			cout << "That is an invalid input" << endl;
		} else {
			
		}
	}
};

void visitEnchanter(Hero& x, Enchanter& y){
	cout << "You walk over to a small tent near the outskirts of town" << endl;
	cout << "An intense aroma of incense washes over you as you pull aside the entrance flap." << endl;
	cout << "From the depths of the tent you hear a soft ominous voice" << endl;
	y.greeting();
	y.provideEnchantment(x);
}

class FinalBoss {
private: 
	string name
	int attack1
	int attack2
	int attack3
	int health
	int regainHealth

public:
	void setName()
	{
		name = "Mithralda";
	}
	string getName()
	{
		return name;
	}
	void setHealth()
	{
		health = 15;
	}
	int getHealth()
	{
		return health;
	}
	void Attack1(Hero& x)
	{
		x.takeDamage(3);
	}
	void Attack2(Hero& x)
	{
		x.takeDamage(2);
	}
	void Attack3(Hero& x)
	{
		x.takeDamage(1);
	}	
	void HeroDeath(Hero& x) 
	{
		//return to HUB
	}
	void GameEnd()
	{
		//dialogue
	}

};

#endif
