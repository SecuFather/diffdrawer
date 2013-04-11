/*
 * PowFunction.h
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#ifndef POWFUNCTION_H_
#define POWFUNCTION_H_

#include "Function.h"

class PowFunction : public Function{
public:
	const static string name;
	const static int priority = 3;

	PowFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* POWFUNCTION_H_ */
