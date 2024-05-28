#include "user.h"

int User::loggingIn() {
    cout << "Enter your login: ";
    cin >> login;
    cout << "Enter your password: ";
    cin >> password;
    if (login == "admin" && password == "admin") {
        return 1;
    }
    else {
        cout << "Wrong login or password";
        exit(0);
    }
}