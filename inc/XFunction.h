/*
 * XFunction.h
 *
 *  Created on: Jun 1, 2011
 *      Author: ziomq1991
 */

#ifndef XFUNCTION_H_
#define XFUNCTION_H_

#include "Function.h"
#include <stdlib.h>

class XFunction : public Function{
protected:
	float a;
	float y;
public:
	const static string name;
	const static int priority = 0;

	XFunction(string source="") : Function(source), a(source.empty() ? 1.0f : atof(source.c_str())), y(a*Function::x){}

	virtual void getResult(MainFunction* mf){ throw "Could not get result!"; }
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
	virtual operator float(){ return y; }
	virtual void setValue(float v){ y = v; }
};

#endif /* XFUNCTION_H_ */
