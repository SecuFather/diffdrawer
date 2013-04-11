/*
 * RPNConverter.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef RPNCONVERTER_H_
#define RPNCONVERTER_H_

#include <string>
#include <sstream>
#include <stack>
#include "Function.h"
#include "MainFunction.h"
#include "FunctionsFactory.h"
using namespace std;

class RPNConverter{
public:
	static void convert(string& toConvert, MainFunction* mf);
};

#endif /* RPNCONVERTER_H_ */
