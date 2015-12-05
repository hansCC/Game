#pragma once
#ifndef source1_h
#define source1_h

#include <cstdlib>
#include <string>

#include <limits>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

#include<stdexcept>
#include<algorithm>

//------- Prototype classes ------------
class Hero;
class Merchant;
class Teacher;
class InnKeeper;
class Enchanter;
class FinalBoss;
class Dealer;
//------- Prototype functions ----------
void visitMerchant(Hero& x, Merchant& y);
void characterCreation(Hero& x);
void visitEnchanter(Hero& x, Enchanter& y);
void visitInn(Hero& x, InnKeeper& y);
void HUB(Hero& heroObj, InnKeeper& innKeeperObj, Merchant& merchantObj, Enchanter& enchanterObj);
void visitDealer(Hero& Stoner, Dealer& dealerObj);

using namespace std;

class Hero 
{
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
	Hero() 
	{
		maxHealth = 100;
		health = 100;
		attack = 10;
		name = "Spencer";
		gender = "male";
		weapon = "knife";
		potion = 0;
		gold = 100;
	}
	bool decreaseGold(int x)//Checks to see if the hero can afford to buy something.
	{ 
		if(x > gold)
		{
			cout << "You cannot afford this" << endl;
			return false;
		} else {
			gold = gold - x;
			return true;
		}
	}
	void usePotion()
	{
		if(potion > 0)
		{
			potion--;
			health = maxHealth;
			//cout << "------------------------------------" << endl;
			cout << "\nYour health has been restored to max" << endl;
			displayHealthBar();
			//cout << "------------------------------------\n" << endl;
		} else {
			//cout << "\n------------------------------------" << endl;
			cout << "\nYou are out of potions!" << endl;
			//cout << "------------------------------------" << endl;
		}
	}
	void setMaxHealth(int x)
	{
		maxHealth = x;
	}
	int getMaxHealth(){
		return maxHealth;
	}
	void setGender(string x) 
	{
		gender = x;
	}
	string getGender() 
	{
		return gender;
	}
	void setHealth(int x) 
	{
		health = x;
	}
	int getHealth() 
	{
		return health;
	}
	void setAttack(int x) 
	{
		attack = x;
	}
	int getAttack() 
	{
		return attack;
	}
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
		weapon = x;
	}
	string getWeapon() 
	{
		return weapon;
	}
	void setPotion(int x) 
	{
		potion = x;
	}
	int getPotion()
	{
		return potion;
	}
	void incPotion()
	{
		potion++;
	}
	void decPotion()
	{
		potion--;
	}
	void setGold(int x)
	{
		gold = x;
	}
	int getGold()
	{
		return gold;
	}

	void takeDamage(int x)
	{
		health -= x;
		if(health < 0)
			health = 0;
	}
	void printAll()//THIS FUNCTION IS FOR TESTING
	{ 
		cout << "\n---------- Hero's current parameters ----------" << endl;
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Weapon: " << weapon << endl;
		cout << "Health: " << health << endl;
		cout << "Max Health: " << maxHealth << endl;
		cout << "Potions: " << potion << endl;
		cout << "Gold: " << gold << endl;
		cout << "Attack: " << attack << endl;
	}
	void displayHealthBar()
	{
		int value = health/10;
		//cout << "Health: " << health << endl;
		//cout << "maxHealth: " << maxHealth << endl;
		//cout << "Value: " << value << endl;
		cout << name <<"'s Health: [";
		for(int i = 1; i <= value; i++)
		{
			cout << "=";
		}
		for(int i = value; i < maxHealth/10; i++)
		{
			cout << " ";
		}
		cout << "]" << endl;
		cout << "   " << name << "'s Health: " << health << endl;
	}
};
	

//Wei Wei's code begin

//Monster class - allows creation of different monsters
class Monster {
	private:
		string name;
		int health;
		int maxHealth;

	public:
		//constructor for Monster
		Monster() {
			cout << "RAWR! Fear me!" << endl;
			name = "Monster";
			health = 6;
		}
		void displayHealthBar()
		{
			int value = health/10;
			//cout << name << "'s Health: " << health << endl;
			//cout << "maxHealth: " << maxHealth << endl;
			//cout << "Value: " << value << endl;
			cout << name <<"'s Health: [";
			for(int i = 1; i <= value; i++)
			{
				cout << "~";
			}
			for(int i = value; i < maxHealth/10; i++)
			{
				cout << " ";
			
			}
			cout << "]" << endl;
			cout << "   " << name << "'s Health: " << health << endl;
		}

		//setters and getters for Name and Health
		void setName(string s) {
			this->name = s;
		}
		string getName() {
			return this->name;
		}
		void setMaxHealth(int x)
		{
			this->maxHealth = x;
			this->health = x;
		}
		int getMaxHealth()
		{
			return this->maxHealth;
		}
		void setHealth(int x) {
			this->health = x;
		}
		int getHealth() {
			return this->health;
		}
		void decreaseHealth(int x) {
			if (x >= health) {
				cout << name << " is dead!" << endl;
				health = 0;
			} else {
				health -= x;
			}
		}

		//function for Attack, all Attack details located in this function, including attack value
		void Attack(Hero& h, int KO, int maxAttack) {
			if(KO > 999 || KO < 0 || maxAttack < 0 || maxAttack > 100)	//check for valid value
			{
				throw std::invalid_argument( "received invalid value" );
			}
			srand(time(0));	//seed for random number generator
			int odds = rand() % 1000;	//determines odds of monster killing hero in one shot
			int max = h.getHealth();
			if (odds >= KO)
			{
				cout << "KO!" << endl;
				h.setHealth(0);
			}
			else
			{	//use maxAttack to determine max percentae of damage monster can deal
				max = std::max(maxAttack * max / 100, 2);
				int damageOdds = rand() % 100;	//use to change probabilities of the amount of damage that can be dealt
				int damage = 0;
				if (damageOdds >= 97) {
					cout << "Critical Hit!" << endl;
					damage = max;
				}
				else
				{
					if (damageOdds <= 5)	//monster misses
					{
						cout << this->name << "'s attack missed!" << endl;
						damage = 0;
					}
					else
					{
						if(damageOdds <= 75)	//monster deals normal amount of damage
						{
							damage = rand() % (max / 2) + 1;
						}
						else	//monster deals a little more than the normal amount of damage
						{
							damage = rand() % (max * 3 / 5) + 1;
						}
					}
				}

				h.takeDamage(damage);	//change hero's health
				cout << h.getName() << " takes " << damage << " damage! \n" << endl;
			}

		}

		//display helath bar function
	};



