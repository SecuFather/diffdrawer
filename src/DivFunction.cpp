/*
 * DivFunction.cpp
 *
 *  Created on: May 28, 2011
 *      Author: ziomq1991
 */

#include "../inc/DivFunction.h"

const string DivFunction::name = "/";

void DivFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = mf->top()->operator float();
	mf->pop();

	if(result == 0.0){
		throw "Division by zero!";
	}else{
		result = mf->top()->operator float() / result;
	}

	mf->top()->setValue(result);
}
