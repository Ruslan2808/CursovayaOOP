#pragma once
#include "settings.h"

template<class T>
class Interface {
private:
	T data;
public:
	Interface() {
		data = 0;
	}
	Interface(T dat) {
		data = dat;
	}
	int menuMain();
	int menuSort();
	int menuSearch();
	int menuUpdate();
	int menuWorkData();
	int menuStatus();
	int menuAccount();
	int menuWorkAccount();
	int menuAdmin();
	int menuConfirm();
	~Interface() {}
};

template<class T> int Interface<T>::menuMain() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {

		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << "Добро пожаловать\n";

		if (ViborPunktaMenu == 0) {
			setColor(9, 0);
			cout << "->Регистрация" << endl;
			setColor(15, 0);
		}
		else {
			cout << "Регистрация" << endl;
		}

		if (ViborPunktaMenu == 1) {
			setColor(9, 0);
			cout << "->Авторизация" << endl;
			setColor(15, 0);
		}
		else {
			cout << "Авторизация" << endl;
		}

		if (ViborPunktaMenu == 2) {
			setColor(9, 0);
			cout << "->Выход" << endl;
			setColor(15, 0);
		}
		else {
			cout << "Выход" << endl;
		}

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuSort() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 4) % 4;

		if (ViborPunktaMenu == 0) cout << "->Сортировка по марке" << endl;
		else cout << "Сортировка по марке" << endl;

		if (ViborPunktaMenu == 1) cout << "->Сортировка кол-ву мест" << endl;
		else cout << "Сортировка кол-ву мест" << endl;

		if (ViborPunktaMenu == 2) cout << "->Сортировка по году выпуска" << endl;
		else cout << "Сортировка по году выпуска" << endl;

		if (ViborPunktaMenu == 3) cout << "->Выход в меню работы с данными" << endl;
		else cout << "Выход в меню работы с данными" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuUpdate() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		cout << "Редактирование " << data << "-ого автобуса" << endl;
		ViborPunktaMenu = (ViborPunktaMenu + 10) % 10;

		if (ViborPunktaMenu == 0) cout << "->Статус" << endl;
		else cout << "Статус" << endl;

		if (ViborPunktaMenu == 1) cout << "->Фамилия водителя" << endl;
		else cout << "Фамилия водителя" << endl;

		if (ViborPunktaMenu == 2) cout << "->Имя водителя" << endl;
		else cout << "Имя водителя" << endl;

		if (ViborPunktaMenu == 3) cout << "->Отчество водителя" << endl;
		else cout << "Отчество водителя" << endl;

		if (ViborPunktaMenu == 4) cout << "->Марка автобуса" << endl;
		else cout << "Марка автобуса" << endl;

		if (ViborPunktaMenu == 5) cout << "->Номер автобуса" << endl;
		else cout << "Номер автобуса" << endl;

		if (ViborPunktaMenu == 6) cout << "->Кол-во мест" << endl;
		else cout << "Кол-во мест" << endl;

		if (ViborPunktaMenu == 7) cout << "->Цвет" << endl;
		else cout << "Цвет" << endl;

		if (ViborPunktaMenu == 8) cout << "->Год выпуска" << endl;
		else cout << "Год выпуска" << endl;

		if (ViborPunktaMenu == 9) cout << "->Выход в меню работы с данными" << endl;
		else cout << "Выход в меню работы с данными" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuSearch() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 4) % 4;

		if (ViborPunktaMenu == 0) cout << "->Поиск по статусу" << endl;
		else cout << "Поиск по статусу" << endl;

		if (ViborPunktaMenu == 1) cout << "->Поиск по марке" << endl;
		else cout << "Поиск по марке" << endl;

		if (ViborPunktaMenu == 2) cout << "->Поиск по году выпуска" << endl;
		else cout << "Поиск по году выпуска" << endl;

		if (ViborPunktaMenu == 3) cout << "->Выход в меню работы с данными" << endl;
		else cout << "Выход в меню работы с данными" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuWorkData() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 7) % 7;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Добавление автобуса" << endl;
		else cout << "Добавление автобуса" << endl;

		if (ViborPunktaMenu == 1) cout << "->Просмотр автобусов" << endl;
		else cout << "Просмотр автобусов" << endl;

		if (ViborPunktaMenu == 2) cout << "->Редактирование данных автобуса" << endl;
		else cout << "Редактирование данных автобуса" << endl;

		if (ViborPunktaMenu == 3) cout << "->Удаление автобуса" << endl;
		else cout << "Удаление автобуса" << endl;

		if (ViborPunktaMenu == 4) cout << "->Сортировка автобусов" << endl;
		else cout << "Сортировка автобусов" << endl;

		if (ViborPunktaMenu == 5) cout << "->Поиск автобусов" << endl;
		else cout << "Поиск автобусов" << endl;

		if (ViborPunktaMenu == 6) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuStatus() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Маршрут" << endl;
		else cout << "Маршрут" << endl;

		if (ViborPunktaMenu == 1) cout << "->Автопарк" << endl;
		else cout << "Автопарк" << endl;

		if (ViborPunktaMenu == 2) cout << "->Ремонт" << endl;
		else cout << "Ремонт" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuAccount() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 5) % 5;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Изменить логин" << endl;
		else cout << "Изменить логин" << endl;

		if (ViborPunktaMenu == 1) cout << "->Изменить пароль" << endl;
		else cout << "Изменить пароль" << endl;

		if (ViborPunktaMenu == 2) cout << "->Изменить роль" << endl;
		else cout << "Изменить роль" << endl;

		if (ViborPunktaMenu == 3) cout << "->Изменить состояние" << endl;
		else cout << "Изменить состояние" << endl;

		if (ViborPunktaMenu == 4) cout << "->Выход в меню работы с аккаунтами" << endl;
		else cout << "Выход в меню работы с аккаунтами" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuWorkAccount() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 5) % 5;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Просмотр аккаунтов" << endl;
		else cout << "Просмотр аккаунтов" << endl;

		if (ViborPunktaMenu == 1) cout << "->Добавление аккаунта" << endl;
		else cout << "Добавление аккаунта" << endl;

		if (ViborPunktaMenu == 2) cout << "->Редактирование данных аккаунта" << endl;
		else cout << "Редактирование данных аккаунта" << endl;

		if (ViborPunktaMenu == 3) cout << "->Удаление аккаунта" << endl;
		else cout << "Удаление аккаунта" << endl;

		if (ViborPunktaMenu == 4) cout << "->Выход в модуль администратора" << endl;
		else cout << "Выход в модуль администратора" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuConfirm() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 2) % 2;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Да" << endl;
		else cout << "Да" << endl;

		if (ViborPunktaMenu == 1) cout << "->Нет" << endl;
		else cout << "Нет" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}

template<class T> int Interface<T>::menuAdmin() {
	int ViborPunktaMenu = 0, arrow = 0;

	while (true) {
		ViborPunktaMenu = (ViborPunktaMenu + 3) % 3;

		cout << data << endl;

		if (ViborPunktaMenu == 0) cout << "->Модуль работы с аккаунтами" << endl;
		else cout << "Модуль работы с аккаунтами" << endl;

		if (ViborPunktaMenu == 1) cout << "->Модуль работы с данными автопарка" << endl;
		else cout << "Модуль работы с данными автопарка" << endl;

		if (ViborPunktaMenu == 2) cout << "->Выход в главное меню" << endl;
		else cout << "Выход в главное меню" << endl;

		arrow = _getch();
		if (arrow == 224) {
			arrow = _getch();
			if (arrow == 72) ViborPunktaMenu--;
			if (arrow == 80) ViborPunktaMenu++;
		}
		if (arrow == 13) {
			system("cls");
			return ViborPunktaMenu;
		}
		system("cls");
	}
}