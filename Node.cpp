#include "Node.h"
#include <string.h>
#include <cstddef>
#include <iostream>
using std::cout;
using std::endl;

Node::Node() {
    next=NULL;
    prev=NULL;
    position = 0;
}
    
void Node::setPrev(Node* prev) {        
    this->prev = prev;    
}

void Node::setNext(Node* next){
    this->next = next;
}

Node* Node::getNext(){
    return next;
} 

Node* Node::getPrev(){
    return prev;
}

void Node::setName(char* name){
    strcpy(this->name, name);
}

void Node::setRg(char* rg){
    strcpy(this->rg, rg);
}

void Node::setReg(int n){
    n_register = n;
}

int Node::getReg(){
    return n_register;
}

char* Node::getName(){
    return name;
}

char* Node::getRg(){
    return rg;
}

void Node::setPos(int pos){
    position = pos;
}

int Node::getPos(){
    return position;
}

void Node::sumPos(int sum){
    position += sum;
}

Node::~Node() {
}

