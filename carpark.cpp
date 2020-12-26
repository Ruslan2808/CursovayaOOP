#include "carpark.h"
#include "menu.h"
#include "defence.h"

Status::Status()
{

}

void Status::updateStatus(string st) {
	status = st;
}

string Status::getStatus()
{
	return status;
}

Status::~Status() {

}

Voditel::Voditel() {

}

string Voditel::getSurname()
{
	return surname;
}

string Voditel::getName()
{
	return name;
}

string Voditel::getPat()
{
	return pat;
}

void Voditel::updateName(string nam) {
	name = nam;
}

void Voditel::updateSurname(string sn) {
	surname = sn;
}

void Voditel::updatePat(string p) {
	pat = p;
}

Voditel::~Voditel() {

}

Bus::Bus() {
	kolmest = 0;
	year = 0;
}

Bus::Bus(const Bus& obj)
{
	status = obj.status;
	surname = obj.surname;
	name = obj.name;
	pat = obj.pat;
	marka = obj.marka;
	num = obj.num;
	kolmest = obj.kolmest;
	color = obj.color;
	year = obj.year;
}

string Bus::getMarka()
{
	return marka;
}

string Bus::getNum()
{
	return num;
}

CharakteristicsBus::CharakteristicsBus(): Status()
{
	kolmest = 0;
	year = 0;
}

int CharakteristicsBus::getKolmest()
{
	return kolmest;
}

string CharakteristicsBus::getColor()
{
	return color;
}

int CharakteristicsBus::getYear()
{
	return year;
}

void Bus::updateMarka(string m) {
	marka = m;
}

void Bus::updateNum(string n) {
	num = n;
}

void CharakteristicsBus::updateKolmest(int k) {
	kolmest = k;
}

void CharakteristicsBus::updateColor(string clr) {
	color = clr;
}

void CharakteristicsBus::updateYear(int y) {
	year = y;
}

CharakteristicsBus::~CharakteristicsBus()
{
}

Bus::~Bus() {

}

ostream& operator<<(ostream& out, Bus& bus)
{
	out << "Статус: " << bus.getStatus() << endl;
	if (bus.getStatus() == "Маршрут") {
		out << "ФИО водителя: " << bus.getSurname() << " ";
		out << bus.getName()[0] << ".";
		out << bus.getPat()[0] << "." << endl;
	}
	/*else {
		out << "ФИО водителя: " << "-" << endl;
	}*/
	out << "Марка: " << bus.getMarka() << endl;
	out << "Номер автобуса: " << bus.getNum() << endl;
	out << "Кол-во мест: " << bus.getKolmest() << endl;
	out << "Цвет: " << bus.getColor() << endl;
	out << "Год выпуска: " << bus.getYear() << endl;
	return out;
}

ifstream& operator>>(ifstream& fin, Bus& bus)
{
	string s;
	getline(fin, bus.status);
	getline(fin, bus.surname);
	getline(fin, bus.name);
	getline(fin, bus.pat);
	getline(fin, bus.marka);
	getline(fin, bus.num);
	getline(fin, s);
	bus.kolmest = stoi(s);
	getline(fin, bus.color);
	getline(fin, s);
	bus.year = stoi(s);
	return fin;
}

ofstream& operator<<(ofstream& fout, Bus& bus)
{
	fout << bus.status << endl;
	fout << bus.surname << endl;
	fout << bus.name << endl;
	fout << bus.pat << endl;
	fout << bus.marka << endl;
	fout << bus.num << endl;
	fout << bus.kolmest << endl;
	fout << bus.color << endl;
	fout << bus.year << endl;
	return fout;
}

void writeFileBus(Bus* mas_of_bus, int number_of_bus) {
	ofstream fout(FILE_OF_CARPARK, ios::out);
	for (int i = 0; i < number_of_bus; i++) {
		fout << mas_of_bus[i];
	}
	fout.close();
}

void readFileBus(Bus* mas_of_bus, int& number_of_bus) {
	if (number_of_bus != 0) {
		ifstream fin(FILE_OF_CARPARK, ios::in);
		int i = 0;
		while (fin.peek() != EOF) {
			fin >> mas_of_bus[i];
			i++;
		}
		number_of_bus = i;
		fin.close();
	}
}

void showBus(Bus* mas_of_bus, int number_of_bus)
{
	if (number_of_bus > 0) {
		for (int i = 0; i < number_of_bus; i++) {
			cout << "\tАтобус № " << i + 1 << endl;
			cout << mas_of_bus[i] << endl;
			//Sleep(500);
		}
	}
	else cout << "Нет автобусов" << endl;
}

