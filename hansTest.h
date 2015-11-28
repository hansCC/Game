#pragma once
#ifndef hansTest_h
#define hansTest_h

#include <string>
using namespace std;

class Hero {
private:
	int health;
	int attack;
	string name;
	string gender;
	string weapon;
	int potion;
	int gold;
public:
	Hero() {
		cout << "I'm a hero" << endl;
		int health = 10;
		int attack = 10;
		string name = "Gyro";
		string gender = "female";
		string weapon = "cheese stick";
		int potion = 0;
		int gold = 3;
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
	void getInventory()
	{
		return potion; //need more
	}

};



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
 class Teacher(){

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

     void setName(string name){
          return name;
  
     }

};

#endif
