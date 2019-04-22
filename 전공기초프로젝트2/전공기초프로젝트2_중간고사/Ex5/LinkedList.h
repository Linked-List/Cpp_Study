#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;
class LinkedList
{
	Node* header;
	Node* trailer;
public:
	LinkedList() {
		header = new Node();
		trailer = new Node();

		header->setNextNode(trailer);
		trailer->setPrevNode(header);
	}
	~LinkedList() {
		Node* temp = header;
		Node* next = header->getNextNode();
		while (next != trailer) {
			delete temp;
			temp = next;
			next = next->getNextNode();
		}
		delete temp;
		delete next;
	}

	void add(string str) {
		Node* toAdd = new Node();
		toAdd->setElement(str);

		toAdd->setPrevNode(trailer->getPrevNode());
		toAdd->setNextNode(trailer);
		trailer->getPrevNode()->setNextNode(toAdd);
		trailer->setPrevNode(toAdd);
	}
	void printAll() {
		Node* temp = header->getNextNode();
		while (temp != trailer) {
			cout << temp->getElement() << endl;
			temp = temp->getNextNode();
		}
	}

	void readFile(ifstream& from) {
		string str;
		while (getline(from, str)) {
			this->add(str);
		}
	}
};

