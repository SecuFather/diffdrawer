/*
 * SinFunction.cpp
 *
 *  Created on: May 29, 2011
 *      Author: ziomq1991
 */

#include "../inc/SinFunction.h"
#include <cmath>

const string SinFunction::name = "sin";

void SinFunction::getResult(MainFunction* mf){
	mf->pop();
	mf->top()->setValue( sin( *(mf->top()) ) );
}
