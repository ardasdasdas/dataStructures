#pragma once
#include<iostream>
class queue
{
private:
	int size = 10; // size of the queue
	int *Q; // array holding the queue elements (ints)
	int rear; // front of the queue
	int front; // rear of the queue
	int itemCounter; // # of items in the queue
public:
	queue();
	~queue();
	void enQueue(int);
	int deQueue();
	void display();
	bool isEmpty();
	bool isFull();
};