//function controls all mechanisms of the level
void fightMonster(Hero& h)
{
	cout << "------ The Deadlands ------" << endl;
	cout << "You have now entered The Deadlands. Be prepared for anything that goes bump in the night... \n" << endl;
	srand(time(0));
	int numMon = rand() % 5 + 1;	//predetermines how many monsters the hero must defeat in order to complete level

	cout << "You find yourself in a dimly lit...forest? You aren't entirely sure where you are, and you wished you had remembered a flashlight/torch. \n";
	cout << "You suddenly hear something move behind you, but when you turn to look, nothing's there... \n";
	cout << "Whatever, that doesn't frighten you. You decide to move forward... \n" << endl;

	while (numMon > 0)	//stay in while loop until monsters are all defeated
	{
		cout << "\n You are walking in a dimly lit area. Do you turn (1) left or (2) right?" << endl;
		int input = 0;
		cin >> input;
		bool err = true;	//input validation - checks for type and range
		while (err)
		{
			if(!cin)
			{
				cout << "Oh no, you can't move that way! Do you turn (1) left or (2) right?" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> input;
				err = true;
			}
			else
			{
				if(input != 1 && input != 2)
				{
					cout << "Oh no, you can't move that way! Do you turn (1) left or (2) right?" << endl;
					cin >> input;
					err = true;
				}
				else
				{
					err = false;
				}
			}
		}

		int chance = rand() % 100;	//sets up different probabilities that hero will encounter different scenarios
		//every monster scenario has same basic format, differences comes in how they/hero reacts in the situation
		if (chance >= 95)
		{
			//Troll scenario - 5% chance
			numMon--;
			Monster* t = new Monster();	//initialize troll
			t->setName("Troll");
			t->setMaxHealth(std::max(9 * h.getHealth() / 10, 20));
			cout << "I am a " << t->getName() << "! \n";
			while (h.getHealth() > 0 && t->getHealth() > 0)	//stop the loop when either the hero or troll dies
			{
				cout << "----- " << t->getName() << " vs. " << h.getName() << " -------" << endl;
				t->displayHealthBar();
				h.displayHealthBar();
				cout << "   " << h.getName() << "'s Potion Count: " << h.getPotion() << endl;
				cout << "\n What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
				cin >> input;
				err = true;		//input validation - checks type and range
				while(err)
				{
					if(!cin)
					{
						cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
						cin.clear();
						cin.ignore(256, '\n');
						cin >> input;
						err = true;
					}
					else
					{
						if(input < 1 || input > 4)
						{
							cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
							cin >> input;
							err = true;
						}
						else
						{
							err = false;
						}
					}
				}
				cout << "----- Result of last action -------" << endl;
				if (input == 1)
				{
					//hero attacks
					srand(time(0));
					int hMiss = rand() % 50;	//probability that hero will miss
					if(hMiss == 0)
					{
						cout << "You attack " << t->getName() << ", but your attack misses. Oh no! \n";
					}
					else
					{
						cout << "You attack " << t->getName() << ". You do " << h.getAttack() << " damage! \n";
						t->decreaseHealth(h.getAttack());
						if (t->getHealth() == 0)
						{
							break;
						}
					}

				}
				else
				{
					if (input == 2)
					{
						//hero uses potion
						h.usePotion();
						
					}
					else
					{
						//hero tries to pay off monster
						if (input == 3)
						{
							if (h.getGold() == 0)	//if hero has no gold, hero can't pay off monster
							{
								cout << "Uh-oh, you don't have any gold to give..." << endl;
							}
							else
							{
								cout << "You want give gold to " << t->getName() << ". How much gold to you want to give? \n";
								cin >> input;
								err = true;
								while(err)		//input validation - checks for range and type
								{
									if(!cin)
									{
										cout << "You can't give that amount of gold! How much d you want to actually give? \n";
										cin.clear();
										cin.ignore(256, '\n');
										cin >> input;
										err = true;
									}
									else
									{
										if (input > h.getGold() || input < 0)
										{
											cout << "You can't give that amount of gold! How much do you want to actually give? \n";
											cin >> input;
											err = true;
										}
										else
										{
											err = false;
										}
									}
								}

								if (input >= 50)	//troll requires a one time payment of at least 50 gold pieces for this to work
								{
									t->setHealth(0);
									cout << t->getName() << " stomps away with your gold. You are alone again. \n";
									h.setGold(h.getGold() - input);
									break;
								}
								if(input == 1)
								{
									cout << "You give " << t->getName() << " " << input << " piece of gold. \n";
								}
								else
								{
									cout << "You give " << t->getName() << " " << input << " pieces of gold. \n";
								}
								h.setGold(h.getGold() - input);
							}
						}
						else
						{
							if (input == 4)
							{
								//hero tries to run away
								srand(time(0));
								int run = rand() % 8;	//sets up probability of escape
								if (run == 0)
								{
									cout << "You successfully run away!" << endl;
									numMon++;
									break;
								}
								else
								{
									//different scenarios for not getting away
									int block = rand() % 3;
									switch(block)
									{
									case 0:
										cout << "You try to run away, but you run into a tree." << endl;
										break;
									case 1:
										cout << "You try to run away, but you trip over a rock." << endl;
										break;
									case 2:
										cout << "You try to run away, but you are blocked by a bush." << endl;
										break;
									}
								}
							}
						}
					}
				}
				cout << t->getName() << " attacks! \n";		//monster attacks
				t->Attack(h, 990, 50);
			}
		}
		else
		{
			//Zombie scenario - 15% chance
			if (chance >= 80)
			{
				numMon--;
				Monster* z = new Monster();
				z->setName("Zombie");
				z->setMaxHealth(std::max(h.getHealth() * 4 / 5, 13));
				cout << "I am a " << z->getName() << "! \n";
				int goldZ = 30;
				while (h.getHealth() > 0 && z->getHealth() > 0)	//continue loop until zombie or hero dies
				{
					cout << "----- " << z->getName() << " vs. " << h.getName() << " -------" << endl;
					z->displayHealthBar();
					h.displayHealthBar();
					cout << "   " << h.getName() << "'s Potion Count: " << h.getPotion() << endl;
					cout << "\n What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
					cin >> input;
					err = true;
					while(err)		//input validation - checks for range and type
					{
						if(!cin)
						{
							cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
							cin.clear();
							cin.ignore(256, '\n');
							cin >> input;
							err = true;
						}
						else
						{
							if(input < 1 || input > 4)
							{
								cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
								cin >> input;
								err = true;
							}
							else
							{
								err = false;
							}
						}
					}
					cout << "----- Result of last action -------" << endl;
					if (input == 1)
					{
						//hero attacks
						srand(time(0));
						int hMiss = rand() % 50;	//probability that hero's attack will miss
						if(hMiss == 0)
						{
							cout << "You attack " << z->getName() << ", but your attack misses. Oh no! \n";
						}
						else
						{
							cout << "You attack " << z->getName() << ". You do " << h.getAttack() << " damage! \n";
							z->decreaseHealth(h.getAttack());
							if (z->getHealth() == 0)
							{
								break;
							}
						}
					}
					else
					{
						if (input == 2)
						{
							//hero uses potion
							h.usePotion();
							

						}
						else
						{
							if (input == 3)
							{
								//hero tries to pay off monster
								if (h.getGold() == 0)		//if hero has no money, then nothing happens
								{
									cout << "Uh-oh, you don't have any gold to give..." << endl;
								}
								else
								{
									cout << "You want give gold to " << z->getName() << ". How much gold to you want to give? \n";
									cin >> input;
									err = true;
									while(err)		//input validation - checks for type and range
									{
										if(!cin)
										{
											cout << "You can't give that amount of gold! How much d you want to actually give? \n";
											cin.clear();
											cin.ignore(256, '\n');
											cin >> input;
											err = true;
										}
										else
										{
											if (input > h.getGold() || input < 0)
											{
												cout << "You can't give that amount of gold! How much do you want to actually give? \n";
												cin >> input;
												err = true;
											}
											else
											{
												err = false;
											}
										}
									}
									if(input == 1)
									{
										cout << "You give " << z->getName() << " " << input << " piece of gold. \n";
									}
									else
									{
										cout << "You give " << z->getName() << " " << input << " pieces of gold. \n";
									}
									goldZ -= input;		//must pay zombie at least 30 pieces of gold (cumulative) to escape
									h.setGold(h.getGold() - input);
									if (goldZ <= 0)
									{
										z->setHealth(0);
										cout << z->getName() << " becomes distracted by all the gold you gave it. You manage to run away, and you are once again alone. \n";
										break;
									}
								}
							}
							else
							{
								if (input == 4)
								{
									//hero tries to run away
									srand(time(0));
									int run = rand() % 5;
									if (run == 0)
									{
										cout << "You successfully run away!" << endl;
										numMon++;
										break;
									}
									else
									{
										int block = rand() % 3;
										switch(block)
										{
										case 0:
											cout << "You try to run away, but you run into a tree." << endl;
											break;
										case 1:
											cout << "You try to run away, but you trip over a rock." << endl;
											break;
										case 2:
											cout << "You try to run away, but you are blocked by a bush." << endl;
											break;
										}
									}
								}
							}
						}
					}
					cout << z->getName() << " attacks! \n";		//zombie attacks
					z->Attack(h, 995, 40);
				}
			}
			else
			{
				//velociraptor scenario - 20% chance
				if (chance >= 60)
				{
					numMon--;
					Monster* v = new Monster();
					v->setName("Velociraptor");
					v->setMaxHealth(std::max(h.getHealth() * 11 / 20, 15));
					int vMax = v->getHealth();
					cout << "I am a " << v->getName() << "! \n";
					while (h.getHealth() > 0 && v->getHealth() > 0)		//continue loop until hero or velociraptor dies
					{
						cout << "----- " << v->getName() << " vs. " << h.getName() << " -------" << endl;
						v->displayHealthBar();
						h.displayHealthBar();
						cout << "   " << h.getName() << "'s Potion Count: " << h.getPotion() << endl;
						cout << "\n What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
						cin >> input;
						err = true;
						while(err)		//input validation - checks for range and type
						{
							if(!cin)
							{
								cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
								cin.clear();
								cin.ignore(256, '\n');
								cin >> input;
								err = true;
							}
							else
							{
								if(input < 1 || input > 4)
								{
									cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
									cin >> input;
									err = true;
								}
								else
								{
									err = false;
								}
							}
						}
						cout << "----- Result of last action -------" << endl;
						if (input == 1)
						{
							//hero attacks
							srand(time(0));
							int hMiss = rand() % 50;
							if(hMiss == 0)
							{
								cout << "You attack " << v->getName() << ", but your attack misses. Oh no! \n";
							}
							else
							{
								cout << "You attack " << v->getName() << ". You do " << h.getAttack() << " damage! \n";
								v->decreaseHealth(h.getAttack());
								if (v->getHealth() == 0)
								{
									break;
								}
							}
						}
						else
						{
							if (input == 2)
							{
								//hero uses potion
								h.usePotion();
							}
							else
							{
								if (input == 3)
								{
									//can't pay off the velociraptors
									cout << "So silly, why would a velociraptor want gold? Oh well, too bad for you :P" << endl;
								}
								else
								{
									if (input == 4)
									{
										//try to run away
										srand(time(0));
										int run = rand() % 7;
										if (run == 0)
										{
											cout << "You successfully run away!" << endl;
											numMon++;
											break;
										}
										else
										{
											int block = rand() % 3;
											switch(block)
											{
											case 0:
												cout << "You try to run away, but you run into a tree." << endl;
												break;
											case 1:
												cout << "You try to run away, but you trip over a rock." << endl;
												break;
											case 2:
												cout << "You try to run away, but you are blocked by a bush." << endl;
												break;
											}
										}
									}
								}
							}
						}
						cout << v->getName() << " attacks! \n";		//velociraptor attacks
						v->Attack(h, 995, 45);
					}
				}
				else
				{
					//vampire scenario - 25% chance
					if (chance >= 35)
					{
						numMon--;
						int goldE = 20;
						Monster* e = new Monster();
						e->setName("Vampire");
						e->setMaxHealth(std::max(h.getHealth() / 2, 13));
						cout << "I am a " << e->getName() << "! \n";
						while (h.getHealth() > 0 && e->getHealth() > 0)	//continue loop until hero or monster dies
						{
							cout << "----- " << e->getName() << " vs. " << h.getName() << " -------" << endl;
							e->displayHealthBar();
							h.displayHealthBar();
							cout << "   " << h.getName() << "'s Potion Count: " << h.getPotion() << endl;
							cout << "\n What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
							cin >> input;
							err = true;
							while(err)		//input validation - checks for type and range
							{
								if(!cin)
								{
									cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
									cin.clear();
									cin.ignore(256, '\n');
									cin >> input;
									err = true;
								}
								else
								{
									if(input < 1 || input > 4)
									{
										cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
										cin >> input;
										err = true;
									}
									else
									{
										err = false;
									}
								}
							}
							cout << "----- Result of last action -------" << endl;
							if (input == 1)
							{
								//hero attacks
								srand(time(0));
								int hMiss = rand() % 50;
								if(hMiss == 0)
								{
									cout << "You attack " << e->getName() << ", but your attack misses. Oh no! \n";
								}
								else
								{
									cout << "You attack " << e->getName() << ". You do " << h.getAttack() << " damage! \n";
									e->decreaseHealth(h.getAttack());
									if (e->getHealth() == 0)
									{
										break;
									}
								}
							}
							else
							{
								if (input == 2)
								{
									//hero uses potion
									h.usePotion();

								}
								else
								{
									if (input == 3)
									{
										//hero tries to pay off monster
										if (h.getGold() == 0)
										{
											cout << "Uh-oh, you don't have any gold to give..." << endl;
										}
										else
										{
											cout << "You want give gold to " << e->getName() << ". How much gold to you want to give? \n";
											cin >> input;
											err = true;
											while(err)
											{
												if(!cin)
												{
													cout << "You can't give that amount of gold! How much d you want to actually give? \n";
													cin.clear();
													cin.ignore(256, '\n');
													cin >> input;
													err = true;
												}
												else
												{
													if (input > h.getGold() || input < 0)
													{
														cout << "You can't give that amount of gold! How much do you want to actually give? \n";
														cin >> input;
														err = true;
													}
													else
													{
														err = false;
													}
												}
											}
											if(input == 1)
											{
												cout << "You give " << e->getName() << " " << input << " piece of gold. \n";
											}
											else
											{
												cout << "You give " << e->getName() << " " << input << " pieces of gold. \n";
											}
											goldE -= input;		//need at least 20 gold pieces (cumulative) to pay off vampire
											h.setGold(h.getGold() - input);
											if (goldE <= 0)
											{
												e->setHealth(0);
												cout << e->getName() << " becomes distracted by all the gold you gave it. You manage to run away, and you are once again alone. \n";
												break;
											}
										}
									}
									else
									{
										if (input == 4)
										{
											//tries to run away
											srand(time(0));
											int run = rand() % 6;
											if (run == 0)
											{
												cout << "You successfully run away!" << endl;
												numMon++;
												break;
											}
											else
											{
												int block = rand() % 3;
												switch(block)
												{
												case 0:
													cout << "You try to run away, but you run into a tree." << endl;
													break;
												case 1:
													cout << "You try to run away, but you trip over a rock." << endl;
													break;
												case 2:
													cout << "You try to run away, but you are blocked by a bush." << endl;
													break;
												}
											}
										}
									}
								}
							}
							cout << e->getName() << " attacks! \n";		//vampire attacks
							e->Attack(h, 998, 35);
						}
					}
					else
					{
						//ghost scenario - 15% chance
						if (chance >= 20)
						{
							numMon--;
							Monster* g = new Monster();
							g->setName("Ghost");
							g->setMaxHealth(std::max(h.getHealth() * 3 / 8, 7));
							cout << "I am a " << g->getName() << "! \n";
							while (h.getHealth() > 0 && g->getHealth() > 0)
							{
								cout << "----- " << g->getName() << " vs. " << h.getName() << " -------" << endl;
								g->displayHealthBar();
								h.displayHealthBar();
								cout << "   " << h.getName() << "'s Potion Count: " << h.getPotion() << endl;
								cout << "\n What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
								cin >> input;
								err = true;
								while(err)		//input validation - checks for range and type
								{
									if(!cin)
									{
										cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
										cin.clear();
										cin.ignore(256, '\n');
										cin >> input;
										err = true;
									}
									else
									{
										if(input < 1 || input > 4)
										{
											cout << "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away" << endl;
											cin >> input;
											err = true;
										}
										else
										{
											err = false;
										}
									}
								}
								cout << "----- Result of last action -------" << endl;
								if (input == 1)
								{
									//hero attacks
									srand(time(0));
									int hMiss = rand() % 50;
									if(hMiss == 0)
									{
										cout << "You attack " << g->getName() << ", but your attack misses. Oh no! \n";
									}
									else
									{
										cout << "You attack " << g->getName() << ". You do " << h.getAttack() << " damage! \n";
										g->decreaseHealth(h.getAttack());
										if (g->getHealth() == 0)
										{
											break;
										}
									}
								}
								else
								{
									if (input == 2)
									{
										//hero uses potion
										h.usePotion();

									}
									else
									{
										if (input == 3)
										{
											//hero tries to pay off monster
											if (h.getGold() == 0)
											{
												cout << "Uh-oh, you don't have any gold to give..." << endl;
											}
											else
											{
												cout << "You want give gold to " << g->getName() << ". How much gold to you want to give? \n";
												cin >> input;
												err = true;
												while(err)
												{
													if(!cin)
													{
														cout << "You can't give that amount of gold! How much d you want to actually give? \n";
														cin.clear();
														cin.ignore(256, '\n');
														cin >> input;
														err = true;
													}
													else
													{
														if (input > h.getGold() || input < 0)
														{
															cout << "You can't give that amount of gold! How much do you want to actually give? \n";
															cin >> input;
															err = true;
														}
														else
														{
															err = false;
														}
													}
												}
												if (input >= 2) 		//need at least 2 gold pieces at any time to escape
												{
													g->setHealth(0);
													cout << g->getName() << " disappears with your gold. You are alone again. \n";
													h.setGold(h.getGold() - input);
													break;
												}
												cout << "You give " << g->getName() << " " << input << " pieces of gold. \n";
												h.setGold(h.getGold() - input);
											}

										}
										else
										{
											if (input == 4)
											{
												//try to run away
												srand(time(0));
												int run = rand() % 5;
												if (run == 0)
												{
													cout << "You successfully run away!" << endl;
													numMon++;
													break;
												}
												else
												{
													int block = rand() % 3;
													switch(block)
													{
													case 0:
														cout << "You try to run away, but you run into a tree." << endl;
														break;
													case 1:
														cout << "You try to run away, but you trip over a rock." << endl;
														break;
													case 2:
														cout << "You try to run away, but you are blocked by a bush." << endl;
														break;
													}
												}
											}
										}
									}
								}
								cout << g->getName() << " attacks! \n";		//ghost attacks
								g->Attack(h, 999, 30);
							}
						}
						else 
						{
							//20% not encountering monsters, different scenarios for no monsters
							srand(time(0));
							int randItem = rand() % 4;
							int rand2 = rand() % 3;
							int rand3 = rand() % 10 + 1;
							if(randItem == 0 || randItem == 1)
							{
								cout << "Phew! You don't see any monsters. You breathe a sigh of relief, then start moving forward." << endl;
							}
							else
							{
								if(randItem == 2)
								{
									//not encountering items
									if(rand2 == 0)
									{
										cout << "You accidentally kick something. You bend down to pick it up... \n" << endl;
										cout << "..." << endl;
										cout << "You pick up a stick. You feel silly for being scared of a little twig, so you throw it back into the darkness and move on. \n" << endl;
									}
									if(rand2 == 1)
									{
										cout << "You accidentally kick something. You bend down to pick it up... \n" << endl;
										cout << "..." << endl;
										cout << "You pick up a snAKE OMG WHAT THE-- You throw the snake back into the darkness with a shudder, and you move on. \n" << endl;
									}
									if(rand2 == 2)
									{
										cout << "You accidentally kick something. You bend down to pick it up... \n" << endl;
										cout << "..." << endl;
										cout << "You pick up a sleeping chicken. You put it back down gently, so as to not disturb the chicken, and move on. \n" << endl;
									}
								}
								if(randItem == 3)
								{
									//encountering gold or potion
									if(rand3 <= 4)
									{
										cout << "You accidentally kick something. You bend down to pick it up... \n" << endl;
										cout << "..." << endl;
										cout << "You pick up " << rand3 << " gold piece(s)! You put them away and move on. \n" << endl;
										h.setGold(h.getGold() + rand3);
									}
									else
									{
										cout << "You accidentally kick something. You bend down to pick it up... \n" << endl;
										cout << "..." << endl;
										cout << "You pick up a potion! You put it away and move on. \n" << endl;
										h.incPotion();
									}
								}
							}
						}
				}
			}
		}
	}
		if(h.getHealth() == 0)
		{
			break;		//end loop if hero died
		}
	}

	//different cases for when loop is over
	if (h.getHealth() == 0)		//nothing if hero dies
	{
		cout << "Oh no, you have died..." << endl;
		cout << "------ You leave The Deadlands ------" << endl;
	}
	else
	{	//receive reward if completed level
		cout << "You suddenly see three chests in front of you. Do you choose (1) the left chest, (2) the middle chest, or (3) the right chest?" << endl;
		int chest = 0;
		cin >> chest;
		bool errEnd = true;
		while(errEnd)
		{
			if(!cin)
			{
				cout << "Ummm, that's not an option...Did you mean (1) the left chest, (2) the middle chest, or (3) the right chest?" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> chest;
				errEnd = true;
			}
			else
			{
				if (chest < 1 || chest > 3)
				{
					cout << "Ummm, that's not an option...Did you mean (1) the left chest, (2) the middle chest, or (3) the right chest?" << endl;
					cin >> chest;
					errEnd = true;
				}
				else
				{
					errEnd = false;
				}
			}
		}

		if (chest == 1)
		{
			int goldGift = rand() % 10 + 11;
			cout << "You chose the left chest. You open it and find " << goldGift << " pieces!" << endl;
			h.setGold(h.getGold() + goldGift);
		}
		else
		{
			if(chest == 2)
			{
				int pGift = rand() % 3 + 1;
				cout << "You chose the middle chest. You open it and find " << pGift << " potions!" << endl;
				h.setPotion(h.getPotion() + pGift);
			}
			else
			{
				int attGift = rand() % 6 + 5;
				cout << "You chose the right chest. You open it and see a strange light. You reach for the light, and when you touch it, your attack increases by " << attGift << "!" << endl;
				h.setAttack(h.getAttack() + attGift);
			}
		}
		cout << "Congratulations! You have clear The Deadlands!" << endl;		//congratulatory statement only if completed level
		cout << "------ You leave The Deadlands ------" << endl;
	}
}


