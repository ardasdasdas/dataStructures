#include "queueWithLinkedLists.h"



queue::queue()
{
	Q = new int[size];
	front = 0;
	rear = 0;
	itemCounter = 0;
}


queue::~queue()
{
}
bool queue::isEmpty() {
	return itemCounter == 0;
}
bool queue::isFull() {
	return itemCounter == size;
}
void queue::enQueue(int _item) {
	if(isFull()) {
		std::cout << "The queue is FULL!" << std::endl;
		return;
	}
	else {
		Q[rear] = _item; // put the _item at the end.
		rear++;
		if (rear == size)
			rear = 0;
		itemCounter++; // one more item in the queue
	}

} // end enQueue

int queue::deQueue() {
	int index;
	if (isEmpty()) {
		std::cout << "The queue is EMPTY!" << std::endl;
		return -1;
	}

	index = front;
	front++;
	if (front == size) 
		front = 0;
	itemCounter--; // one less item in the queue

	return Q[index]; // return the item
} // end deQueue
void queue::display() {
	if (!isEmpty()) {
		int j = 1;
		for (int i = front; i < itemCounter; i++)
		{
			std::cout << "[" << j << "]. " << Q[i] << std::endl;
			j++;
		}
	}
}