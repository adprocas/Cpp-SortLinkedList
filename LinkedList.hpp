#pragma once
template <class T>
class LinkedList {
private:
	T data;

	

public:
	LinkedList(T d) {
		data = d;

		prev = NULL;
		next = NULL;
	}

	LinkedList<T> * next;
	LinkedList<T> * prev;

	LinkedList<T> * setPrev(LinkedList<T> * p) {
		prev = p;

		return this;
	}

	LinkedList<T> * setNext(LinkedList<T> * n) {
		next = n;

		return this;
	}

	LinkedList<T>* setData(T d) {
		data = d;

		return this;
	}

	T getData() {
		return data;
	}

	void add(T d) {
		LinkedList<T>* node = this;
		LinkedList<T>* nodeLast = this->prev;
		LinkedList<T>* newNode = new LinkedList<T>(d);

		while (node->next != NULL) {
			nodeLast = node;
			node = node->next;
		}

		node->next = newNode;
		newNode->prev = node;
	}

	LinkedList<T>* begin() {
		LinkedList<T>* t = this;

		while (t->prev != NULL) {
			t = t->prev;
		}

		return t;
	}

	LinkedList<T>* end() {
		LinkedList<T>* t = this;

		while (t->next != NULL) {
			t = t->next;
		}

		return t;
	}
};
