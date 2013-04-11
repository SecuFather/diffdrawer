/*
 * FunctionsFactory.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef FUNCTIONSFACTORY_H_
#define FUNCTIONSFACTORY_H_

#include "Function.h"

#include <string>
#include <vector>
#include <sstream>
#include "SyntaxCorrector.h"
using namespace std;

class FunctionsFactory{
public:
	static bool isFloat(string source);
	static bool isXFunction(string source);
	static void create(string source, vector<Function*>& funVec);
};

#endif /* FUNCTIONSFACTORY_H_ */
