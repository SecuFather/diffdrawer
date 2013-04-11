/*
 * RightBracket.h
 *
 *  Created on: Jun 1, 2011
 *      Author: ziomq1991
 */

#ifndef RIGHTBRACKET_H_
#define RIGHTBRACKET_H_

#include "Function.h"

class RightBracket : public Function{
public:
	static const string name;
	const static int priority = 4;

	RightBracket(string source = "") : Function(source){}

	virtual void getResult(MainFunction* mf){ throw "Bracket could not return result"; }
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* RIGHTBRACKET_H_ */
