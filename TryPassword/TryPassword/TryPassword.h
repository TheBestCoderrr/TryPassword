#pragma once
#include <iostream>
using namespace std;

const enum RULES {
	SMALL = 0b0001,
	BIG = 0b0010,
	NUMS = 0b0100,
	SYMBOLS = 0b1000,
	LEN = 0b10000,
	SIZE = 5
};

inline RULES operator|(RULES LEFT, RULES RIGHT) {
	return static_cast<RULES>(LEFT + RIGHT);
}

class TryPassword
{
public:
	TryPassword(const string password,const RULES RULES) : password(password), RULES(RULES) {}
	bool ValidPassword() const;
private:
	string password;
	const RULES RULES;
};

