#include "accounts.h"
#include "carpark.h"
#include "defence.h"

Accounts::Accounts()
{
	role = 0;
	acess = 0;
}

string Accounts::getLogin()
{
	return login;
}

string Accounts::getPassword()
{
	return password;
}

int Accounts::getRole()
{
	return role;
}

int Accounts::getAcess()
{
	return acess;
}

void Accounts::updateLogin(string log)
{
	login = log;
}

void Accounts::updatePassword(string pas)
{
	password = pas;
}

void Accounts::updateRole(int rol)
{
	role = rol;
}

void Accounts::updateAcess(int ac)
{
	acess = ac;
}

Accounts::~Accounts()
{

}

ostream& operator<<(ostream& out, Accounts& account) {
	out << "�����: " << account.getLogin() << endl;
	out << "������: " << account.getPassword() << endl;
	out << "���������: ";
	if (account.getAcess() == 0) {
		out << "�� �����������" << endl;
	}
	else out << "�����������" << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Accounts& account)
{
	string s;
	getline(fin, account.login);
	getline(fin, s);
	account.password = deencryptionPassword(s);
	getline(fin, s);
	account.role = stoi(s);
	getline(fin, s);
	account.acess = stoi(s);
	return fin;
}

ofstream& operator<<(ofstream& fout, Accounts& account)
{
	fout << account.login << endl;
	fout << encryptionPassword(account.password) << endl;
	fout << account.role << endl;
	fout << account.acess << endl;
	return fout;
}

void writeFileAccounts(Accounts* mas_of_accounts, int number_of_accounts) {
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < number_of_accounts; i++) {
		fout << mas_of_accounts[i];
	}
	fout.close();
}

void readFileAccounts(Accounts* mas_of_accounts, int& number_of_accounts) {
	if (number_of_accounts != 0) {
		ifstream fin(FILE_OF_ACCOUNTS, ios::in);
		int i = 0;
		while (fin.peek() != EOF) {
			fin >> mas_of_accounts[i];
			i++;
		}
		number_of_accounts = i;
		fin.close();
	}
}

void showAccounts(Accounts* mas_of_accounts, int number_of_accounts)
{
	int nAdmin = 1, nUser = 1;
	for (int i = 0; i < number_of_accounts; i++) {
		if (mas_of_accounts[i].getRole() == 1) {
			cout << "\t������������� " << "� " << nAdmin << endl;
			nAdmin++;
			cout << mas_of_accounts[i];
		}
		else {
			cout << "\t������������ " << "� " << nUser << endl;
			nUser++;
			cout << mas_of_accounts[i];
		}
		//Sleep(500);
	}
}

void addAccounts(Accounts*& mas_of_accounts, int& number_of_accounts, int r)
{
	string log, pass;
	int role, kol = 0;
	if (number_of_accounts - 1 == 0) {
		cout << "������ ������� ������ ���� ������� ���������������!" << endl;
		cout << "�����(�� ����� 3 ��������): "; log = vvodLogin();
		mas_of_accounts[number_of_accounts - 1].updateLogin(log);
		cout << "������(�� ����� 5 ��������): "; pass = vvodPassword();
		mas_of_accounts[number_of_accounts - 1].updatePassword(pass);
		mas_of_accounts[number_of_accounts - 1].updateRole(1);
		mas_of_accounts[number_of_accounts - 1].updateAcess(1);
		cout << "�� ������� ���������������� � �������� ��������������" << endl;
		system("pause");
	}
	else {
		cout << "�����(�� ����� 3 ��������): ";
		log = vvodLogin(); 
		for (int i = 0; i < number_of_accounts; i++) {
			if (mas_of_accounts[i].getLogin() == log) kol++;
		}
		if (kol != 0) {
			cout << "������� � ����� ������� ��� ����������!" << endl;
			number_of_accounts--;
			system("pause");
		}
		else {
			mas_of_accounts[number_of_accounts - 1].updateLogin(log);
			cout << "������(�� ����� 5 ��������): ";
			pass = vvodPassword();
			mas_of_accounts[number_of_accounts - 1].updatePassword(pass);
			if (r == 0) {
				mas_of_accounts[number_of_accounts - 1].updateRole(0);
				mas_of_accounts[number_of_accounts - 1].updateAcess(0);
				cout << "�� ������� ���������������� � �������� ������������, ��������� ������������� �������� ��� ����� � �������" << endl;
				system("pause");
			}
			else {
				if (r == 1) {
					cout << "����� �������(1 - �����, 0 - ������������): ";
					role = vvodRole();
					mas_of_accounts[number_of_accounts - 1].updateRole(role);
					mas_of_accounts[number_of_accounts - 1].updateAcess(1);
					if (role == 1) cout << "������������� ��������" << endl;
					else cout << "������������ ��������" << endl;
				}
			}
		}
	}
}

