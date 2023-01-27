#ifndef LINKEDLIST_H
#define LINKEDLIST_H


#include "node.h"
#include <initializer_list>

#include <utility>

using std::endl;
using namespace std;


// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:
template<typename T>

class LinkedList{

	private:
		Node<T>* head;
		Node<T>* tail;
		int totalCount;
		//NodeIterator<T>& itr;


	public:

		LinkedList()
		{
			head = nullptr;
			tail = nullptr;
			totalCount = 0;
		}

//initializer

	LinkedList(std::initializer_list<T> list1)
	: head(nullptr), tail(nullptr), totalCount(0){
		for (const T& element:list1){
			this->push_back(element);
		}
	}

	void push_front(const T item)
	{	

		Node<T> * newNode = new Node<T> (item);
		if (totalCount==0)
			{
				tail = newNode;
				head= newNode;
				++ totalCount;
			}

		else  
			{
				newNode ->next = head;
				head->previous = newNode;
				head = newNode;
				++totalCount;
			}

	}
	T & front()
	{
		if (totalCount == 1)
		{
			return tail-> data;
		}

		else
		{
			return head->data;
		}
	}

	void push_back(const T item)
	{	
		Node<T>* newNode = new Node<T>(item);
		if (totalCount==0)
		{
				tail= newNode;
				head= newNode;
				totalCount++;
		}
		else
		{
			newNode->previous=tail;
			tail->next = newNode;
			tail = newNode;
			++totalCount;
		}
	}

	T & back()
	{
		return tail->data;
	}

	int size()
	{
		return totalCount;
	}

	NodeIterator <T> begin()
	{
		return NodeIterator<T> (head);
	}

	NodeIterator <T> end()
	{
		return NodeIterator<T> (tail->next);
	}


//destructor to delete every node in the list
	~LinkedList()
	{
		Node<T>*current = head;
		Node<T>*toDelete;


		while (current != nullptr)
		{
			toDelete = current;
			current = current->next;
			delete toDelete;
			toDelete = nullptr;
		}

	}

void reverse(){

	Node <T> *current = head;
	Node <T> *tempTail = tail;
	Node<T> *temp = tail;
	Node<T> *tempNext;
	Node<T> *tempPrevious;

	int index=0;

    
    while(index<totalCount) {
//swapping process
        tempNext = temp -> next;
        tempPrevious = temp->previous;
        temp->next = tempPrevious;
     	temp->previous = tempNext;
        temp =tempPrevious;
        index++;

    }
//if index!<totalcount..
  		
    	head = tempTail;
    	tail = current;
    }

//insert function for the node

NodeIterator<T> insert(NodeIterator<T> & itr, const T& someitem)
{	
	//put the original data into the iterator:))
	T originItem = itr.current->data;
	itr.current->data = someitem;
	Node<T> *newNode = new Node<T>(originItem);
	newNode ->next = itr.current->next;
	newNode -> previous = itr.current;
	if (tail==itr.current)
	{
		tail = newNode;
	}
	else
	{
		itr.current->next->previous = newNode;
	}

	itr.current->next = newNode;
	++totalCount;
	return itr;
}

NodeIterator <T>  erase(NodeIterator<T> &itr)
{
	Node<T>* eraseNode = itr.current;
	if (head== itr.current)
	{
		head = eraseNode -> next;
		head-> previous = nullptr;
	}
	else if (tail == itr.current)

	{
		tail = eraseNode-> previous;
		tail -> next = nullptr;
	}
	else
	{
		eraseNode->next->previous = eraseNode->previous;
		eraseNode->previous->next = eraseNode->next;
	}
	--totalCount;
	++itr;
	delete eraseNode;
	return itr;

}

NodeIterator<T> begin() const
{
	return NodeIterator<T>(head);
}

NodeIterator<T> end() const
{
	return NodeIterator<T>(tail->next);
}

};
// do not edit below this line

#endif
