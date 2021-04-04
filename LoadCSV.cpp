#include "Header.h"

void LoadAccounts(string name, user*& head, user* &tail) {
	ifstream Read(name);
	if (Read.is_open() == false) {
		cout << "Unavailable File" << endl;
	}
	user* cur = nullptr;
	string temp, word;
	while (!Read.eof()) {
		if (!head) {
			head = new user;
			cur = head;
			cur->prev = nullptr;
		}
		else {
			cur->next = new user;
			cur->next->prev = cur;
			cur = cur->next;
		}
		getline(Read, temp);
		stringstream line(temp);

		getline(line, word, ',');
		stringstream username(word);
		username >> cur->username;

		getline(line, word, ',');
		stringstream password(word);
		password >> cur->password;

		getline(line, word, ',');
		stringstream role(word);
		role >> cur->role;

		cur->next = nullptr;
	}
	tail = cur;
	Read.close();
}

void Display(user* head) {
	if (!head) return;
	while (head) {
		cout << head->username << " " << head->password << " " << head->role << endl;
		head = head->next;
	}
}

void Delete(user*& head) {
	if (!head) return;
	user* cur = head;
	while (head) {
		head = head->next;
		delete cur;
		cur = head;
	}
}

user LogIn(user* head, user temp) {
	cout << "Username: ";
	cin >> temp.username;
	cout << "Password: ";
	cin >> temp.password;
	if (head == nullptr) {
		cout << "Your account does not existed" << endl;
		exit(0);
	}
	user* cur = head;
	temp.role = "guest";
	while (cur) {
		if (cur->username == temp.username) {
			if (cur->password == temp.password) {
				temp.role = cur->role;
				return temp;
			}
			else {
				cout << "Password is not correct" << endl;
				exit(0);
			}
		}
		cur = cur->next;
	}
	return temp;
}