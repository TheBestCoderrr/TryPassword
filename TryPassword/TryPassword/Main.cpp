#include "TryPassword.h"

string GeneratePassword() {
	string password;
	for (int i = rand() % 25 + 1; i > 0; i--)
		password.push_back(rand() % 100 + 33);
	return password;
}

int main() {
	srand(time(0));
	string password = GeneratePassword();
	cout << password << endl;
	TryPassword A(password, SMALL | BIG | NUMS | SYMBOLS | LEN);
	A.ValidPassword();
}