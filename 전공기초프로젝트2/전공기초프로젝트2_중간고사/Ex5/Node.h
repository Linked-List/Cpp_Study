#pragma once
#include <string>
using namespace std;
class Node
{
private:
	string element;
	Node* prevNode;
	Node* nextNode;
public:
	void setElement(string str) {
		element = str;
	}
	void setPrevNode(Node* p) {
		prevNode = p;
	}
	void setNextNode(Node* p) {
		nextNode = p;
	}
	string getElement() {
		return element;
	}
	Node* getPrevNode() {
		return prevNode;
	}
	Node* getNextNode() {
		return nextNode;
	}
};

