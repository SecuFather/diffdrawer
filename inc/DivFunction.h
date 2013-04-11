/*
 * DivFunction.h
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#ifndef DIVFUNCTION_H_
#define DIVFUNCTION_H_

#include "Function.h"

class DivFunction : public Function{
public:
	static const string name;
	const static int priority = 2;

	DivFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* DIVFUNCTION_H_ */
