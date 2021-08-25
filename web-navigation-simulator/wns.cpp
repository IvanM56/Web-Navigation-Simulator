#include <iostream>
#include <string>
#include "classes/structs.h"
#include "classes/stack.h"
#include "wns.h"


Stack backPages;
Stack nextPages;
std::string currentPage = "Start page";

void welcome(){
	std::cout << "\n";
	std::cout << "----------------------\n";
	std::cout << "Welcome to the Browser\n";
	std::cout << "----------------------\n\n";
};
void display(){
	std::cout << "Current page: " << currentPage << "\n";	
	std::cout << "Back page: " << backPages.getTop() << "\n";
	std::cout << "Next page: " << nextPages.getTop() << "\n\n";
};
void openNewPage(std::string page){
	backPages.addToStack(currentPage);
	currentPage = page;
	
	while(!nextPages.isEmpty()){
		nextPages.removeTop();	
	};
	
	display();
};
void goBack(){
	nextPages.addToStack(currentPage);
	currentPage = backPages.getTop();
	backPages.removeTop();
	
	display();
};
void goNext(){
	backPages.addToStack(currentPage);
	currentPage = nextPages.getTop();
	nextPages.removeTop();
	
	display();
};
void workflow(){
	std::string enterURL = "Enter URL";
	std::string back = "B|b for back";
	std::string next = "N|n for next";
	std::string quit = "Q|q for quit";
		
	std::string menu;
	std::string userInput;
	bool backBtn = false;
	bool nextBtn = false;
	bool exit = false;
		
	display();
	
	while(exit == false){
		if(!backPages.isEmpty() && nextPages.isEmpty()){
			menu = enterURL + ", " + back + ", " + quit;
			backBtn = true;
			nextBtn = false;
		} else if(!backPages.isEmpty() && !nextPages.isEmpty()){
			menu = enterURL + ", " + back + ", " + next + ", " + quit;
			backBtn = true;
			nextBtn = true;
		} else if(backPages.isEmpty() && !nextPages.isEmpty()){
			menu = enterURL + ", " + next + ", " + quit;
			nextBtn = true;
			backBtn = false;
		} else {
			menu = enterURL + ", " + quit;
		}
			
		std::cout << menu << "\n";
		std::cout << "Go to: ";
		
		std::cin >> userInput;
		
		if((userInput == "b" || userInput == "B") && backBtn == true){
			goBack();
		} else if((userInput == "n" || userInput == "N") && nextBtn == true){
			goNext();
		} else if(userInput == "b" || userInput == "B"){
			std::cout << "No back pages!\n\n";
		} else if(userInput == "n" || userInput == "N"){
			std::cout << "No next pages!\n\n";
		} else if(userInput == "q" || userInput == "Q"){
			exit = true;
		}  else {
			openNewPage(userInput);
		}		
	}
};





