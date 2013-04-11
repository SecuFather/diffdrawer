/*
 * Function.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <string>
#include <stack>
#include "MainFunction.h"
using namespace std;



class Function{
protected:
	static float x;
	string source;

public:
	Function(string source = "") : source(source) {}

	virtual void getResult(MainFunction* mf) = 0;
	virtual string getName() = 0;
	virtual int getPriority() = 0;
	virtual operator float(){ throw "Could not cast to float!"; }
	virtual void setValue(float v){ throw "Could not set value!"; }

	inline static void setX(float x){ Function::x = x; }
};

#endif /* FUNCTION_H_ */
