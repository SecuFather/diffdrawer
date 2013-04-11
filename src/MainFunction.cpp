/*
 * MainFunction.cpp
 *
 *  Created on: May 30, 2011
 *      Author: ziomq1991
 */

#include "../inc/MainFunction.h"
#include "../inc/Function.h"
#include "../inc/SyntaxCorrector.h"
#include "../inc/RPNConverter.h"

MainFunction::MainFunction(string source){
	SyntaxCorrector::correct(source);
	RPNConverter::convert(source, this);
}

MainFunction::operator float(){
	if(innerFunctions.size() == 0){
		throw "Function is empty!";
	}
	for(unsigned int i=0; i<innerFunctions.size(); ++i){
		try{
			rpnStack.push(innerFunctions[i]);
			rpnStack.top()->getResult(this);
		}catch(const char* e){
			if(string(e) != string("Could not get result!")){
				throw e;
			}
		}
	}
	float result = rpnStack.top()->operator float();
	rpnStack.pop();
	return result;
}

void MainFunction::pop(){
	if(rpnStack.size() > 0){
		delete rpnStack.top();
		rpnStack.pop();
	}else{
		throw "No item to pop!";
	}
}

Function* MainFunction::top(){
	if(rpnStack.size() > 0){
		return rpnStack.top();
	}else{
		throw "Stack is empty!";
	}
}
