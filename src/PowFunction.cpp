/*
 * PowFunction.cpp
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#include "../inc/PowFunction.h"
#include <cmath>

const string PowFunction::name = "^";

void PowFunction::getResult(MainFunction* mf){
	mf->pop();

	float result = mf->top()->operator float();
	mf->pop();
	result = pow(mf->top()->operator float(), result);

	mf->top()->setValue( result );
}
