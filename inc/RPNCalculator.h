/*
 * RPNCalculator.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef RPNCALCULATOR_H_
#define RPNCALCULATOR_H_

#include "Function.h"
#include "FunctionsFactory.h"

#include <string>
using namespace std;

class RPNCalculator{
public:
	static void calculate(string& toCalculate, Function* function);
};

#endif /* RPNCALCULATOR_H_ */
