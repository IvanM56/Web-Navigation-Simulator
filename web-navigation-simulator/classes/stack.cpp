#include <iostream>
#include <string>
#include "structs.h"
#include "stack.h"


Stack::Stack(){
	top = NULL;	
};
bool Stack::isEmpty(){
	if(!top){
		return true;
	} 
	return false;	
}
void Stack::addToStack(std::string value){
	Node *newNode = new Node;
	newNode->data = value;
	newNode->next = top;
	
	top = newNode;
}
std::string Stack::getTop(){
	if(!top){
		return "";
	} 
	return top->data;
}
void Stack::removeTop(){
	if(!isEmpty()){
		Node *ptr;
		ptr = top;
		top = ptr->next;
		delete ptr;	
	} 	
}
void Stack::printStack(){
	if(isEmpty()){
		std::cout << "Stack is empty!\n";
	}
	Node *ptr;
	ptr = top;
	while(ptr != NULL){
		std::cout << ptr->data << "-->";
		ptr = ptr->next;
	}
}	

