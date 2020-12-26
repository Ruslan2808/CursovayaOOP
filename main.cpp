#include "menu.h"
#include "accounts.h"
#include "carpark.h"
#include "settings.h"
#include "defence.h"

int main() {
	SettingsConsole();
	existenceFile(FILE_OF_ACCOUNTS);
	existenceFile(FILE_OF_CARPARK);
	system("pause");
	bool quit = true;
	int nBus = getCountOfStucturesInFile(FILE_OF_CARPARK, 9);
	int nAcc = getCountOfStucturesInFile(FILE_OF_ACCOUNTS, 4);
	Bus* bus = new Bus[nBus];
	Accounts* acc = new Accounts[nAcc];
	Interface<int> b;
	readFileAccounts(acc, nAcc);
	readFileBus(bus, nBus);
	while (quit) {
		system("cls");
		switch (b.menuMain()) {
		case 0:
			cout << "\tРегистрация\n";
			Registration(acc, nAcc, 0);
			break;
		case 1:
			cout << "\tАвторизация\n";
			Authorization(acc, nAcc, bus, nBus);
			break;
		case 2:
			quit = false;
			break;
		}
	}
	delete[]acc;
	delete[]bus;
	return 0;
}