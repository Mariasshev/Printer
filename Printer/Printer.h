#pragma once
#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;


class Wait {
	string* name;
	int* Pri;
	string* time;
	int* Queue;
	int QueueLength;
	int MaxLenght;
public:
	Wait(int len);
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	int GetMaxLength();
	int GetQueueLength();
	int Extract();
	void Show();
	void Add();
	~Wait();
};