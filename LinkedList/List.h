#pragma once
#include "Node.h"
#include <fstream>
using namespace std;

class List{
protected:
    Node *header;
    Node *tailer;
public:
    List(){
        initList();
    }
    void initList(){
        header = new Node();
        tailer = new Node();
        header->setNextNode(tailer);
        tailer->setPrevNode(header);
    }
    void printAll(){
        Node *temp = header->getNextNode();
        while(temp!=tailer){
            cout << temp->getString() << endl;
            temp=temp->getNextNode();
        }
    }
    void add(string str){
        Node* added = new Node();
        added->setString(str);
        Node* temp = header;
        while(temp->getNextNode() != tailer){
            temp = temp->getNextNode();
        }
        temp->setNextNode(added);
        added->setNextNode(tailer);
        tailer->setPrevNode(added);
    }
    void fileSave(){
        ofstream ofs;
        ofs.open("file.txt");
        Node* temp = header->getNextNode();
        while(temp!=tailer){
            ofs << temp->getString() << "\n";
            temp = temp->getNextNode();
        }
        ofs.close();
    }
    void fileLoad(){
        ifstream ifs;
        ifs.open("file.txt");
        string data;
        while(getline(ifs,data)){
            this->add(data);
        }
        ifs.close();
    }
    ~List(){
        Node* temp = header;
        Node* next = header->getNextNode();
        while(true){
            delete temp;
            if(next == nullptr)
                break;
            temp = next;
            next = next->getNextNode();
        }
    }
};