void addBus(Bus*& mas_of_bus, int& number_of_bus) {
	number_of_bus++;
	Bus* ptr = new Bus[number_of_bus];
	copy(mas_of_bus, mas_of_bus + number_of_bus - 1, ptr);
	mas_of_bus = ptr;
	ptr = NULL;
	delete[]ptr;
	vvodDataBus(mas_of_bus, number_of_bus);
	writeFileBus(mas_of_bus, number_of_bus);
}

void vvodDataBus(Bus*& mas_of_bus, int& number_of_bus) {
	string st, sm, n, p, m, num, c;
	int k, y;
	st = "Автопарк";
	mas_of_bus[number_of_bus - 1].updateStatus(st);
	if (st == "Маршрут") {
		cout << "Фамилия водителя: ";
		sm = getWords();
		mas_of_bus[number_of_bus - 1].updateSurname(sm);
		cout << "Имя: ";
		n = getWords();
		mas_of_bus[number_of_bus - 1].updateName(n);
		cout << "Отчество: ";
		p = getWords();
		mas_of_bus[number_of_bus - 1].updatePat(p);
	}
	else {
		mas_of_bus[number_of_bus - 1].updateSurname("-");
		mas_of_bus[number_of_bus - 1].updateName("-");
		mas_of_bus[number_of_bus - 1].updatePat("-");
	}
	cout << "Марка автобуса: ";
	m = getWords();
	mas_of_bus[number_of_bus - 1].updateMarka(m);
	num = isNumberUniq(mas_of_bus, number_of_bus);
	mas_of_bus[number_of_bus - 1].updateNum(num);
	cout << "Количество мест: ";
	k = getInt();
	mas_of_bus[number_of_bus - 1].updateKolmest(k);
	cout << "Цвет: ";
	c = getWords();
	mas_of_bus[number_of_bus - 1].updateColor(c);
	cout << "Год выпуска: ";
	y = getYearCar();
	mas_of_bus[number_of_bus - 1].updateYear(y);
}

void delBus(Bus*& mas_of_bus, int& number_of_bus) {
	showBus(mas_of_bus, number_of_bus);
	int num;
	if (number_of_bus > 0) {
		cout << "Введите номер автобуса, который хотите удалить: ";
		num = getInt();
		if (num > number_of_bus || num == 0) {
			cout << "Такого автобуса нет" << endl;
		}
		else {
			system("cls");
			Interface<string> b("Вы действительно хотите удалить автобус из автопарка?");
			if (b.menuConfirm() == 0) {
				for (int i = num - 1; i < number_of_bus - 1; i++) {
					mas_of_bus[i] = mas_of_bus[i + 1];
				}
				cout << "Автобус удален!" << endl;
				number_of_bus--;
			}
		}
	}
	writeFileBus(mas_of_bus, number_of_bus);
}

