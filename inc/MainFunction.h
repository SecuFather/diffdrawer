/*
 * MainFunction.h
 *
 *  Created on: May 30, 2011
 *      Author: ziomq1991
 */

#ifndef MAINFUNCTION_H_
#define MAINFUNCTION_H_

#include <stack>
#include <vector>
#include <string>

using namespace std;

class Function;

class MainFunction {
protected:
	stack<Function*> rpnStack;
	vector<Function*> innerFunctions;
public:
	static const string name;

	MainFunction(string source);

	void push(Function* f){ innerFunctions.push_back(f); }
	Function* top();
	void pop();

	operator float();
};

#endif /* MAINFUNCTION_H_ */
