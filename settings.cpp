#include "menu.h"
#include "accounts.h"

void SettingsConsole() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

void setColor(int text, int background) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}