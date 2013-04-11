/*
 * SubFunction.h
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#ifndef SUBFUNCTION_H_
#define SUBFUNCTION_H_

#include "Function.h"

class SubFunction : public Function{
public:
	const static string name;
	const static int priority = 1;

	SubFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* SUBFUNCTION_H_ */
