/*
 * SyntaxCorrector.cpp
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#include "../inc/SyntaxCorrector.h"

void SyntaxCorrector::correct(string& toCorrect){
	int bracketsWithoutPair = 0;
	bool numberExpected = true;
	bool insertWhiteSpace = false;

	for(unsigned int i=0; i<toCorrect.length(); ++i){
		if(findBracket(toCorrect, i, bracketsWithoutPair, numberExpected)){
			if(toCorrect[i] == ' '){
				insertWhiteSpace = false;
			}
			continue;
		}

		if(manageWhiteSpace(toCorrect, i, insertWhiteSpace)){
			continue;
		}

		if(checkFunction(toCorrect, i)){
			numberExpected = true;
		}else{
			if(numberExpected){
				numberExpected = checkFloat(toCorrect, i);
			}else{
				numberExpected = checkOperator(toCorrect, i);
			}
		}

		insertWhiteSpace = true;
	}
	checkBrackets(bracketsWithoutPair);
}

bool SyntaxCorrector::checkFunction(string& toCheck, unsigned int& index){
	string matched;
	char c = toCheck[index];

	if(c == SinFunction::name[0]){
		matched = SinFunction::name;
	}
	if(c == CosFunction::name[0]){
		matched = CosFunction::name;
	}
	if(c == LnFunction::name[0]){
		matched = LnFunction::name;
	}
	if((toCheck.length()-index) < matched.length() || matched.empty() ||
	   toCheck.substr(index, matched.length()) != matched){
		return false;
	}else{
		index += matched.length()-1;
	}
	return true;
}

bool SyntaxCorrector::findBracket(string& toSearch, unsigned int& index, int& bracketsWithoutPair, bool& numberExpected){
	char c = toSearch[index];

	if(c == '('){
		if(!numberExpected){
			toSearch.insert(index, " * ");
			index += 4;
		}else{
			toSearch.insert(index, " ");
			index += 2;
		}
		toSearch.insert(index, " ");
		++bracketsWithoutPair;
		numberExpected = true;
		return true;
	}
	if(c == ')'){
		toSearch.insert(index, " ");
		++index;
		--bracketsWithoutPair;
		numberExpected = false;
		return true;
	}
	return false;
}

void SyntaxCorrector::checkBrackets(int& bracketsWithoutPair){
	if(bracketsWithoutPair < 0){
		throw "'(' not found!";
	}
	if(bracketsWithoutPair > 0){
		throw "')' not found!";
	}
}

bool SyntaxCorrector::checkFloat(string& toCheck, unsigned int& index){
	bool dotFound = false;

	if(index+1 < toCheck.length() && toCheck[index] == '-'){
		++index;
		if(toCheck[index] == 'x'){
			toCheck.insert(index, "1");
		}
	}
	unsigned int start = index;
	for(;index<toCheck.length(); ++index){
		if(toCheck[index] == '.'){
			if(dotFound){
				throw syntaxErrorAfter(toCheck, index).c_str();
			}else{
				dotFound = true;
			}
			continue;
		}

		if(toCheck[index] < '0' || toCheck[index] > '9' ){
			if(toCheck[index] != 'x'){
				--index;
				if(index < start){
					throw syntaxErrorAfter(toCheck, index).c_str();
				}
			}
			return false;
		}
	}
	return false;
}

bool SyntaxCorrector::checkOperator(string& toCheck, unsigned int& index){
	string matched;
	char c = toCheck[index];

	if(c == AddFunction::name[0]) {
		return true;
	}
	if(c == SubFunction::name[0]){
		return true;
	}
	if(c == MulFunction::name[0]){
		return true;
	}
	if(c == DivFunction::name[0]){
		return true;
	}
	if(c == PowFunction::name[0]){
		return true;
	}

	throw syntaxErrorAfter(toCheck, index).c_str();
}

string SyntaxCorrector::syntaxErrorAfter(string& source, unsigned int after){
	return string("Syntax error after '") + source.substr(0, after) + string("'");
}

bool SyntaxCorrector::manageWhiteSpace(string& source, unsigned int& index, bool& insertWhiteSpace){
	char c = source[index];
	if(insertWhiteSpace && c == ' '){
		insertWhiteSpace = false;
		return true;
	}
	if(insertWhiteSpace && c != ' '){
		insertWhiteSpace = false;
		source.insert(index, " ");
		return true;
	}
	if(!insertWhiteSpace && c == ' '){
		source.erase(index, 1);
		--index;
		return true;
	}
	return false;
}