//end Wei's code
	
	

//Ana's code START

class Teacher {

	private:
		string name;
		string answer;
		int attack;
                int incorrect_count;
                

    int calculate_value(int x, int y, int op){

	switch(op) {
		case 0: return x + y;
		case 1: return x - y;
		case 2: return x * y;
		case 3: return x / y;
		case 4: return x % y;
		default: return 0; 
		}
	}

	string print_op(int x, int y, int op){ 
		stringstream convert;
		switch(op) {
			case 0: convert <<  x << "+" << y; break;
			case 1: convert <<  x << "-" << y; break;
			case 2: convert <<  x << "*" << y; break;
			case 3: convert <<  x << "/" << y; break;
			case 4: convert <<  x << "%" << y; break;
			default: convert << "ERROR"; 
		}
		return convert.str();
	}

		string print_op(int y, int op){

     			stringstream convert;

      			switch(op) {
                		case 0: convert <<   "+" << y; break;
                		case 1: convert <<   "-" << y; break;
                		case 2: convert <<  "*" << y; break;
                		case 3: convert <<  "/" << y; break;
                		case 4: convert <<  "%" << y; break;
                		default: convert << "ERROR";
      			}

     	 		return convert.str();
		}


	public:

		Teacher(){ 
			name = "Clarissa";
			cout << "Hello! I am your Teacher, " << name << endl;
			incorrect_count=0;
		}
				/*
                Teacher(string name){

                       this.name = name; 
		       cout << "Hello! I am your Teacher, " <<name<< std::endl;			
                       incorrect_count=0;
                }
				*/

