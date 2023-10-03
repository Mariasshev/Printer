#include "Printer.h"
#include <iostream>
using namespace std;

int main() {
	srand(time(0));
	int amount;
	cout << "Enter amount: ";
	cin >> amount;
	Wait QUP(amount);

	for (int i = 0; i < amount; i++)
	{
		QUP.Add();
	}
	QUP.Show();
	QUP.Extract();

	QUP.Show();
}