#pragma once
#ifndef source1_h
#define source1_h

#include <cstdlib>
#include <string>

#include <limits>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>



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
		maxHealth = 100;
		health = 100;
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
		if(health < 0)
			health = 0;
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


//Ana's code commented out

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
			name == "Clarissa";
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





//Wei Wei's code commented out
//Error Checking:
//what if they don't input an integer

/*
void stage4(Hero* h) {
	c.out
			<< "You have now entered Stage 4. Be prepared for anything that goes bump in the night... \n"
			<< endl;
	srand(time(0));
	int numMon = rand() % 3 + 1;

	while (numMon > 0) {
		cout
				<< "You are walking in a dimly lit area. Do you turn (1) left or (2) right?"
				<< endl;
		int input = 0;
		cin >> input;
		while (input != 1 && input != 2) {
			cout
					<< "Oh no, you can't move that way! Do you turn (1) left or (2) right?"
					<< endl;
			cin >> input;
		}
		int chance = rand() % 100;
		if (chance >= 80) {
			numMon--;
			Monster* Troll = new Monster();
			Troll->setName("Troll");
			Troll->setHealth(h->getHealth());
			cout << "I am a " << Troll->getName() << "\n";
			while (h->getHealth() > 0 && Troll->getHealth() > 0) {
				cout
						<< "What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
						<< endl;
				cin >> input;
				while (input < 1 || input > 4) {
					cout
							<< "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
							<< endl;
					cin >> input;
				}
				if (input == 1) {
					cout << "You attack " << Troll->getName() << ". You do "
							<< h->getAttack() << " damage! \n";
					Troll->decreaseHealth(h->getAttack());
					if (Troll->getHealth() == 0) {
						break;
					}
				} else {
					if (input == 2) {
						cout << "You use a potion!" << endl;
						int potion = h->getPotion();
						h->setHealth(h->getHealth() + potion);
						h->setPotion(0);

					} else {
						if (input == 3) {
							if (h->getGold() == 0) {
								cout
										<< "Uh-oh, you don't have any gold to give..."
										<< endl;
							} else {
								cout << "You want give gold to "
										<< Troll->getName()
										<< ". How much gold to you want to give? \n";
								cin >> input;
								while (input > h->getGold()) {
									cout
											<< "You don't have that much gold! How much do you want to actually give? \n";
									cin >> input;
								}
								if (input >= h->getGold() / 2) {
									Troll->setHealth(0);
									cout << Troll->getName()
											<< " stomps away with your gold. You are alone again. \n";
									h->setGold(h->getGold() - input);
									break;
								}
								cout << "You give " << Troll->getName() << input
										<< " pieces of gold. \n";
								h->setGold(h->getGold() - input);
							}

						} else {
							if (input == 4) {
								srand(time(0));
								int run = rand() % 7;
								if (run == 0) {
									cout << "You successfully run away!"
											<< endl;
									break;
								}
							}
						}
					}
				}
				cout << Troll->getName() << " attacks! \n";
				Troll->Attack(h);
			}
		} else {
			if (chance >= 60) {
				numMon--;
				Monster* v = new Monster();
				v->setName("Velociraptor");
				v->setHealth(h->getHealth() * 3 / 4);
				cout << "I am a " << v->getName() << "\n";
				while (h->getHealth() > 0 && v->getHealth() > 0) {
					cout
							<< "What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
							<< endl;
					cin >> input;
					while (input < 1 || input > 4) {
						cout
								<< "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
								<< endl;
						cin >> input;
					}
					if (input == 1) {
						cout << "You attack " << v->getName() << ". You do "
								<< h->getAttack() << " damage! \n";
						v->decreaseHealth(h->getAttack());
						if (v->getHealth() == 0) {
							break;
						}
					} else {
						if (input == 2) {
							cout << "You use a potion!" << endl;
							int potion = h->getPotion();
							h->setHealth(h->getHealth() + potion);
							h->setPotion(0);

						} else {
							if (input == 3) {
								cout
										<< "So silly, why would a velociraptor want gold? Oh well, too bad for you :P"
										<< endl;
							} else {
								if (input == 4) {
									srand(time(0));
									int run = rand() % 5;
									if (run == 0) {
										cout << "You successfully run away!"
												<< endl;
										break;
									}
								}
							}
						}
					}
					cout << v->getName() << " attacks! \n";
					v->Attack(h);
				}
			} else {
				if (chance >= 30) {
					numMon--;
					Monster* g = new Monster();
					g->setName("Ghost");
					g->setHealth(h->getHealth() / 2);
					cout << "I am a " << g->getName() << "\n";
					while (h->getHealth() > 0 && g->getHealth() > 0) {
						cout
								<< "What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
								<< endl;
						cin >> input;
						while (input < 1 || input > 4) {
							cout
									<< "That's not a choice! What will you do: \n\t (1) Attack \n\t (2) Use Potion \n\t (3) Give Gold \n\t (4) Run Away"
									<< endl;
							cin >> input;
						}
						if (input == 1) {
							cout << "You attack " << g->getName() << ". You do "
									<< h->getAttack() << " damage! \n";
							g->decreaseHealth(h->getAttack());
							if (g->getHealth() == 0) {
								break;
							}
						} else {
							if (input == 2) {
								cout << "You use a potion!" << endl;
								int potion = h->getPotion();
								h->setHealth(h->getHealth() + potion);
								h->setPotion(0);

							} else {
								if (input == 3) {
									if (h->getGold() == 0) {
										cout
												<< "Uh-oh, you don't have any gold to give..."
												<< endl;
									} else {
										cout << "You want give gold to "
												<< g->getName()
												<< ". How much gold to you want to give? \n";
										cin >> input;
										while (input > h->getGold()) {
											cout
													<< "You don't have that much gold! How much do you want to actually give? \n";
											cin >> input;
										}
										if (input >= h->getGold() * 3 / 8) {
											g->setHealth(0);
											cout << g->getName()
													<< " disappears with your gold. You are alone again. \n";
											h->setGold(h->getGold() - input);
											break;
										}
										cout << "You give " << g->getName()
												<< input
												<< " pieces of gold. \n";
										h->setGold(h->getGold() - input);
									}

								} else {
									if (input == 4) {
										srand(time(0));
										int run = rand() % 7;
										if (run == 0) {
											cout << "You successfully run away!"
													<< endl;
											break;
										}
									}
								}
							}
						}
						cout << g->getName() << " attacks! \n";
						g->Attack(h);
					}
				} else {
					cout << "Phew! You don't see any monsters!" << endl;
				}
			}
		}
	}

	if (h->getHealth() == 0) {
		cout << "Oh no, you have died..." << endl;
	} else {
		cout
				<< "Congratulations! You have completed Stage 4! You suddenly see two chests in front of you. Do you choose (1) the left chest or (2) the right chest?"
				<< endl;
		int chest = 0;
		cin >> chest;
		while (chest != 1 && chest != 2) {
			cout
					<< "Ummm, that's not an option...Did you mean (1) the left chest or (2) the right chest?"
					<< endl;
			cin >> chest;
		}
		if (chest == 1) {
			int goldGift = rand() % 7 + 1;
			cout << "You chose the left chest. You open it and find "
					<< goldGift << " pieces!" << endl;
			h->setGold(h->getGold() + goldGift);
		} else {
			int pGift = rand() % 7 + 1;
			cout
					<< "You chose the right chest. You open it and find a potion for "
					<< pGift << " health!" << endl;
			h->setPotion(h->getPotion() + pGift);
		}
	}

}

*/


