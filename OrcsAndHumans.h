#pragma once
// It would be much better to create one Class Unit 
// and two derived classes Orc and Human, but int the task
// requested creation of two classes. That is why I've ignored virtual functions.
class Human {
private:
	//stats
	int HP;
	int DMG, CRIT, seed;
	char InfoBlock = '#';
	
public:
	Human();
	~Human();
	// function attack() - generate a random damage(DMG) value;
	int attack();
	// function info() - shows a list of unit's stats;
	void info();
	// function SetHealth(int dmg) - updates health(HP) value by deducting dmg;
	void SetHealth(int dmg);
	// function GetHeath() - returns health(HP) value;
	int GetHealth();
	// function CriticalHit - generates an double damage(DMG) value with pseudorandom probability;
	void CriticalHit();
	
};

class Orc {
private:
	int HP;
	int DMG, CRIT, seed;
	char InfoBlock = '#';
public:
	Orc();
	~Orc();
	
	// function attack() - generate a random damage(DMG) value;
	int attack();
	// function info() - shows a list of unit's stats;
	void info();
	// function SetHealth(int dmg) - updates health(HP) value by deducting dmg;
	void SetHealth(int dmg);
	// function GetHeath() - returns health(HP) value;
	int GetHealth();

	// function CriticalHit - generates an double damage(DMG) value with pseudorandom probability;
	void CriticalHit();

};
