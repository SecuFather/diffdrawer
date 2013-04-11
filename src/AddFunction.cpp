/*
 * AddFunction.cpp
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#include "../inc/AddFunction.h"

const string AddFunction::name = "+";

void AddFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = mf->top()->operator float();
	mf->pop();
	result += mf->top()->operator float();
	mf->top()->setValue(result);
}