void updateBus(Bus*& mas_of_bus, int number_of_bus) {
	showBus(mas_of_bus, number_of_bus);
	string status, surname, name, pat, marka, num, color;
	int kolmest, year, n, up;
	bool quit = true;
	Interface<string> c("Введите новый статус: ");
	if (number_of_bus != 0) {
		cout << "Введите номер автобуса, который хотите изменить: ";
		n = getInt();
		if (n > number_of_bus || n == 0) {
			cout << "Нет такого автобуса" << endl;
		}
		else {
			Interface<int> b(n);
			while (quit) {
				system("cls");
				up = b.menuUpdate();
				switch (up) {
				case 0:
					cout << "Текущий статус: ";
					cout << mas_of_bus[n - 1].getStatus();
					cout << endl;
					system("pause");
					system("cls");
					switch (c.menuStatus()) {
					case 0:
						status = "Маршрут";
						mas_of_bus[n - 1].updateStatus(status);
						break;
					case 1:
						status = "Автопарк";
						mas_of_bus[n - 1].updateStatus(status);
						break;
					case 2:
						status = "Ремонт";
						mas_of_bus[n - 1].updateStatus(status);
						break;
					}
					if (status == "Маршрут") {
						cout << "Фамилия водителя: ";  mas_of_bus[n - 1].updateSurname(getWords());
						cout << "Имя: "; mas_of_bus[n - 1].updateName(getWords());
						cout << "Отчество: "; mas_of_bus[n - 1].updatePat(getWords());
					}
					break;
				case 1:
					if (mas_of_bus[n - 1].getStatus() == "Маршрут") {
						cout << "Текущяя фамилия: ";
						cout << mas_of_bus[n - 1].getSurname();
						cout << endl;
						cout << "Введите новую фамилию водителя: ";
						surname = getWords();
						mas_of_bus[n - 1].updateSurname(surname);
					}
					else {
						cout << "Нельзя изменить фамилию водителя, т.к. автобус не на маршруте" << endl;
					}
					system("pause");
					break;
				case 2:
					if (mas_of_bus[n - 1].getStatus() == "Маршрут") {
						cout << "Текущее имя: ";
						cout << mas_of_bus[n - 1].getName();
						cout << endl;
						cout << "Введите новое имя водителя: ";
						name = getWords();
						mas_of_bus[n - 1].updateName(name);
					}
					else {
						cout << "Нельзя изменить имя водителя, т.к. автобус не на маршруте" << endl;
					}
					system("pause");
					break;
				case 3:
					if (mas_of_bus[n - 1].getStatus() == "Маршрут") {
						cout << "Текущее отчество: ";
						cout << mas_of_bus[n - 1].getPat();
						cout << endl;
						cout << "Введите новое отчество водителя: ";
						pat = getWords();
						mas_of_bus[n - 1].updatePat(pat);
					}
					else {
						cout << "Нельзя изменить отчество водителя, т.к. автобус не на маршруте" << endl;
					}
					system("pause");
					break;
				case 4:
					cout << "Текущяя марка: ";
					cout << mas_of_bus[n - 1].getMarka();
					cout << endl;
					cout << "Введите новыую марку: ";
					marka = getWords();
					mas_of_bus[n - 1].updateMarka(marka);
					break;
				case 5:
					cout << "Текущий номер: ";
					cout << mas_of_bus[n - 1].getNum();
					cout << endl;
					cout << "Введите новый номер: ";
					num = getNumber();
					mas_of_bus[n - 1].updateNum(num);
					break;
				case 6:
					cout << "Текущее кол-во мест: ";
					cout << mas_of_bus[n - 1].getKolmest();
					cout << endl;
					cout << "Введите новое кол-во мест: ";
					kolmest = getInt();
					mas_of_bus[n - 1].updateKolmest(kolmest);
					break;
				case 7:
					cout << "Текущий цвет: ";
					cout << mas_of_bus[n - 1].getColor();
					cout << endl;
					cout << "Введите новый цвет: ";
					color = getWords();
					mas_of_bus[n - 1].updateColor(color);
					break;
				case 8:
					cout << "Текущий год выпуска: ";
					cout << mas_of_bus[n - 1].getYear();
					cout << endl;
					cout << "Введите новый год выпуска: ";
					year = getYearCar();
					mas_of_bus[n - 1].updateYear(year);
					break;
				case 9:
					quit = false;
					break;
				}
			}
		}
	}
	writeFileBus(mas_of_bus, number_of_bus);
}

void sortmarkaBus(Bus*& mas_of_bus, int number_of_bus)
{
	Bus marka;
	for (int i = 0; i < number_of_bus - 1; i++) {
		for (int j = i + 1; j < number_of_bus; j++) {
			if (mas_of_bus[i].getMarka()[0] > mas_of_bus[j].getMarka()[0]) {
				marka = mas_of_bus[i];
				mas_of_bus[i] = mas_of_bus[j];
				mas_of_bus[j] = marka;
			}
		}
	}
	cout << "Сортировка прошла успешно\n";
	showBus(mas_of_bus, number_of_bus);
	system("pause");
}

void sortkolmestBus(Bus*& mas_of_bus, int number_of_bus) {
	Bus kolmest;
	for (int i = 0; i < number_of_bus - 1; i++) {
		for (int j = i + 1; j < number_of_bus; j++) {
			if (mas_of_bus[i].getKolmest() > mas_of_bus[j].getKolmest()) {
				kolmest = mas_of_bus[i];
				mas_of_bus[i] = mas_of_bus[j];
				mas_of_bus[j] = kolmest;
			}
		}
	}
	cout << "Сортировка прошла успешно\n";
	showBus(mas_of_bus, number_of_bus);
	system("pause");
}

void sortyearBus(Bus*& mas_of_bus, int number_of_bus) {
	Bus year;
	for (int i = 0; i < number_of_bus - 1; i++) {
		for (int j = i + 1; j < number_of_bus; j++) {
			if (mas_of_bus[i].getYear() > mas_of_bus[j].getYear()) {
				year = mas_of_bus[i];
				mas_of_bus[i] = mas_of_bus[j];
				mas_of_bus[j] = year;
			}
		}
	}
	cout << "Сортировка прошла успешно\n";
	showBus(mas_of_bus, number_of_bus);
	system("pause");
}

