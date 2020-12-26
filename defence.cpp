#include "defence.h"

void existenceFile(string FILE_NAME) {
	ifstream file;
	file.open(FILE_NAME);
	if (!file) {
		ofstream fout(FILE_NAME, ios::out);
		fout.close();
		cout << "Файл с именем " << FILE_NAME << " создан" << endl;
	}
	file.close();
}

string vvodLogin() {
	string word;
	int Knopka;
	char symbol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else {
			if (Knopka == 13 && word.length() >= 3) break;
			else {
				symbol = (char)Knopka;
				if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9') || symbol == '_') {
					word = word + symbol;
					cout << symbol;
				}
			}
		}
	}
	cout << endl;
	return word;
}

string vvodPassword() {
	string parol;
	int i;
	char par;
	while (true) {
		i = _getch();
		if (i == 8) {
			if (parol.length() != 0) {
				cout << '\b' << " " << '\b';
				parol.erase(parol.length() - 1);
			}
		}
		else
			if (i == 13 && parol.length() >= 5) break;
			else
				if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9')) {
					par = (char)i;
					parol = parol + par;
					cout << "*";
				}
	}
	cout << endl;
	return parol;
}

string encryptionPassword(string password) {
	string enc;
	for (int i = 0; i < password.length(); i++) {
		char s = password[i];
		s = s + '+';
		enc.push_back(s);
	}
	return enc;
}

string deencryptionPassword(string password) {
	string enc;
	for (int i = 0; i < password.length(); i++) {
		char s = password[i];
		s = s - '+';
		enc.push_back(s);
	}
	return enc;
}

string getWords() {
	string word;
	int Knopka;
	char symbol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				symbol = (char)Knopka;
				if ((symbol >= 'а' && symbol <= 'я') || (symbol >= 'А' && symbol <= 'Я') || symbol == ' ') {
					word = word + symbol;
					cout << symbol;
				}
			}
	}
	cout << endl;
	return word;
}

string getNumber() {
	string word;
	int Knopka;
	char symbol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() == 9 && (word[5] >= 'A' && word[5] <= 'Z') && (word[6] >= 'A' && word[6] <= 'Z') && (word[8] >= '0' && word[8] <= '9')) break;
			else {
				symbol = (char)Knopka;
				if ((symbol >= 'A' && symbol <= 'Z') || (symbol >= '0' && symbol <= '9')) {
					word = word + symbol;
					cout << symbol;
				}
				if (word.length() == 4) {
					word = word + " ";
					cout << " ";
				}
				if (word.length() == 7) {
					word = word + "-";
					cout << "-";
				}
			}
	}
	cout << endl;
	return word;
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

int getYearCar() {
	string year;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (year.length() != 0) {
					cout << '\b' << " " << '\b';
					year.erase(year.length() - 1);
				}
			}
			else
				if (key == 13 && year.length() == 4 && stoi(year) <= 2020 && stoi(year) >= 1970) break;
				else
					if (key >= '0' && key <= '9') {
						year = year + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(year);
}

int vvodRole() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '1') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

int getCountOfStucturesInFile(string FILE_NAME, int n)
{
	ifstream file(FILE_NAME, ios::in);
	int count_of_strings = 0;
	if (file.is_open())
	{
		string buffer;
		while (getline(file, buffer))
			count_of_strings++;
	}
	file.close();
	return count_of_strings / n;
}