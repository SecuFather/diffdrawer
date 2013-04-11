/*
 * Calculator.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "Function.h"
#include "MainFunction.h"
#include "SyntaxCorrector.h"
#include "RPNConverter.h"
#include "RPNCalculator.h"

#include <string>
using namespace std;

class Calculator{
public:
	static void calculate(string toCalculate, MainFunction* mf);
};

#endif /* CALCULATOR_H_ */