void sortBus(Bus* mas_of_bus, int number_of_bus) {
	int sort = 0;
	if (number_of_bus == 0) {
		cout << "Нет автобусов" << endl;
		system("pause");
	}
	else {
		Interface<int> b;
		while (sort != 4) {
			system("cls");
			sort = b.menuSort();
			switch (sort) {
			case 0:
				sortmarkaBus(mas_of_bus, number_of_bus);
				break;
			case 1:
				sortkolmestBus(mas_of_bus, number_of_bus);
				break;
			case 2:
				sortyearBus(mas_of_bus, number_of_bus);
				break;
			case 3:
				sort = 4;
				break;
			}
		}
	}
	writeFileBus(mas_of_bus, number_of_bus);
}

void searchstatusBus(Bus* mas_of_bus, int number_of_bus) {
	string status;
	int p = 0;
	cout << "Введите статус: ";
	status = getWords();
	for (int i = 0; i < number_of_bus; i++) {
		int kol = 0;
		if (status.length() <= mas_of_bus[i].getStatus().length()) {
			for (int j = 0; j < status.length(); j++) {
				if (status[j] != tolower(mas_of_bus[i].getStatus()[j]) && status[j] != toupper(mas_of_bus[i].getStatus()[j])) kol++;
			}
			if (kol == 0) {
				cout << "\tАвтобус № " << i + 1 << endl;
				cout << mas_of_bus[i];
				p = 1;
			}
		}
	}
	if (p == 0) cout << "Нет таких автобусов\n";
	system("pause");
}

void searchmarkaBus(Bus* mas_of_bus, int number_of_bus) {
	string marka;
	int p = 0;
	cout << "Введите марку: ";
	marka = getWords();
	for (int i = 0; i < number_of_bus; i++) {
		int kol = 0;
		if (marka.length() <= mas_of_bus[i].getMarka().length()) {
			for (int j = 0; j < marka.length(); j++) {
				if (marka[j] != tolower(mas_of_bus[i].getMarka()[j]) && marka[j] != toupper(mas_of_bus[i].getMarka()[j])) kol++;
			}
			if (kol == 0) {
				cout << "\tАвтобус № " << i + 1 << endl;
				cout << mas_of_bus[i];
				p = 1;
			}
		}
	}
	if (p == 0) cout << "Нет таких автобусов\n";
	system("pause");
}

void searchyearBus(Bus* mas_of_bus, int number_of_bus) {
	int year = 0, kolvo = 0;
	cout << "Введите год выпуска: ";
	cin >> year;
	for (int i = 0; i < number_of_bus; i++) {
		if (year == mas_of_bus[i].getYear()) {
			cout << "\tАвтобус № " << i + 1 << endl;
			cout << mas_of_bus[i];
			kolvo++;
		}
	}
	if (kolvo == 0) cout << "Нет таких автобусов\n";
	system("pause");
}

void searchBus(Bus* mas_of_bus, int number_of_bus) {
	int search = 0;
	if (number_of_bus == 0) {
		cout << "Нет автобусов" << endl;
		system("pause");
	}
	else {
		Interface<int> b;
		while (search != 4) {
			system("cls");
			search = b.menuSearch();
			switch (search) {
			case 0:
				searchstatusBus(mas_of_bus, number_of_bus);
				break;
			case 1:
				searchmarkaBus(mas_of_bus, number_of_bus);
				break;
			case 2:
				searchyearBus(mas_of_bus, number_of_bus);
				break;
			case 3:
				search = 4;
				break;
			}
		}
	}
}

void workData(Bus* mas_of_bus, int number_of_bus) {
	int data = 0;
	Interface<string> b("МОДУЛЬ РАБОТЫ ПОЛЬЗОВАТЕЛЯ");
	while (data != 7) {
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
			data = 7;
			break;
		}
	}
}

string isNumberUniq(Bus* mas_of_bus, int number_of_bus) {
	string num;
	int exit;
	while (1)
	{
		exit = 0;
		cout << "Номер автобуса: ";
		num = getNumber();
		for (int i = 0; i < number_of_bus; i++) {
			if (mas_of_bus[i].getNum() == num) {
				cout << "Автобус с таким номером уже существует, выберите другой!" << endl;
				exit++;
				break;
			}

		}
		if (exit == 0) return num;
	}
}