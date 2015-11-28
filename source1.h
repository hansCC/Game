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
		health = 10;
		attack = 10;
		name = "Gyro";
		gender = "female";
		weapon = "cheese stick";
		potion = 0;
		gold = 3;
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
	string weapon;
	int potion;
	int cost;
public:
	void setName(string x)
	{
		name = x;	
	}
	string getName()
	{
		return name;
	}
	void setWeapon(string x)
	{
		name = x;	
	}
	string getWeapon()
	{
		return weapon;
	}
	void setCost(int x)
	{
		cost = x;
	}
	int getCost()
	{
		return cost;
	}
	int getInventory()
	{
		return potion; //need more
	}

};

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

void inn(Hero& x){
	
}



#endif