		void setName(string x) {
			 name = x;

		}
                string getName(string name) {
		       return name;
	        }
                bool get_answer(Hero student,string answer){
 
                       if( this->answer==answer) {
                          
                          cout<<"Your answer is correct!"<<endl;
                          incorrect_count=0;
                          return true;
                       }
               
                       else{
                          cout<<" Your answer is incorrect!"<<endl;
                          incorrect_count++;
                          if(incorrect_count==3){
                             student.takeDamage(attack);
                          }
                          return false;
                       }
                       
                }
                
      
                void set_attack(int attack){
                       this->attack=attack;
                }

                int get_attack(){
                      return attack;
                }

                string get_question(){
                      int subject =  rand()%3;
                      switch(subject){
                             case 0: return get_question_history();
                             case 1: return get_question_literature();
                             default: return get_question_math();
                      }
                }
 
                string get_question_history(){
                       string questions [] = { "Which year did WWI start?",
                                               " When did Columbus discover America?"};
                       string answers [] = {"1914",
                                            "1492"};
                       int number_of_questions = 2; //formula
                       // kako se odredjuje koliko ima elemnata u array
                        //size of questions /size of string = tacno
                   
                       int choice = rand()% number_of_questions;
       
                       answer = answers[choice];

                       return questions[choice];
                }
 
