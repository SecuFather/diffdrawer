/*
 * SubFunction.cpp
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#include "../inc/SubFunction.h"

const string SubFunction::name = "-";

void SubFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = mf->top()->operator float();
	mf->pop();
	result = mf->top()->operator float() - result;
	mf->top()->setValue(result);
}
