#include "TryPassword.h"

bool TryPassword::ValidPassword() const
{
    try {
        bool counter = 0;
        if (RULES & SMALL) {
            for (int i = 0; i < password.size(); i++) {
                for (char j = 97; j < 123; j++) {
                    if (password[i] == j) {
                        counter++;
                        break;
                    }
                }
            }
            if (!counter) throw exception("Password dont have small letters. Use: a,b,c...");
        }
        if (RULES & BIG) {
            counter = 0;
            for (int i = 0; i < password.size(); i++) {
                for (char j = 65; j < 91; j++) {
                    if (password[i] == j) {
                        counter++;
                        break;
                    }
                }
            }
            if (!counter) throw exception("Password dont have big letters. Use: A,B,C...");
        }
        if (RULES & NUMS) {
            counter = 0;
            for (int i = 0; i < password.size(); i++) {
                for (char j = 48; j < 58; j++) {
                    if (password[i] == j) {
                        counter++;
                        break;
                    }
                }
            }
            if (!counter) throw exception("Password dont have numbers. Use: 1,2,3...");
        }
        if (RULES & SYMBOLS) {
            counter = 0;
            const string SYMBOLS = { "~`!@#$%^&*()-_=+[]{}\\|/<>,.?;:'\"" };
            for (int i = 0; i < password.size(); i++) {
                for (int j = 0; j < SYMBOLS.size(); j++) {
                    if (password[i] == SYMBOLS[j]) {
                        counter++;
                        break;
                    }
                }
            }
            if (!counter) throw exception("Password dont have symbols. Use: !,@,#...");
        }
        if (RULES & LEN) {
            if (password.size() < SIZE) throw exception("Password is short");
        }
    }
    catch (exception ex) {
        cout << ex.what() << endl;
        return false;
    }
    return true;
}
