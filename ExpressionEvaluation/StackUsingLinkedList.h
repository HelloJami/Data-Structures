#pragma once

#include "DoublyLinkedList.h"

template <typename T>
class Stack {
private:
	DoublyLinkedList<T> linkedList;
public:
	Stack() = default;

	Stack(const Stack& other);
	Stack& operator=(const Stack& rhs); // Assignment operator overloading
	~Stack();
	void push(T const value);
	bool pop(T& value);
	/*T top() {

	}*/
	bool isEmpty() {
		return linkedList.isEmpty();
	}
	bool isFull() {
		return false;
	}
};


template <typename T>
Stack<T>::Stack(const Stack& other) {
	linkedList = other.linkedList;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
	if (this != &rhs) {
		linkedList = rhs.linkedList; // Use the copy assignment operator of DoublyLinkedList
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() {
	T v;
	while (pop(v)) {
		continue;
	}
}

template <typename T>
void Stack<T>::push(T const value) {
	linkedList.insertAtHead(value);
}

template <typename T>
bool Stack<T>::pop(T& value) {
	if (!linkedList.isEmpty()) {
		linkedList.removeAtHead(value);
		return  true;
	}
	else {
		return false;
	}
}