/*
 * ConstFunction.h
 *
 *  Created on: May 30, 2011
 *      Author: ziomq1991
 */

#ifndef CONSTFUNCTION_H_
#define CONSTFUNCTION_H_

#include "../inc/Function.h"
#include <stdlib.h>

class ConstFunction : public Function{
protected:
	float y;
public:
	const static string name;
	const static int priority = 0;

	ConstFunction(string source = "") : Function(source), y(atof(source.c_str())){}

	virtual void getResult(MainFunction* mf){ throw "Could not get result!"; }
	virtual string getName(){ return name; }
	virtual operator float() { return y; }
	virtual void setValue(float v){ y = v; }
	virtual int getPriority(){ return priority; }
};

#endif /* CONSTFUNCTION_H_ */
