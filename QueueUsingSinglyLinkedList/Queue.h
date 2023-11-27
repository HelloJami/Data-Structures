#pragma once
#include "SinglyLinkedlist.h"

class Queue {
private:
	SinglyLinkedListClass queue;

public:
	void enqueue(const int& value);
	bool dequeue(int& value);

	bool isEmpty() {
		return queue.isEmpty();
	}

	bool isFull() {
		return false;
	}
};

void Queue::enqueue(const int& value) {
	queue.insert(value);
}

bool Queue::dequeue(int& value) {
	if (queue.isEmpty())
		return false;
	else {
		queue.removeAtHead(value);
		return true;
	}
}
