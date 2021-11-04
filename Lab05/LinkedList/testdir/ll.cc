#include "ll.h" 
#include <cstdlib>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool LinkedList::insert(unsigned uiData) {
	Link* new_link = new Link(uiData, m_pHead);	// Get a new node and fill with data.

	m_pHead = new_link;				// Put it at the head.

	return true;				// Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
	if (!m_pHead)				// Empty list?
		return false;				// Indicate failure.

	Link *temp = m_pHead;			// Point to the first node.
	m_pHead = m_pHead->m_pNext;			// Remove the first node.
	pData = temp->m_uiData;			// Obtain first node’s data.
	delete temp;

	return true;				// Indicate success.
}

void LinkedList::print(){
	Link *temp = m_pHead;
	unsigned tempData;
	while(temp){
		tempData = temp->m_uiData;
		temp = temp->m_pNext;
		cout << tempData;
		if(temp){
			cout << " ";
		}
	}
}

std::ostream &operator<<(std::ostream &out, LinkedList &ll){
	ll.print();
	return out << "\n";
}
