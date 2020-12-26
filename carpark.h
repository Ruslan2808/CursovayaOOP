#pragma once
#include "menu.h"
#pragma warning(disable:4250)

class CarPark {
public:
	virtual string getStatus() = 0;
	virtual string getSurname() = 0;
	virtual string getName() = 0;
	virtual string getPat() = 0;
	virtual string getMarka() = 0;
	virtual string getNum() = 0;
	virtual int getKolmest() = 0;
	virtual string getColor() = 0;
	virtual int getYear() = 0;
	virtual void updateStatus(string) = 0;
	virtual void updateName(string) = 0;
	virtual void updateSurname(string) = 0;
	virtual void updatePat(string) = 0;
	virtual void updateMarka(string) = 0;
	virtual void updateNum(string) = 0;
	virtual void updateKolmest(int) = 0;
	virtual void updateColor(string) = 0;
	virtual void updateYear(int) = 0;
};

class Status: virtual public CarPark {
protected:
	string status;
public:
	Status();
	void updateStatus(string);
	string getStatus();
	~Status();
};

class Voditel : virtual public CarPark {
protected:
	string name;
	string surname;
	string pat;
public:
	Voditel();
	string getSurname();
	string getName();
	string getPat();
	void updateName(string);
	void updateSurname(string);
	void updatePat(string);
	~Voditel();
};

class CharakteristicsBus : public Status {
protected:
	int kolmest;
	string color;
	int year;
public:
	CharakteristicsBus();
	int getKolmest();
	string getColor();
	int getYear();
	void updateKolmest(int);
	void updateColor(string);
	void updateYear(int);
	~CharakteristicsBus();
};


class Bus : public Voditel, public CharakteristicsBus {
private:
	string marka;
	string num;
public:
	Bus();
	Bus(const Bus&);
	string getMarka();
	string getNum();
	void updateMarka(string);
	void updateNum(string);
	friend ostream& operator<<(ostream&, Bus&);
	friend ifstream& operator>>(ifstream&, Bus&);
	friend ofstream& operator<<(ofstream&, Bus&);
	~Bus();
};

void writeFileBus(Bus*, int);

void readFileBus(Bus*, int&);

void showBus(Bus*, int);

void addBus(Bus*&, int&);

void vvodDataBus(Bus*&, int&);

void delBus(Bus*&, int&);

void updateBus(Bus*&, int);

void sortmarkaBus(Bus*&, int);

void sortkolmestBus(Bus*&, int);

void sortyearBus(Bus*&, int);

void sortBus(Bus*, int);

void searchstatusBus(Bus*, int);

void searchmarkaBus(Bus*, int);

void searchyearBus(Bus*, int);

void searchBus(Bus*, int);

void workData(Bus*, int);

string isNumberUniq(Bus*, int);