                string get_question_literature(){

                       string questions [] = { "What is the name of the author who wrote Brothers Karamazov?",
                                               " Who was the fater of Transdentalism?"};
                       string answers [] = {"Fyodor Dostoyevsky.",
                                            "Ralph Wlado Emerson"};
                       int number_of_questions = 2;
                   
                       int choice = rand()% number_of_questions;
       
                       answer = answers[choice];

                       return questions[choice];
                        
  
                }
                string get_question_math(){

          		string question = "";
			int int_answer;
                        
                        stringstream convert;

			int value_0;
			int value_1;
        		int op;
        		
			int number_of_nesting = rand() % 2 + 1;

	
			value_0 = rand() % 10;
			value_1 = rand() % 10;
	
			op = rand() % 5;

			while (op == 3 && value_1 == 0) 
				value_1 = rand() % 100;

        		question = "(" + print_op(value_0, value_1, op) + ")";
        		int_answer = calculate_value(value_0, value_1, op);

        		for (int i = 0; i < number_of_nesting; i++) {
	      			value_1 = rand() % 10;

              			op = rand() % 5;

              			while (op == 3 && value_1 == 0)
                  			value_1 = rand() % 10;

              			question = "(" + question;
             		 	question += print_op(value_1, op);
              			question += ")";
              			int_answer = calculate_value(int_answer, value_1, op);
                        
			}
        		//cout << question << endl;
        		//cout << answer << endl;
                        
                        convert<<int_answer;
                        answer = convert.str();
        		return question;
	
		}

        
};


//Ana's code END


void characterCreation(Hero& x){
	string tempString;
	string input = "no";
	while(input == "no" && input != "yes")
	{
		cout << " -------------- Welcome to Team 8's Text Based RPG --------------" << endl;
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
		cout << "\nHello Hero!, the Merchant bellows from behind the bar." << endl;
		cout << "Come and spend the night, free of charge for helping our city." << endl;
	}
};


void visitInn(Hero& x, InnKeeper& y){
	cout << "\n----- You enter the Leaky Cauldren looking for a place to sleep -----" << endl;
	y.greeting();
	y.healPlayer(x);
	cout << "\nAfter a quite night of rest you feel refreshed!" << endl;
	cout << "Your health is now full" << endl;
	x.displayHealthBar();
}

