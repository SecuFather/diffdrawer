/*
 * SyntaxCorrector.h
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#ifndef SYNTAXCORRECTOR_H_
#define SYNTAXCORRECTOR_H_

#include "Function.h"
#include "ConstFunction.h"
#include "AddFunction.h"
#include "SubFunction.h"
#include "MulFunction.h"
#include "DivFunction.h"
#include "SinFunction.h"
#include "CosFunction.h"
#include "PowFunction.h"
#include "LnFunction.h"
#include "LeftBracket.h"
#include "RightBracket.h"
#include "XFunction.h"

#include <string>
using namespace std;

class SyntaxCorrector{
public:
	static bool findBracket(string& toSearch, unsigned int& index, int& bracketsWithoutPair, bool& numberExpected);
	static void checkBrackets(int& bracketsWithoutPair);
	static bool checkFloat(string& toCkeck, unsigned int& index);
	static bool checkOperator(string& toCheck, unsigned int& index);
	static bool checkFunction(string& toCheck, unsigned int& index);
	static string syntaxErrorAfter(string& source, unsigned int after);
	static bool manageWhiteSpace(string& source, unsigned int& index, bool& insertWhiteSpace);

	static void correct(string& toCorrect);
};

#endif /* SYNTAXCORRECTOR_H_ */
