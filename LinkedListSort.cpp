#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedList.hpp"

using namespace std;

int sortLinkedList(LinkedList<int>* h) {
	LinkedList<int>* head = h;

	int iterations = 0;

	while (head != NULL) {
		
		if (head->prev != NULL && head->prev->getData() > head->getData()) {
			LinkedList<int>* p = head->prev;

			while (p->prev != NULL && p->prev->getData() > head->getData()) {
				p = p->prev;
			}

			int prevData = p->getData();
			int headData = head->getData();

			p->setData(headData);
			head->setData(prevData);

			head = p->next;
		}
		else {
			head = head->next;
		}

		++iterations;
	}

	while (h != NULL) {
		h = h->prev;
	}

	return iterations;
}

const int iters = 100;

int main() {
	LinkedList<int> *ll = new LinkedList<int>(2);

	srand((unsigned)time(0));

	for (int i = 0; i < iters; ++i) {
		int r = rand() % 10000;

		ll->add(r);
	}

	LinkedList<int> *head = ll;

	cout << "unsorted: " << endl;

	while (ll != NULL) {
		cout << ll->getData() << endl;

		ll = ll->next;
	}

	int iters = sortLinkedList(head);

	ll = head->begin();

	cout << endl << endl;
	cout << "sorted: " << endl;
	while (ll != NULL) {
		cout << ll->getData() << endl;

		ll = ll->next;
	}

	cout << "sorted with " << iters << " iterations" << endl;

	return 0;
}
