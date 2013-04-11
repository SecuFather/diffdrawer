/*
 * RPNConverter.cpp
 *
 *  Created on: May 27, 2011
 *      Author: ziomq1991
 */

#include "../inc/RPNConverter.h"

void RPNConverter::convert(string& toConvert, MainFunction* mf){
	stringstream ss(toConvert);
	stack<Function*> tempStack;
	vector<Function*> tempInners;
	string temp;

	FunctionsFactory::create(toConvert, tempInners);

	for(unsigned int i=0; i<tempInners.size(); ++i){
		if(tempInners[i]->getPriority() == 0){
			mf->push(tempInners[i]);
			continue;
		}
		if(tempStack.empty()){
			tempStack.push( tempInners[i] );
		}else{
			if(tempInners[i]->getPriority() <= tempStack.top()->getPriority() &&
					tempInners[i]->getName() != string(")") &&
					tempStack.top()->getName() != string("(") ){
				mf->push( tempStack.top() );
				tempStack.pop();
				tempStack.push( tempInners[i] );
			}else{
				if(tempInners[i]->getName() == string(")")){
					delete tempInners[i];
					while(tempStack.top()->getName() != string("(")){
						mf->push( tempStack.top());
						tempStack.pop();
					}
					delete tempStack.top();
					tempStack.pop();
				}else{
					tempStack.push( tempInners[i] );
				}
			}
		}
	}
	while(tempStack.size() != 0){
		mf->push( tempStack.top() );
		tempStack.pop();
	}
}
