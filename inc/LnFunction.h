/*
 * LnFunction.h
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#ifndef LNFUNCTION_H_
#define LNFUNCTION_H_

#include "Function.h"

class LnFunction : public Function{
public:
	const static string name;
	const static int priority = 3;

	LnFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* LNFUNCTION_H_ */