void characterCreation(Hero& x){
	string tempString;
	string input = "no";
	while(input == "no" && input != "yes")
	{
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
		if(input == 1 && x.decreaseGold(500) == true)
		{
			x.setAttack(currentAttack+5);
		}else if (input == 2 && x.decreaseGold(1000) == true)
		{
			x.setAttack(currentAttack+10);
		}else if (input == 3 && x.decreaseGold(1500) == true)
		{
			x.setAttack(currentAttack+15);
		}else if (input == 4 && x.decreaseGold(2000) == true)
		{
			x.setAttack(currentAttack+20);
		}else if(input == 5 && x.decreaseGold(2500) == true)
		{
			x.setAttack(currentAttack+25);
		}else if(input > 5)
		{
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
	string name;
	int health;
	int regainHealth;
	int temp;

public:
	bool end;
	FinalBoss()
	{
		name = "Mithaldra";
		end = false;
	}
	void BossBattle(Hero& Stoner)
	{
		health = Stoner.getHealth() + 50;
		bool beak = false;
		while(true)
		{
			int input;
			int x = Stoner.getGold();
			int attackOption = 0;
			int temp = 0;
			bool healthRegain = false;
			cout << "Congratulations on completing all 3 stages. Now you are ready to face the ultimate test.\n";
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
				cin >> input;
			}
			catch(exception e)
			{
				cout << "Invalid input. Please enter a number.\n";
			}

			if(input == 1)
			{
				cout << "Creature approaches your body, you notice that this creature is a mythical dragon, thought to be extinct.\n";
				cout << "The creature, not believing you are dead, eats you.\n";
				cout << "Now, you are dead. Return to the HUB and try again.\n";
				cout << "You have lost " << x * .05 << " gold.\n"; 
				Stoner.setGold(x * .95);
				break;
			}
			else if(input == 2)
			{
				cout << "Creature looks around and moves deeper into the cave. You notice that this creature is a mythical dragon, thought to be extinct.\n";
				cout << "The dragon, knowing you are still in the cave, shoots a fireball into the air to create light.\n";
				cout << "The fireball startles you and you are unable to move. The dragon can now see you and runs at you.\n";
				cout << "Still paralyzed with fear, you do not move and the dragon crushes you.\n";
				cout << "Now, you are dead. Return to the HUB and try again.\n";
				cout << "You have lost " << x * .05 << " gold.\n"; 
				Stoner.setGold(x * .95);
				break;
			}
			else if(input == 3)
			{
				cout << "You draw your weapon. The creature moves towards you, and you notice that it is a mythical dragon, thought to be extinct.\n";
				cout << "The dragon roars in your direction, and you brace yourself for battle.\n";
				while(getHealth() != 0 && Stoner.getHealth() != 0)
				{
					cout << "Your health is: " << Stoner.getHealth() <<endl;
					cout << "The dragon's health is: " << getHealth() << endl;
					cout << "\n";
					cout << "What would you like to do?\n";
					cout << "1. Use a potion.\n";
					cout << "2. Attack.\n";
					cout << "\n";
					try
					{
						cin >> attackOption;
					}
					catch(exception e)
					{
						cout << "Invalid input. Please enter a number.\n";
					}

					if(attackOption == 1)
					{
						if(Stoner.getPotion() != 0)
						{
							temp = Stoner.getHealth(); 
							Stoner.setHealth(temp + 1); //check how much potions regain
							temp = Stoner.getPotion();
							Stoner.setPotion(temp - 1);
						}
					}
					if(attackOption == 2)
					{
						if(dodgeChance() >= 95)
						{
							cout << "The dragon dodged your attack.\n";
						}
						else{
							cout << "You do " << Stoner.getAttack() << " damage to the dragon.\n";
							temp = getHealth();
							setHealth(temp-Stoner.getAttack());
							cout << "The dragon's health is now: " << getHealth() << "\n";
						}
						if(getHealth() < getHealth() / 2  && !healthRegain){
							cout << "The dragon flies to the ceiling and eats some kind of glowing berries. These berries restore some of its health \n";
							temp = getHealth();
							setHealth(temp + getHealth() / 4);
							cout << "The dragon's health is now: " << getHealth() << "\n";
							healthRegain = true;
						}
					}

					temp = attackNum();

					if(temp == 1){
						Attack1(Stoner);
					}
					if(temp == 2){
						Attack2(Stoner);
					}
					if(temp == 3){
						Attack3(Stoner);
						if(getHealth() < 0)
							health = 0;
					}

					if(Stoner.getHealth() == 0)
					{
						cout << "Now, you are dead. Return to the HUB and try again.\n";
						cout << "You have lost " << x * .05 << " gold.\n"; 
						Stoner.setGold(x * .95);						
						beak = true;
						break;
					}
					if(getHealth() == 0)
					{
						EndGame(Stoner);
						beak = true;
						break;
					}
				}
				if(beak)
				{
					break;
				}
			}
			else
			{
				cout << "Invalid input. Try again.\n";
				cin >> input;
			}
		}
	}
	int dodgeChance()
	{
		return rand() % 100 + 1;
	}
	int attackNum()
	{
		return rand() % 3 + 1;
	}
	string getName()
	{
		return name;
	}
	void setHealth(int x)
	{
		health = x;
	}
	int getHealth()
	{
		return health;
	}
	void Attack1(Hero& x)
	{
		cout << "The dragon roars and its mouth begins to fill with fire.\n";
		cout << "The dragon shoots a fireball and it hurls in your direction.\n";
		cout << "\n";
		cout << "To dodge this, you must calculate how far you must move to dodge the fireball! \n";
		//Here ... you solve math
		cout << "What, my lord, is two plus two?\n";
		try
		{
			cin >> temp;
		}
		catch(exception e)
		{
			cout << "Invalid input. Please enter a number.\n";
		}
		if(temp == 4)
		{
			cout << "Good job, you dodged the fireball with your quick thinking.\n";
		}
		else
		{
			cout << "WRONG, you did not move quickly enough away from the fireball. \n";
			cout << "You take " << temp << " damage.\n";
			x.takeDamage(25);
			cout << "You now have " << x.getHealth() << " health. \n";
		}
	}
	void Attack2(Hero& x)
	{
		cout << "The dragon swings its mighty tail at you.\n";
		cout << "You must use your combat skills to deflect the attack.\n";
		x.takeDamage(25);
		//need combat training 
	}
	void Attack3(Hero& x)
	{
		cout << "The dragon looks up and screeches, and undead skeletons start to rise from the ground.\n";
		cout << "You reach into your satchel and grab the Horn of Gilgamesh to call your reinforcements.\n";
		cout << "You hear cheers and the townsfolk you aided come rushing to your side.\n";
		cout << "How would you like to use these reinforcements?\n";
		cout << "1. Defend you from the undead army.\n";
		cout << "2. Attack the dragon.\n";
		cout << endl;
		try
		{
			cin >> temp;
		}
		catch(exception e)
		{
			cout << "Invalid input. Please enter a number.\n";
		}
		if(temp == 1)
		{
			cout << "Your reinforcements proceed to attack the undead army.\n";
			cout << "They successfully defend you, but sacrifice themselves in your honor.\n";
		}
		else if(temp == 2)
		{
			cout << "Your reinforcements proceed to attack the dragon.\n";
			temp = x.getAttack() + attackNum() * 4;
			setHealth(getHealth() - temp);
			cout << "They deal " << temp << " damage to the dragon, but sacrifice themselves in your honor.\n";
			cout << "However, the undead army attacks you, dealing 20 damage, and then collapse back into the ground.\n";
			temp = x.getHealth();
			x.setHealth(temp - 20);
		}
	}	
	void EndGame(Hero& Stoner)
	{
		cout << endl;
		cout << "You have defeated the dragon! Congratulations " << Stoner.getName() << endl;
		cout << "In honor of your brave conquest, the townsfolk would like to make you their new king.\n";
		cout << "All hail King " << Stoner.getName() << "!\n";
		cout << endl;
		cout << "Thank you for playing.\n";
		end = true;
	}

};

void HUB(Hero& heroObj, InnKeeper& innKeeperObj, Merchant& merchantObj, Enchanter& enchanterObj){ //this is incomplete
	int input;
	cout << "---------- Welcome to the city of Anvil ----------" << endl;
	cout << "Where would you like to go?" << endl;
	cout << "1: Inn" << endl;
	cin >> input;
	if (input == 1){
		cout << "Inn" << endl;
	} else if (input == 2) {
		cout << "Visit Merchant" << endl;
	} else if (input == 3) {
		cout << "Visit Enchanter" << endl;
	} else {
		cout << "Invalid input" << endl;
	}
}


#endif
