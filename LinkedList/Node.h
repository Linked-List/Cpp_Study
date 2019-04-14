#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node{
private:
    Node *prevNode;
    Node *nextNode;
    string str;
public:
    void setString(string str){
        this->str=str;
    }
    void setNextNode(Node* node){
        this->nextNode=node;
    }
    void setPrevNode(Node* node){
        this->prevNode=node;
    }
    string getString(){
        return this->str;
    }
    Node* getNextNode(){
        return nextNode;
    }
};