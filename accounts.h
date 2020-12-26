#pragma once
#include "menu.h"
#include "carpark.h"

class Accounts {
protected:
	string login;
	string password;
	int role;
	int acess;
public:
	Accounts();
	Accounts(const Accounts& acc) {
		login = acc.login;
		password = acc.password;
		role = acc.role;
		acess = acc.acess;
	}
	string getLogin();
	string getPassword();
	int getRole();
	int getAcess();
	void updateLogin(string);
	void updatePassword(string);
	void updateRole(int);
	void updateAcess(int);
	friend ostream& operator<<(ostream&, Accounts&);
	friend ifstream& operator>>(ifstream&, Accounts&);
	friend ofstream& operator<<(ofstream&, Accounts&);
	~Accounts();
};

void writeFileAccounts(Accounts*, int);

void readFileAccounts(Accounts*, int&);

void addAccounts(Accounts*&, int&, int);

void delAccounts(Accounts*&, int&, string);

string updateAccounts(Accounts*&, int, string);

void workAccount(Accounts*&, int&, string);

void workDataAdmin(Bus*, int);

void modulAdmin(Accounts*&, int&, Bus*&, int&, string);

void Registration(Accounts*&, int&, int);

void Authorization(Accounts*&, int&, Bus*, int&);

string isLoginUniq(Accounts*, int);