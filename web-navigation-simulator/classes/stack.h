#ifndef STACK_H
#define STACK_H

class Stack{
	private:
		Node *top;
	public:
		Stack();
		bool isEmpty();
		void addToStack(std::string value);
		std::string getTop();
		void removeTop();
		void printStack();	
};

#endif