/*
 * LeftBracket.h
 *
 *  Created on: Jun 1, 2011
 *      Author: ziomq1991
 */

#ifndef LEFTBRACKET_H_
#define LEFTBRACKET_H_

#include "Function.h"

class LeftBracket : public Function{
public:
	static const string name;
	const static int priority = 4;

	LeftBracket(string source = "") : Function(source){}

	virtual void getResult(MainFunction* mf) { throw "Bracket could not return results"; }
	virtual string getName(){ return name; }
	virtual int getPriority(){ return priority; }
};

#endif /* LEFTBRACKET_H_ */
