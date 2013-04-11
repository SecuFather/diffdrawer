/*
 * CosFunction.cpp
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#include "../inc/CosFunction.h"
#include <cmath>

const string CosFunction::name = "cos";

void CosFunction::getResult(MainFunction* mf){
	mf->pop();
	float result = cos( mf->top()->operator float() );
	mf->top()->setValue( result );
}
