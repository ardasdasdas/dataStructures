#pragma once
#include<iostream>
struct queueNODE {
	int data = 0;
	queueNODE *next;
	queueNODE(int _data) {
		data = _data;
		next = NULL;
	}
};
class queueWithLinkedLists
{
public:

	queueNODE *front;
	queueNODE *rear;
	queueWithLinkedLists();
	~queueWithLinkedLists();
	bool isEmpty();
	void enQueue(int);
	int deQueue();
};

