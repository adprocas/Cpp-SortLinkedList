#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int sortLinkedList(LinkedList<int>* h) {
	LinkedList<int>* head = h;

	int iterations = 0;

	while (head != NULL) {
		
		if (head->prev != NULL && head->prev->getData() > head->getData()) {
			//handle previous previous
			if (head->prev->prev != NULL) {
				head->prev->prev->next = head;
			}

			LinkedList<int>* p = head->prev;
			LinkedList<int>* n = head->next;

			//handle head
			//prev
			head->prev = head->prev->prev;
			//next
			head->next = p;

			//handle previous
			//next
			p->next = n;
			//prev
			p->prev = head;

			//handle next
			if (n != NULL) {
				n->prev = p;
			}

			if (p->prev != NULL)
				head = p->prev;
			else 
				head = p;
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

int main() {
	LinkedList<int> *ll = new LinkedList<int>(2);

	ll->add(2);
	ll->add(2);
	ll->add(0);
	ll->add(1);
	ll->add(0);

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
