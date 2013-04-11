/*
 * CosFunction.h
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#ifndef COSFUNCTION_H_
#define COSFUNCTION_H_

#include "Function.h"

class CosFunction : public Function{
public:
	const static string name;
	const static int priority = 3;

	CosFunction(string source="") : Function(source) {}

	virtual void getResult(MainFunction* mf);
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* COSFUNCTION_H_ */
