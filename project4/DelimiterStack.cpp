#include "stdafx.h"
#include<iostream>
#include "DelimiterStack.h"

using namespace std;

DelimiterStack::~DelimiterStack()
{
	DelimiterNode *nodePtr = nullptr, *nextNode = nullptr;
	nodePtr = top;

	while (nodePtr != nullptr) 
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;

	}

}



//Stack Operations
void DelimiterStack::push(char character, int lineNumber, int charCount) {

	DelimiterNode *newNode = nullptr;

	newNode = new DelimiterNode;
	newNode->character = character;
	newNode->lineNumber = lineNumber;
	newNode->charCount = charCount;

	if (isEmpty()) {
		top = newNode;
		newNode->next = nullptr;
	}
	else {
		newNode->next = top;
		top = newNode;
	}

}



// reference variables because three variables 
//cannot be returned through return statement
void DelimiterStack::popDelimiter(char &character, int &lineNumber, int &charCount) {

	DelimiterNode * temp = nullptr;

	if (isEmpty())
	{
		cout << "The stack is empty. \n";
	}
	else {
		character = top->character;
		lineNumber = top->lineNumber;
		charCount = top->charCount;
		temp = top->next;
		delete top;
		top = temp;
	}

}



bool DelimiterStack::isEmpty() {

	bool status;

	if (!top) {
		status = true;
	}
	else {
		status = false;
	}

	return status;


}