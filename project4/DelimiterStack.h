
#ifndef DELIMITERSTACK_H
#define DELIMITERSTACK_H


class DelimiterStack {

private:
	struct DelimiterNode {
		char character;
		int lineNumber;
		int charCount;
		DelimiterNode * next;
	};
	// Define stack top
	DelimiterNode *top;

public:
	//Constructor
	DelimiterStack() {
		top = nullptr;
	}
	//Destructor
	~DelimiterStack();


	//Stack Operations
	void push(char, int, int);
	void popDelimiter(char&, int &, int &); // reference variables because three variables cannot be returned through return statement
	bool isEmpty();
};



#endif // !DELIMITERSTACK_H