class Enchanter{
private:
	string name;
public:
	Enchanter()
	{
		name = "Catlyn";
	}
	void greeting()
	{
		cout << "Care to buy an enchantment hero?" << endl;
	}
	void provideEnchantment(Hero& x)
	{
		int input;
		bool exitFlag = false;
		while(exitFlag == false)
		{	
			int currentAttack = x.getAttack();	
			cout << "\nI can empower your weapon, for a price\n" << endl;
			cout << "1: Add 5 to your weapon's attack for 500 gold" << endl;
			cout << "2: Add 10 to your weapon's attack for 1000 gold" << endl;
			cout << "3: Add 15 to your weapon's attack for 1500 gold" << endl;
			cout << "4: Add 20 to your weapon's attack for 2000 gold" << endl;
			cout << "5: Add 25 to your weapon's attack for 2500 gold" << endl;
			cout << "0: Return to town" << endl;
			cin >> input;
			if(input == 1)
			{
				if(x.decreaseGold(500) == true)
				{
					x.setAttack(currentAttack+5);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 2)
			{
				if(x.decreaseGold(1000) == true)
				{
					x.setAttack(currentAttack+10);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 3)
			{
				if(x.decreaseGold(1500) == true)
				{
					x.setAttack(currentAttack+15);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if (input == 4)
			{
				if(x.decreaseGold(2000) == true)
				{
					x.setAttack(currentAttack+20);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if(input == 5)
			{
				if(x.decreaseGold(2500) == true)
				{
					x.setAttack(currentAttack+25);
					cout << "Your weapon hums with power as its attack increases" << endl;
					cout << "You attack rating is now: " << x.getAttack() << endl;
				}
			}else if(input == 0)
			{
				cout << "\nYou leave the tent" << endl;
				exitFlag = true;
			} else {
				cout << "\nInvalid Input" << endl;
			}
		}
	}
};

void visitEnchanter(Hero& x, Enchanter& y){
	cout << "---------- The Enchanter's Tent ----------" << endl;
	cout << "You walk over to a small tent near the outskirts of town" << endl;
	cout << "An intense aroma of incense washes over you as you pull aside the entrance flap." << endl;
	cout << "From the depths of the tent you hear a soft ominous voice" << endl;
	y.greeting();
	y.provideEnchantment(x);
}

class FinalBoss {
private: 
	string name; //Dragon's name
	int maxhealth; //Dragon's max health
	int health; //Dragon's current health
	int regainHealth; //Dragon's ability to regain health
	int temp; //Temporary value
	int question; //Testing to see if input is put in correctly
	string strtemp; //Inputted value

public:
	bool end; //To see if EndGame() should be called
	FinalBoss()
	{
		name = "Mithaldra";
		end = false;
	}
	void displayHealthBar()
	{
		
		int value = health/10;
		cout << "Health: " << health << endl;
		cout << "maxHealth: " << maxhealth << endl;
		cout << "Value: " << value << endl;
		cout << "Health: [";
		for(int i = 1; i <= value; i++)
		{
			cout << "=";
		}
		for(int i = value; i < maxhealth/10; i++)
		{
			cout << " ";
		}
		
		cout << "]";
	}
	void BossBattle(Hero& Stoner) //Needs to use the Hero class
	{
		maxhealth = Stoner.getMaxHealth() + 50; //Dragon's health is 50 more than whatever the hero's health is
		health = maxhealth;
		bool beak = false; //to break be able to out of the loop
		int healthRegain = 0;

		while(true)
		{
			int x = Stoner.getGold(); //see how much gold the hero has
			int temp = 0; //initialize temporary value
			cout << "\nCongratulations on completing all 3 stages. Now you are ready to face the ultimate test.\n"; //narration
			cout << Stoner.getName() << " enters the Cave of Destruction. You see a weird inscription on the ground and proceed to investigate.\n";
			cout << "During investigation of the inscription, you hear a loud roar.\n";
			cout << "Out of the darkness, a one-eyed creature drops from the ceiling, blocking your escape.\n";
			cout << "You look for another exit, but there is no way out. You \n";
			cout << "\n";
			cout << "1. Play dead.\n";
			cout << "2. Hide in the shadows.\n";
			cout << "3. Fight.\n";
			cout << "\n";

			try
			{
				cin >> strtemp; //input your choice
			}
			catch(exception e)
			{
				cout << "Invalid input. Please enter a number.\n";
			}

			if(strtemp == "1") //Choosing to play dead
			{
				cout << "\nThe creature approaches your body, you notice that this creature is a mythical dragon, thought to be extinct.\n"; //narration
				cout << "The creature, not believing you are dead, eats you.\n";
				cout << "Now, you are dead. Return to the HUB and try again.\n";
				cout << "You have lost " << x * .05 << " gold.\n"; //When the hero dies, he/she loses 5% gold
				Stoner.setGold(x * .95);
				break;
			}
			else if(strtemp == "2") //Choosing to hide in the shadows
			{
				cout << "\nCreature looks around and moves deeper into the cave. You notice that this creature is a mythical dragon, thought to be extinct.\n"; //narration
				cout << "The dragon, knowing you are still in the cave, shoots a fireball into the air to create light.\n";
				cout << "The fireball startles you and you are unable to move. The dragon can now see you and runs at you.\n";
				cout << "Still paralyzed with fear, you do not move and the dragon crushes you.\n";
				cout << "Now, you are dead. Return to the HUB and try again.\n";
				cout << "You have lost " << x * .05 << " gold.\n"; //When the hero dies, he/she loses 5% gold
				Stoner.setGold(x * .95);
				break;
			}
			else if(strtemp == "3") //Choosing to fight
			{
				cout << "\nYou draw your weapon. The creature moves towards you, and you notice that it is a mythical dragon, thought to be extinct.\n"; //narration
				cout << "The dragon roars in your direction, and you brace yourself for battle.\n";
				cout << "You must use everything you have learned thus far to defeat the dragon.\n";
				while(getHealth() != 0 && Stoner.getHealth() != 0) //While the dragon and hero are alive
				{
					cout << "\nYour health is: " << Stoner.getHealth() <<endl; //shows how much health the dragon and hero have
					cout << "The dragon's health is: " << getHealth() << endl;
					cout << "\n";
					question = 0;
					while(question == 0) //To test if the input is correct
					{
						cout << "What would you like to do?\n"; //Whether to use a potion or attack the dragon
						cout << "1. Use a potion.\n";
						cout << "2. Attack.\n";
						cout << "\n";
						try
						{
							cin >> strtemp; //your choice
						}
						catch(exception e)
						{
							cout << "Invalid input. Please enter a number.\n";
						}

						if(strtemp == "1") //use a potion
						{
							if(Stoner.getPotion() != 0) //checks if hero has potions available
							{
								temp = Stoner.getMaxHealth() * .50; //the amount of health the hero will gain
								Stoner.setHealth(Stoner.getHealth() + temp);
								if(Stoner.getHealth() > Stoner.getMaxHealth()) //health can't gain more health than the max health
								{
									Stoner.setHealth(Stoner.getMaxHealth()); 
								}
								cout << endl;
								cout << "You have gained " << temp << " health.\n"; //prints how much health the hero gains
								cout << "You now have " << Stoner.getHealth() << " health." << endl;
								temp = Stoner.getPotion();
								Stoner.setPotion(temp - 1); //decreases amount of potions
								question = 1;
							}
							else //hero has no potions 
							{
								cout << "You have no potions to use.\n";
								cout << endl;
							}
						}
						else if(strtemp == "2") //Hero attacks the dragon
						{
							if(dodgeChance() >= 90) //10% of the time, the dragon can dodge the attack
							{
								cout << "The dragon dodged your attack.\n";
								question = 1;
							}
							
							else
							{
								cout << "You do " << Stoner.getAttack() << " damage to the dragon.\n"; //damage done to the dragon
								temp = getHealth();
								setHealth(temp - Stoner.getAttack());
								if(getHealth() < 0) //Dragon's health can't be negative, will be set to 0
								{
									health = 0;
									cout << "The dragon's health is now: " << getHealth() << "\n";
									EndGame(Stoner);
									beak = true;
									break;
								}
								cout << "The dragon's health is now: " << getHealth() << "\n";
								question = 1;
							}
						}
						
						else //checks if there is invalid input
						{
							cout << "Invalid input. Try again.\n";
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					}

					if(getHealth() <= maxhealth / 2  && healthRegain == 0) //if dragon's health is 50% of its max, it regains some health (can only do this once)
					{
						cout << "The dragon flies to the ceiling and eats some kind of glowing berries. These berries restore some of its health \n";
						temp = getHealth();
						setHealth(temp + (getHealth() / 3));
						cout << "The dragon's health is now: " << getHealth() << "\n";
						healthRegain = 1;
					}
					
					if(Stoner.getHealth() == 0) //checks if hero is dead
					{
						cout << "\nYou are now dead. Return to the HUB and try again.\n";
						cout << "You have lost " << x * .05 << " gold.\n"; 
						Stoner.setGold(x * .95);						
						beak = true;
						break;
					}

					if(getHealth() < 0) //checks if dragon is dead
					{
						health = 0;
						EndGame(Stoner);
						beak = true;
						break;
					}

				if(beak) //breaks the loop if one of them dies
				{
					break;
				}
					
					cout << endl;
					
					temp = attackNum(); //dragon does its attack

					if(temp == 1)
					{
						Attack1(Stoner);
						if(getHealth() < 0) //health can't be negative
						{
							health = 0;
						}
					}
					
					if(temp == 2)
					{
						Attack2(Stoner);
						if(getHealth() < 0) //health can't be negative
						{
							health = 0;
						}
					}
					
					if(temp == 3)
					{
						Attack3(Stoner);
						if(getHealth() < 0) //health can't be negative
						{
							health = 0;
						}
					}

					if(Stoner.getHealth() == 0) //checks if hero is dead
					{
						cout << "\nYou are now dead. Return to the HUB and try again.\n";
						cout << "You have lost " << x * .05 << " gold.\n"; 
						Stoner.setGold(x * .95);						
						beak = true;
						break;
					}

					if(health == 0) //checks if dragon is dead
					{
						cout << "The dragon's health is now: " << getHealth() << "\n";
						EndGame(Stoner);
						beak = true;
						break;
					}
				}

				if(beak) //breaks loop if dragon or hero is dead
				{
					break;
				}
			}

			else //checks for bad input
			{
				cout << "Invalid input. Try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}
	
	int dodgeChance() //Dragon's ability to dodge
	{
		return rand() % 100 + 1;
	}
	
	int attackNum() //Checks which attack the dragon uses
	{
		return rand() % 3 + 1;
	}
	
	string getName() //gets dragon's name
	{
		return name;
	}
	
	void setHealth(int x) //sets dragon's health
	{
		health = x;
	}
	
	int getHealth() //gets dragon's health
	{
		return health;
	}
	void setMaxHealth(int x)
	{
		maxhealth = x;
	}
	int getMaxHealth()
	{
		return maxhealth;
	}
	int questionChance() //determines which question the hero must answer
	{
		return rand() % 10 + 1;
	}
	
	void Attack1(Hero& x) //dragon's first attack (implements lessons learned from the teaching stage)
	{
		cout << endl;
		cout << "The dragon roars and its mouth begins to fill with fire.\n"; //narration
		cout << "The dragon shoots a fireball and it hurls in your direction.\n";
		cout << "\n";
		cout << "To dodge this, you must answer a question:\n";
		
		cout << endl;
		temp = questionChance(); //checks which question will be used
		question = 0;

		while(question == 0)
		{
			cout << endl;
			if(temp == 1)
			{
				//first question - MATH
				cout << "What is 5 + 2 * 10?\n";
				cout << "A. 70\n";
				cout << "B. 25\n";
				cout << "C. 52\n";
				cout << "D. 17\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "B")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}

				else if(strtemp == "A" || strtemp == "C" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if(temp == 2)
			{
				//second question - HISTORY
				cout << "What century did World War I take place in?\n";
				cout << "A. 21\n";
				cout << "B. 19\n";
				cout << "C. 17\n";
				cout << "D. 20\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "D")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}

				else if(strtemp == "A" || strtemp == "B" || strtemp == "C")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if(temp == 3)
			{
				//third question - LITERATURE
				cout << "Who wrote the book '1984'?\n";
				cout << "A. George Orwell\n";
				cout << "B. Dr. Seuss\n";
				cout << "C. George Washington\n";
				cout << "D. Oprah Winfrey\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "A")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}

				else if(strtemp == "B" || strtemp == "C" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if(temp == 4)
			{
				//fourth question - MATH
				cout << "What is 8 * 3 - 5 * 4?\n";
				cout << "A. 76\n";
				cout << "B. -64\n";
				cout << "C. 4\n";
				cout << "D. 0\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "C")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}

				else if(strtemp == "A" || strtemp == "B" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if(temp == 5) 
			{
				//fifth question - HISTORY
				cout << "When did Columbus discover America?\n";
				cout << "A. 1492\n";
				cout << "B. 1942\n";
				cout << "C. 1249\n";
				cout << "D. 1429\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "A")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}
				else if(strtemp == "B" || strtemp == "C" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if(temp == 6) 
			{
				//sixth question - LITERATURE
				cout << "Who was the father of Transcendentalism?\n";
				cout << "A. Barack Obama\n";
				cout << "B. Edgar Allen Poe\n";
				cout << "C. Dr. Seuss\n";
				cout << "D. Ralph Waldo Emerson\n";
				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}
				
				if(strtemp == "D")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}
				
				else if(strtemp == "B" || strtemp == "C" || strtemp == "A")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if(temp == 7) 
			{
				//seventh question - MATH
				cout << "How many sides is a pentagon?\n";
				cout << "A. 10\n";
				cout << "B. 5\n";
				cout << "C. 6\n";
				cout << "D. 4\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}

				if(strtemp == "B")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}

				else if(strtemp == "A" || strtemp == "C" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

			else if(temp == 8) 
			{
				//third question - HISTORY
				cout << "Who is the current president of the United States?\n";
				cout << "A. Barack Obama\n";
				cout << "B. Donald Trump\n";
				cout << "C. Abraham Lincoln\n";
				cout << "D. Lebron James\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}
				
				if(strtemp == "A")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}
				
				else if(strtemp == "B" || strtemp == "C" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}

				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if(temp == 9) 
			{
				//ninth question - CHEMISTRY
				cout << "What is the first element in the periodic table?\n";
				cout << "A. Helium\n";
				cout << "B. Zinc\n";
				cout << "C. Carbon\n";
				cout << "D. Hydrogen\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}
				
				if(strtemp == "D")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}
				
				else if(strtemp == "B" || strtemp == "C" || strtemp == "A")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}
				
				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			
			else if(temp == 10) 
			{
				//tenth question - MATH
				cout << "How many degrees does the angles of a triangle add up to?\n";
				cout << "A. 360\n";
				cout << "B. 270\n";
				cout << "C. 180\n";
				cout << "D. 90\n";

				try
				{
					cin >> strtemp;
				}
				catch(exception e)
				{
					cout << "Invalid input. Try again.\n";
				}
				
				if(strtemp == "C")
				{
					cout << "\nGood job, you dodged the fireball with your quick thinking.\n";
					question = 1;
				}
				
				else if(strtemp == "B" || strtemp == "A" || strtemp == "D")
				{
					cout << "\nWRONG, you did not move quickly enough away from the fireball. \n";
					cout << "You take " << 25 << " damage.\n";
					x.takeDamage(25);
					cout << "You now have " << x.getHealth() << " health. \n";
					question = 1;
				}
				
				else
				{
					cout << "Invalid input. Try again.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
		}
	}

	void Attack2(Hero& x) //dragon's second attack (implements lessons learned from the combat stage)
	{
		cout << endl;
		cout << "The dragon swings its mighty tail at you.\n"; //narration
		cout << "You must use your combat skills to deflect the attack.\n";
		question = 0;

		while(question == 0)
		{
			cout << "\n"; //combat options
			cout << "1. Counterattack" << endl;
			cout << "2. Fall to the ground" << endl;
			cout << "3. Attempt to jump over the tail" << endl;
			cout << "4. Timewarp" << endl;
			cout << endl;
			
			try
			{
				cin >> strtemp; //choice
			}
			catch(exception e)
			{
				cout << "Invalid input. Please enter a number" << endl;
			}
			
			if(strtemp == "1") //choosing to counterattack
			{
				cout << "You use your " << x.getWeapon() << " to attack the dragon's tail." << endl;
				cout << "You succefully do " << x.getAttack()/2 << " damage to the dragon's tail." << endl;
				cout << "But unfortunately during your attack, the dragon's tail hit you.  You suffer " << x.getAttack()/2 << " damage as well." << endl;
				cout << endl;
				x.takeDamage(x.getAttack()/2);
				setHealth(getHealth() - (x.getAttack()/2));
				question = 1;
			}
			
			else if(strtemp == "2") //attempting to dodge by falling to the ground
			{
				cout << "You fall to the ground in an attempt to dodge the dragon's tail." << endl;
				cout << "..." << endl;
			
				if(dodgeChance() >= 60)
				{
					cout << "You hit the ground with a thud and see the tail come swinging over your head." << endl;
					cout << "You jump back to your feet, ready for your next attack." << endl;
					question = 1;
				}
				
				else
				{
					cout << "You hit the ground with a thud and looking for where the tail is." << endl;
					cout << "You feel a scorching pain in your side as the tail rams into you." << endl;
					cout << "You take 20 damage." << endl;
					cout << "You painfully rise back to your feet, ready for your next attack." << endl;
					cout << endl;
					x.takeDamage(20);
					question = 1;
				}
			}
			
			else if(strtemp == "3") //attempting to dodge by jumping over the tail
			{
				cout << "You jump off of the ground in an attempt to dodge the dragon's tail." << endl;
				cout << "..." << endl;
			
				if(dodgeChance() >= 40)
				{
					cout << "While in midair you look down and see the dragon's tail come hit the ground, spraying dirt in all directions." << endl;
					cout << "You land on your feet, ready for your next attack." << endl;
					question = 1;
				}
				
				else
				{
					cout << "You jump into the air looking for the dragon's tail below you." << endl;
					cout << "You feel a scorching pain in your legs as the tail comes swinging into your body." << endl;
					cout << "You take 20 damage." << endl;
					cout << "You land on your shoulder and feel something crack." << endl;
					cout << "You painfully rise back to your feet, ready for your next attack." << endl;
					cout << endl;
					x.takeDamage(20);
					question = 1;
				}
			}
			
			else if(strtemp == "4") //attempting to dodge via timewarp
			{
				if(dodgeChance() <= 20)
				{
					cout << "You pull out a magical drink out of your satchel." << endl;
					cout << "You were told this give a second chance when your in most need of it." << endl;
					cout << "Drinking the bottle you feel queasy, and lose your balance." << endl;
					cout << "You open your eyes to find yourself back on your feet.  The dragon is awaiting your next attack." << endl;
					cout << endl;
					question = 1;
				}
				
				else
				{
					cout << "You pull out a magical drink out of your satchel." << endl;
					cout << "You were told this give a second chance when your in most need of it." << endl;
					cout << "Drinking the bottle you feel queasy, and lose your balance. " << endl;
					cout << "Nothing happens. The dragon's tail swoops in to hit you, dealing 20 damage." << endl;
					cout << endl;
					x.takeDamage(20);
					question = 1;
				}
			}
			
			else
			{
				cout << "Invalid input. Try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}	
	}
	
	void Attack3(Hero& x) //dragon's third attack (implements lessons learned from the leading stage)
	{
		cout << endl; //narration
		cout << "The dragon looks up and screeches, and undead skeletons start to rise from the ground.\n";
		cout << "You reach into your satchel and grab the Horn of Gilgamesh to call your reinforcements.\n";
		cout << "You hear cheers and the townsfolk you aided come rushing to your side.\n";
		question = 0;

		while(question == 0)
		{	
			cout << endl;
			cout << "How would you like to use these reinforcements?\n"; //using reinforcements from leading stage
			cout << "1. Defend you from the undead army.\n";
			cout << "2. Attack the dragon.\n";
			cout << endl;

			try
			{
				cin >> strtemp;
			}
			
			catch(exception e)
			{
				cout << "Invalid input. Please enter a number.\n";
			}
			
			if(strtemp == "1") //reinforcements defend you from the undead army
			{
				cout << "Your reinforcements proceed to attack the undead army.\n";
				cout << "They successfully defend you, but sacrifice themselves in your honor.\n";
				question = 1;
			}
			
			else if(strtemp == "2") //reinforcements ignore the undead army and attack the dragon 
			{
				cout << "Your reinforcements proceed to attack the dragon.\n";
				temp = x.getAttack() + attackNum() * 4;
				setHealth(getHealth() - temp);
				cout << "They deal " << temp << " damage to the dragon, but sacrifice themselves in your honor.\n";
				cout << "However, the undead army attacks you, dealing 20 damage, and then collapse back into the ground.\n";
				x.takeDamage(20);
				question = 1;
			}
			
			else
			{
				cout << "Invalid input. Try again.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
	}	
	
	void EndGame(Hero& Stoner)
	{
		cout << endl; //narration afte defeating dragon
		cout << "You have defeated the dragon! Congratulations " << Stoner.getName() << endl;
		cout << "In honor of your brave conquest, the townsfolk would like to make you their new king.\n";
		cout << "All hail King " << Stoner.getName() << "!\n";
		cout << endl;
		cout << "Thank you for playing.\n";
		cout << endl;
		end = true;
	}

};


class Merchant {
private: 
	string name;
	string inventory[5];
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
			for (int i = 0; i < 5; i++){
					cout << i+1 << ": " << inventory[i] << endl;
			}
			cout << "0: Nevermind" << endl;
				cin >> input;
				if(input == 1 && x.decreaseGold(25)==true){
					x.setWeapon(inventory[0]);
				} else if(input == 2 && x.decreaseGold(25)==true){
					x.setWeapon(inventory[1]);
				} else if(input == 3 && x.decreaseGold(25)==true){
					x.setWeapon(inventory[2]);
				} else if(input == 4 && x.decreaseGold(25)==true){
					x.setWeapon(inventory[3]);
				} else if(input == 5 && x.decreaseGold(25)==true){
					x.setWeapon(inventory[4]);
				} else {
					//do nothing
				}
		
	}
};


class Dealer{
private:
	string name;
public:
	Dealer()
	{
		name = "Simon";
	}
	void magicCups(Hero& Stoner){
	int cupNum = 0;
	bool exitFlag = false;
	bool exitFlag2 = false;
	int input = 0;
	int herosBet;
	cout << "------ Magic Cup Game ------" << endl;
		while(exitFlag == false)
		{
			cout << "You wish to play the magic cup game! How much are you will to gamble?" << endl;
			while(exitFlag2 == false){
			cin >> herosBet;
				if (herosBet > Stoner.getGold()){
					cout << "You don't have that much gold, try gambling a different amount" << endl;
				} else {
					exitFlag2 = true;
				}
			}
			exitFlag2 = false;
				
				
			showAllCups();
			cout << "1: The ball is beneath cup 1" << endl;
			cout << "2: The ball is beneath cup 2" << endl;
			cout << "3: The ball is beneath cup 3" << endl;
			cout << "0: Quit magic cup game." << endl;
			
			cupNum = rand() % 3 + 1;
			cin >> input;
			if(input == 1 || input == 2 || input == 3)
			{
				if(cupNum == 1)
				{
					showCup1();
					if(input == 1){
						cout << "\nYou guessed correctly Hero!" << endl;
						cout << "You have won: " << herosBet*2 << endl;
						Stoner.setGold(herosBet*2);
					} else{
						cout << "\nOh I'm sorry, that's wrong" << endl;
						cout << "You have lost: " << herosBet << endl;
						Stoner.setGold(Stoner.getGold()-herosBet);
					}
				}else if(cupNum == 2)
				{
					showCup2();
					if(input == 2){
						cout << "\nYou guessed correctly Hero!" << endl;
						cout << "You have won: " << herosBet*2 << endl;
						Stoner.setGold(herosBet*2);
					} else{
						cout << "\nOh I'm sorry, that's wrong" << endl;
						cout << "You have lost: " << herosBet << endl;
						Stoner.setGold(Stoner.getGold()-herosBet);
					}
				}else if(cupNum == 3)
				{
					showCup3();
					if(input == 3){
						cout << "\nYou guessed correctly Hero!" << endl;
						cout << "You have won: " << herosBet*2 << endl;
						Stoner.setGold(herosBet*2);
					} else{
						cout << "\nOh I'm sorry, that's wrong" << endl;
						cout << "You have lost: " << herosBet << endl;
						Stoner.setGold(Stoner.getGold()-herosBet);
					}
				}
			} else {
				cout << "\nThat is an invalid input" << endl;
			}
			if(input == 0)
			{
				exitFlag = true;
			}
			cout << "\n Would you like to try again?" << endl;
			cout << "1: Yes" << endl;
			cout << "2: No" << endl;
			bool x = false;
			while (x == false)
			{
				cin >> input;
				if(input == 1){
					exitFlag = false;
					x = true;
				} else if(input == 2){
					exitFlag = true;
					x = true;
				} else {
					cout << "That is an invalid input" << endl;
				}
			}
		}
			showAllCups();
			showCup1();
			showCup2();
			showCup3();
	}
	void showAllCups(){
		cout << "cup:  1      2      3  " << endl;
		cout << "    _---_  _---_  _---_" << endl;
		cout << "    |   |  |   |  |   |" << endl;
		cout << "    |   |  |   |  |   |" << endl;
	}
	void showCup1(){
		cout << "    _---_              " << endl;
		cout << "    |   |  _---_  _---_" << endl;
		cout << "    |   |  |   |  |   |" << endl;
		cout << "      0    |   |  |   |" << endl;
	}
	void showCup2(){
		cout << "           _---_       " << endl;
		cout << "    _---_  |   |  _---_" << endl;
		cout << "    |   |  |   |  |   |" << endl;
		cout << "    |   |    0    |   |" << endl;
	}
	void showCup3(){
		cout << "                  _---_" << endl;
		cout << "    _---_  _---_  |   |" << endl;
		cout << "    |   |  |   |  |   |" << endl;
		cout << "    |   |  |   |    0  " << endl;
	}
		
		
	void setName(string x)
	{
		name = x;
	}
	string getName()
	{
		return name;
	}
};



void HUB(Hero& Stoner, InnKeeper& innKeeperObj, Merchant& merchantObj, Enchanter& enchanterObj, Dealer& dealerObj){ //this is incomplete
	int input;
	bool exitFlag = false;
	cout << "\n---------- Welcome to the city of Anvil ----------" << endl;
	
	while (exitFlag == false){
		cout << "\nWhere in Anvil would you like to go?" << endl;
		cout << "1: Inn" << endl;
		cout << "2: Merchant" << endl;
		cout << "3: Enchanter" << endl;
		cout << "4: Dealer" << endl;
		cout << "9: Check Inventory" << endl;
		cout << "0: Exit Anvil" << endl;
		cin >> input;
		if (input == 1)
		{
			visitInn(Stoner, innKeeperObj);
		} else if (input == 2)
		{
			visitMerchant(Stoner, merchantObj);
		} else if (input == 3) 
		{
			cout << "\nVisit Enchanter" << endl;
			visitEnchanter(Stoner, enchanterObj);
		}else if(input == 4)
		{
			visitDealer(Stoner, dealerObj);
		}else if(input == 9)
		{
			Stoner.printAll();
		} else if(input == 0)
		{
			exitFlag = true;
			cout << "You venture out into the wilds" << endl;
		} else 
		{
			cout << "\nInvalid input" << endl;
		}
	}
}

void visitMerchant(Hero& x, Merchant& y){
	int input;
	bool exitFlag = false;
	cout << "\nYou walk into a small shop by the Inn" << endl;
	while(exitFlag == false)
	{
		cout << "How can I help you?, the merchant chirps." << endl;
		cout << "1: to buy a potion" << endl;
		cout << "2: to buy a weapon" << endl;
		cout << "0: Leave merchant" << endl;
		cin >> input;
		if (input == 1)
		{
			y.sellPotion(x);
		} else if (input ==  2)
		{
			y.sellWeapon(x);
		} else if(input == 0)
		{
			exitFlag = true;
		} else 
		{
			cout << "That is an invalid input" << endl;
		}
	}
}


void visitDealer(Hero& Stoner, Dealer& dealerObj)
{
	dealerObj.magicCups(Stoner);
}





/*
		int temp = x.getHealth();
		x.setHealth(temp-10); //Tiger does 10 damage
*/

#endif
