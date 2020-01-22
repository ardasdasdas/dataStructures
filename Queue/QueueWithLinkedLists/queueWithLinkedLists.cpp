#include "queueWithLinkedLists.h"



queueWithLinkedLists::queueWithLinkedLists()
{
	front = NULL;
	rear = NULL;
}

queueWithLinkedLists::~queueWithLinkedLists()
{
}

bool queueWithLinkedLists::isEmpty() {
	return front == NULL;
}

void queueWithLinkedLists::enQueue(int _data) {
	queueNODE *qNODE = new queueNODE(_data);

	if (front == NULL) {
		front = rear = qNODE;
	}
	else {
		rear->next = qNODE;
		rear = qNODE;
	}
} // end enQueue


int queueWithLinkedLists::deQueue() {
	if (isEmpty()) {
		std::cout << "The queue is EMPTY!" << std::endl;
		return -1;
	}

	queueNODE *temp = front;

	front = front->next;
	if (front == NULL)
		rear = NULL;

	return temp->data;
} //  end deQueue