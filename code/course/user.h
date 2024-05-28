#ifndef user_h
#define user_h
#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string login;
    string password;
public:
    int loggingIn();
};

#endif // !user_h

