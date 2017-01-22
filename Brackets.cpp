#include <string>
#include <iostream>
#include <vector>
//Task: check if string contains a correct brackets structure.
bool check(std::string str);

int main() {
	std::string str;
	std::cin >> str;
	if (check(str)) {
		std::cout << "OK\n";
	}
	else
		std::cout << "NotOK\n";
}
bool check(std::string str) {
	//vector of pairs just for fun :D
	std::vector <std::pair <char, int>> bra;

	//inserting bracket types and counter = 0;
	bra.push_back(std::pair <char, int>('(', 0));
	bra.push_back(std::pair <char, int>('[', 0));
	bra.push_back(std::pair <char, int>('{', 0));
	bra.push_back(std::pair <char, int>(')', 0));
	bra.push_back(std::pair <char, int>(']', 0));
	bra.push_back(std::pair <char, int>('}', 0));

	const char* str_ch = str.c_str();
	
	for (int i = 0; i < str.length(); ++i) {
		if (str_ch[i] == bra[0].first) {
			bra[0].second++;
		}
		if (str_ch[i] == bra[1].first) {
			bra[1].second++;
		}
		if (str_ch[i] == bra[2].first) {
			bra[2].second++;
		}
		if (str_ch[i] == bra[3].first) {
			bra[3].second++;
		}
		if (str_ch[i] == bra[4].first) {
			bra[4].second++;
		}
		if (str_ch[i] == bra[5].first) {
			bra[5].second++;
		}

	}

	if (bra[0].second != bra[3].second || bra[1].second != bra[4].second || bra[2].second != bra[5].second) {
		return false;
	}
	else
		return true;
}