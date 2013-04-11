/*
 * LnFunction.cpp
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#include "../inc/LnFunction.h"
#include <cmath>

const string LnFunction::name = "ln";

void LnFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = mf->top()->operator float();
	if(result > 0.0){
		mf->top()->setValue( log(result) );
	}else{
		throw "Negative and zero argument not allowed for logarithm!";
	}
}