void delAccounts(Accounts*& mas_of_accounts, int& number_of_accounts, string l) {
	showAccounts(mas_of_accounts, number_of_accounts);
	string log;
	int number = 0, q = 0;
	if (number_of_accounts > 0) {
		cout << "������� ����� ��������, ������� ������ �������: ";
		log = vvodLogin();
		if (log == l) cout << "������ ������� ����������� �������" << endl;
		else {
			for (int i = 1; i < number_of_accounts; i++) {
				if (log == mas_of_accounts[i].getLogin()) {
					q++;
					number = i;
					break;
				}
			}
			if (q == 0) {
				cout << "������������� � ������� " << log << " ���" << endl;
			}
			else {
				system("cls");
				Interface<string> b("�� ������������� ������ ������� �������?");
				if (b.menuConfirm() == 0) {
					if (mas_of_accounts[number].getRole() == 1) {
						for (int i = number; i < number_of_accounts - 1; i++) {
							mas_of_accounts[i] = mas_of_accounts[i + 1];
						}
						cout << "������������� " << log << " ������!" << endl;
						number_of_accounts--;
					}
					else {
						for (int i = number; i < number_of_accounts - 1; i++) {
							mas_of_accounts[i] = mas_of_accounts[i + 1];
						}
						cout << "������������ " << log << " ������!" << endl;
						number_of_accounts--;
					}
				}
			}
		}
	}
	writeFileAccounts(mas_of_accounts, number_of_accounts);
}

string updateAccounts(Accounts*& mas_of_accounts, int number_of_accounts, string l) {
	showAccounts(mas_of_accounts, number_of_accounts);
	string login, password;
	int role = 0, acess = 0, update = 0, q = 0, number = 0;
	bool quit = true;
	cout << "������� ����� ��������, ������� ������ ��������: ";
	login = vvodLogin();
	for (int i = 0; i < number_of_accounts; i++) {
		if (login == mas_of_accounts[i].getLogin()) {
			q++;
			number = i;
			break;
		}
	}
	if (q == 0) {
		cout << "�������� � ������� " << login << " ���" << endl;
	}
	else {
		while (quit) {
			Interface<string> b("�������������� �������� � ������� " + login);
			system("cls");
			switch (b.menuAccount()) {
			case 0:
				cout << "������� �����: ";
				cout << mas_of_accounts[number].getLogin();
				cout << endl;
				if (mas_of_accounts[number].getLogin() == l) {
					login = isLoginUniq(mas_of_accounts, number_of_accounts);
					mas_of_accounts[number].updateLogin(login);
					l = login;
				}
				else {
					login = isLoginUniq(mas_of_accounts, number_of_accounts);
					mas_of_accounts[number].updateLogin(login);
				}
				break;
			case 1:
				cout << "������� ������: ";
				cout << mas_of_accounts[number].getPassword();
				cout << endl;
				cout << "������� ����� ������(�� ����� 5 ��������): ";
				password = vvodPassword();
				mas_of_accounts[number].updatePassword(password);
				break;
			case 2:
				cout << "������� ����� �������(1 - �������������, 0 - ������������): ";
				cout << mas_of_accounts[number].getRole();
				cout << endl;
				if (login == l) {
					cout << "������ �������� ����������� ����" << endl;
					system("pause");
				}
				else {
					if (mas_of_accounts[number].getRole() == 1) mas_of_accounts[number].updateRole(0);
					else mas_of_accounts[number].updateRole(1);
					cout << "���� ��������" << endl;
					system("pause");
				}
				break;
			case 3:
				cout << "������� ���������(1 - ������� �����������, 0 - ������� �� �����������): ";
				cout << mas_of_accounts[number].getAcess();
				cout << endl;
				if (login == l) {
					cout << "������ �������� ����������� ���������" << endl;
					system("pause");
				}
				else {
					if (mas_of_accounts[number].getAcess() == 1) mas_of_accounts[number].updateAcess(0);
					else mas_of_accounts[number].updateAcess(1);
					cout << "��������� ��������" << endl;
					system("pause");
				}
				break;
			case 4:
				quit = false;
				break;
			}
		}
	}
	writeFileAccounts(mas_of_accounts, number_of_accounts);
	return l;
}

