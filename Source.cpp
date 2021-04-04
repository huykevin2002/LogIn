#include <iostream>
#include <string>
#include <sstream>
#include "Header.h"
using namespace std;

int main() {
	user* head = nullptr, * tail = nullptr, temp;
	LoadAccounts("username&password.csv", head, tail);
	user x = LogIn(head, temp);
	if (x.role.compare("guest") != 0) {
		cout << x.username << " " << x.password << " " << x.role << endl;
	}
	else
		cout << "Your account does not existed" << endl;
	Delete(head);

}
