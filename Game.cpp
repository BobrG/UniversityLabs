#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <windows.h>
#include "OrcsAndHumans.h"

int main() {

	Human Warrior;
	Orc UrukHai;
	int dmg_orc = 0, dmg_hum = 0;
	int key = 0, i = 0;
	srand(time(NULL));
	std::cout << "____________________________________________________________________" << std::endl;
	std::cout << "|                      Choose who goes first:                      |" << std::setfill('*') << std::endl;
	std::cout << "|                          1 - Warrior                             |" << std::endl;
	std::cout << "|                          2 - Uruk-Hai                            |" << std::endl;
	std::cout << "|__________________________________________________________________|" << std::endl;
	std::cin >> key;
	if (key == 1) 
		std::cout << "|                      Humans attack first                         |" << std::endl;
	else
		std::cout << "|                       Orcs attack first                          |" << std::endl;
	std::cout << "|__________________________________________________________________|" << std::endl;
	while(Warrior.GetHealth() > 0 && UrukHai.GetHealth() > 0) {

		std::cout << "|                             TURN#" << i << "                               |" << std::endl;
		if (key == 1) {
			UrukHai.SetHealth(dmg_hum);
			Warrior.SetHealth(dmg_orc);
			UrukHai.info();
			Warrior.info();
		    
		}
		else {
			Warrior.SetHealth(dmg_orc);
			UrukHai.SetHealth(dmg_hum);
			Warrior.info();
			UrukHai.info();
			
		}

       
		if (Warrior.GetHealth() > 0)
		dmg_orc = UrukHai.attack();
		else break;
		if (UrukHai.GetHealth() > 0)
		dmg_hum = Warrior.attack();
		else break;
		i++;
		std::cout << "|__________________________________________________________________|" << std::endl;
	}

	return 0;
}