#include "Printer.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


Wait::Wait(int len)
{
	MaxLenght = len;
	name = new string[20];
	time = new string[100];
	Queue = new int[MaxLenght];
	Pri = new int [MaxLenght];
	QueueLength = 0;
}

bool Wait::IsEmpty()
{
	return QueueLength == 0;
}

bool Wait::IsFull()
{
	return QueueLength == MaxLenght;
}

int Wait::GetCount()
{
	return QueueLength;
}

int Wait::GetMaxLength()
{
	return MaxLenght;
}

int Wait::GetQueueLength()
{
	return QueueLength;
}

int Wait::Extract()
{
	// Если в очереди есть элементы, то возвращаем тот, 
	// у которого наивысший приоритет и сдвигаем очередь	
	if (!IsEmpty()) {


		//пусть приоритетный элемент - нулевой
		int max_pri = Pri[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;

		//ищем приоритет
		for (int i = 1; i < QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri < Pri[i]) {
				max_pri = Pri[i];
				pos_max_pri = i;
			}

		//вытаскиваем приоритетный элемент
		int temp1 = Queue[pos_max_pri];
		int temp2 = Pri[pos_max_pri];

		//сдвинуть все элементы
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			Queue[i] = Queue[i + 1];
			Pri[i] = Pri[i + 1];
		}
		//уменьшаем количество
		QueueLength--;
		// возврат извлеченного элемента	
		return temp1;

	}
	else return -1;
}

void Wait::Show()
{
	for (int i = 0; i < QueueLength; i++) {
		cout << name[i] << " - " << Pri[i] << " - " << time[i] << "\n\n";
	}
	cout << "\n-------------------------------------\n";
}

void Wait::Add()
{
	SYSTEMTIME t;
	GetLocalTime(&t);
	if (!IsFull()) 
	{
		cout << "Priority: ";
		cin >> Pri[QueueLength];
		cout << "Name: ";
		cin.ignore();
		getline(cin, name[QueueLength]);
		time[QueueLength] = to_string(t.wHour) + ":" + to_string(t.wMinute) + ":" + to_string(t.wSecond);
		QueueLength++;
	}
}

Wait::~Wait()
{
	delete[]name;
	delete[]Pri;
	delete[]time;
}
