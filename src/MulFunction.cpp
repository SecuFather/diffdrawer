/*
 * MulFunction.cpp
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#include "../inc/MulFunction.h"

const string MulFunction::name = "*";

void MulFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = mf->top()->operator float();
	mf->pop();
	result *= mf->top()->operator float();

	mf->top()->setValue(result);
}
