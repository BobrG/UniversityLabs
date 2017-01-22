#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <windows.h>
#include "OrcsAndHumans.h"

Human::Human() {
	HP = 300;
	DMG = 0;
	seed = rand()%HP;
}

Human::~Human() { }

void Human::SetHealth( int dmg ) {
	HP -= dmg;
}

int Human::GetHealth() {
	return HP;
}

void Human::CriticalHit() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	// pseudorandom generator of critical hit probability. The idea is to
	// generate two random values which are comming close to each other on every hit.
	// The seed for random generates from HP and DMG values of unit to make randomization
	// more clear and avoid similar values. This idea supports the scheme: hit hit crit hit hit hit ... etc
	// Maybe this is idea make no sence, and would not work properly, but I've liked it.
	if ((CRIT = rand() % (DMG + 1)) > seed) {
		if (HP > 0)
			seed = 10*rand()% HP;
		else
			seed = 0;
		DMG *= 2;
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << " HUMAN X2 DAMAGE   " << "Human sreams - 'I bid you stand, Men of the West! '"<< std::endl;
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else {
		if (seed > DMG)
			seed = rand() % (seed - DMG + 1);
		else
			seed = rand() % (DMG - seed + 1);
	}

}

int Human::attack() {
	DMG = 20 * (1 + rand() % 3);
	CriticalHit();
	return DMG;
}


void Human::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "Human";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::setw(13) << std::right << std::setfill('_') << "|" ;
	std::cout << std::setw(48) << std::right << std::setfill('_') << "|" << std::endl;

	if (HP < 50) {
		if (HP < 30) {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (HP > 0) {
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
			}
			else
				std::cout << "dead";
			std::cout << std::endl;
		}
		else {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			for (int i = 0; i < HP; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|";
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < HP; i = i + 10) {
			std::cout << InfoBlock;
		}
		std::cout << std::endl;
	}
	if (HP > 0) {
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << "|_Attack___" << std::setw(10) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << DMG << "|";
	}

	if (DMG < 90 && HP > 0) {
		if (DMG <= 30) {
			std::cout << "weak" << std::endl;
		}
		if (DMG > 30 && DMG < 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "good" << std::endl;
		}
		if (DMG >= 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "perfect" << std::endl;
		}


	}
	else {
		if (HP > 0) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "critical" << std::endl;
		}
		std::cout << std::endl;
	}

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;
}

Orc::Orc() {
	HP = 400;
	DMG = 0;
	seed = rand()%HP;
}

Orc::~Orc() { }

void Orc::SetHealth(int dmg) {
	HP = HP - dmg;
}

int Orc::GetHealth() {
	return HP;
}

void Orc::CriticalHit() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	if ((CRIT = rand() % (DMG + 1)) > seed) {
		if (HP > 0)
			seed = 10 * rand() % HP;
		else
			seed = 0;
		DMG *= 2;
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
		std::cout << " ORC X2 DAMAGE "<< "Orc screams - 'H u M a N s MUST DIE !'" << std::endl;
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else {
		if (seed > DMG)
			seed = rand() % (seed - DMG + 1);
		else
			seed = rand() % (DMG - seed + 1);
	}
}

int Orc::attack() {
	//srand(time(NULL));
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	DMG = 10 * (1 + rand() % 5);
	CriticalHit();
	return DMG;
}

void Orc::info() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	std::cout << "|_";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "ORC";
	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout <<  std::setw(15) << std::right << std::setfill('_') << "|" << std::endl;

	if (HP < 50) {
		if (HP < 30) {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|" ;
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			if (HP > 0) {
				for (int i = 0; i < HP; i = i + 10) {
					std::cout << InfoBlock;
				}
			}
			else
				std::cout << "dead";
			std::cout << std::endl;
		}
		else {
			std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
			std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|" ;
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			for (int i = 0; i < HP; i = i + 10) {
				std::cout << InfoBlock;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "|_HealthPoints_" << std::setw(6) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << HP << "|" ;	
		SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		for (int i = 0; i < HP; i = i + 10) {
			std::cout << InfoBlock;
		}
		std::cout << std::endl;
	}

	if (HP > 0) {
		SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		std::cout << "|_Attack___" << std::setw(10) << std::right << std::setfill('_') << "|_";
		std::cout << std::setw(3) << std::left << std::setfill('_') << DMG << "|";
	}

	if (DMG < 90 && HP > 0) {
		if (DMG <= 30) {
			std::cout << "weak" << std::endl;
		}
		if (DMG > 30 && DMG < 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "good" << std::endl;
		}
		if (DMG >= 70) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			std::cout << "perfect" << std::endl;
		}


	}
	else {
		if (HP > 0) {
			SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_INTENSITY);
			std::cout << "critical" << std::endl;
		}
		std::cout << std::endl;
	}

	SetConsoleTextAttribute(hstdout, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	std::cout << std::endl;
}
