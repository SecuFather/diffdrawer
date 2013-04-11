/*
 * AddFunction.h
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#ifndef ADDFUNCTION_H_
#define ADDFUNCTION_H_

#include "Function.h"

class AddFunction : public Function{
public:
	static const string name;
	const static int priority = 1;

	AddFunction(string source = "") : Function(source){}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* ADDFUNCTION_H_ */
