#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <string>

class LinkedList {
  using string = std::string;
  public:
    string list();
    LinkedList(): m_pHead(nullptr){}
    bool insert(unsigned uiData);
    bool remove(unsigned &pData);
    void print();
    
  private:
    struct Link {
	unsigned m_uiData;
	Link *m_pNext;
	Link(unsigned uiData, Link *pNext): m_uiData(uiData), m_pNext(pNext){}
    } *m_pHead;
};

std::ostream &operator<<(std::ostream &, LinkedList &);

#endif /* LINKED_LIST_H */ 
