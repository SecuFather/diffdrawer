/*
 * SinFunction.h
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#ifndef SINFUNCTION_H_
#define SINFUNCTION_H_

#include "Function.h"

class SinFunction : public Function{
public:
	const static string name;
	const static int priority = 3;

	SinFunction(string source = "") : Function(){}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* SINFUNCTION_H_ */