void workAccount(Accounts*& mas_of_accounts, int& number_of_accounts, string l) {
	int n = 0;
	Interface<string> b("������ ������ �������������� � ���������� ");
	while (n != 5) {
		system("cls");
		n = b.menuWorkAccount();
		switch (n) {
		case 0:
			showAccounts(mas_of_accounts, number_of_accounts);
			system("pause");
			break;
		case 1:
			Registration(mas_of_accounts, number_of_accounts, 1);
			system("pause");
			break;
		case 2:
			l = updateAccounts(mas_of_accounts, number_of_accounts, l);
			system("pause");
			break;
		case 3:
			delAccounts(mas_of_accounts, number_of_accounts, l);
			system("pause");
			break;
		case 4:
			n = 5;
			break;
		}
	}
}

void workDataAdmin(Bus* mas_of_bus, int number_of_bus) {
	int data = 0;
	Interface<string> b("������ ������ �������� �������������� � ������� �����������");
	while (data != 6) {
		system("cls");
		data = b.menuWorkData();
		switch (data) {
		case 0:
			addBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 1:
			showBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 2:
			updateBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 3:
			delBus(mas_of_bus, number_of_bus);
			system("pause");
			system("cls");
			break;
		case 4:
			sortBus(mas_of_bus, number_of_bus);
			system("cls");
			break;
		case 5:
			searchBus(mas_of_bus, number_of_bus);
			system("cls");
			break;
		case 6:
			data = 6;
			break;
		}
	}
}

void modulAdmin(Accounts*& mas_of_accounts, int& number_of_accounts, Bus*& mas_of_bus, int& number_of_bus, string l) {
	int m = 0;
	Interface<string> b("������ ��������������");
	while (m != 3) {
		system("cls");
		m = b.menuAdmin();
		switch (m) {
		case 0:
			workAccount(mas_of_accounts, number_of_accounts, l);
			break;
		case 1:
			workData(mas_of_bus, number_of_bus);
			break;
		case 2:
			m = 3;
			break;
		}
	}
}

void Registration(Accounts*& mas_of_accounts, int& number_of_accounts, int r) {
	number_of_accounts++;
	Accounts* ptr = new Accounts[number_of_accounts];
	copy(mas_of_accounts, mas_of_accounts + number_of_accounts - 1, ptr);
	mas_of_accounts = ptr;
	ptr = NULL;
	delete[]ptr;
	addAccounts(mas_of_accounts, number_of_accounts, r);
	writeFileAccounts(mas_of_accounts, number_of_accounts);
}

void Authorization(Accounts*& mas_of_accounts, int& number_of_accounts, Bus* mas_of_bus, int& number_of_bus)
{
	if (number_of_accounts != 0) {
		bool power = true;
		string log, pass;
		int exit, quit;
		while (power)
		{
			exit = 0, quit = 0;
			cout << "�����: ";
			log = vvodLogin();
			cout << "������: ";
			pass = vvodPassword();
			for (int i = 0; i < number_of_accounts; i++) {
				if (log == mas_of_accounts[i].getLogin() && pass == mas_of_accounts[i].getPassword()) {
					exit++;
					if (mas_of_accounts[i].getRole() == 1 && mas_of_accounts[i].getAcess() == 1) {
						quit++;
						cout << "�� ����� � ������� ��� ������������� " << mas_of_accounts[i].getLogin() << endl;
						system("pause");
						modulAdmin(mas_of_accounts, number_of_accounts, mas_of_bus, number_of_bus, mas_of_accounts[i].getLogin());
						power = false;
					}
					if (mas_of_accounts[i].getRole() == 0 && mas_of_accounts[i].getAcess() == 1) {
						quit++;
						cout << "�� ����� � ������� ��� ������������ " << mas_of_accounts[i].getLogin() << endl;
						system("pause");
						workData(mas_of_bus, number_of_bus);
						power = false;
					}
				}
			}
			if (exit == 0) {
				cout << "����������� ������ ����� ��� ������\n";
				break;
			}
			else if (exit != 0 && quit == 0) {
				cout << "������� �� �����������\n";
				break;
			}
		}
	}
	else cout << "��������� ���!" << endl;
	system("pause");
}

string isLoginUniq(Accounts* mas_of_accounts, int number_of_accounts) {
	string login;
	int exit;
	while (1)
	{
		cout << "������� ����� �����(�� ����� 3 ��������): ";
		exit = 0;
		login = vvodLogin();
		for (int i = 0; i < number_of_accounts; i++) {
			if (mas_of_accounts[i].getLogin() == login) {
				cout << "������� � ����� ������� ��� ����������, �������� ������!" << endl;
				exit++;
				break;
			}
		}
		if (exit == 0) return login;
	}
}