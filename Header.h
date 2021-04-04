#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct user {
	string username, password, role;
	user* next, * prev;
};

void LoadAccounts(string name, user*& head, user*& tail);
void Display(user* head);
void Delete(user*& head);
user LogIn(user* head, user temp);