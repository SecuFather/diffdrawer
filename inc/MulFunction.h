/*
 * MulFunction.h
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#ifndef MULFUNCTION_H_
#define MULFUNCTION_H_

#include "Function.h"

class MulFunction : public Function{
public:
	static const string name;
	const static int priority = 2;

	MulFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* MULFUNCTION_H_ */
