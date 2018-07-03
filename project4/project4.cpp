// project4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"DelimiterStack.h"
#include <string>

using namespace std;

string readConsole(int &);
void parseLine(string, DelimiterStack &, int);

int main(){
	
	DelimiterStack mydelistack;
	string currentLine;
	int lineCount = 0;
	
	cout << "Please enter a sentence with {}, [], or () as delimeter or enter DONE to quit \n\n";

do {
	
	//currentLine = readConsole();
	lineCount++;
	currentLine = readConsole(lineCount);	//if (currentLine != "DONE") {
		//cout << "Line " << lineCount << ": " << currentLine << endl;
	//}
	parseLine(currentLine, mydelistack, lineCount);

} while (currentLine != "DONE");
	
cout << "Good bye!";
system("pause");

return 0;
}

void parseLine(string str, DelimiterStack &stack, int line) {

	const char *charPtr = nullptr;
	char delimeter = NULL;
	int charCount = 0;
	int refcharCount = 0;
	int popLine = 0;
	string msg = "";

	charPtr = str.c_str();

	for (int ind = 0; ind < str.length(); ind++) {
		charCount++;

		if (charPtr[ind] == '{' ||
			charPtr[ind] == '(' ||
			charPtr[ind] == '[') {
			stack.push(charPtr[ind], line, charCount);
		}
		else if (
			charPtr[ind] == '}' ||
			charPtr[ind] == ')' ||
			charPtr[ind] == ']') {
	
			if (!stack.isEmpty()) {
				stack.popDelimiter(delimeter, popLine, refcharCount);

				msg =
					"Mismatched delimiter " + string(1, delimeter) +
					" found at line " + to_string(popLine) +
					", char " + to_string(refcharCount) +
					" does not match " + charPtr[ind] +
					" found at line " + to_string(line) +
					", char " + to_string(charCount) + "\n";

				if (delimeter == '{' && charPtr[ind] != '}') {
					cout << msg;
				}
				else if (delimeter == '[' && charPtr[ind] != ']') {
					cout << msg;
				}
				else if (delimeter == '(' && charPtr[ind] != ')') {
					cout << msg;
				}
			}
			else {
				msg =
					string("Right delimiter ") + charPtr[ind] +
					string(" had no left delimiter found at line ") + to_string(line) +
					", char " + to_string(charCount) + "\n";

				cout << msg;
			}
		}
		
	}//end of for

	if (!stack.isEmpty() && str == "DONE") {

		stack.popDelimiter(delimeter, popLine, refcharCount);
		msg =
			"Left delimiter " + string(1, delimeter) +
			" found at line " + to_string(popLine) +
			", char " + to_string(refcharCount) +
			" had no right delimiter\n";

		cout << msg;
	}
}

string readConsole(int &refline) {

	string userString = "";
	bool flag = true;
	int letterCount = 0;

	do {
		try {
			cout << "Line " + to_string(refline) + ">> ";
			getline(cin, userString);

			for (int ind = 0; ind < userString.size(); ind++) {
				
				if(userString.empty()) {
					throw string("Sentence should have atleast one word");
				}
				else if(!isspace(userString[ind])) {
					letterCount++;
				}
			}

			if(letterCount == 0) {
				throw string("Empty entry !");
			}
			flag = false;
		}
		catch (string exceptionString) {
			cout << exceptionString << endl;
		}

	} while (flag);

	int ind = 0;
	//remove all space at the begining of user entry
	while (isspace(userString[ind])) {
		ind++;
	}
	userString.erase(0, ind);

	ind = 0;
	//remove all spaces at the end of user entry
	while (isspace(userString[userString.size() - 1 - ind])) {
		ind++;
	}
	userString.erase(userString.size() - ind, ind);

	//remove more than one space between two words in user entry
	ind = 0;
	while (userString[ind] != '\0') {
		if (isspace(userString[ind]) && isspace(userString[ind + 1])) {
			userString.erase(ind + 1, 1);
		}
		else {
			ind++;
		}
	}


	return userString;
}

