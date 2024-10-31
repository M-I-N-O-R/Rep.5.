#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

void createAccount(string& owner, double& balance);
void deposit(double* balance);
void withdraw(double* balance);
void displayAccounts(const string owners[], const double balance[], int accountCount);

int main() {
	setlocale(0, ".1251");
	string owners[MAX_ACCOUNTS];
	double balance[MAX_ACCOUNTS];
	int accountCount = 0;
	int choice;

	do {
		cout << "------------------------" << endl;
		cout << "1. Створити банкiвський рахунок" << endl;
		cout << "2. Поповнення рахунку" << endl;
		cout << "3. Зняття грошей" << endl;
		cout << "4. Вiдображення iнформацiї про рахунки" << endl;
		cout << "5. Вихiд" << endl;
		cout <<"   Виберiть пункт : " << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			if (accountCount < MAX_ACCOUNTS) {
				createAccount(owners[accountCount], balance[accountCount]);
				accountCount++;
			}
			else {
				cout << "Лiмiт акаунтiв досягнуто" << endl;
			}
			break;

		case 2:
			int accountNumber;
			cout << "Введiть номер аккаунта: ";
			cin >> accountNumber;

			if (accountNumber < 0 || accountNumber >= accountCount) {
				cout << "Помилка: Неправильний номер аккаунта." << endl;
			}
			else {
				int depositAmount;
				cout << "Введiть суму поповнення: ";
				cin >> depositAmount;

				if (depositAmount <= 0) {
					cout << "Помилка: Сума поповнення має бути бiльше 0." << endl;
				}
				else {
					deposit(&balance[accountNumber]);
					cout << "Поповнення успiшно здiйснено." << endl;
				}
			}
			break;

		case 3:
			int accountNumbers;
			cout << "Введiть номер аккаунта: ";
			cin >> accountNumbers;
			if (accountNumbers < 0 || accountNumbers >= accountCount) {
				cout << "Помилка: Неправильний номер аккаунта." << endl;
			}
			else {
				int depositAmount;
				cout << "Введiть суму зняття: ";
				cin >> depositAmount;

				if (depositAmount <= 0) {
					cout << "Помилка: Сума зняття має бути бiльше 0." << endl;
				}
				else {
					withdraw(&balance[accountNumbers]);
					cout << "Зняття успiшно здiйснено." << endl;
				}
			}
			break;

		case 4:
			displayAccounts(owners, balance, accountCount);
			break;

		case 5:
			cout << "Вихiд" << endl;
			break;
		}

	} while (choice != 5);

	return 0;
}

void createAccount(string& owner, double& balance) {
	cout << "Введiть iм'я: ";
	cin >> owner;
	cout << "Введiть суму: ";
	cin >> balance;
	cout << "Рахунок створено: " << owner << endl;
	cout << "Баланс: " << balance << endl;
}

void deposit(double* balance) {
	double amount;
	cout << "Сума поповнення: " << endl;
	cin >> amount;
	if (amount > 0) {
		*balance += amount;
		cout << "Баланс оновлено" << endl;
	}
}

void withdraw(double* balance) {
	double amount;
	cout << "Сума зняття: " << endl;
	cin >> amount;

	if (amount > 0 && *balance >= amount) {
		*balance -= amount;
	}
	else {
		cout << "Помилка, коштiв невистачає." << endl;
	}
}

void displayAccounts(const string owners[], const double balance[], int accountCount) {
	cout << "Список рахункiв: " << endl;
	for (int i = 0; i < accountCount; i++)
	{
		cout << "Рахунок " << i + 1 << ": " << owners[i] << ", Баланс: " << balance[i] << endl;
	}
}

